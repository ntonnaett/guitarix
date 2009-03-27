//-----------------------------------------------------
// name : "guitarix"
// version : "0.03.3"
// author : "hermann meyer"
// contributors : "Julius O. Smith (jos at ccrma.stanford.edu)"
// license : "GPL"
// copyright : "(c)brummer 2008"
// reference : "http://ccrma.stanford.edu/realsimple/faust_strings/"
//
// Code prototype generated with Faust 0.9.9.4f (http://faust.grame.fr)
//-----------------------------------------------------

/******************************************************************************
*******************************************************************************

								jack interface
	main.cpp
	here is the main jack play tread
*******************************************************************************
*******************************************************************************/

/* link with  */
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <cstdlib>
#include <dlfcn.h>
#include <pthread.h> 
#include <limits.h>

// #include <X11/Xlib.h>
// #include <X11/cursorfont.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include <libgen.h>
#include <jack/jack.h>
#include <jack/midiport.h>

using namespace std;

// On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
// flags to avoid costly denormals
#ifdef __SSE__
#include <xmmintrin.h>
#ifdef __SSE2__
#define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
#else
#define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
#endif
#else
#define AVOIDDENORMALS
#endif

inline void *aligned_calloc(size_t nmemb, size_t size)
{
    return (void*)(((size_t)(calloc((nmemb*size)+15,sizeof(char)))+15) & (~15));
}

// g++ -O3 -pipe  -march=native -mfpmath=sse -ffast-math -lm -ljack `gtk-config --cflags --libs` ex2.cpp

#define max(x,y) (((x)>(y)) ? (x) : (y))
#define min(x,y) (((x)<(y)) ? (x) : (y))

// ------------------define the parameter reading,  -----------------------------------
#define OPTARGS_CHECK_GET(wrong,right) lokke==argc-1?(fprintf(stderr,"Must supply argument for '%s'\n",argv[lokke]),exit(-2),wrong):right
#define OPTARGS_BEGIN(das_usage) {int lokke;const char *usage=das_usage;for(lokke=1;lokke<argc;lokke++){char *a=argv[lokke];if(!strcmp("--help",a)||!strcmp("-h",a)){fprintf(stderr,usage);return 0;
#define OPTARG(name,name2) }}else if(!strcmp(name,a)||!strcmp(name2,a)){{
#define OPTARG_GETSTRING() OPTARGS_CHECK_GET("",argv[++lokke])
#define OPTARGS_END }else{fprintf(stderr,usage);return(-1);}}}

inline int		lsr (int x, int n)
{
    return int(((unsigned int)x) >> n);
}

inline int 		int2pow2 (int x)
{
    int r=0;
    while ((1<<r)<x) r++;
    return r;
}

#include <map>
#include <list>

using namespace std;

struct Meta : map<const char*, const char*>
{
    void declare (const char* key, const char* value)
    {
        (*this)[key]=value;
    }
};



#include "UI.cpp"


#define stackSize 256
#define kSingleMode 0
#define kBoxMode 1
#define kTabMode 2

#include "./guitarix/Gtkwaveview.h"
#include "./guitarix/GTKUI.h"
#include"./guitarix/jconv_settings.h"
#include "./guitarix/resample.h"
#include "guitarix.cpp"
#include "Gtkwaveview.cpp"
#include "GTKUI.cpp"
#include"resample.cpp"
#include"jconv_settings.cpp"
#include "BEATDETECTOR.cpp"
#include "dsp.cpp"


/******************************************************************************
*******************************************************************************

							JACK AUDIO INTERFACE

*******************************************************************************
*******************************************************************************/

//----------------------------------------------------------------------------
// 	number of input and output channels
//----------------------------------------------------------------------------

int		gNumInChans;


//----------------------------------------------------------------------------
// Jack ports
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
// tables of noninterleaved input and output channels for FAUST
//----------------------------------------------------------------------------

float* 	gInChannel[256];
float* 	gOutChannel[256];
void*		midi_port_buf ;

//----------------------------------------------------------------------------
// Jack Callbacks
//----------------------------------------------------------------------------

int srate(jack_nframes_t nframes, void *arg)
{
   // printf("the sample rate is now %u/sec\n", nframes);
  //  jackframe = nframes;
    return 0;
}

void jack_shutdown(void *arg)
{
    exit(1);
}

