// generated from file '../src/LV2/faust/compressor.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace compressor {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT 	fentry0;
	FAUSTFLOAT	*fentry0_;
	FAUSTFLOAT 	fentry1;
	FAUSTFLOAT	*fentry1_;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fRec1[2];
	double 	fConst3;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	double 	fRec0[2];
	FAUSTFLOAT 	fentry2;
	FAUSTFLOAT	*fentry2_;
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "compressor";
	name = N_("Compressor");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec0[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = exp((0 - (1e+01 / double(iConst0))));
	fConst2 = (1 - fConst1);
	fConst3 = (1.0 / double(iConst0));
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fentry0 (*fentry0_)
#define fentry1 (*fentry1_)
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
#define fentry2 (*fentry2_)
	double 	fSlow0 = double(fentry1);
	double 	fSlow1 = (fSlow0 - double(fentry0));
	double 	fSlow2 = exp((0 - (fConst3 / max(fConst3, double(fslider0)))));
	double 	fSlow3 = exp((0 - (fConst3 / max(fConst3, double(fslider1)))));
	double 	fSlow4 = (1.0 / (0.001 + fSlow0));
	double 	fSlow5 = (double(fentry2) - 1);
	for (int i=0; i<count; i++) {
		double fTemp0 = (double)input0[i];
		fRec1[0] = ((fConst1 * fRec1[1]) + (fConst2 * fabs((fTemp0 + 1e-20))));
		double fTemp1 = ((fSlow3 * (fRec0[1] < fRec1[0])) + (fSlow2 * (fRec0[1] >= fRec1[0])));
		fRec0[0] = ((fRec0[1] * fTemp1) + (fRec1[0] * (0 - (fTemp1 - 1))));
		double fTemp2 = max((double)0, ((20 * log10(fRec0[0])) + fSlow1));
		double fTemp3 = (fSlow5 * min((double)1, max((double)0, (fSlow4 * fTemp2))));
		output0[i] = (FAUSTFLOAT)(fTemp0 * pow(10,(0.05 * ((fTemp2 * (0 - fTemp3)) / (1 + fTemp3)))));
		// post processing
		fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
	}
#undef fentry0
#undef fentry1
#undef fslider0
#undef fslider1
#undef fentry2
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case ATTACK: 
		fslider1_ = (float*)data; // , 0.002, 0.0, 1.0, 0.001 
		break;
	case KNEE: 
		fentry1_ = (float*)data; // , 3.0, 0.0, 2e+01, 0.1 
		break;
	case RATIO: 
		fentry2_ = (float*)data; // , 2.0, 1.0, 2e+01, 0.1 
		break;
	case RELEASE: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1e+01, 0.01 
		break;
	case THRESHOLD: 
		fentry0_ = (float*)data; // , -2e+01, -96.0, 1e+01, 0.1 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   ATTACK, 
   KNEE, 
   RATIO, 
   RELEASE, 
   THRESHOLD, 
} PortIndex;
*/

} // end namespace compressor
