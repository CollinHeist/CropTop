EESchema Schematic File Version 4
LIBS:croptop_rev1-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 5 7
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
L croptop_rev1-rescue:AD7799-croptop U?
U 1 1 669BF5BB
P 4750 1950
AR Path="/669BF5BB" Ref="U?"  Part="1" 
AR Path="/669AB112/669BF5BB" Ref="U?"  Part="1" 
F 0 "U?" H 5000 2550 50  0000 C CNN
F 1 "AD7799" H 5025 1350 50  0000 C CNN
F 2 "" H 4650 1650 50  0001 C CNN
F 3 "" H 4650 1650 50  0001 C CNN
	1    4750 1950
	1    0    0    -1  
$EndComp
Text GLabel 1650 2100 0    39   Input ~ 0
ADC_CS
Text GLabel 1650 1800 0    39   Input ~ 0
SCLK_1
Text GLabel 1650 1900 0    39   Input ~ 0
MOSI_1
Text GLabel 1650 2000 0    39   Input ~ 0
MISO_1
$Comp
L croptop_rev1-rescue:MC74HC125A-croptop U?
U 1 1 669BF5C6
P 2950 1850
AR Path="/669BF5C6" Ref="U?"  Part="1" 
AR Path="/669AB112/669BF5C6" Ref="U?"  Part="1" 
F 0 "U?" H 3075 2000 50  0000 C CNN
F 1 "MC74HC125A" H 3225 1300 50  0000 C CNN
F 2 "" H 3950 1850 50  0001 C CNN
F 3 "" H 3950 1850 50  0001 C CNN
	1    2950 1850
	1    0    0    -1  
$EndComp
Text Notes 6000 3950 0    98   ~ 20
Rotary Encoder Interface w/ Buffer
$Comp
L croptop_rev1-rescue:AVDD-croptop #PWR?
U 1 1 669BF5CE
P 4850 1100
AR Path="/669BF5CE" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF5CE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4850 950 50  0001 C CNN
F 1 "AVDD" H 4865 1273 50  0000 C CNN
F 2 "" H 4850 1100 50  0001 C CNN
F 3 "" H 4850 1100 50  0001 C CNN
	1    4850 1100
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 669BF5D4
P 4550 1100
AR Path="/669BF5D4" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF5D4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4550 950 50  0001 C CNN
F 1 "DVDD" H 4565 1273 50  0000 C CNN
F 2 "" H 4550 1100 50  0001 C CNN
F 3 "" H 4550 1100 50  0001 C CNN
	1    4550 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1200 4750 1150
Wire Wire Line
	4750 1150 4850 1150
Wire Wire Line
	4850 1200 4850 1150
$Comp
L croptop_rev1-rescue:AVDD-croptop #PWR?
U 1 1 669BF5EE
P 8850 1050
AR Path="/669BF5EE" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF5EE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8850 900 50  0001 C CNN
F 1 "AVDD" H 8865 1223 50  0000 C CNN
F 2 "" H 8850 1050 50  0001 C CNN
F 3 "" H 8850 1050 50  0001 C CNN
	1    8850 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 1050 8850 1150
$Comp
L croptop_rev1-rescue:AGND-croptop #PWR?
U 1 1 669BF610
P 4850 2850
AR Path="/669BF610" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF610" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4850 2600 50  0001 C CNN
F 1 "AGND" H 4855 2677 50  0000 C CNN
F 2 "" H 4850 2850 50  0001 C CNN
F 3 "" H 4850 2850 50  0001 C CNN
	1    4850 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 669BF616
P 3850 1650
AR Path="/669BF616" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF616" Ref="R?"  Part="1" 
F 0 "R?" V 3750 1650 50  0000 C CNN
F 1 "500" V 3850 1650 50  0000 C CNN
F 2 "" V 3780 1650 50  0001 C CNN
F 3 "~" H 3850 1650 50  0001 C CNN
	1    3850 1650
	0    1    1    0   
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF61D
P 2950 2600
AR Path="/669BF61D" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF61D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2950 2350 50  0001 C CNN
F 1 "DGND" H 2954 2445 50  0000 C CNN
F 2 "" H 2950 2600 50  0001 C CNN
F 3 "" H 2950 2600 50  0001 C CNN
	1    2950 2600
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF623
P 2400 2600
AR Path="/669BF623" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF623" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2400 2350 50  0001 C CNN
F 1 "DGND" H 2404 2445 50  0000 C CNN
F 2 "" H 2400 2600 50  0001 C CNN
F 3 "" H 2400 2600 50  0001 C CNN
	1    2400 2600
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF629
P 3500 2600
AR Path="/669BF629" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF629" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3500 2350 50  0001 C CNN
F 1 "DGND" H 3504 2445 50  0000 C CNN
F 2 "" H 3500 2600 50  0001 C CNN
F 3 "" H 3500 2600 50  0001 C CNN
	1    3500 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2200 3500 2200
Wire Wire Line
	3500 2200 3500 2300
Wire Wire Line
	3450 2300 3500 2300
Connection ~ 3500 2300
Wire Wire Line
	3500 2300 3500 2600
Wire Wire Line
	2950 2550 2950 2600
Wire Wire Line
	2450 2200 2400 2200
Wire Wire Line
	2400 2200 2400 2300
Wire Wire Line
	2450 2300 2400 2300
Connection ~ 2400 2300
Wire Wire Line
	2400 2300 2400 2600
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF647
P 8100 6200
AR Path="/669BF647" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF647" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8100 5950 50  0001 C CNN
F 1 "DGND" H 8104 6045 50  0000 C CNN
F 2 "" H 8100 6200 50  0001 C CNN
F 3 "" H 8100 6200 50  0001 C CNN
	1    8100 6200
	1    0    0    -1  
$EndComp
Text Notes 550  700  0    98   ~ 20
Force Sensor Interface w/ ADC and Buffer
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF64F
P 8950 6200
AR Path="/669BF64F" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF64F" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8950 5950 50  0001 C CNN
F 1 "DGND" H 8954 6045 50  0000 C CNN
F 2 "" H 8950 6200 50  0001 C CNN
F 3 "" H 8950 6200 50  0001 C CNN
	1    8950 6200
	1    0    0    -1  
$EndComp
Text Notes 550  3950 0    98   ~ 20
Linear Actuator Interface w/ DC Motor Driver
Text GLabel 7000 5350 0    39   Input ~ 0
ROT_Y1
Text GLabel 7000 5550 0    39   Input ~ 0
ROT_Y2
Wire Wire Line
	7600 5400 7500 5400
Wire Wire Line
	7600 5500 7500 5500
Wire Wire Line
	4100 1800 4100 1650
