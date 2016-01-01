// generated from file '../src/plugins/hfb.dsp' by dsp2cc:
// Code generated with Faust 0.9.65 (http://faust.grame.fr)

#include "gx_faust_support.h"
#include "gx_plugin.h"

namespace pluginlib {
namespace hfb {

class Dsp: public PluginDef {
private:
	int fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	double 	fRec0[2];
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	FAUSTFLOAT 	fslider1;
	double 	fRec1[2];
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fRec2[3];
	void clear_state_f();
	int load_ui_f(const UiBuilder& b, int form);
	void init(unsigned int samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	int register_par(const ParamReg& reg);

	static void clear_state_f_static(PluginDef*);
	static int load_ui_f_static(const UiBuilder& b, int form);
	static void init_static(unsigned int samplingFreq, PluginDef*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef*);
	static int register_params_static(const ParamReg& reg);
	static void del_instance(PluginDef *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginDef() {
	version = PLUGINDEF_VERSION;
	flags = 0;
	id = "hfb";
	name = N_("HF Brightener");
	groups = 0;
	description = N_("High Frequency Brightener"); // description (tooltip)
	category = N_("Tone control");       // category
	shortname = N_("HF Brighten");     // shortname
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	register_params = register_params_static;
	load_ui = load_ui_f_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(192000, max(1, fSamplingFreq)));
	fConst1 = (2.36551040815034e-10 * fConst0);
	fConst2 = (1.32257544516629e-08 + fConst1);
	fConst3 = (1.17023754306854e-09 * fConst0);
	fConst4 = (0 - (6.50608604711861e-08 + fConst3));
	fConst5 = (1.18275520407517e-09 * fConst0);
	fConst6 = (6.61287722583147e-08 + fConst5);
	fConst7 = (fConst1 - 1.32257544516629e-08);
	fConst8 = (6.50608604711861e-08 - fConst3);
	fConst9 = (fConst5 - 6.61287722583147e-08);
	fConst10 = faustpower<2>(fConst0);
	clear_state_f();
}

void Dsp::init_static(unsigned int samplingFreq, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
	double 	fSlow0 = (0.007000000000000006 * (1 - double(fslider0)));
	double 	fSlow1 = (0.007000000000000006 * double(fslider1));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		fRec1[0] = ((0.993 * fRec1[1]) + fSlow1);
		double fTemp0 = (4.40858481722098e-05 + (fConst0 * (7.88503469383447e-07 + ((fRec1[0] * (fConst6 + (fConst4 * fRec1[0]))) + (fConst2 * fRec0[0])))));
		double fTemp1 = (fConst0 * ((fRec1[0] * ((5.12666523663255e-23 * fRec1[0]) - 1.59041010538546e-09)) - (3.18082021077091e-10 * fRec0[0])));
		fRec2[0] = ((double)input0[i] - (((fRec2[1] * (8.81716963444196e-05 + (fConst10 * ((fRec1[0] * ((2.34047508613708e-09 * fRec1[0]) - 2.36551040815034e-09)) - (4.73102081630068e-10 * fRec0[0]))))) + (fRec2[2] * (4.40858481722098e-05 + (fConst0 * (((fRec1[0] * (fConst9 + (fConst8 * fRec1[0]))) + (fConst7 * fRec0[0])) - 7.88503469383447e-07))))) / fTemp0));
		output0[i] = (FAUSTFLOAT)(fConst0 * ((((fRec2[0] * (fTemp1 - 1.06027340359031e-06)) + (fConst0 * (fRec2[1] * ((6.36164042154183e-10 * fRec0[0]) + (fRec1[0] * (3.18082021077092e-09 + (0 - (1.02533304732651e-22 * fRec1[0])))))))) + (fRec2[2] * (1.06027340359031e-06 + fTemp1))) / fTemp0));
		// post processing
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fRec1[1] = fRec1[0];
		fRec0[1] = fRec0[0];
	}
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerVar("hfb.Intensity",N_("Intensity"),"S","",&fslider1, 0.5, 0.0, 1.0, 0.01);
	reg.registerVar("hfb.Volume",N_("Volume"),"S","",&fslider0, 0.5, 0.0, 1.0, 0.01);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

inline int Dsp::load_ui_f(const UiBuilder& b, int form)
{
    if (form & UI_FORM_STACK) {
#define PARAM(p) ("hfb" "." p)
b.openHorizontalhideBox("");
    b.create_master_slider(PARAM("Volume"), N_("Volume"));
b.closeBox();
b.openHorizontalBox("");
    b.insertSpacer();
    b.insertSpacer();
    b.create_small_rackknobr(PARAM("Volume"), N_("Volume"));
    b.create_small_rackknobr(PARAM("Intensity"), N_("Intensity"));
    b.insertSpacer();
b.closeBox();

#undef PARAM
        return 0;
    }
	return -1;
}

int Dsp::load_ui_f_static(const UiBuilder& b, int form)
{
	return static_cast<Dsp*>(b.plugin)->load_ui_f(b, form);
}
PluginDef *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginDef *p)
{
	delete static_cast<Dsp*>(p);
}

} // end namespace hfb
} // end namespace pluginlib