void signal_handler(int sig)
{
	jack_client_close(client);
	jack_client_close(midi_client);
	fprintf(stderr, "signal received, exiting ...\n");
	exit(0);
}

int process (jack_nframes_t nframes, void *arg)
{
    AVOIDDENORMALS;
    for (int i = 0; i < gNumInChans; i++)
    {
        gInChannel[i] = (float *)jack_port_get_buffer(input_ports[i], nframes);
    }
    for (int i = 0; i < gNumOutChans; i++)
    {
        gOutChannel[i] = (float *)jack_port_get_buffer(output_ports[i], nframes);
    }
    DSP.compute(nframes, gInChannel, gOutChannel);
    return 0;
}

int midi_process (jack_nframes_t nframes, void *arg)
{
    if (midi_output_ports != NULL){
    AVOIDDENORMALS;
    midi_port_buf =  jack_port_get_buffer(midi_output_ports, frag);
    jack_midi_clear_buffer(midi_port_buf);
    cpu_load = jack_cpu_load(midi_client);
    DSP.compute_midi(nframes, gInChannel, midi_port_buf);
    }
    return 0;
}
/******************************************************************************
*******************************************************************************

								MAIN PLAY THREAD

*******************************************************************************
*******************************************************************************/

//-------------------------------------------------------------------------
// 									MAIN
//-------------------------------------------------------------------------

