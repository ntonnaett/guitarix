// generated automatically
// DO NOT MODIFY!
declare id          "bossds1";
declare name        "Boss DS1";
declare category    "Distortion";
declare shortname   "DS1";
declare description "Boss DS1";
//declare samplerate  "96000";

import("filter.lib");

ds1_in = iir((b0/a0,b1/a0),(a1/a0)) with {
    fs = float(SR);

    b0 = 2.07110717442793e-5*fs;

    b1 = -2.07110717442793e-5*fs;

    a0 = 2.08232145615427e-5*fs + 0.000485701045951343;

    a1 = -2.08232145615427e-5*fs + 0.000485701045951343;
};

ds1_boost= iir((b0/a0,b1/a0,b2/a0,b3/a0),(a1/a0,a2/a0,a3/a0)) with {
    fs = float(SR);

    b0 = -5.51041967277497e-9*pow(fs,2);

    b1 = 5.51041967277497e-9*pow(fs,2);

    b2 = 5.51041967277497e-9*pow(fs,2);

    b3 = -5.51041967277497e-9*pow(fs,2);

    a0 = fs*(3.53982651634833e-10*fs + 2.38582349500046e-7) + 1.94656546234155e-5;

    a1 = fs*(-3.53982651634833e-10*fs + 2.38582349500046e-7) + 5.83969638702466e-5;

    a2 = fs*(-3.53982651634833e-10*fs - 2.38582349500046e-7) + 5.83969638702466e-5;

    a3 = fs*(3.53982651634833e-10*fs - 2.38582349500046e-7) + 1.94656546234155e-5;
};

ds1_ampin = iir((b0/a0,b1/a0),(a1/a0)) with {
    fs = float(SR);

    b0 = 1.89077966855745e-5*fs;

    b1 = -1.89077966855745e-5*fs;

    a0 = 2.07985763541319e-5*fs + 0.00166833500166833;

    a1 = -2.07985763541319e-5*fs + 0.00166833500166833;
};

ds1_ampout = iir((b0/a0,b1/a0),(a1/a0)) with {
    fs = float(SR);

    b0 = 0.319154715341156;

    b1 = 0.319154715341156;

    a0 = 1.40428074750109e-5*fs + 0.325945241199478;

    a1 = -1.40428074750109e-5*fs + 0.325945241199478;
};

ds1_tone = iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {
    s = 0.993;

    fs = float(SR);

        Tone = vslider("Tone[name:Tone]", 0.7, 0, 1, 0.01) : smooth(s);
    
    b0 = Tone*(fs*(-2.18842400636233e-10*fs + 5.20602596669238e-8) + 0.000537812599864916) + (fs*(2.18842400636233e-10*fs + 2.33324618325395e-7) + 0.000182856283954071);

    b1 = Tone*(4.37684801272465e-10*pow(fs,2) + 0.00107562519972983) + (-4.37684801272465e-10*pow(fs,2) + 0.000365712567908143);

    b2 = Tone*(fs*(-2.18842400636233e-10*fs - 5.20602596669238e-8) + 0.000537812599864916) + (fs*(2.18842400636233e-10*fs - 2.33324618325395e-7) + 0.000182856283954071);

    a0 = Tone*(Tone*(fs*(-2.89644353783249e-10*fs - 9.44398925362792e-7) - 0.000537812599864916) + fs*(2.65571689713263e-10*fs + 7.50424979344313e-7) + 0.000537812599864916) + fs*(3.3778968192322e-10*fs + 1.55559824875468e-6) + 0.00114855258827151;

    a1 = Tone*(Tone*(5.79288707566498e-10*pow(fs,2) - 0.00107562519972983) - 5.31143379426527e-10*pow(fs,2) + 0.00107562519972983) - 6.7557936384644e-10*pow(fs,2) + 0.00229710517654303;

    a2 = Tone*(Tone*(fs*(-2.89644353783249e-10*fs + 9.44398925362792e-7) - 0.000537812599864916) + fs*(2.65571689713263e-10*fs - 7.50424979344313e-7) + 0.000537812599864916) + fs*(3.3778968192322e-10*fs - 1.55559824875468e-6) + 0.00114855258827151;
};