Wire Wire Line
	4150 1800 4100 1800
Wire Wire Line
	4150 1900 4050 1900
Wire Wire Line
	4050 1900 4050 1850
Wire Wire Line
	4150 2000 4050 2000
Wire Wire Line
	4050 2000 4050 2050
Wire Wire Line
	4150 2100 4100 2100
Wire Wire Line
	4100 2100 4100 2250
Wire Wire Line
	3600 1800 3600 1650
Wire Wire Line
	3650 1900 3650 1850
Wire Wire Line
	3650 1850 3700 1850
Wire Wire Line
	3700 1650 3600 1650
Wire Wire Line
	3650 2000 3650 2050
Wire Wire Line
	3650 2050 3700 2050
Wire Wire Line
	3600 2100 3600 2250
Wire Wire Line
	3600 2250 3700 2250
Wire Wire Line
	3450 2100 3600 2100
Wire Wire Line
	3450 2000 3650 2000
Wire Wire Line
	3450 1900 3650 1900
Wire Wire Line
	3450 1800 3600 1800
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF67A
P 4500 5550
AR Path="/669BF67A" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF67A" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4500 5300 50  0001 C CNN
F 1 "DGND" H 4504 5395 50  0000 C CNN
F 2 "" H 4500 5550 50  0001 C CNN
F 3 "" H 4500 5550 50  0001 C CNN
	1    4500 5550
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DVDD_UNREG-croptop #PWR?
U 1 1 669BF680
P 9550 5000
AR Path="/669BF680" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF680" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 9550 4850 50  0001 C CNN
F 1 "DVDD_UNREG" H 9565 5173 50  0000 C CNN
F 2 "" H 9550 5000 50  0001 C CNN
F 3 "" H 9550 5000 50  0001 C CNN
	1    9550 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 5100 9550 5100
Wire Wire Line
	9550 5100 9550 5000
Text Notes 8800 4950 0    50   ~ 0
DNP one
$Comp
L croptop_rev1-rescue:MC74HC125A-croptop U?
U 1 1 669BF68B
P 8100 5450
AR Path="/669BF68B" Ref="U?"  Part="1" 
AR Path="/669AB112/669BF68B" Ref="U?"  Part="1" 
F 0 "U?" H 7950 5600 50  0000 C CNN
F 1 "MC74HC125A" H 7825 4900 50  0000 C CNN
F 2 "" H 9100 5450 50  0001 C CNN
F 3 "" H 9100 5450 50  0001 C CNN
	1    8100 5450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8100 6150 8100 6200
NoConn ~ 8600 5600
NoConn ~ 8600 5700
NoConn ~ 7600 5700
NoConn ~ 7600 5600
Wire Wire Line
	7600 5800 7500 5800
Wire Wire Line
	7500 5800 7500 5900
Wire Wire Line
	7600 5900 7500 5900
Connection ~ 7500 5900
Wire Wire Line
	7500 5900 7500 6200
Wire Wire Line
	8600 5800 8700 5800
Wire Wire Line
	8700 5800 8700 5900
Wire Wire Line
	8700 5900 8600 5900
Wire Wire Line
	8700 5900 8700 6200
Connection ~ 8700 5900
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF6A2
P 7500 6200
AR Path="/669BF6A2" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF6A2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7500 5950 50  0001 C CNN
F 1 "DGND" H 7504 6045 50  0000 C CNN
F 2 "" H 7500 6200 50  0001 C CNN
F 3 "" H 7500 6200 50  0001 C CNN
	1    7500 6200
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF6A8
P 8700 6200
AR Path="/669BF6A8" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF6A8" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8700 5950 50  0001 C CNN
F 1 "DGND" H 8704 6045 50  0000 C CNN
F 2 "" H 8700 6200 50  0001 C CNN
F 3 "" H 8700 6200 50  0001 C CNN
	1    8700 6200
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DRV8872-croptop U?
U 1 1 669BF6AE
P 2550 5200
AR Path="/669BF6AE" Ref="U?"  Part="1" 
AR Path="/669AB112/669BF6AE" Ref="U?"  Part="1" 
F 0 "U?" H 2550 5450 50  0000 C CNN
F 1 "DRV8872" H 2550 4950 50  0000 C CNN
F 2 "" H 2400 5450 50  0001 C CNN
F 3 "" H 2400 5450 50  0001 C CNN
	1    2550 5200
	1    0    0    -1  
$EndComp
Text GLabel 1400 5000 0    39   Input ~ 0
DRV_IN1
Text GLabel 1400 5200 0    39   Input ~ 0
DRV_IN2
Text GLabel 1800 5400 0    39   Input ~ 0
DRV_FLT
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF6B8
P 2000 5450
AR Path="/669BF6B8" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF6B8" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2000 5200 50  0001 C CNN
F 1 "DGND" H 2004 5295 50  0000 C CNN
F 2 "" H 2000 5450 50  0001 C CNN
F 3 "" H 2000 5450 50  0001 C CNN
	1    2000 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 5350 2000 5350
Wire Wire Line
	2000 5350 2000 5450
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF6C0
P 3100 5450
AR Path="/669BF6C0" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF6C0" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3100 5200 50  0001 C CNN
F 1 "DGND" H 3104 5295 50  0000 C CNN
F 2 "" H 3100 5450 50  0001 C CNN
F 3 "" H 3100 5450 50  0001 C CNN
	1    3100 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 5350 3100 5350
Wire Wire Line
	3100 5350 3100 5450
$Comp
L Device:C C?
U 1 1 669BF6C8
P 3350 5450
AR Path="/669BF6C8" Ref="C?"  Part="1" 
AR Path="/669AB112/669BF6C8" Ref="C?"  Part="1" 
F 0 "C?" H 3465 5496 50  0000 L CNN
F 1 "0.1uF" H 3465 5405 50  0000 L CNN
F 2 "" H 3388 5300 50  0001 C CNN
F 3 "~" H 3350 5450 50  0001 C CNN
	1    3350 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 669BF6CF
P 3800 5450
AR Path="/669BF6CF" Ref="C?"  Part="1" 
AR Path="/669AB112/669BF6CF" Ref="C?"  Part="1" 
F 0 "C?" H 3915 5496 50  0000 L CNN
F 1 "10uF" H 3915 5405 50  0000 L CNN
F 2 "" H 3838 5300 50  0001 C CNN
F 3 "~" H 3800 5450 50  0001 C CNN
	1    3800 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 5250 3350 5250
Wire Wire Line
	3350 5250 3350 5300
Connection ~ 3350 5250
Wire Wire Line
	3350 5250 3800 5250
