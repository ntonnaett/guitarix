v 20110115 2
C 40000 40000 0 0 0 title-B.sym
C 47000 47400 1 90 0 resistor-2.sym
{
T 46650 47800 5 10 0 0 90 0 1
device=RESISTOR
T 46700 48100 5 10 1 1 180 0 1
refdes=R4
T 47200 47400 5 10 0 1 90 0 1
}
T 48200 48800 5 10 0 1 90 0 1
}
T 46700 47800 5 10 1 1 180 0 1
value=56k
}
N 48800 46600 48800 45800 4
C 48100 44600 1 0 0 ground.sym
C 45700 48400 1 0 0 input-1.sym
{
T 45700 48700 5 10 0 0 0 0 1
device=INPUT
T 45400 48400 5 10 1 1 0 0 1
refdes=IN1
}
C 49500 48400 1 0 0 output-1.sym
{
T 49600 48700 5 10 0 0 0 0 1
device=OUTPUT
T 50300 48400 5 10 1 1 0 0 1
refdes=OUT1
}
T 46200 47300 8 10 0 1 0 0 1
netname=GND
T 44000 45000 8 10 0 1 0 0 1
netname=GND
C 47100 48300 1 0 0 capacitor-1.sym
{
T 47300 49000 5 10 0 0 0 0 1
device=CAPACITOR
T 47200 48800 5 10 1 1 0 0 1
refdes=C1
T 47300 49200 5 10 0 0 0 0 1
symversion=0.1
T 47600 48800 5 10 1 1 0 0 1
value=250p
}
C 47100 46900 1 0 0 capacitor-1.sym
{
T 47300 47600 5 10 0 0 0 0 1
device=CAPACITOR
T 47200 47400 5 10 1 1 0 0 1
refdes=C2
T 47300 47800 5 10 0 0 0 0 1
symversion=0.1
T 47600 47400 5 10 1 1 0 0 1
value=20n
}
C 47100 45200 1 0 0 capacitor-1.sym
{
T 47300 45900 5 10 0 0 0 0 1
device=CAPACITOR
T 47300 45700 5 10 1 1 0 0 1
refdes=C3
T 47300 46100 5 10 0 0 0 0 1
symversion=0.1
T 47600 45700 5 10 1 1 0 0 1
value=20n
}
N 46900 45400 46900 47400 4
C 48200 48300 1 270 0 resistor-variable-2.sym
{
T 48550 47900 5 10 1 1 0 0 1
refdes=P1
T 49100 47500 5 10 0 1 270 0 1
device=VARIABLE_RESISTOR
T 48500 47500 5 10 1 1 0 0 1
value=value=250k,var=t
}
C 48400 44900 1 90 0 resistor-variable-2.sym
{
T 48750 45600 5 10 1 1 180 0 1
refdes=P3
T 47500 45700 5 10 0 1 90 0 1
device=VARIABLE_RESISTOR
T 48500 45200 5 10 1 1 0 0 1
value=value=25k,var=m
}
C 48200 47100 1 270 0 resistor-variable-2.sym
{
T 48450 46900 5 10 1 1 0 0 1
refdes=P2
T 49100 46300 5 10 0 1 270 0 1
device=VARIABLE_RESISTOR
T 48500 46700 5 10 1 1 0 0 1
value=value=1M,var=l
}
N 47800 45400 48000 45400 4
N 48300 48500 48000 48500 4
N 48000 47100 48300 47100 4
N 47100 47100 46900 47100 4
N 46500 48500 47100 48500 4
N 47100 45400 46900 45400 4
N 48300 47100 48300 47400 4
N 48800 45800 48300 45800 4
N 46900 48500 46900 48300 4
N 48300 48300 48300 48500 4
N 49200 48500 49200 47800 4
N 48800 47800 49200 47800 4
N 49200 48500 49500 48500 4
