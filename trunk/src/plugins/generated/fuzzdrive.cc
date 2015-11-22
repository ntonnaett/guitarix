// generated from file '../src/plugins/fuzzdrive.dsp' by dsp2cc:
// Code generated with Faust 0.9.65 (http://faust.grame.fr)

#include "gx_faust_support.h"
#include "gx_plugin.h"
#include "trany.h"

namespace pluginlib {
namespace fuzzdrive {

class Dsp: public PluginDef {
private:
	int fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	FAUSTFLOAT 	fslider1;
	double 	fRec12[2];
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	double 	fConst20;
	double 	fConst21;
	double 	fConst22;
	double 	fConst23;
	double 	fConst24;
	double 	fConst25;
	double 	fConst26;
	double 	fConst27;
	double 	fConst28;
	double 	fConst29;
	double 	fConst30;
	double 	fConst31;
	double 	fConst32;
	double 	fConst33;
	double 	fConst34;
	double 	fConst35;
	double 	fConst36;
	double 	fConst37;
	double 	fConst38;
	double 	fConst39;
	double 	fConst40;
	double 	fConst41;
	double 	fConst42;
	double 	fConst43;
	double 	fRec26[9];
	double 	fConst44;
	double 	fConst45;
	double 	fConst46;
	double 	fConst47;
	double 	fConst48;
	double 	fConst49;
	double 	fConst50;
	double 	fConst51;
	double 	fConst52;
	double 	fConst53;
	double 	fConst54;
	double 	fConst55;
	double 	fConst56;
	double 	fConst57;
	double 	fConst58;
	double 	fConst59;
	double 	fConst60;
	FAUSTFLOAT 	fslider2;
	double 	fRec27[2];
	double 	fVec0[2];
	double 	fConst61;
	double 	fConst62;
	double 	fConst63;
	double 	fRec25[2];
	double 	fRec24[3];
	double 	fConst64;
	double 	fConst65;
	double 	fConst66;
	double 	fConst67;
	double 	fRec28[2];
	double 	fRec23[3];
	double 	fConst68;
	double 	fConst69;
	double 	fConst70;
	double 	fConst71;
	double 	fConst72;
	double 	fRec22[2];
	double 	fConst73;
	double 	fRec21[2];
	double 	fRec20[3];
	double 	fRec29[2];
	double 	fRec19[3];
	double 	fRec18[2];
	double 	fRec17[2];
	double 	fRec16[3];
	double 	fRec30[2];
	double 	fRec15[3];
	double 	fRec14[2];
	double 	fRec13[4];
	double 	fConst74;
	double 	fConst75;
	double 	fConst76;
	double 	fConst77;
	double 	fConst78;
	double 	fConst79;
	double 	fVec1[2];
	double 	fConst80;
	double 	fRec11[2];
	double 	fRec10[3];
	double 	fRec31[2];
	double 	fRec9[3];
	double 	fRec8[2];
	double 	fRec7[2];
	double 	fRec6[3];
	double 	fRec32[2];
	double 	fRec5[3];
	double 	fRec4[2];
	double 	fRec3[2];
	double 	fRec2[3];
	double 	fRec33[2];
	double 	fRec1[3];
	double 	fRec0[2];
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
	id = "fuzzdrive";
	name = N_("Fuzz Drive");
	groups = 0;
	description = N_("Fuzz Distortion"); // description (tooltip)
	category = N_("Fuzz");       // category
	shortname = N_("Fuzz Drive");     // shortname
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
	for (int i=0; i<2; i++) fRec12[i] = 0;
	for (int i=0; i<9; i++) fRec26[i] = 0;
	for (int i=0; i<2; i++) fRec27[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	for (int i=0; i<2; i++) fRec25[i] = 0;
	for (int i=0; i<3; i++) fRec24[i] = 0;
	for (int i=0; i<2; i++) fRec28[i] = 0;
	for (int i=0; i<3; i++) fRec23[i] = 0;
	for (int i=0; i<2; i++) fRec22[i] = 0;
	for (int i=0; i<2; i++) fRec21[i] = 0;
	for (int i=0; i<3; i++) fRec20[i] = 0;
	for (int i=0; i<2; i++) fRec29[i] = 0;
	for (int i=0; i<3; i++) fRec19[i] = 0;
	for (int i=0; i<2; i++) fRec18[i] = 0;
	for (int i=0; i<2; i++) fRec17[i] = 0;
	for (int i=0; i<3; i++) fRec16[i] = 0;
	for (int i=0; i<2; i++) fRec30[i] = 0;
	for (int i=0; i<3; i++) fRec15[i] = 0;
	for (int i=0; i<2; i++) fRec14[i] = 0;
	for (int i=0; i<4; i++) fRec13[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<3; i++) fRec10[i] = 0;
	for (int i=0; i<2; i++) fRec31[i] = 0;
	for (int i=0; i<3; i++) fRec9[i] = 0;
	for (int i=0; i<2; i++) fRec8[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	for (int i=0; i<3; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fRec32[i] = 0;
	for (int i=0; i<3; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fRec33[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec0[i] = 0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = tan((50265.48245743669 / double(iConst0)));
	fConst2 = (2 * (1 - (1.0 / faustpower<2>(fConst1))));
	fConst3 = (1.0 / fConst1);
	fConst4 = (1 + ((fConst3 - 1.0000000000000004) / fConst1));
	fConst5 = (1.0 / (1 + ((1.0000000000000004 + fConst3) / fConst1)));
	fConst6 = double(iConst0);
	fConst7 = (1.2099049942893e-14 * fConst6);
	fConst8 = (2.49252253398618e-08 + (fConst6 * (2.51801622165627e-10 + fConst7)));
	fConst9 = (3.57407648445144e-16 * fConst6);
	fConst10 = (2.53046873750701e-09 + (fConst6 * (2.81736895109737e-13 + fConst9)));
	fConst11 = (1.79347857986842e-13 * fConst6);
	fConst12 = (3.45357917689612e-12 - fConst11);
	fConst13 = ((fConst6 * (2.51801622165627e-10 - fConst7)) - 2.49252253398618e-08);
	fConst14 = ((fConst6 * (2.81736895109737e-13 - fConst9)) - 2.53046873750701e-09);
	fConst15 = (3.62971498286789e-14 * fConst6);
	fConst16 = ((fConst6 * (fConst15 - 2.51801622165627e-10)) - 2.49252253398618e-08);
	fConst17 = (1.07222294533543e-15 * fConst6);
	fConst18 = ((fConst6 * (fConst17 - 2.81736895109737e-13)) - 2.53046873750701e-09);
	fConst19 = (2.49252253398618e-08 + (fConst6 * (0 - (2.51801622165627e-10 + fConst15))));
	fConst20 = (2.53046873750701e-09 + (fConst6 * (0 - (2.81736895109737e-13 + fConst17))));
	fConst21 = (1.20954612086615e-39 * fConst6);
	fConst22 = (2.45020046020493e-40 * fConst6);
	fConst23 = (1.21134747730432e-39 * fConst6);
	fConst24 = (3.12426915869143e-13 + (fConst6 * (((fConst6 * (4.74767687606168e-17 + (fConst6 * ((fConst6 * (1.73266579347222e-22 + (fConst6 * ((fConst6 * (4.4344097371444e-29 + (fConst6 * (fConst23 - 1.63282987404348e-33)))) - 1.07298568411666e-25)))) - 1.31102852092565e-19)))) - 7.12034665177176e-15) + (0.5 * ((6.87339214912114e-17 + (fConst6 * ((fConst6 * (8.29607943811672e-21 + (fConst6 * ((fConst6 * (2.76343706770825e-26 + (fConst6 * ((fConst6 * (1.12017008405057e-33 + fConst22)) - 2.68390877243249e-29)))) - 1.93946085329172e-23)))) - 1.41480755159492e-18))) + (0.5 * (fConst6 * ((fConst6 * (4.85407145719168e-22 + (fConst6 * ((fConst6 * (6.96590249983833e-27 + (fConst6 * ((fConst6 * (2.86589792702458e-34 - fConst21)) - 6.29844123704863e-30)))) - 2.97472992156056e-24)))) - 2.26821940920998e-20))))))));
	fConst25 = (9.6763689669292e-39 * fConst6);
	fConst26 = faustpower<2>(fConst6);
	fConst27 = (1.96016036816394e-39 * fConst6);
	fConst28 = (9.69077981843452e-39 * fConst6);
	fConst29 = (2.49941532695314e-12 + (fConst6 * (((fConst6 * (1.89907075042467e-16 + (fConst6 * ((fConst26 * (2.14597136823331e-25 + (fConst6 * ((fConst6 * (9.79697924426087e-33 - fConst28)) - 1.77376389485776e-28)))) - 2.62205704185131e-19)))) - 4.27220799106305e-14) + (0.5 * ((4.12403528947268e-16 + (fConst6 * ((fConst6 * (1.65921588762334e-20 + (fConst26 * ((fConst6 * (1.073563508973e-28 + (fConst6 * (0 - (6.7210205043034e-33 + fConst27))))) - 5.52687413541649e-26)))) - 5.65923020637969e-18))) + (0.5 * (fConst6 * ((fConst6 * (9.70814291438336e-22 + (fConst26 * ((fConst6 * (2.51937649481945e-29 + (fConst6 * (fConst25 - 1.71953875621475e-33)))) - 1.39318049996767e-26)))) - 9.0728776368399e-20))))))));
	fConst30 = (3.38672913842522e-38 * fConst6);
	fConst31 = (6.86056128857379e-39 * fConst6);
	fConst32 = (3.39177293645208e-38 * fConst6);
	fConst33 = (8.74795364433599e-12 + (fConst6 * (((fConst6 * (1.89907075042467e-16 + (fConst6 * (2.62205704185131e-19 + (fConst6 * ((fConst6 * (2.14597136823331e-25 + (fConst6 * (1.77376389485776e-28 + (fConst6 * (fConst32 - 2.28596182366087e-32)))))) - 6.93066317388889e-22)))))) - 9.96848531248046e-14) + (0.5 * ((9.62274900876959e-16 + (fConst6 * ((fConst6 * ((fConst6 * (7.75784341316688e-23 + (fConst6 * ((fConst6 * ((fConst6 * (1.56823811767079e-32 + fConst31)) - 1.073563508973e-28)) - 5.52687413541649e-26)))) - 1.65921588762334e-20)) - 5.65923020637969e-18))) + (0.5 * (fConst6 * ((fConst6 * ((fConst6 * (1.18989196862423e-23 + (fConst6 * ((fConst6 * ((fConst6 * (4.01225709783442e-33 - fConst30)) - 2.51937649481945e-29)) - 1.39318049996767e-26)))) - 9.70814291438336e-22)) - 9.0728776368399e-20))))))));
	fConst34 = (6.77345827685044e-38 * fConst6);
	fConst35 = (1.37211225771476e-38 * fConst6);
	fConst36 = (6.78354587290416e-38 * fConst6);
	fConst37 = (1.7495907288672e-11 + (fConst6 * (((fConst6 * ((fConst6 * (7.86617112555392e-19 + (fConst26 * ((fConst6 * (1.77376389485776e-28 + (fConst6 * (2.28596182366087e-32 - fConst36)))) - 6.43791410469994e-25)))) - 1.89907075042467e-16)) - 9.96848531248046e-14) + (0.5 * ((9.62274900876959e-16 + (fConst6 * (5.65923020637969e-18 + (fConst6 * ((fConst26 * (1.65806224062495e-25 + (fConst6 * ((fConst6 * (0 - (1.56823811767079e-32 + fConst35))) - 1.073563508973e-28)))) - 4.97764766287003e-20))))) + (0.5 * (fConst6 * (9.0728776368399e-20 + (fConst6 * ((fConst26 * (4.179541499903e-26 + (fConst6 * ((fConst6 * (fConst34 - 4.01225709783442e-33)) - 2.51937649481945e-29)))) - 2.91244287431501e-21))))))))));
	fConst38 = (2.186988411084e-11 + (fConst26 * (((fConst26 * (1.03959947608333e-21 + (fConst26 * ((8.47943234113021e-38 * fConst26) - 4.4344097371444e-28)))) - 4.74767687606168e-16) + (0.5 * ((1.41480755159492e-17 + (fConst26 * ((fConst26 * (2.68390877243249e-28 + (1.71514032214345e-38 * fConst26))) - 1.16367651197503e-22))) + (0.5 * (2.26821940920998e-19 + (fConst26 * ((fConst26 * (6.29844123704863e-29 - (8.46682284606305e-38 * fConst26))) - 1.78483795293634e-23)))))))));
	fConst39 = (1.7495907288672e-11 + (fConst6 * ((9.96848531248046e-14 + (fConst6 * ((fConst6 * ((fConst26 * (6.43791410469994e-25 + (fConst6 * (1.77376389485776e-28 + (fConst6 * (0 - (2.28596182366087e-32 + fConst36))))))) - 7.86617112555392e-19)) - 1.89907075042467e-16))) + (0.5 * (((fConst6 * (5.65923020637969e-18 + (fConst6 * (4.97764766287003e-20 + (fConst26 * ((fConst6 * ((fConst6 * (1.56823811767079e-32 - fConst35)) - 1.073563508973e-28)) - 1.65806224062495e-25)))))) - 9.62274900876959e-16) + (0.5 * (fConst6 * (9.0728776368399e-20 + (fConst6 * (2.91244287431501e-21 + (fConst26 * ((fConst6 * ((fConst6 * (4.01225709783442e-33 + fConst34)) - 2.51937649481945e-29)) - 4.179541499903e-26))))))))))));
	fConst40 = (8.74795364433599e-12 + (fConst6 * ((9.96848531248046e-14 + (fConst6 * (1.89907075042467e-16 + (fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * (1.77376389485776e-28 + (fConst6 * (2.28596182366087e-32 + fConst32)))) - 2.14597136823331e-25)) - 6.93066317388889e-22)) - 2.62205704185131e-19))))) + (0.5 * (((fConst6 * ((fConst6 * (1.65921588762334e-20 + (fConst6 * (7.75784341316688e-23 + (fConst6 * (5.52687413541649e-26 + (fConst6 * ((fConst6 * (fConst31 - 1.56823811767079e-32)) - 1.073563508973e-28)))))))) - 5.65923020637969e-18)) - 9.62274900876959e-16) + (0.5 * (fConst6 * ((fConst6 * (9.70814291438336e-22 + (fConst6 * (1.18989196862423e-23 + (fConst6 * (1.39318049996767e-26 + (fConst6 * ((fConst6 * (0 - (4.01225709783442e-33 + fConst30))) - 2.51937649481945e-29)))))))) - 9.0728776368399e-20))))))));
	fConst41 = (2.49941532695314e-12 + (fConst6 * ((4.27220799106305e-14 + (fConst6 * (1.89907075042467e-16 + (fConst6 * (2.62205704185131e-19 + (fConst26 * ((fConst6 * ((fConst6 * (0 - (9.79697924426087e-33 + fConst28))) - 1.77376389485776e-28)) - 2.14597136823331e-25))))))) + (0.5 * (((fConst6 * ((fConst6 * ((fConst26 * (5.52687413541649e-26 + (fConst6 * (1.073563508973e-28 + (fConst6 * (6.7210205043034e-33 - fConst27)))))) - 1.65921588762334e-20)) - 5.65923020637969e-18)) - 4.12403528947268e-16) + (0.5 * (fConst6 * ((fConst6 * ((fConst26 * (1.39318049996767e-26 + (fConst6 * (2.51937649481945e-29 + (fConst6 * (1.71953875621475e-33 + fConst25)))))) - 9.70814291438336e-22)) - 9.0728776368399e-20))))))));
	fConst42 = (3.12426915869143e-13 + (fConst6 * ((7.12034665177176e-15 + (fConst6 * (4.74767687606168e-17 + (fConst6 * (1.31102852092565e-19 + (fConst6 * (1.73266579347222e-22 + (fConst6 * (1.07298568411666e-25 + (fConst6 * (4.4344097371444e-29 + (fConst6 * (1.63282987404348e-33 + fConst23))))))))))))) + (0.5 * (((fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * (fConst22 - 1.12017008405057e-33)) - 2.68390877243249e-29)) - 2.76343706770825e-26)) - 1.93946085329172e-23)) - 8.29607943811672e-21)) - 1.41480755159492e-18)) - 6.87339214912114e-17) + (0.5 * (fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * (0 - (2.86589792702458e-34 + fConst21))) - 6.29844123704863e-30)) - 6.96590249983833e-27)) - 2.97472992156056e-24)) - 4.85407145719168e-22)) - 2.26821940920998e-20))))))));
	fConst43 = (1.0 / fConst42);
	fConst44 = (1.29594227235659e-40 * fConst6);
	fConst45 = (1.17227175222998e-40 * fConst6);
	fConst46 = (((fConst6 * ((fConst6 * (6.72185939565773e-21 + (fConst6 * ((fConst6 * (3.96129387282593e-28 + (fConst6 * (8.60503380045389e-34 + fConst45)))) - 4.46652612440854e-25)))) - 2.17087377052947e-18)) - 1.32343844239659e-17) + (0.5 * (fConst6 * (4.36734685990874e-21 + (fConst6 * ((fConst6 * (1.58018238163299e-26 + (fConst6 * ((fConst6 * (8.87073657190112e-34 + fConst44)) - 1.64126469795529e-30)))) - 1.52868099778786e-23))))));
	fConst47 = (1.03675381788527e-39 * fConst6);
	fConst48 = (9.37817401783986e-40 * fConst6);
	fConst49 = (((fConst6 * ((fConst26 * (8.93305224881709e-25 + (fConst6 * ((fConst6 * (0 - (5.16302028027233e-33 + fConst48))) - 1.58451754913037e-27)))) - 4.34174754105893e-18)) - 5.29375376958635e-17) + (0.5 * (fConst6 * (8.73469371981747e-21 + (fConst26 * ((fConst6 * (6.56505879182116e-30 + (fConst6 * (0 - (5.32244194314067e-33 + fConst47))))) - 3.16036476326599e-26))))));
	fConst50 = (3.62863836259845e-39 * fConst6);
	fConst51 = (3.28236090624395e-39 * fConst6);
	fConst52 = (((fConst6 * (4.34174754105893e-18 + (fConst6 * ((fConst6 * (8.93305224881709e-25 + (fConst6 * (1.58451754913037e-27 + (fConst6 * (1.20470473206354e-32 + fConst51)))))) - 2.68874375826309e-20)))) - 5.29375376958635e-17) + (0.5 * (fConst6 * ((fConst6 * (6.11472399115143e-23 + (fConst6 * ((fConst6 * ((fConst6 * (1.24190312006616e-32 + fConst50)) - 6.56505879182116e-30)) - 3.16036476326599e-26)))) - 8.73469371981747e-21))));
	fConst53 = (7.2572767251969e-39 * fConst6);
	fConst54 = (6.5647218124879e-39 * fConst6);
	fConst55 = ((5.29375376958635e-17 + (fConst6 * (1.30252426231768e-17 + (fConst26 * ((fConst6 * (1.58451754913037e-27 + (fConst6 * (0 - (1.20470473206354e-32 + fConst54))))) - 2.67991567464513e-24))))) + (0.5 * (fConst6 * ((fConst26 * (9.48109428979796e-26 + (fConst6 * ((fConst6 * (0 - (1.24190312006616e-32 + fConst53))) - 6.56505879182116e-30)))) - 2.62040811594524e-20))));
	fConst56 = ((1.32343844239659e-16 + (fConst26 * (4.03311563739464e-20 + (fConst26 * ((8.20590226560988e-39 * fConst26) - 3.96129387282593e-27))))) + (0.5 * (fConst26 * ((fConst26 * (1.64126469795529e-29 + (9.07159590649613e-39 * fConst26))) - 9.17208598672714e-23))));
	fConst57 = ((5.29375376958635e-17 + (fConst6 * ((fConst26 * (2.67991567464513e-24 + (fConst6 * (1.58451754913037e-27 + (fConst6 * (1.20470473206354e-32 - fConst54)))))) - 1.30252426231768e-17))) + (0.5 * (fConst6 * (2.62040811594524e-20 + (fConst26 * ((fConst6 * ((fConst6 * (1.24190312006616e-32 - fConst53)) - 6.56505879182116e-30)) - 9.48109428979796e-26))))));
	fConst58 = (((fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * (1.58451754913037e-27 + (fConst6 * (fConst51 - 1.20470473206354e-32)))) - 8.93305224881709e-25)) - 2.68874375826309e-20)) - 4.34174754105893e-18)) - 5.29375376958635e-17) + (0.5 * (fConst6 * (8.73469371981747e-21 + (fConst6 * (6.11472399115143e-23 + (fConst6 * (3.16036476326599e-26 + (fConst6 * ((fConst6 * (fConst50 - 1.24190312006616e-32)) - 6.56505879182116e-30))))))))));
	fConst59 = (((fConst6 * (4.34174754105893e-18 + (fConst26 * ((fConst6 * ((fConst6 * (5.16302028027233e-33 - fConst48)) - 1.58451754913037e-27)) - 8.93305224881709e-25)))) - 5.29375376958635e-17) + (0.5 * (fConst6 * ((fConst26 * (3.16036476326599e-26 + (fConst6 * (6.56505879182116e-30 + (fConst6 * (5.32244194314067e-33 - fConst47)))))) - 8.73469371981747e-21))));
	fConst60 = (((fConst6 * (2.17087377052947e-18 + (fConst6 * (6.72185939565773e-21 + (fConst6 * (4.46652612440854e-25 + (fConst6 * (3.96129387282593e-28 + (fConst6 * (fConst45 - 8.60503380045389e-34)))))))))) - 1.32343844239659e-17) + (0.5 * (fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * ((fConst6 * (fConst44 - 8.87073657190112e-34)) - 1.64126469795529e-30)) - 1.58018238163299e-26)) - 1.52868099778786e-23)) - 4.36734685990874e-21))));
	fConst61 = (1 + fConst3);
	fConst62 = (fConst26 / (fConst61 * fConst42));
	fConst63 = (0 - ((1 - fConst3) / fConst61));
	fConst64 = (1.0 / tan((270.1769682087222 / double(iConst0))));
	fConst65 = (1 + fConst64);
	fConst66 = (0.027 / fConst65);
	fConst67 = (0 - ((1 - fConst64) / fConst65));
	fConst68 = (1.0 / tan((97.38937226128358 / double(iConst0))));
	fConst69 = (0 - fConst68);
	fConst70 = (1 + fConst68);
	fConst71 = (0.025 / fConst70);
	fConst72 = (0 - ((1 - fConst68) / fConst70));
	fConst73 = (1.0 / fConst61);
	fConst74 = (1.0360737530688401e-13 * fConst6);
	fConst75 = (5.38043573960525e-13 * fConst6);
	fConst76 = (0.1 * (fConst75 - 3.45357917689612e-12));
	fConst77 = (0 - (3.45357917689612e-12 + fConst75));
	fConst78 = (0.1 * (3.45357917689612e-12 + fConst11));
	fConst79 = (3.4535791768961205e-14 * fConst6);
	fConst80 = (fConst26 / fConst61);
	clear_state_f();
}