Wire Wire Line
	3800 5250 3800 5300
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF6DC
P 3350 5650
AR Path="/669BF6DC" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF6DC" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3350 5400 50  0001 C CNN
F 1 "DGND" H 3354 5495 50  0000 C CNN
F 2 "" H 3350 5650 50  0001 C CNN
F 3 "" H 3350 5650 50  0001 C CNN
	1    3350 5650
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF6E2
P 3800 5650
AR Path="/669BF6E2" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF6E2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3800 5400 50  0001 C CNN
F 1 "DGND" H 3804 5495 50  0000 C CNN
F 2 "" H 3800 5650 50  0001 C CNN
F 3 "" H 3800 5650 50  0001 C CNN
	1    3800 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 5600 3800 5650
Wire Wire Line
	3350 5600 3350 5650
Wire Wire Line
	8600 5400 9050 5400
Wire Wire Line
	8600 5500 9050 5500
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF6EC
P 4750 4650
AR Path="/669BF6EC" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF6EC" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4750 4400 50  0001 C CNN
F 1 "DGND" H 4754 4495 50  0000 C CNN
F 2 "" H 4750 4650 50  0001 C CNN
F 3 "" H 4750 4650 50  0001 C CNN
	1    4750 4650
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 669BF6F2
P 4650 4250
AR Path="/669BF6F2" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF6F2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4650 4100 50  0001 C CNN
F 1 "DVDD" H 4665 4423 50  0000 C CNN
F 2 "" H 4650 4250 50  0001 C CNN
F 3 "" H 4650 4250 50  0001 C CNN
	1    4650 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4400 4700 4400
Wire Wire Line
	4650 4250 4650 4300
Wire Wire Line
	4650 4300 4850 4300
Wire Wire Line
	4500 5550 4500 5350
Wire Wire Line
	4500 5350 4650 5350
Text GLabel 4700 4400 0    39   Input ~ 0
LIN_VOLT
Text GLabel 4850 4400 2    39   Input ~ 0
LIN_IN
Text GLabel 4650 5050 2    39   Input ~ 0
DRV_OUT1
Text GLabel 4650 5150 2    39   Input ~ 0
DRV_OUT2
Text GLabel 4650 5250 2    39   Input ~ 0
DRV_BAT
Text GLabel 4650 5350 2    39   Input ~ 0
DRV_GND
Text GLabel 4850 4300 2    39   Input ~ 0
LIN_VDD
Text GLabel 4850 4500 2    39   Input ~ 0
LIN_GND
Wire Wire Line
	4750 4500 4850 4500
Wire Wire Line
	4750 4500 4750 4650
Text GLabel 9050 5600 2    39   Input ~ 0
ROT_GND
Wire Wire Line
	8950 5300 9050 5300
Text GLabel 9050 5300 2    39   Input ~ 0
ROT_VDD
Wire Wire Line
	8950 5600 9050 5600
Wire Wire Line
	8950 5600 8950 6200
Text GLabel 9050 5400 2    39   Input ~ 0
ROT_A1
Text GLabel 9050 5500 2    39   Input ~ 0
ROT_A2
$Comp
L Device:R R?
U 1 1 669BF71A
P 3850 1850
AR Path="/669BF71A" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF71A" Ref="R?"  Part="1" 
F 0 "R?" V 3750 1850 50  0000 C CNN
F 1 "500" V 3850 1850 50  0000 C CNN
F 2 "" V 3780 1850 50  0001 C CNN
F 3 "~" H 3850 1850 50  0001 C CNN
	1    3850 1850
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 669BF721
P 3850 2050
AR Path="/669BF721" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF721" Ref="R?"  Part="1" 
F 0 "R?" V 3750 2050 50  0000 C CNN
F 1 "500" V 3850 2050 50  0000 C CNN
F 2 "" V 3780 2050 50  0001 C CNN
F 3 "~" H 3850 2050 50  0001 C CNN
	1    3850 2050
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 669BF728
P 3850 2250
AR Path="/669BF728" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF728" Ref="R?"  Part="1" 
F 0 "R?" V 3750 2250 50  0000 C CNN
F 1 "500" V 3850 2250 50  0000 C CNN
F 2 "" V 3780 2250 50  0001 C CNN
F 3 "~" H 3850 2250 50  0001 C CNN
	1    3850 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 669BF72F
P 2100 1900
AR Path="/669BF72F" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF72F" Ref="R?"  Part="1" 
F 0 "R?" V 2000 1900 50  0000 C CNN
F 1 "10" V 2100 1900 50  0000 C CNN
F 2 "" V 2030 1900 50  0001 C CNN
F 3 "~" H 2100 1900 50  0001 C CNN
	1    2100 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 1800 2450 1800
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 669BF74A
P 4550 2850
AR Path="/669BF74A" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/669BF74A" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4550 2600 50  0001 C CNN
F 1 "DGND" H 4554 2695 50  0000 C CNN
F 2 "" H 4550 2850 50  0001 C CNN
F 3 "" H 4550 2850 50  0001 C CNN
	1    4550 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2700 4750 2800
$Comp
L Device:R R?
U 1 1 669BF754
P 7250 5550
AR Path="/669BF754" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF754" Ref="R?"  Part="1" 
F 0 "R?" V 7150 5550 50  0000 C CNN
F 1 "10" V 7250 5550 50  0000 C CNN
F 2 "" V 7180 5550 50  0001 C CNN
F 3 "~" H 7250 5550 50  0001 C CNN
	1    7250 5550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 669BF75B
P 7250 5350
AR Path="/669BF75B" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF75B" Ref="R?"  Part="1" 
F 0 "R?" V 7150 5350 50  0000 C CNN
F 1 "10" V 7250 5350 50  0000 C CNN
F 2 "" V 7180 5350 50  0001 C CNN
F 3 "~" H 7250 5350 50  0001 C CNN
	1    7250 5350
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 5550 7500 5550
Wire Wire Line
	7500 5550 7500 5500
Wire Wire Line
	7500 5400 7500 5350
Wire Wire Line
	7500 5350 7400 5350
Wire Wire Line
	7100 5350 7000 5350
Wire Wire Line
	7100 5550 7000 5550
