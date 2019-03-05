EESchema Schematic File Version 4
LIBS:croptop-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 7 7
Title "CropTop"
Date "2018-11-20"
Rev "Revision 8"
Comp "University of Idaho"
Comment1 "Kennedy Caisley, Ryan Donahue"
Comment2 "Designer 2: Ryan Donahue"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CropTop:+5V_REG #PWR?
U 1 1 5ECACACF
P 1400 1450
AR Path="/64807BBC/5ECACACF" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5ECACACF" Ref="#PWR?"  Part="1" 
AR Path="/5EC973C3/5ECACACF" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1400 1300 50  0001 C CNN
F 1 "+5V_REG" H 1415 1623 50  0000 C CNN
F 2 "" H 1400 1450 50  0001 C CNN
F 3 "" H 1400 1450 50  0001 C CNN
	1    1400 1450
	1    0    0    -1  
$EndComp
$Comp
L CropTop:AGND #PWR?
U 1 1 5ECACAD5
P 1400 1900
AR Path="/669AB112/5ECACAD5" Ref="#PWR?"  Part="1" 
AR Path="/5EC973C3/5ECACAD5" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1400 1650 50  0001 C CNN
F 1 "AGND" H 1405 1727 50  0000 C CNN
F 2 "" H 1400 1900 50  0001 C CNN
F 3 "" H 1400 1900 50  0001 C CNN
	1    1400 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 1900 1400 1850
$Comp
L Device:C C?
U 1 1 5ECACADC
P 1400 1700
AR Path="/5ECACADC" Ref="C?"  Part="1" 
AR Path="/65B709D0/5ECACADC" Ref="C?"  Part="1" 
AR Path="/66A12230/5ECACADC" Ref="C?"  Part="1" 
AR Path="/669AB112/5ECACADC" Ref="C?"  Part="1" 
AR Path="/5EC973C3/5ECACADC" Ref="C?"  Part="1" 
F 0 "C?" H 1450 1800 50  0000 L CNN
F 1 "10uF" H 1450 1600 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1438 1550 50  0001 C CNN
F 3 "~" H 1400 1700 50  0001 C CNN
	1    1400 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 1450 1400 1500
Wire Wire Line
	1400 1500 2100 1500
Wire Wire Line
	2100 1500 2100 2050
Connection ~ 1400 1500
Wire Wire Line
	1400 1500 1400 1550
$Comp
L Connector:Screw_Terminal_01x12 J?
U 1 1 5ECACAE8
P 1850 2850
AR Path="/669AB112/5ECACAE8" Ref="J?"  Part="1" 
AR Path="/5EC973C3/5ECACAE8" Ref="J?"  Part="1" 
F 0 "J?" H 1929 2842 50  0000 L CNN
F 1 "ADI Terminal" H 1929 2751 50  0000 L CNN
F 2 "" H 1850 2850 50  0001 C CNN
F 3 "~" H 1850 2850 50  0001 C CNN
	1    1850 2850
	1    0    0    -1  
$EndComp
Text GLabel 1250 2750 0    39   Input ~ 0
ADI_A1-
Text GLabel 1250 2600 0    39   Input ~ 0
ADI_A1+
Text GLabel 1250 3050 0    39   Input ~ 0
ADI_A2-
Text GLabel 1250 2900 0    39   Input ~ 0
ADI_A2+
Text GLabel 1250 3350 0    39   Input ~ 0
ADI_A3-
Text GLabel 1250 3200 0    39   Input ~ 0
ADI_A3+
Text GLabel 1450 3700 0    39   Input ~ 0
ADI_PSW
Wire Wire Line
	3450 1700 3450 2125
Text Notes 4320 2545 0    39   ~ 0
Motor
Text Notes 4140 2545 0    39   ~ 0
BAT
Text Notes 3720 2545 0    39   ~ 0
Rot Encoder
Text Notes 3490 2545 0    39   ~ 0
POT
Text Notes 3050 2545 0    39   ~ 0
Load Cell
Wire Notes Line
	4500 2475 4500 2445
Wire Notes Line
	4310 2475 4500 2475
Wire Notes Line
	4310 2445 4310 2475
Wire Notes Line
	4290 2475 4290 2445
Wire Notes Line
	4110 2475 4290 2475
Wire Notes Line
	3000 2475 3000 2445
Wire Notes Line
	3390 2475 3000 2475
Wire Notes Line
	4110 2445 4110 2475
Wire Notes Line
	4090 2475 3710 2475
Wire Notes Line
	4090 2445 4090 2475
Wire Notes Line
	3710 2445 3710 2475