int main(int argc, char *argv[] )
{

    {
        OPTARGS_BEGIN("\033[1;34m guitarix settings useage\033[0m\n all parameters are optional\n\n[\033[1;31m--pix -p\033[0m] [\033[1;31m--clear -c\033[0m] [\033[1;31m--rcset -r\033[0m]\n\n"
                      "[\033[1;31m--pix\033[0m] or [\033[1;31m-p\033[0m]  ->use the gtk-pixmap engine with guitarix_pix.rc\n\n"
                      "[\033[1;31m--clear\033[0m] or [\033[1;31m-c\033[0m]  ->dont use a gtkrc style file\n\n"
                      "[\033[1;31m--rcset\033[0m] or [\033[1;31m-r\033[0m]  ->use the given path/name of gtk.rc file with guitarix.\n\n"
                      "                                                                                 -> leave it blank to use the gtk-clearlooks engine with guitarix.rc\n\n"
                     )
        {
            OPTARG("--pix","-p") rcpath = "/usr/share/guitarix/guitarix_black.rc";
            OPTARG("--rcset","-r") rcpath=OPTARG_GETSTRING();
            OPTARG("--clear","-c") rcpath = "    ";
            OPTARG("--nogui","-nogui") param = "nogui";

        }
        OPTARGS_END;
    }
    if  (strcmp(rcpath, " ") == 0) rcpath =  "/usr/share/guitarix/guitarix.rc";
    char                buf [256];
    jack_status_t       jackstat;
    const char*			home;
    char*				pname;
    char*				jname;
    char*				midi_jname;
    char                rcfilename[256];
    char                midiname[256];
    param = basename (argv [1]);
    jname = basename (argv [0]);
    snprintf(midiname, 256, "%s", "guitarix_midi");
    midi_jname = midiname;

    AVOIDDENORMALS;

    if ((strcmp(param, "nogui") == 0) || (strcmp(param, "--nogui") == 0) || (strcmp(param, "-nogui") == 0))
    {
        fprintf (stderr, "no Gui version loaded\n");
        param = "nogui";
    }

    client = jack_client_open (jname, (jack_options_t) 0, &jackstat);
    if (client == 0)
    {
        fprintf (stderr, "Can't connect to JACK, is the server running ?\n");
        exit (1);
    }
    if (jackstat & JackNameNotUnique)
    {
        jname = jack_get_client_name (client);
    }

    midi_client = jack_client_open (midi_jname, (jack_options_t) 0, &jackstat);
    if (midi_client == 0)
    {
        fprintf (stderr, "Can't connect to JACK, is the server running ?\n");
        exit (1);
    }
    if (jackstat & JackNameNotUnique)
    {
        midi_jname = jack_get_client_name (midi_client);
    }

    jack_set_process_callback(client, process, 0);
    jack_set_process_callback(midi_client, midi_process, 0);
    jack_set_sample_rate_callback(client, srate, 0);
    jack_on_shutdown(client, jack_shutdown, 0);
    gNumInChans = DSP.getNumInputs();
    gNumOutChans = DSP.getNumOutputs();
    jackframes = jack_get_sample_rate (client);
    jackframe = jackframes;
    printf("the sample rate is now %u/sec\n", jackframes);
    frag = jack_get_buffer_size (client);
    printf("the buffer size is now %u/frames\n", frag);

	signal(SIGQUIT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGHUP, signal_handler);
	signal(SIGINT, signal_handler);
       /*
	rc = jack_set_buffer_size(midi_client, frag);
	if (rc)
		fprintf(stderr, "jack_set_buffer_size(): %s\n", strerror(rc));
       */
    for (int i = 0; i < gNumInChans; i++)
    {
        snprintf(buf, 256, "in_%d", i);
        input_ports[i] = jack_port_register(client, buf, JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    }
    for (int i = 0; i < gNumOutChans; i++)
    {
        snprintf(buf, 256, "out_%d", i);
        output_ports[i] = jack_port_register(client, buf,JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
    }
    for (int i = 2; i < gNumOutChans; i++)
    {
        jack_port_unregister(client, output_ports[i]);
    }
  // midi_output_ports = jack_port_register(midi_client, "midi_out_1", JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, frag);
  //  jack_port_unregister(midi_client, midi_output_ports);
    interface = new GTKUI (jname, &argc, &argv);
    DSP.init(jackframes);
    DSP.buildUserInterface(interface);

    home = getenv ("HOME");
    if (home == 0) home = ".";
    snprintf(rcfilename, 256, "%s/.guitarix/%src", home, jname);
    interface->recallState(rcfilename);

    if (jack_activate(client))
    {
        fprintf(stderr, "Can't activate JACK client\n");
        return 1;
    }
    if (jack_activate(midi_client))
    {
        fprintf(stderr, "Can't activate JACK midi client\n");
        return 1;
    }
    // set midi tread to a lower rt-prio when run in realtime.
    if (jack_is_realtime(midi_client) == 1) 
    {
    sched_param  spar;
    int  __policy;
    pthread_getschedparam (jack_client_thread_id (midi_client), &__policy, &spar);
    int rtis;
    char istrr[256];
    snprintf(istrr, 256, "%u",spar.sched_priority);
    string isrt = istrr;
    istringstream isn(isrt);
    isn >> rtis;
    if (rtis > 19) pthread_setschedprio ( jack_client_thread_id (midi_client), 19 );
    }
    // set autoconnect capture to capture_port_1
    setenv("GUITARIX2JACK_INPUTS", "system:capture_%d", 0);
    pname = getenv("GUITARIX2JACK_INPUTS");
    if (pname && *pname)
    {
        for (int i = 0; i < gNumInChans; i++)
        {
            snprintf(buf, 256, pname, i + 1);
            jack_connect(client, buf, jack_port_name(input_ports[i]));
        }
    }

    // set autoconnect to the first pysical playback ports
    //setenv("GUITARIX2JACK_OUTPUTS", "system:playback_%d", 0);
    setenv("GUITARIX2JACK_OUTPUTS1", "system:playback_1", 0);
    setenv("GUITARIX2JACK_OUTPUTS2", "system:playback_2", 0);
    pname = getenv("GUITARIX2JACK_OUTPUTS1");
    if (pname && *pname)
    {
        int i = 0;
        snprintf(buf, 256, pname, i + 1);
        jack_connect(client, jack_port_name(output_ports[i]), buf);
        i++;
        pname = getenv("GUITARIX2JACK_OUTPUTS2");
        snprintf(buf, 256, pname, i + 1);
        jack_connect(client, jack_port_name(output_ports[i]), buf);
    }
    gNumOutChans = 2;
    interface->run();
    //sleep(2);
    jack_deactivate(midi_client);
    jack_deactivate(client);

    for (int i = 0; i < gNumInChans; i++)
    {
        jack_port_unregister(client, input_ports[i]);
    }
    for (int i = 0; i < gNumOutChans; i++)
    {
        jack_port_unregister(client, output_ports[i]);
    }
    if (midi_output_ports != NULL){
    jack_port_unregister(midi_client, midi_output_ports);
    }

    jack_client_close(midi_client);
    jack_client_close(client);
    interface->saveState(rcfilename);

    return 0;
}