$Comp
L Device:R R?
U 1 1 669BF768
P 2100 1700
AR Path="/669BF768" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF768" Ref="R?"  Part="1" 
F 0 "R?" V 2000 1700 50  0000 C CNN
F 1 "10" V 2100 1700 50  0000 C CNN
F 2 "" V 2030 1700 50  0001 C CNN
F 3 "~" H 2100 1700 50  0001 C CNN
	1    2100 1700
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 669BF771
P 1650 5200
AR Path="/669BF771" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF771" Ref="R?"  Part="1" 
F 0 "R?" V 1550 5200 50  0000 C CNN
F 1 "10" V 1650 5200 50  0000 C CNN
F 2 "" V 1580 5200 50  0001 C CNN
F 3 "~" H 1650 5200 50  0001 C CNN
	1    1650 5200
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 669BF778
P 1650 5000
AR Path="/669BF778" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF778" Ref="R?"  Part="1" 
F 0 "R?" V 1550 5000 50  0000 C CNN
F 1 "10" V 1650 5000 50  0000 C CNN
F 2 "" V 1580 5000 50  0001 C CNN
F 3 "~" H 1650 5000 50  0001 C CNN
	1    1650 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 5050 1900 5000
Wire Wire Line
	1900 5000 1800 5000
Wire Wire Line
	1900 5050 2100 5050
Wire Wire Line
	1900 5150 1900 5200
Wire Wire Line
	1900 5200 1800 5200
Wire Wire Line
	1900 5150 2100 5150
Wire Wire Line
	1900 5250 1900 5400
Wire Wire Line
	1900 5400 1800 5400
Wire Wire Line
	1900 5250 2100 5250
Wire Wire Line
	1400 5200 1500 5200
Wire Wire Line
	1500 5000 1400 5000
Wire Wire Line
	4650 1200 4650 1150
Wire Wire Line
	4100 2250 4000 2250
Wire Wire Line
	4050 2050 4000 2050
Wire Wire Line
	4050 1850 4000 1850
Wire Wire Line
	4100 1650 4000 1650
$Comp
L Device:R R?
U 1 1 669BF7B9
P 9200 5100
AR Path="/669BF7B9" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF7B9" Ref="R?"  Part="1" 
F 0 "R?" V 9300 5100 50  0000 C CNN
F 1 "0" V 9195 5100 50  0000 C CNN
F 2 "" V 9130 5100 50  0001 C CNN
F 3 "~" H 9200 5100 50  0001 C CNN
	1    9200 5100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 669BF7C0
P 8700 5100
AR Path="/669BF7C0" Ref="R?"  Part="1" 
AR Path="/669AB112/669BF7C0" Ref="R?"  Part="1" 
F 0 "R?" V 8800 5100 50  0000 C CNN
F 1 "0" V 8695 5100 50  0000 C CNN
F 2 "" V 8630 5100 50  0001 C CNN
F 3 "~" H 8700 5100 50  0001 C CNN
	1    8700 5100
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D?
U 1 1 669BF7C7
P 4250 5250
AR Path="/669BF7C7" Ref="D?"  Part="1" 
AR Path="/669AB112/669BF7C7" Ref="D?"  Part="1" 
F 0 "D?" H 4250 5034 50  0000 C CNN
F 1 "MBR0540" H 4250 5125 50  0000 C CNN
F 2 "" H 4250 5250 50  0001 C CNN
F 3 "~" H 4250 5250 50  0001 C CNN
	1    4250 5250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x15 J?
U 1 1 669EE9CE
P 3275 7500
AR Path="/669EE9CE" Ref="J?"  Part="1" 
AR Path="/669AB112/669EE9CE" Ref="J?"  Part="1" 
F 0 "J?" V 3225 6600 50  0000 L CNN
F 1 "Terminal Block" V 3325 6125 50  0000 L CNN
F 2 "" H 3275 7500 50  0001 C CNN
F 3 "~" H 3275 7500 50  0001 C CNN
	1    3275 7500
	0    -1   1    0   
$EndComp
Text GLabel 3375 7200 1    39   Input ~ 0
ROT_GND
Text GLabel 3275 7200 1    39   Input ~ 0
ROT_VDD
Text GLabel 3475 7200 1    39   Input ~ 0
ROT_A1
Text GLabel 3575 7200 1    39   Input ~ 0
ROT_A2
Text GLabel 2675 7200 1    39   Input ~ 0
ADC_GND
Text GLabel 2575 7200 1    39   Input ~ 0
ADC_VDD
Text GLabel 2775 7200 1    39   Input ~ 0
ADC_A1+
Text GLabel 2875 7200 1    39   Input ~ 0
ADC_A1-
Text GLabel 3875 7200 1    39   Input ~ 0
DRV_OUT1
Text GLabel 3975 7200 1    39   Input ~ 0
DRV_OUT2
Text GLabel 3675 7200 1    39   Input ~ 0
DRV_BAT
Text GLabel 3775 7200 1    39   Input ~ 0
DRV_GND
Text GLabel 3175 7200 1    39   Input ~ 0
LIN_IN
Text GLabel 2975 7200 1    39   Input ~ 0
LIN_VDD
Text GLabel 3075 7200 1    39   Input ~ 0
LIN_GND
Wire Wire Line
	2575 7200 2575 7300
Wire Wire Line
	2675 7200 2675 7300
Wire Wire Line
	2775 7200 2775 7300
Wire Wire Line
	2875 7200 2875 7300
Wire Wire Line
	2975 7200 2975 7300
Wire Wire Line
	3075 7200 3075 7300
Wire Wire Line
	3175 7200 3175 7300
Wire Wire Line
	3275 7200 3275 7300
Wire Wire Line
	3375 7200 3375 7300
Wire Wire Line
	3475 7200 3475 7300
Wire Wire Line
	3575 7200 3575 7300
Wire Wire Line
	3675 7200 3675 7300
Wire Wire Line
	3775 7200 3775 7300
Wire Wire Line
	3875 7200 3875 7300
Wire Wire Line
	3975 7200 3975 7300
Text Notes 2545 7610 0    28   ~ 0
5V
Text Notes 2630 7610 0    28   ~ 0
GND
Text Notes 2735 7610 0    28   ~ 0
A1+
Text Notes 2835 7610 0    28   ~ 0
A1-
Text Notes 2935 7610 0    28   ~ 0
3V3
Text Notes 3030 7610 0    28   ~ 0
GND
Text Notes 3155 7610 0    28   ~ 0
IN
Text Notes 3245 7610 0    28   ~ 0
5V
Text Notes 3330 7610 0    28   ~ 0
GND
Text Notes 3460 7610 0    28   ~ 0
A
Text Notes 3560 7610 0    28   ~ 0
B
Text Notes 3635 7610 0    28   ~ 0
12V
Text Notes 3730 7610 0    28   ~ 0
GND
Text Notes 3835 7610 0    28   ~ 0
12V
Text Notes 3930 7610 0    28   ~ 0
GND
Wire Notes Line
	2915 7620 2915 7650
Wire Notes Line
	2935 7620 2935 7650
Wire Notes Line
	2935 7650 3215 7650
Wire Notes Line
	3215 7650 3215 7620
Wire Notes Line
	3235 7620 3235 7650