Wire Notes Line
	3690 2475 3690 2445
Wire Notes Line
	3410 2475 3690 2475
Wire Notes Line
	3410 2445 3410 2475
Wire Notes Line
	3390 2445 3390 2475
Text Notes 4415 2435 0    28   ~ 0
O2\n
Text Notes 4320 2435 0    28   ~ 0
O1
Text Notes 4205 2435 0    28   ~ 0
GND
Text Notes 4110 2435 0    28   ~ 0
12V
Text Notes 4035 2435 0    28   ~ 0
B
Text Notes 3935 2435 0    28   ~ 0
A
Text Notes 3805 2435 0    28   ~ 0
GND
Text Notes 3720 2435 0    28   ~ 0
5V
Text Notes 3630 2435 0    28   ~ 0
IN
Text Notes 3505 2435 0    28   ~ 0
GND
Text Notes 3410 2435 0    28   ~ 0
3V3
Text Notes 3310 2435 0    28   ~ 0
A1-
Text Notes 3210 2435 0    28   ~ 0
A1+
Text Notes 3105 2435 0    28   ~ 0
GND
Text Notes 3020 2435 0    28   ~ 0
5V
Wire Wire Line
	4450 2025 4450 2125
Wire Wire Line
	4350 2025 4350 2125
Wire Wire Line
	4250 2025 4250 2125
Wire Wire Line
	4150 2025 4150 2125
Wire Wire Line
	4050 2025 4050 2125
Wire Wire Line
	3950 2025 3950 2125
Wire Wire Line
	3850 2025 3850 2125
Wire Wire Line
	3750 2025 3750 2125
Wire Wire Line
	3650 2025 3650 2125
Wire Wire Line
	3550 2025 3550 2125
Wire Wire Line
	3350 2025 3350 2125
Wire Wire Line
	3250 2025 3250 2125
Wire Wire Line
	3150 2025 3150 2125
Wire Wire Line
	3050 2025 3050 2125
Text GLabel 3550 2025 1    39   Input ~ 0
LIN_GND
Text GLabel 3650 2025 1    39   Input ~ 0
LIN_IN
Text GLabel 4250 2025 1    39   Input ~ 0
DRV_GND
Text GLabel 4150 2025 1    39   Input ~ 0
DRV_BAT
Text GLabel 4450 2025 1    39   Input ~ 0
DRV_OUT2
Text GLabel 4350 2025 1    39   Input ~ 0
DRV_OUT1
Text GLabel 3350 2025 1    39   Input ~ 0
ADC_A1-
Text GLabel 3250 2025 1    39   Input ~ 0
ADC_A1+
Text GLabel 3050 2025 1    39   Input ~ 0
ADC_VDD
Text GLabel 3150 2025 1    39   Input ~ 0
ADC_GND
Text GLabel 4050 2025 1    39   Input ~ 0
ROT_A2
Text GLabel 3950 2025 1    39   Input ~ 0
ROT_A1
Text GLabel 3750 2025 1    39   Input ~ 0
ROT_VDD
Text GLabel 3850 2025 1    39   Input ~ 0
ROT_GND
$Comp
L Connector:Screw_Terminal_01x15 J?
U 1 1 5EFE4826
P 3750 2325
AR Path="/5EFE4826" Ref="J?"  Part="1" 
AR Path="/669AB112/5EFE4826" Ref="J?"  Part="1" 
AR Path="/5EC973C3/5EFE4826" Ref="J?"  Part="1" 
F 0 "J?" V 3700 1425 50  0000 L CNN
F 1 "Terminal Block" V 3800 950 50  0000 L CNN
F 2 "TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x15_P3.50mm_Horizontal" H 3750 2325 50  0001 C CNN
F 3 "~" H 3750 2325 50  0001 C CNN
	1    3750 2325
	0    -1   1    0   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5EFE482D
P 3450 1700
AR Path="/64807BBC/5EFE482D" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5EFE482D" Ref="#PWR?"  Part="1" 
AR Path="/5EC973C3/5EFE482D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3450 1550 50  0001 C CNN
F 1 "+3V3" H 3465 1873 50  0000 C CNN
F 2 "" H 3450 1700 50  0001 C CNN
F 3 "" H 3450 1700 50  0001 C CNN
	1    3450 1700
	1    0    0    -1  
$EndComp
Text GLabel 4700 4250 0    39   Input ~ 0
AUX_BATTERY
Text GLabel 4700 4550 0    39   Output ~ 0
DRV_OUT2
Text GLabel 4700 4450 0    39   Output ~ 0
DRV_OUT1
$EndSCHEMATC