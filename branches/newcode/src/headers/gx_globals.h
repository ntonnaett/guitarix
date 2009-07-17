/*
 * Copyright (C) 2009 Hermann Meyer and James Warden
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 * --------------------------------------------------------------------------
 *
 *  This is the guitarix global variable declarations for all namespaces
 *  These global vars are created  /  initialized in gx_globals.cpp
 *
 * --------------------------------------------------------------------------
 */

#pragma once


/* -------------------------------------------------------------------------- */

/* ----- main engine ----- */
namespace gx_engine
{
  /* engine state : can be on or off or bypassed */
  typedef enum {
    kEngineOff    = 0,
    kEngineOn     = 1,
    kEngineBypass = 2
  } GxEngineState;
  
  typedef enum {
    kMidiOff    = 0,
    kMidiOn     = 1
  } GxMidiState;
  
  /* global var  declarations */
  extern const char* stopit;
  extern float  checky;
  extern float* get_frame;
  extern float* checkfreq;
  extern float* oversample;

  /* number of channels */
  extern int    gNumInChans;
  extern int    gNumOutChans;

  extern float* gInChannel [1];
  extern float* gOutChannel[4];

  /* latency warning  switch */
  extern float fwarn_swap;
  extern float fwarn;
}

/* -------------------------------------------------------------------------- */

/* ----- jack namespace ----- */
namespace gx_jack 
{
  /* latency change confirmation */
  typedef enum {
    kUnknownAction = 0,
    kChangeLatency,
    kKeepLatency
  } GxJackLatencyChange;

  extern const int nIPorts; // mono input
  extern const int nOPorts; // stereo output + jconv
  extern int NO_CONNECTION;
  extern bool  manual_startup;

  /* variables */
  extern jack_nframes_t      jack_sr;   // jack sample rate
  extern jack_nframes_t      jack_bs;   // jack buffer size
  extern float               jcpu_load; // jack cpu_load

  extern jack_client_t*      client ;
  extern jack_port_t*        output_ports[];
  extern jack_port_t*        input_ports [];
  extern void*               midi_port_buf;

  extern GxJackLatencyChange change_latency;

#ifdef USE_RINGBUFFER
  extern struct MidiMessage  ev;
  extern jack_ringbuffer_t*  jack_ringbuffer;
#endif

  extern jack_port_t*        midi_output_ports;
  extern jack_nframes_t      time_is;
  extern bool                jack_is_running;

}

/* -------------------------------------------------------------------------- */

/* ----- JConv namespace ----- */
namespace gx_jconv 
{
  /* some global vars */
  extern float checkbutton7;
  extern float checkbox7;

  extern bool jconv_is_running;
}

/* -------------------------------------------------------------------------- */

/* ----- preset namespace ----- */
namespace gx_preset 
{
  /* global var declarations */
  extern GdkModifierType list_mod[];
  extern const char* preset_accel_path[];    
  extern const char* preset_menu_name[];    
  extern map<GtkMenuItem*, string> preset_list[];
  
  extern string gx_current_preset;
  extern string old_preset_name;
  
  extern GtkWidget* presmenu[];
  extern GtkWidget* presMenu[];

  extern vector<string> plist;
  extern bool setting_is_preset;

  extern GCallback preset_action_func[];
}

/* -------------------------------------------------------------------------- */

/* ----- child process namespace ----- */
namespace gx_child_process
{
  /* global var declarations  */

  extern FILE*    jcap_stream;
  extern FILE*    jconv_stream;
  extern string   mbg_pidfile;

  extern pid_t child_pid[];
}


/* -------------------------------------------------------------------------- */

/* ----- system namespace ----- */
namespace gx_system
{
  /* message handling */
  typedef enum {
    kInfo    = 1,
    kWarning,
    kError
  } GxMsgType;

  /* variables and constants */
  extern const int SYSTEM_OK;

  extern string rcpath;

  extern const char*  guitarix_dir;
  extern const char*  guitarix_reset;
  extern const char*  guitarix_preset;
  extern const char*  jcapsetup_file;
  extern const char*  jcapfile_wavbase;
  extern const char*  default_setting;
  extern const string gx_pixmap_dir;
  extern const string gx_style_dir;
  extern const string gx_user_dir;

  /* shell variable names */
  extern const char* shell_var_name[];
}

/* -------------------------------------------------------------------------- */

/* ----- GUI namespace ----- */
namespace gx_gui 
{
  typedef enum { 
    kWvMode1 = 1,
    kWvMode2,      
    kWvMode3      
  } GxWaveviewMode;

  /* wave view globals */
  extern bool           new_wave_view;
  extern GxWaveviewMode wave_view_mode;
  
  /* global GUI widgets */
  extern GtkWidget* fWindow;
  extern GtkWidget* menuh;
  extern GtkWidget* pb;
  extern GtkWidget* midibox;
  extern GtkWidget* fbutton;

  /* wave view widgets */
  extern GtkWidget* livewa; 
  extern GdkPixbuf* ib; 
  extern GdkPixbuf* ibm; 
  extern GdkPixbuf* ibr;

  /* jack latency change warning */
  extern GtkWidget* warn_dialog;
  extern GtkWidget* disable_warn ;

  /* engine status images */
  extern GtkWidget* gx_engine_on_image;
  extern GtkWidget* gx_engine_off_image;
  extern GtkWidget* gx_engine_bypass_image;
  extern GtkWidget* gx_engine_item;

  /* some more widgets */
  extern GtkWidget* label6;
  extern GtkWidget* label1;

  extern GtkStatusIcon* status_icon;

  extern int showwave;
  extern int shownote;

  /* skin handling */
  extern vector<string> skin_list;
  extern gint gx_current_skin;
}

/* -------------------------------------------------------------------------- */