Wire Notes Line
	3615 7620 3615 7650
Wire Notes Line
	3615 7650 3235 7650
Wire Notes Line
	3635 7620 3635 7650
Wire Notes Line
	2915 7650 2525 7650
Wire Notes Line
	2525 7650 2525 7620
Wire Notes Line
	3635 7650 3815 7650
Wire Notes Line
	3815 7650 3815 7620
Wire Notes Line
	3835 7620 3835 7650
Wire Notes Line
	3835 7650 4025 7650
Wire Notes Line
	4025 7650 4025 7620
Text Notes 2575 7720 0    39   ~ 0
Load Cell
Text Notes 3015 7720 0    39   ~ 0
POT
Text Notes 3245 7720 0    39   ~ 0
Rot Encoder
Text Notes 3665 7720 0    39   ~ 0
BAT
Text Notes 3845 7720 0    39   ~ 0
Motor
Text GLabel 5000 2750 2    39   Input ~ 0
ADC_PSW
Wire Wire Line
	7750 2100 7750 2150
Wire Wire Line
	7650 2200 7650 2300
Wire Wire Line
	1850 1800 1650 1800
$Comp
L Device:R R?
U 1 1 5C644C28
P 8100 1550
AR Path="/5C644C28" Ref="R?"  Part="1" 
AR Path="/669AB112/5C644C28" Ref="R?"  Part="1" 
F 0 "R?" V 8000 1550 50  0000 C CNN
F 1 "100" V 8100 1550 50  0000 C CNN
F 2 "" V 8030 1550 50  0001 C CNN
F 3 "~" H 8100 1550 50  0001 C CNN
	1    8100 1550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C644C2F
P 8400 1700
AR Path="/5C644C2F" Ref="R?"  Part="1" 
AR Path="/669AB112/5C644C2F" Ref="R?"  Part="1" 
F 0 "R?" V 8300 1700 50  0000 C CNN
F 1 "100" V 8400 1700 50  0000 C CNN
F 2 "" V 8330 1700 50  0001 C CNN
F 3 "~" H 8400 1700 50  0001 C CNN
	1    8400 1700
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C644C36
P 8100 1850
AR Path="/5C644C36" Ref="R?"  Part="1" 
AR Path="/669AB112/5C644C36" Ref="R?"  Part="1" 
F 0 "R?" V 8000 1850 50  0000 C CNN
F 1 "100" V 8100 1850 50  0000 C CNN
F 2 "" V 8030 1850 50  0001 C CNN
F 3 "~" H 8100 1850 50  0001 C CNN
	1    8100 1850
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C644C3D
P 8400 2000
AR Path="/5C644C3D" Ref="R?"  Part="1" 
AR Path="/669AB112/5C644C3D" Ref="R?"  Part="1" 
F 0 "R?" V 8300 2000 50  0000 C CNN
F 1 "100" V 8400 2000 50  0000 C CNN
F 2 "" V 8330 2000 50  0001 C CNN
F 3 "~" H 8400 2000 50  0001 C CNN
	1    8400 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C644C44
P 8100 2150
AR Path="/5C644C44" Ref="R?"  Part="1" 
AR Path="/669AB112/5C644C44" Ref="R?"  Part="1" 
F 0 "R?" V 8000 2150 50  0000 C CNN
F 1 "100" V 8100 2150 50  0000 C CNN
F 2 "" V 8030 2150 50  0001 C CNN
F 3 "~" H 8100 2150 50  0001 C CNN
	1    8100 2150
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5C644C4B
P 8400 2300
AR Path="/5C644C4B" Ref="R?"  Part="1" 
AR Path="/669AB112/5C644C4B" Ref="R?"  Part="1" 
F 0 "R?" V 8300 2300 50  0000 C CNN
F 1 "100" V 8400 2300 50  0000 C CNN
F 2 "" V 8330 2300 50  0001 C CNN
F 3 "~" H 8400 2300 50  0001 C CNN
	1    8400 2300
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 5C6CD366
P 9450 1900
AR Path="/5C6CD366" Ref="J?"  Part="1" 
AR Path="/669AB112/5C6CD366" Ref="J?"  Part="1" 
F 0 "J?" H 9422 1873 50  0000 R CNN
F 1 "Unused1" H 9422 1782 50  0000 R CNN
F 2 "" H 9450 1900 50  0001 C CNN
F 3 "~" H 9450 1900 50  0001 C CNN
	1    9450 1900
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 5C6CD36D
P 9450 2350
AR Path="/5C6CD36D" Ref="J?"  Part="1" 
AR Path="/669AB112/5C6CD36D" Ref="J?"  Part="1" 
F 0 "J?" H 9422 2323 50  0000 R CNN
F 1 "Unused2" H 9422 2232 50  0000 R CNN
F 2 "" H 9450 2350 50  0001 C CNN
F 3 "~" H 9450 2350 50  0001 C CNN
	1    9450 2350
	-1   0    0    -1  
$EndComp
Text GLabel 9250 1450 2    39   Input ~ 0
ADC_GND
Text GLabel 9250 1350 2    39   Input ~ 0
ADC_VDD
Text GLabel 9250 1550 2    39   Input ~ 0
ADC_A1+
Text GLabel 9250 1650 2    39   Input ~ 0
ADC_A1-
Wire Wire Line
	8650 2300 8650 2550
Wire Wire Line
	8750 2150 8750 2450
Wire Wire Line
	8850 2000 8850 2100
Wire Wire Line
	8950 1850 8950 2000
Wire Wire Line
	8950 1700 8950 1650
Wire Wire Line
	8550 2300 8650 2300
Wire Wire Line
	8550 2000 8850 2000
Wire Wire Line
	8250 1850 8950 1850
Wire Wire Line
	8550 1700 8950 1700
Wire Wire Line
	1650 2000 2450 2000
Wire Wire Line
	1650 2100 2450 2100
Wire Wire Line
	1650 1900 1950 1900
Wire Wire Line
	2250 1900 2450 1900
Wire Wire Line
	1850 1800 1850 1700
Wire Wire Line
	1850 1700 1950 1700
Wire Wire Line
	2250 1700 2350 1700
Wire Wire Line
	2350 1700 2350 1800
Wire Wire Line
	7650 1700 7650 1550
Wire Wire Line
	7750 1800 7750 1700
Wire Wire Line
	7850 1900 7850 1850
Text GLabel 8950 1250 0    39   Input ~ 0
ADC_PSW
Wire Wire Line
	8950 1250 9050 1250
Wire Wire Line
	8850 1150 9150 1150
Wire Wire Line
	8250 1550 9250 1550
Wire Wire Line
	8950 1650 9250 1650
Wire Wire Line
	8950 2000 9250 2000