ds1_out = iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {
    fs = float(SR);

    b0 = fs*(4.26031359768866e-10*fs + 2.06011295826338e-10);

    b1 = -8.52062719537733e-10*pow(fs,2);

    b2 = fs*(4.26031359768866e-10*fs - 2.06011295826338e-10);

    a0 = fs*(4.33883931795138e-10*fs + 6.90412007909908e-9) + 2.33802056631403e-8;

    a1 = -8.67767863590276e-10*pow(fs,2) + 4.67604113262805e-8;

    a2 = fs*(4.33883931795138e-10*fs - 6.90412007909908e-9) + 2.33802056631403e-8;
};

ds1_drive = iir((b0/a0,b1/a0,b2/a0),(a1/a0,a2/a0)) with {
    fs = float(SR);

    b0 = drive*(-3.18093350083904e-10*drive*pow(fs,2) + fs*(3.0314296262996e-10*fs + 1.59012835323858e-5)) + fs*(1.49503874539434e-11*fs + 7.50903344506575e-7) + 0.000169198590470161;

    b1 = drive*(6.36186700167807e-10*drive*pow(fs,2) - 6.0628592525992e-10*pow(fs,2)) - 2.99007749078869e-11*pow(fs,2) + 0.000338397180940323;

    b2 = drive*(-3.18093350083904e-10*drive*pow(fs,2) + fs*(3.0314296262996e-10*fs - 1.59012835323858e-5)) + fs*(1.49503874539434e-11*fs - 7.50903344506575e-7) + 0.000169198590470161;

    a0 = drive*(-3.18093350083904e-10*drive*pow(fs,2) + fs*(3.0314296262996e-10*fs - 3.38397180940322e-9)) + fs*(1.49503874539434e-11*fs + 1.66555708487018e-5) + 0.000169198590470162;

    a1 = drive*(6.36186700167807e-10*drive*pow(fs,2) - 6.0628592525992e-10*pow(fs,2)) - 2.99007749078869e-11*pow(fs,2) + 0.000338397180940324;

    a2 = drive*(-3.18093350083904e-10*drive*pow(fs,2) + fs*(3.0314296262996e-10*fs + 3.38397180940322e-9)) + fs*(1.49503874539434e-11*fs - 1.66555708487018e-5) + 0.000169198590470162;
};

    s = 0.993;
    drive =  hslider("drive[name:Drive]", 0.5, 0, 1, 0.01) : *(0.314): component("filter.lib").smooth(s);

process = ds1_in : ds1_boost : ds1_drive : sclip : ds1_ampin : X1 : X3  : clip : ds1_ampout : *(cgain) : ds1_tone : ds1_out : *(gain)  with {
    R1 = 4700 + 100000 * (1.0 - drive);
    R2 = 100000 + 100000 * drive;
    C = 0.047 * 1e-6;
    a1 = (R1 + R2) * C * 2 * SR;
    a2 = R1 * C * 2 * SR;
    B0 = (1 + a1) / (1 + a2);
    B1 = (1 - a1) / (1 + a2);
    A1 = (1 - a2) / (1 + a2);
    X2 = component("filter.lib").tf1(B0, B1, A1);
    s = 0.993;
    symclip = ffunction(float asymclip3(float), "clipping.h", "");
    sclip = symclip(_);
    opamp = ffunction(float opamp(float), "clipping.h", "");
    X1 = _ <: _ - opamp(_) :> _ ;
    X3 = _ <: _ - opamp(X2-_) :> _ ;
    asymclip = ffunction(float asymhardclip2(float), "clipping.h", "");
    clip = asymclip(_);
    cgain = 3.0 : component("music.lib").db2linear ;
    gain = hslider("Level[name:Level]", 3, -20, 12, 0.1) : component("music.lib").db2linear : component("filter.lib").smooth(s);
};