void Dsp::init_static(unsigned int samplingFreq, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
	double 	fSlow0 = (0.01 * double(fslider0));
	double 	fSlow1 = (1 - fSlow0);
	double 	fSlow2 = (0.007000000000000006 * (1 - double(fslider1)));
	double 	fSlow3 = (0.007000000000000006 * double(fslider2));
	for (int i=0; i<count; i++) {
		double fTemp0 = (double)input0[i];
		fRec12[0] = ((0.993 * fRec12[1]) + fSlow2);
		double fTemp1 = (2.49252253398618e-07 + (fConst6 * (fConst10 + (fConst8 * fRec12[0]))));
		fRec26[0] = ((fSlow0 * fTemp0) - (fConst43 * ((((((((fConst41 * fRec26[1]) + (fConst40 * fRec26[2])) + (fConst39 * fRec26[3])) + (fConst38 * fRec26[4])) + (fConst37 * fRec26[5])) + (fConst33 * fRec26[6])) + (fConst29 * fRec26[7])) + (fConst24 * fRec26[8]))));
		fRec27[0] = ((0.993 * fRec27[1]) + fSlow3);
		double fTemp2 = (fRec27[0] * (((((((((fConst60 * fRec26[0]) + (fConst59 * fRec26[1])) + (fConst58 * fRec26[2])) + (fConst57 * fRec26[3])) + (fConst56 * fRec26[4])) + (fConst55 * fRec26[5])) + (fConst52 * fRec26[6])) + (fConst49 * fRec26[7])) + (fConst46 * fRec26[8])));
		fVec0[0] = fTemp2;
		fRec25[0] = ((fConst63 * fRec25[1]) + (fConst62 * (fVec0[0] + fVec0[1])));
		fRec24[0] = (fRec25[0] - (fConst5 * ((fConst4 * fRec24[2]) + (fConst2 * fRec24[1]))));
		fRec28[0] = ((fConst67 * fRec28[1]) + (fConst66 * (fRec23[1] + fRec23[2])));
		fRec23[0] = (Ftrany(TRANY_TABLE_7199P_68k, ((fRec28[0] + (fConst5 * (fRec24[2] + (fRec24[0] + (2 * fRec24[1]))))) - 3.571981)) - 117.70440740740739);
		fRec22[0] = ((fConst72 * fRec22[1]) + (fConst71 * ((fConst68 * fRec23[0]) + (fConst69 * fRec23[1]))));
		fRec21[0] = ((fConst63 * fRec21[1]) + (fConst73 * (fRec22[0] + fRec22[1])));
		fRec20[0] = (fRec21[0] - (fConst5 * ((fConst4 * fRec20[2]) + (fConst2 * fRec20[1]))));
		fRec29[0] = ((fConst67 * fRec29[1]) + (fConst66 * (fRec19[1] + fRec19[2])));
		fRec19[0] = (Ftrany(TRANY_TABLE_7199P_68k, ((fRec29[0] + (fConst5 * (fRec20[2] + (fRec20[0] + (2 * fRec20[1]))))) - 3.571981)) - 117.70440740740739);
		fRec18[0] = ((fConst72 * fRec18[1]) + (fConst71 * ((fConst68 * fRec19[0]) + (fConst69 * fRec19[1]))));
		fRec17[0] = ((fConst63 * fRec17[1]) + (fConst73 * (fRec18[0] + fRec18[1])));
		fRec16[0] = (fRec17[0] - (fConst5 * ((fConst4 * fRec16[2]) + (fConst2 * fRec16[1]))));
		fRec30[0] = ((fConst67 * fRec30[1]) + (fConst66 * (fRec15[1] + fRec15[2])));
		fRec15[0] = (Ftrany(TRANY_TABLE_7199P_68k, ((fRec30[0] + (fConst5 * (fRec16[2] + (fRec16[0] + (2 * fRec16[1]))))) - 3.571981)) - 117.70440740740739);
		fRec14[0] = ((fConst72 * fRec14[1]) + (fConst71 * ((fConst68 * fRec15[0]) + (fConst69 * fRec15[1]))));
		fRec13[0] = (fRec14[0] - ((((fRec13[1] * (7.47756760195853e-07 + (fConst6 * (fConst20 + (fConst19 * fRec12[0]))))) + (fRec13[2] * (7.47756760195853e-07 + (fConst6 * (fConst18 + (fConst16 * fRec12[0])))))) + (fRec13[3] * (2.49252253398618e-07 + (fConst6 * (fConst14 + (fConst13 * fRec12[0])))))) / fTemp1));
		double fTemp3 = ((fRec27[0] * ((((fRec13[0] * ((fConst79 * fRec12[0]) + fConst78)) + (0.1 * (fRec13[1] * (fConst77 + (fConst6 * (0 - (1.03607375306884e-12 * fRec12[0]))))))) + (fRec13[2] * (fConst76 + (fConst74 * fRec12[0])))) + (0.1 * (fRec13[3] * (fConst12 + (fConst6 * (0 - (3.45357917689612e-13 * fRec12[0])))))))) / fTemp1);
		fVec1[0] = fTemp3;
		fRec11[0] = ((fConst63 * fRec11[1]) + (fConst80 * (fVec1[0] + fVec1[1])));
		fRec10[0] = (fRec11[0] - (fConst5 * ((fConst4 * fRec10[2]) + (fConst2 * fRec10[1]))));
		fRec31[0] = ((fConst67 * fRec31[1]) + (fConst66 * (fRec9[1] + fRec9[2])));
		fRec9[0] = (Ftrany(TRANY_TABLE_7199P_68k, ((fRec31[0] + (fConst5 * (fRec10[2] + (fRec10[0] + (2 * fRec10[1]))))) - 3.571981)) - 117.70440740740739);
		fRec8[0] = ((fConst72 * fRec8[1]) + (fConst71 * ((fConst68 * fRec9[0]) + (fConst69 * fRec9[1]))));
		fRec7[0] = ((fConst63 * fRec7[1]) + (fConst73 * (fRec8[0] + fRec8[1])));
		fRec6[0] = (fRec7[0] - (fConst5 * ((fConst4 * fRec6[2]) + (fConst2 * fRec6[1]))));
		fRec32[0] = ((fConst67 * fRec32[1]) + (fConst66 * (fRec5[1] + fRec5[2])));
		fRec5[0] = (Ftrany(TRANY_TABLE_7199P_68k, ((fRec32[0] + (fConst5 * (fRec6[2] + (fRec6[0] + (2 * fRec6[1]))))) - 3.571981)) - 117.70440740740739);
		fRec4[0] = ((fConst72 * fRec4[1]) + (fConst71 * ((fConst68 * fRec5[0]) + (fConst69 * fRec5[1]))));
		fRec3[0] = ((fConst63 * fRec3[1]) + (fConst73 * (fRec4[0] + fRec4[1])));
		fRec2[0] = (fRec3[0] - (fConst5 * ((fConst4 * fRec2[2]) + (fConst2 * fRec2[1]))));
		fRec33[0] = ((fConst67 * fRec33[1]) + (fConst66 * (fRec1[1] + fRec1[2])));
		fRec1[0] = (Ftrany(TRANY_TABLE_7199P_68k, ((fRec33[0] + (fConst5 * (fRec2[2] + (fRec2[0] + (2 * fRec2[1]))))) - 3.571981)) - 117.70440740740739);
		fRec0[0] = ((fConst72 * fRec0[1]) + (fConst71 * ((fConst68 * fRec1[0]) + (fConst69 * fRec1[1]))));
		output0[i] = (FAUSTFLOAT)(fRec0[0] + (fSlow1 * fTemp0));
		// post processing
		fRec0[1] = fRec0[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec33[1] = fRec33[0];
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
		fRec32[1] = fRec32[0];
		fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
		fRec7[1] = fRec7[0];
		fRec8[1] = fRec8[0];
		fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
		fRec31[1] = fRec31[0];
		fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
		fRec11[1] = fRec11[0];
		fVec1[1] = fVec1[0];
		for (int i=3; i>0; i--) fRec13[i] = fRec13[i-1];
		fRec14[1] = fRec14[0];
		fRec15[2] = fRec15[1]; fRec15[1] = fRec15[0];
		fRec30[1] = fRec30[0];
		fRec16[2] = fRec16[1]; fRec16[1] = fRec16[0];
		fRec17[1] = fRec17[0];
		fRec18[1] = fRec18[0];
		fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
		fRec29[1] = fRec29[0];
		fRec20[2] = fRec20[1]; fRec20[1] = fRec20[0];
		fRec21[1] = fRec21[0];
		fRec22[1] = fRec22[0];
		fRec23[2] = fRec23[1]; fRec23[1] = fRec23[0];
		fRec28[1] = fRec28[0];
		fRec24[2] = fRec24[1]; fRec24[1] = fRec24[0];
		fRec25[1] = fRec25[0];
		fVec0[1] = fVec0[0];
		fRec27[1] = fRec27[0];
		for (int i=8; i>0; i--) fRec26[i] = fRec26[i-1];
		fRec12[1] = fRec12[0];
	}

}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerVar("fuzzdrive.Distortion",N_("Drive"),"S","",&fslider1, 0.5, 0.0, 0.99, 0.01);
	reg.registerVar("fuzzdrive.Level",N_("Level"),"S","",&fslider2, 0.5, 0.0, 1.0, 0.01);
	reg.registerVar("fuzzdrive.wet_dry",N_("wet/dry"),"S",N_("percentage of processed signal in output signal"),&fslider0, 1e+02, 0.0, 1e+02, 1.0);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

inline int Dsp::load_ui_f(const UiBuilder& b, int form)
{
    if (form & UI_FORM_STACK) {
#define PARAM(p) ("fuzzdrive" "." p)

b.openHorizontalhideBox("");
    b.create_master_slider(PARAM("Level"), "Level");
b.closeBox();
b.openHorizontalBox("");

    b.create_small_rackknobr(PARAM("Level"), "Level");

    b.create_small_rackknobr(PARAM("Distortion"), "Drive");

    b.create_small_rackknobr(PARAM("wet_dry"), "dry/wet");
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

} // end namespace fuzzdrive
} // end namespace pluginlib