Wire Wire Line
	8850 2100 9250 2100
Wire Wire Line
	8750 2450 9250 2450
Wire Wire Line
	8650 2550 9250 2550
Wire Wire Line
	9150 2250 9250 2250
Wire Wire Line
	9150 1150 9150 1350
Wire Wire Line
	9150 1350 9250 1350
Connection ~ 9150 1350
Wire Wire Line
	9150 1350 9150 1800
Wire Wire Line
	9150 1800 9250 1800
Connection ~ 9150 1800
Wire Wire Line
	9150 1800 9150 2250
Wire Wire Line
	9050 1900 9250 1900
Wire Wire Line
	9050 1250 9050 1450
Wire Wire Line
	9050 1900 9050 2350
Wire Wire Line
	9050 2350 9250 2350
Connection ~ 9050 1900
Wire Wire Line
	9050 1450 9250 1450
Connection ~ 9050 1450
Wire Wire Line
	9050 1450 9050 1900
Text Notes 550  6500 0    98   ~ 20
Peripheral Terminal Block
Wire Wire Line
	4850 2700 4850 2750
Wire Wire Line
	4850 2750 5000 2750
Wire Notes Line width 20
	500  3700 10500 3700
Wire Notes Line width 20
	5900 3700 5900 8000
Wire Notes Line width 20
	500  6250 5900 6250
Text Notes 4350 6100 0    79   ~ 16
Add Bulk\nCaps
Text Notes 3050 5900 0    50   ~ 0
make sure these are 25V rated\n
Text Notes 3950 4600 0    79   ~ 16
Caps?
Text Notes 4000 5700 0    79   ~ 16
Pick D
Text Notes 2300 4700 0    79   ~ 16
Replace\nw/ New
Text Notes 6900 6050 0    79   ~ 16
Replace\nw/ New
Text Notes 3100 1500 0    79   ~ 16
Replace\nw/ New
Text Notes 2550 2950 0    79   ~ 16
OE needs tilde
Text Notes 2350 5825 0    79   ~ 16
Fix Vm\nPin
Text Notes 3900 1250 0    79   ~ 16
Two sets\nof caps
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 5CFFD9DA
P 8100 5050
AR Path="/5CFFD9DA" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5CFFD9DA" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5CFFD9DA" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5CFFD9DA" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8100 4900 50  0001 C CNN
F 1 "DVDD" H 8115 5223 50  0000 C CNN
F 2 "" H 8100 5050 50  0001 C CNN
F 3 "" H 8100 5050 50  0001 C CNN
	1    8100 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D03A966
P 7350 4650
AR Path="/5D03A966" Ref="C?"  Part="1" 
AR Path="/65B709D0/5D03A966" Ref="C?"  Part="1" 
AR Path="/66A12230/5D03A966" Ref="C?"  Part="1" 
AR Path="/669AB112/5D03A966" Ref="C?"  Part="1" 
F 0 "C?" H 7400 4750 50  0000 L CNN
F 1 "0.1uF" H 7400 4550 50  0000 L CNN
F 2 "" H 7388 4500 50  0001 C CNN
F 3 "~" H 7350 4650 50  0001 C CNN
	1    7350 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D03A96D
P 7000 4650
AR Path="/5D03A96D" Ref="C?"  Part="1" 
AR Path="/65B709D0/5D03A96D" Ref="C?"  Part="1" 
AR Path="/66A12230/5D03A96D" Ref="C?"  Part="1" 
AR Path="/669AB112/5D03A96D" Ref="C?"  Part="1" 
F 0 "C?" H 7050 4750 50  0000 L CNN
F 1 "1uF" H 7050 4550 50  0000 L CNN
F 2 "" H 7038 4500 50  0001 C CNN
F 3 "~" H 7000 4650 50  0001 C CNN
	1    7000 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D03A974
P 6650 4650
AR Path="/5D03A974" Ref="C?"  Part="1" 
AR Path="/65B709D0/5D03A974" Ref="C?"  Part="1" 
AR Path="/66A12230/5D03A974" Ref="C?"  Part="1" 
AR Path="/669AB112/5D03A974" Ref="C?"  Part="1" 
F 0 "C?" H 6700 4750 50  0000 L CNN
F 1 "10uF" H 6700 4550 50  0000 L CNN
F 2 "" H 6688 4500 50  0001 C CNN
F 3 "~" H 6650 4650 50  0001 C CNN
	1    6650 4650
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 5D03A97B
P 6650 4850
AR Path="/5D03A97B" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5D03A97B" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5D03A97B" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D03A97B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6650 4600 50  0001 C CNN
F 1 "DGND" H 6654 4695 50  0000 C CNN
F 2 "" H 6650 4850 50  0001 C CNN
F 3 "" H 6650 4850 50  0001 C CNN
	1    6650 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 4500 7350 4450
Wire Wire Line
	7000 4500 7000 4450
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 5D03A983
P 7000 4850
AR Path="/5D03A983" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5D03A983" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5D03A983" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D03A983" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7000 4600 50  0001 C CNN
F 1 "DGND" H 7004 4695 50  0000 C CNN
F 2 "" H 7000 4850 50  0001 C CNN
F 3 "" H 7000 4850 50  0001 C CNN
	1    7000 4850
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 5D03A989
P 7350 4850
AR Path="/5D03A989" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5D03A989" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5D03A989" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D03A989" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7350 4600 50  0001 C CNN
F 1 "DGND" H 7354 4695 50  0000 C CNN
F 2 "" H 7350 4850 50  0001 C CNN
F 3 "" H 7350 4850 50  0001 C CNN
	1    7350 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 4850 6650 4800
Wire Wire Line
	7000 4850 7000 4800
Wire Wire Line
	7350 4850 7350 4800
Wire Wire Line
	6650 4500 6650 4450
Connection ~ 7000 4450
Wire Wire Line
	7000 4450 6650 4450
Wire Wire Line
	7350 4450 7000 4450
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 5D03A996
P 6650 4400
AR Path="/5D03A996" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5D03A996" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5D03A996" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D03A996" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6650 4250 50  0001 C CNN
F 1 "DVDD" H 6665 4573 50  0000 C CNN
F 2 "" H 6650 4400 50  0001 C CNN
F 3 "" H 6650 4400 50  0001 C CNN
	1    6650 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 4400 6650 4450
