declare id "mbclip";
declare name "MultiBand Clipper";
declare shortname "MB Clipper";
declare category "Distortion";
declare description "MultiBand Clipper";

import("effect.lib");
import("filter.lib");
import("music.lib");
import("math.lib");
import("reduce.lib");

anti_denormal = pow(10,-20);
anti_denormal_ac = 1 - 1' : *(anti_denormal) : + ~ *(-1);

hifr1      =hslider("crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover bandpass frequency]" ,80 , 20, 20000, 1.08);
hifr2      =hslider("crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover bandpass frequency]",210,20,20000,1.08);
hifr3      =hslider("crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover bandpass frequency]",1700,20,20000,1.08);
hifr4      =hslider("crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover bandpass frequency]",5000,20,20000,1.08);

geq = filterbank(3, (hifr1,hifr2,hifr3,hifr4));

drive1     = hslider("Drive1 [tooltip: Amount of distortion]", 0.33, 0, 1, 0.01);
drive2     = hslider("Drive2 [tooltip: Amount of distortion]", 0.5, 0, 1, 0.01);
drive3     = hslider("Drive3 [tooltip: Amount of distortion]", 0.65, 0, 1, 0.01);
drive4     = hslider("Drive4 [tooltip: Amount of distortion]", 0.33, 0, 1, 0.01);
drive5     = hslider("Drive5 [tooltip: Amount of distortion]", 0.1, 0, 1, 0.01);

gain1      = vslider("Gain", 0, -40, 4, 0.1) : db2linear : smooth(0.999);

vmeter1(x)		= attach(x, envelop(x) : vbargraph("v1[nomidi:no]", -70, +5));
vmeter2(x)		= attach(x, envelop(x) : vbargraph("v2[nomidi:no]", -70, +5));
vmeter3(x)		= attach(x, envelop(x) : vbargraph("v3[nomidi:no]", -70, +5));
vmeter4(x)		= attach(x, envelop(x) : vbargraph("v4[nomidi:no]", -70, +5));
vmeter5(x)		= attach(x, envelop(x) : vbargraph("v5[nomidi:no]", -70, +5));

envelop         = abs : max ~ (1.0/SR) : reduce(max,4096); // : max(db2linear(-70)) : linear2db;
    
clip(drive) = *(pregain) : clip : *(postgain) with {
    pregain = pow(10.0,2*drive);
    clip = ffunction(float symclip(float), "clipping.h", "");
    postgain = max(1.0,1.0/pregain);
};
    
eclip(drive) = *(pregain) : clip : *(postgain) with {
    pregain = pow(10.0,2*drive);    
    clip(x) = ((exp(x*4)-exp(-x*4*1.2))/(exp(x*4)+exp(-x*4)))/4;
    postgain = max(1.0,1.0/(pregain*2.5));
};

cclip(drive) = *(pregain) : clip : *(postgain) with {
    pregain = pow(10.0,drive);
    clip(x) = tanh((drive+0.0001)*x)/tanh(drive+0.0001);
    postgain = max(1.0,1.0/pregain);
};

aclip(drive) = *(pregain) : clip : *(postgain) with {
    pregain = pow(10.0,2*drive);
    clip(x) = atan(x)/PI;
    postgain = max(1.0,1.0/pregain);
};


process    = _: +(anti_denormal_ac): geq: ( dist5s , dist4s , dist3s, dist2s, dist1s) :> *(gain1) with { 
    dist1s = clip(drive1: smooth(0.999)) : vmeter1;
    dist2s = clip(drive2: smooth(0.999)) : vmeter2;
    dist3s = clip(drive3: smooth(0.999)) : vmeter3;
    dist4s = clip(drive4: smooth(0.999)) : vmeter4;
    dist5s = clip(drive5: smooth(0.999)) : vmeter5;
    
};
