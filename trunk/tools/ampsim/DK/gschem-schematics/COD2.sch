v 20130925 2
C 40000 40000 0 0 0 title-B.sym
C 45500 49300 1 180 0 resistor-2.sym
{
T 45100 48950 5 10 0 0 180 0 1
device=RESISTOR
T 45300 49000 5 10 1 1 180 0 1
refdes=R7
T 44800 49400 5 10 1 1 0 0 1
value=4k7
}
C 48000 49300 1 180 0 resistor-2.sym
{
T 47600 48950 5 10 0 0 180 0 1
device=RESISTOR
T 47800 49000 5 10 1 1 180 0 1
refdes=R8
T 47500 49400 5 10 1 1 0 0 1
value=4k7
}
C 46200 47700 1 90 0 resistor-2.sym
{
T 45850 48100 5 10 0 0 90 0 1
device=RESISTOR
T 45900 47900 5 10 1 1 90 0 1
refdes=R9
T 46300 48000 5 10 1 1 0 0 1
value=39k
}
C 46200 46800 1 90 0 resistor-2.sym
{
T 45850 47200 5 10 0 0 90 0 1
device=RESISTOR
T 45900 47000 5 10 1 1 90 0 1
refdes=R10
T 46200 46800 5 10 1 1 0 0 1
value=5k6
}
C 48700 49300 1 90 0 resistor-2.sym
{
T 48350 49700 5 10 0 0 90 0 1
device=RESISTOR
T 48400 49500 5 10 1 1 90 0 1
refdes=R11
T 48700 49300 5 10 1 1 0 0 1
value=150k
}
C 48700 45300 1 90 0 resistor-2.sym
{
T 48350 45700 5 10 0 0 90 0 1
device=RESISTOR
T 48400 45500 5 10 1 1 90 0 1
refdes=R12
T 48700 45300 5 10 1 1 0 0 1
value=33k
}
C 50700 45300 1 90 0 resistor-2.sym
{
T 50350 45700 5 10 0 0 90 0 1
device=RESISTOR
T 50400 45500 5 10 1 1 90 0 1
refdes=R13
T 50700 45300 5 10 1 1 0 0 1
value=470
}
C 50700 49300 1 90 0 resistor-2.sym
{
T 50350 49700 5 10 0 0 90 0 1
device=RESISTOR
T 50400 49500 5 10 1 1 90 0 1
refdes=R14
T 50700 49300 5 10 1 1 0 0 1
value=1k8
}
C 44600 46000 1 0 0 capacitor-1.sym
{
T 44800 46700 5 10 0 0 0 0 1
device=CAPACITOR
T 44800 46900 5 10 0 0 0 0 1
symversion=0.1
T 44800 46500 5 10 1 1 0 0 1
refdes=C3
T 44600 46000 5 10 1 1 0 0 1
value=0.01u
}
C 47100 46000 1 0 0 capacitor-1.sym
{
T 47300 46700 5 10 0 0 0 0 1
device=CAPACITOR
T 47300 46900 5 10 0 0 0 0 1
symversion=0.1
T 47300 46500 5 10 1 1 0 0 1
refdes=C4
T 47100 46000 5 10 1 1 0 0 1
value=0.01u
}
C 46700 47500 1 0 0 capacitor-1.sym
{
T 46900 48200 5 10 0 0 0 0 1
device=CAPACITOR
T 46900 48400 5 10 0 0 0 0 1
symversion=0.1
T 46900 48000 5 10 1 1 0 0 1
refdes=C5
T 46700 47500 5 10 1 1 0 0 1
value=0.1u
}
C 50700 48500 1 0 0 capacitor-1.sym
{
T 50900 49200 5 10 0 0 0 0 1
device=CAPACITOR
T 50900 49400 5 10 0 0 0 0 1
symversion=0.1
T 50900 49000 5 10 1 1 0 0 1
refdes=C6
T 50700 48500 5 10 1 1 0 0 1
value=0.22u
}
C 51400 46200 1 270 0 capacitor-2.sym
{
T 52100 46000 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 52300 46000 5 10 0 0 270 0 1
symversion=0.1
T 51900 46000 5 10 1 1 270 0 1
refdes=C10
T 51400 46200 5 10 1 1 0 0 1
value=25u
}
C 52100 50300 1 270 0 capacitor-2.sym
{
T 52800 50100 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 53000 50100 5 10 0 0 270 0 1
symversion=0.1
T 52600 50100 5 10 1 1 270 0 1
refdes=C11
T 52100 50300 5 10 1 1 0 0 1
value=25u
}
C 52600 48100 1 0 0 output-1.sym
{
T 52700 48400 5 10 0 0 0 0 1
device=OUTPUT
T 52800 48100 5 10 1 1 0 0 1
refdes=OUT1
}
C 46600 49300 1 180 0 resistor-variable-2.sym
{
T 45800 48400 5 10 0 1 180 0 1
device=VARIABLE_RESISTOR
T 46050 48900 5 10 1 1 180 0 1
refdes=P2
T 45500 49600 5 10 1 1 0 0 1
value=value=100k,var=Bass
}
C 45600 46100 1 0 0 resistor-variable-2.sym
{
T 46400 47000 5 10 0 1 0 0 1
device=VARIABLE_RESISTOR
T 46150 46500 5 10 1 1 0 0 1
refdes=P3
T 45300 45800 5 10 1 1 0 0 1
value=value=100k,inv=1,var=Treble
}
C 50100 47200 1 0 0 npn-2.sym
{
T 50700 47700 5 10 0 0 0 0 1
device=NPN_TRANSISTOR
T 50100 47200 5 10 0 0 0 0 1
value=Vt=26mV,Is=7.59fA,Bf=500,Br=5
T 50700 47700 5 10 1 1 0 0 1
refdes=T3
T 50700 47400 5 10 1 1 0 0 1
model-name=BC169C
}
N 51900 48200 51900 48700 4
N 51900 48700 51600 48700 4
N 50600 48200 50600 49300 4
N 50600 48700 50700 48700 4
N 50600 50200 50600 50300 4
N 50600 50300 52300 50300 4
N 51600 46200 50600 46200 4
N 50600 46200 50600 47200 4
C 49200 48500 1 0 0 capacitor-2.sym
{
T 49400 49200 5 10 0 0 0 0 1
device=POLARIZED_CAPACITOR
T 49400 49400 5 10 0 0 0 0 1
symversion=0.1
T 49400 49000 5 10 1 1 0 0 1
refdes=C12
T 49200 48500 5 10 1 1 0 0 1
value=4.7u
}
N 50100 48700 50600 48700 4
N 48600 46200 48600 49300 4
N 48600 47700 50100 47700 4
N 44600 46200 44600 49200 4
N 45500 49200 45700 49200 4
N 46100 48600 46100 48700 4
N 46600 49200 47100 49200 4
N 48000 49200 48000 46200 4
N 47600 47700 48600 47700 4
N 46700 47700 46100 47700 4
N 45500 46200 45600 46200 4
N 46100 46700 46100 46800 4
N 46500 46200 47100 46200 4
N 49200 48700 48000 48700 4
C 48500 41900 1 0 0 gnd-1.sym
C 50500 41900 1 0 0 gnd-1.sym
C 51500 41900 1 0 0 gnd-1.sym
C 52200 48900 1 0 0 gnd-1.sym
N 48600 42200 48600 45300 4
N 50600 42200 50600 45300 4
N 51600 42200 51600 45300 4
N 52300 49400 52300 49200 4
N 51900 48200 52600 48200 4
C 42800 47400 1 0 0 input-1.sym
{
T 42800 47700 5 10 0 0 0 0 1
device=INPUT
T 42800 47400 5 10 1 1 0 0 1
refdes=IN1
}
N 43600 47500 44600 47500 4
C 47800 50200 1 0 0 9V-plus-1.sym
{
T 47800 50200 5 10 0 0 0 0 1
device=POWER
T 47700 50200 5 10 1 1 0 0 1
value=9V
T 47700 50700 5 10 1 1 0 0 1
refdes=Vcc1
}
N 48000 50200 50600 50200 4