Connection ~ 6650 4450
$Comp
L Device:C C?
U 1 1 5D06A073
P 1750 2800
AR Path="/5D06A073" Ref="C?"  Part="1" 
AR Path="/65B709D0/5D06A073" Ref="C?"  Part="1" 
AR Path="/66A12230/5D06A073" Ref="C?"  Part="1" 
AR Path="/669AB112/5D06A073" Ref="C?"  Part="1" 
F 0 "C?" H 1800 2900 50  0000 L CNN
F 1 "0.1uF" H 1800 2700 50  0000 L CNN
F 2 "" H 1788 2650 50  0001 C CNN
F 3 "~" H 1750 2800 50  0001 C CNN
	1    1750 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D06A07A
P 1400 2800
AR Path="/5D06A07A" Ref="C?"  Part="1" 
AR Path="/65B709D0/5D06A07A" Ref="C?"  Part="1" 
AR Path="/66A12230/5D06A07A" Ref="C?"  Part="1" 
AR Path="/669AB112/5D06A07A" Ref="C?"  Part="1" 
F 0 "C?" H 1450 2900 50  0000 L CNN
F 1 "1uF" H 1450 2700 50  0000 L CNN
F 2 "" H 1438 2650 50  0001 C CNN
F 3 "~" H 1400 2800 50  0001 C CNN
	1    1400 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D06A081
P 1050 2800
AR Path="/5D06A081" Ref="C?"  Part="1" 
AR Path="/65B709D0/5D06A081" Ref="C?"  Part="1" 
AR Path="/66A12230/5D06A081" Ref="C?"  Part="1" 
AR Path="/669AB112/5D06A081" Ref="C?"  Part="1" 
F 0 "C?" H 1100 2900 50  0000 L CNN
F 1 "10uF" H 1100 2700 50  0000 L CNN
F 2 "" H 1088 2650 50  0001 C CNN
F 3 "~" H 1050 2800 50  0001 C CNN
	1    1050 2800
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 5D06A088
P 1050 3000
AR Path="/5D06A088" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5D06A088" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5D06A088" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D06A088" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1050 2750 50  0001 C CNN
F 1 "DGND" H 1054 2845 50  0000 C CNN
F 2 "" H 1050 3000 50  0001 C CNN
F 3 "" H 1050 3000 50  0001 C CNN
	1    1050 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2650 1750 2600
Wire Wire Line
	1400 2650 1400 2600
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 5D06A090
P 1400 3000
AR Path="/5D06A090" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5D06A090" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5D06A090" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D06A090" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1400 2750 50  0001 C CNN
F 1 "DGND" H 1404 2845 50  0000 C CNN
F 2 "" H 1400 3000 50  0001 C CNN
F 3 "" H 1400 3000 50  0001 C CNN
	1    1400 3000
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 5D06A096
P 1750 3000
AR Path="/5D06A096" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5D06A096" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5D06A096" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D06A096" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1750 2750 50  0001 C CNN
F 1 "DGND" H 1754 2845 50  0000 C CNN
F 2 "" H 1750 3000 50  0001 C CNN
F 3 "" H 1750 3000 50  0001 C CNN
	1    1750 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 3000 1050 2950
Wire Wire Line
	1400 3000 1400 2950
Wire Wire Line
	1750 3000 1750 2950
Wire Wire Line
	1050 2650 1050 2600
Connection ~ 1400 2600
Wire Wire Line
	1400 2600 1050 2600
Wire Wire Line
	1750 2600 1400 2600
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 5D06A0A3
P 1050 2550
AR Path="/5D06A0A3" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5D06A0A3" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5D06A0A3" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D06A0A3" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1050 2400 50  0001 C CNN
F 1 "DVDD" H 1065 2723 50  0000 C CNN
F 2 "" H 1050 2550 50  0001 C CNN
F 3 "" H 1050 2550 50  0001 C CNN
	1    1050 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 2550 1050 2600
Connection ~ 1050 2600
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 5D076640
P 2950 1500
AR Path="/5D076640" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/5D076640" Ref="#PWR?"  Part="1" 
AR Path="/66A12230/5D076640" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D076640" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2950 1350 50  0001 C CNN
F 1 "DVDD" H 2965 1673 50  0000 C CNN
F 2 "" H 2950 1500 50  0001 C CNN
F 3 "" H 2950 1500 50  0001 C CNN
	1    2950 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 1500 2950 1550
Wire Notes Line
	9750 1750 9850 1750
Wire Notes Line
	9850 1750 9850 2550
Wire Notes Line
	9850 2550 9750 2550
Text Notes 9900 2200 0    50   ~ 0
D.N.P.
Wire Notes Line
	4700 700  4700 3300
Wire Wire Line
	4750 2800 4850 2800
Wire Wire Line
	4850 2800 4850 2850
Wire Wire Line
	4650 2800 4650 2700
Text Notes 6450 850  0    79   Italic 0
Isolated 5V Plane
Wire Wire Line
	4650 2800 4550 2800
Wire Wire Line
	4550 2800 4550 2850
Wire Wire Line
	4650 1150 4550 1150
Wire Wire Line
	4550 1150 4550 1100
Wire Wire Line
	4850 1150 4850 1100
Connection ~ 4850 1150
Wire Wire Line
	8100 5050 8100 5100
Wire Wire Line
	8550 5100 8100 5100
Wire Wire Line
	8850 5100 8950 5100
Wire Wire Line
	8100 5150 8100 5100
Connection ~ 8100 5100
Wire Wire Line
	8950 5300 8950 5100
Connection ~ 8950 5100
Wire Wire Line
	8950 5100 9050 5100
Wire Wire Line
	3800 5250 4100 5250
Connection ~ 3800 5250
Wire Wire Line
	4400 5250 4650 5250
Wire Wire Line
	3000 5150 4650 5150
Wire Wire Line
	3000 5050 4650 5050
Text Notes 2625 6800 0    79   ~ 16
Need ESD Protection Diodes
$Comp
L croptop_rev1-rescue:AGND-croptop #PWR?
U 1 1 5D3C0A58
P 7450 2850
AR Path="/5D3C0A58" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D3C0A58" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7450 2600 50  0001 C CNN
F 1 "AGND" H 7455 2677 50  0000 C CNN
F 2 "" H 7450 2850 50  0001 C CNN
F 3 "" H 7450 2850 50  0001 C CNN
	1    7450 2850
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D3C0A5E
P 5450 2600
AR Path="/5D3C0A5E" Ref="C?"  Part="1" 
AR Path="/669AB112/5D3C0A5E" Ref="C?"  Part="1" 
F 0 "C?" H 5400 2500 50  0000 R CNN
F 1 "0.1uF" H 5400 2700 50  0000 R CNN
F 2 "" H 5488 2450 50  0001 C CNN
F 3 "~" H 5450 2600 50  0001 C CNN
	1    5450 2600
	-1   0    0    1   
$EndComp
$Comp
L croptop_rev1-rescue:AGND-croptop #PWR?
U 1 1 5D3C0A6B
P 7050 2850
AR Path="/5D3C0A6B" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D3C0A6B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7050 2600 50  0001 C CNN
F 1 "AGND" H 7055 2677 50  0000 C CNN
F 2 "" H 7050 2850 50  0001 C CNN
F 3 "" H 7050 2850 50  0001 C CNN
	1    7050 2850
	-1   0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:AGND-croptop #PWR?
U 1 1 5D3C0A71
P 6650 2850
AR Path="/5D3C0A71" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D3C0A71" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6650 2600 50  0001 C CNN
F 1 "AGND" H 6655 2677 50  0000 C CNN
F 2 "" H 6650 2850 50  0001 C CNN
F 3 "" H 6650 2850 50  0001 C CNN
	1    6650 2850
	-1   0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:AGND-croptop #PWR?
U 1 1 5D3C0A77
P 6250 2850
AR Path="/5D3C0A77" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D3C0A77" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6250 2600 50  0001 C CNN
F 1 "AGND" H 6255 2677 50  0000 C CNN
F 2 "" H 6250 2850 50  0001 C CNN
F 3 "" H 6250 2850 50  0001 C CNN
	1    6250 2850
	-1   0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:AGND-croptop #PWR?
U 1 1 5D3C0A7D
P 5850 2850
AR Path="/5D3C0A7D" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D3C0A7D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5850 2600 50  0001 C CNN
F 1 "AGND" H 5855 2677 50  0000 C CNN
F 2 "" H 5850 2850 50  0001 C CNN
F 3 "" H 5850 2850 50  0001 C CNN
	1    5850 2850
	-1   0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:AGND-croptop #PWR?
U 1 1 5D3C0A83
P 5450 2850
AR Path="/5D3C0A83" Ref="#PWR?"  Part="1" 
AR Path="/669AB112/5D3C0A83" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5450 2600 50  0001 C CNN
F 1 "AGND" H 5455 2677 50  0000 C CNN
F 2 "" H 5450 2850 50  0001 C CNN
F 3 "" H 5450 2850 50  0001 C CNN
	1    5450 2850
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D3C0A96
P 6250 2600
AR Path="/5D3C0A96" Ref="C?"  Part="1" 
AR Path="/669AB112/5D3C0A96" Ref="C?"  Part="1" 
F 0 "C?" H 6200 2500 50  0000 R CNN
F 1 "0.1uF" H 6200 2700 50  0000 R CNN
F 2 "" H 6288 2450 50  0001 C CNN
F 3 "~" H 6250 2600 50  0001 C CNN
	1    6250 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5D3C0A9D
P 6650 2600
AR Path="/5D3C0A9D" Ref="C?"  Part="1" 
AR Path="/669AB112/5D3C0A9D" Ref="C?"  Part="1" 
F 0 "C?" H 6600 2500 50  0000 R CNN
F 1 "0.1uF" H 6600 2700 50  0000 R CNN
F 2 "" H 6688 2450 50  0001 C CNN
F 3 "~" H 6650 2600 50  0001 C CNN
	1    6650 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5D3C0AA4
P 7050 2600
AR Path="/5D3C0AA4" Ref="C?"  Part="1" 
AR Path="/669AB112/5D3C0AA4" Ref="C?"  Part="1" 
F 0 "C?" H 7000 2500 50  0000 R CNN
F 1 "0.1uF" H 7000 2700 50  0000 R CNN
F 2 "" H 7088 2450 50  0001 C CNN
F 3 "~" H 7050 2600 50  0001 C CNN
	1    7050 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5D3C0AAB
P 7450 2600
AR Path="/5D3C0AAB" Ref="C?"  Part="1" 
AR Path="/669AB112/5D3C0AAB" Ref="C?"  Part="1" 
F 0 "C?" H 7400 2500 50  0000 R CNN
F 1 "0.1uF" H 7400 2700 50  0000 R CNN
F 2 "" H 7488 2450 50  0001 C CNN
F 3 "~" H 7450 2600 50  0001 C CNN
	1    7450 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5D3C0A8F
P 5850 2600
AR Path="/5D3C0A8F" Ref="C?"  Part="1" 
AR Path="/669AB112/5D3C0A8F" Ref="C?"  Part="1" 
F 0 "C?" H 5800 2500 50  0000 R CNN
F 1 "0.1uF" H 5800 2700 50  0000 R CNN
F 2 "" H 5888 2450 50  0001 C CNN
F 3 "~" H 5850 2600 50  0001 C CNN
	1    5850 2600
	-1   0    0    1   
$EndComp
Wire Wire Line
	5450 2750 5450 2850
Wire Wire Line
	5850 2750 5850 2850
Wire Wire Line
	6250 2750 6250 2850
Wire Wire Line
	6650 2750 6650 2850
Wire Wire Line
	7050 2750 7050 2850
Wire Wire Line
	7450 2750 7450 2850
Wire Wire Line
	5350 2200 5450 2200
Wire Wire Line
	5350 2000 6250 2000
Wire Wire Line
	5350 2100 5850 2100
Wire Wire Line
	5350 1900 6650 1900
Wire Wire Line
	5350 1800 7050 1800
Wire Wire Line
	7450 2450 7450 1700
Wire Wire Line
	5350 1700 7450 1700
Connection ~ 7450 1700
Wire Wire Line
	7450 1700 7650 1700
Wire Wire Line
	7050 2450 7050 1800
Connection ~ 7050 1800
Wire Wire Line
	7050 1800 7750 1800
Wire Wire Line
	6650 2450 6650 1900
Connection ~ 6650 1900
Wire Wire Line
	6650 1900 7850 1900
Wire Wire Line
	6250 2450 6250 2000
Wire Wire Line
	5850 2450 5850 2100
Connection ~ 5850 2100
Wire Wire Line
	5850 2100 7750 2100
Wire Wire Line
	5450 2450 5450 2200
Connection ~ 5450 2200
Wire Wire Line
	5450 2200 7650 2200
Wire Notes Line
	4700 3300 9100 3300
Wire Notes Line
	9100 3300 9100 700 
Wire Notes Line
	4700 700  9100 700 
Wire Wire Line
	8250 2150 8750 2150
Wire Wire Line
	7650 1550 7950 1550
Wire Wire Line
	7750 1700 8250 1700
Wire Wire Line
	7950 1850 7850 1850
Connection ~ 6250 2000
Wire Wire Line
	6250 2000 8250 2000
Wire Wire Line
	7950 2150 7750 2150
Wire Wire Line
	7650 2300 8250 2300
Text Notes 4900 3550 0    79   ~ 16
3 different\ncurrent limit\nresistor sizes?
$EndSCHEMATC
