EESchema Schematic File Version 4
LIBS:croptop_rev1-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 4 8
Title "CropTop"
Date ""
Rev "Revision 1"
Comp "University of Idaho"
Comment1 "Designer 1: Kennedy Caisley"
Comment2 "Designer 2: Ryan Donahue"
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	6800 3400 6700 3400
Wire Wire Line
	6800 3300 6700 3300
Wire Wire Line
	6800 3200 6700 3200
Wire Wire Line
	6800 3100 6700 3100
Wire Wire Line
	6800 3000 6700 3000
Wire Wire Line
	6800 2900 6700 2900
Wire Wire Line
	6800 2800 6700 2800
Wire Wire Line
	6800 2700 6700 2700
Wire Wire Line
	6800 2600 6700 2600
Wire Wire Line
	6800 2500 6700 2500
Wire Wire Line
	6800 2400 6700 2400
Wire Wire Line
	6800 2300 6700 2300
Wire Wire Line
	6800 2200 6700 2200
Wire Wire Line
	6800 2100 6700 2100
Wire Wire Line
	6800 2000 6700 2000
Wire Wire Line
	6800 1900 6700 1900
Wire Wire Line
	6800 1800 6700 1800
Wire Wire Line
	6800 1700 6700 1700
Wire Wire Line
	6800 1600 6700 1600
Text GLabel 6800 3400 2    39   Input ~ 0
SRAM_A18
Text GLabel 6800 3300 2    39   Input ~ 0
SRAM_A17
Text GLabel 6800 3200 2    39   Input ~ 0
SRAM_A16
Text GLabel 6800 3100 2    39   Input ~ 0
SRAM_A15
Text GLabel 6800 3000 2    39   Input ~ 0
SRAM_A14
Text GLabel 6800 2900 2    39   Input ~ 0
SRAM_A13
Text GLabel 6800 2800 2    39   Input ~ 0
SRAM_A12
Text GLabel 6800 2700 2    39   Input ~ 0
SRAM_A11
Text GLabel 6800 2600 2    39   Input ~ 0
SRAM_A10
Text GLabel 6800 2500 2    39   Input ~ 0
SRAM_A9
Text GLabel 6800 2400 2    39   Input ~ 0
SRAM_A8
Text GLabel 6800 2300 2    39   Input ~ 0
SRAM_A7
Text GLabel 6800 2200 2    39   Input ~ 0
SRAM_A6
Text GLabel 6800 2100 2    39   Input ~ 0
SRAM_A5
Text GLabel 6800 2000 2    39   Input ~ 0
SRAM_A4
Text GLabel 6800 1900 2    39   Input ~ 0
SRAM_A3
Text GLabel 6800 1800 2    39   Input ~ 0
SRAM_A2
Text GLabel 6800 1700 2    39   Input ~ 0
SRAM_A1
Text GLabel 6800 1600 2    39   Input ~ 0
SRAM_A0
Wire Wire Line
	2900 1600 3400 1600
Text Notes 2450 1100 0    98   ~ 20
TFT LCD Header
Text Notes 5700 900  0    98   ~ 20
Asynchronous SRAM
Text Notes 4650 4700 0    98   ~ 20
Resistive Touch Driver
Wire Wire Line
	7700 5200 7600 5200
Wire Wire Line
	7700 5100 7600 5100
Text GLabel 7600 5200 0    39   Input ~ 0
SCL_1
Text GLabel 7600 5100 0    39   Input ~ 0
SDA_1
Wire Wire Line
	7600 5000 7700 5000
Wire Wire Line
	7600 5800 7600 5900
Wire Wire Line
	7700 5800 7600 5800
Wire Wire Line
	7600 5900 7700 5900
Connection ~ 7600 5900
Wire Wire Line
	7600 6150 7600 5900
Wire Wire Line
	5100 5750 5950 5750
Wire Wire Line
	5100 5750 5100 5800
Wire Wire Line
	5350 5550 5950 5550
Wire Wire Line
	5350 5550 5350 5800
Wire Wire Line
	5600 5350 5950 5350
Wire Wire Line
	5600 5350 5600 5800
Wire Wire Line
	5850 5150 5950 5150
Wire Wire Line
	5850 5150 5850 5800
Connection ~ 5850 5150
Wire Wire Line
	4900 5150 5850 5150
Connection ~ 5600 5350
Wire Wire Line
	4900 5350 5600 5350
Connection ~ 5350 5550
Wire Wire Line
	4900 5550 5350 5550
Connection ~ 5100 5750
Wire Wire Line
	4900 5750 5100 5750
Wire Wire Line
	6300 5550 6250 5550
Wire Wire Line
	6300 5500 6300 5550
Wire Wire Line
	6300 5350 6250 5350
Wire Wire Line
	6300 5400 6300 5350
Wire Wire Line
	6300 5300 7300 5300
Wire Wire Line
	6300 5150 6250 5150
Wire Wire Line
	6300 5300 6300 5150
Wire Wire Line
	6300 5750 6250 5750
Wire Wire Line
	6300 5600 6300 5750
Wire Wire Line
	5100 6150 5100 6100
Wire Wire Line
	5350 6150 5350 6100
Wire Wire Line
	5600 6150 5600 6100
Wire Wire Line
	5850 6150 5850 6100
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C1F
P 5100 6150
AR Path="/65B71C1F" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C1F" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5100 5900 50  0001 C CNN
F 1 "DGND" H 5104 5995 50  0000 C CNN
F 2 "" H 5100 6150 50  0001 C CNN
F 3 "" H 5100 6150 50  0001 C CNN
	1    5100 6150
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C25
P 5350 6150
AR Path="/65B71C25" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C25" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5350 5900 50  0001 C CNN
F 1 "DGND" H 5354 5995 50  0000 C CNN
F 2 "" H 5350 6150 50  0001 C CNN
F 3 "" H 5350 6150 50  0001 C CNN
	1    5350 6150
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C2B
P 5600 6150
AR Path="/65B71C2B" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C2B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5600 5900 50  0001 C CNN
F 1 "DGND" H 5604 5995 50  0000 C CNN
F 2 "" H 5600 6150 50  0001 C CNN
F 3 "" H 5600 6150 50  0001 C CNN
	1    5600 6150
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C31
P 5850 6150
AR Path="/65B71C31" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C31" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5850 5900 50  0001 C CNN
F 1 "DGND" H 5854 5995 50  0000 C CNN
F 2 "" H 5850 6150 50  0001 C CNN
F 3 "" H 5850 6150 50  0001 C CNN
	1    5850 6150
	1    0    0    -1  
$EndComp
$Comp
L Device:D D?
U 1 1 65B71C37
P 5100 5950
AR Path="/65B71C37" Ref="D?"  Part="1" 
AR Path="/65B709D0/65B71C37" Ref="D?"  Part="1" 
F 0 "D?" V 5146 5871 50  0000 R CNN
F 1 "D" V 5055 5871 50  0000 R CNN
F 2 "" H 5100 5950 50  0001 C CNN
F 3 "~" H 5100 5950 50  0001 C CNN
	1    5100 5950
	0    -1   1    0   
$EndComp
$Comp
L Device:D D?
U 1 1 65B71C3E
P 5350 5950
AR Path="/65B71C3E" Ref="D?"  Part="1" 
AR Path="/65B709D0/65B71C3E" Ref="D?"  Part="1" 
F 0 "D?" V 5396 5871 50  0000 R CNN
F 1 "D" V 5305 5871 50  0000 R CNN
F 2 "" H 5350 5950 50  0001 C CNN
F 3 "~" H 5350 5950 50  0001 C CNN
	1    5350 5950
	0    -1   1    0   
$EndComp
$Comp
L Device:D D?
U 1 1 65B71C45
P 5600 5950
AR Path="/65B71C45" Ref="D?"  Part="1" 
AR Path="/65B709D0/65B71C45" Ref="D?"  Part="1" 
F 0 "D?" V 5646 5871 50  0000 R CNN
F 1 "D" V 5555 5871 50  0000 R CNN
F 2 "" H 5600 5950 50  0001 C CNN
F 3 "~" H 5600 5950 50  0001 C CNN
	1    5600 5950
	0    -1   1    0   
$EndComp
Wire Wire Line
	8700 5900 8700 6150
Wire Wire Line
	7300 6050 7300 6150
Wire Wire Line
	7000 6050 7000 6150
Wire Wire Line
	6700 6050 6700 6150
Wire Wire Line
	6400 6050 6400 6150
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C51
P 6400 6150
AR Path="/65B71C51" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C51" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6400 5900 50  0001 C CNN
F 1 "DGND" H 6404 5995 50  0000 C CNN
F 2 "" H 6400 6150 50  0001 C CNN
F 3 "" H 6400 6150 50  0001 C CNN
	1    6400 6150
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C57
P 6700 6150
AR Path="/65B71C57" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C57" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6700 5900 50  0001 C CNN
F 1 "DGND" H 6704 5995 50  0000 C CNN
F 2 "" H 6700 6150 50  0001 C CNN
F 3 "" H 6700 6150 50  0001 C CNN
	1    6700 6150
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C5D
P 7000 6150
AR Path="/65B71C5D" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C5D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7000 5900 50  0001 C CNN
F 1 "DGND" H 7004 5995 50  0000 C CNN
F 2 "" H 7000 6150 50  0001 C CNN
F 3 "" H 7000 6150 50  0001 C CNN
	1    7000 6150
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C63
P 7300 6150
AR Path="/65B71C63" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C63" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7300 5900 50  0001 C CNN
F 1 "DGND" H 7304 5995 50  0000 C CNN
F 2 "" H 7300 6150 50  0001 C CNN
F 3 "" H 7300 6150 50  0001 C CNN
	1    7300 6150
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C69
P 8700 6150
AR Path="/65B71C69" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C69" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8700 5900 50  0001 C CNN
F 1 "DGND" H 8704 5995 50  0000 C CNN
F 2 "" H 8700 6150 50  0001 C CNN
F 3 "" H 8700 6150 50  0001 C CNN
	1    8700 6150
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71C6F
P 7600 6150
AR Path="/65B71C6F" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71C6F" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7600 5900 50  0001 C CNN
F 1 "DGND" H 7604 5995 50  0000 C CNN
F 2 "" H 7600 6150 50  0001 C CNN
F 3 "" H 7600 6150 50  0001 C CNN
	1    7600 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 5600 6400 5600
Wire Wire Line
	6400 5600 7700 5600
Connection ~ 6400 5600
Wire Wire Line
	6400 5750 6400 5600
Wire Wire Line
	6300 5500 6700 5500
Wire Wire Line
	6700 5500 7700 5500
Connection ~ 6700 5500
Wire Wire Line
	6700 5750 6700 5500
Wire Wire Line
	6300 5400 7000 5400
Wire Wire Line
	7000 5400 7700 5400
Connection ~ 7000 5400
Wire Wire Line
	7000 5750 7000 5400
Wire Wire Line
	7300 5750 7300 5300
Connection ~ 7300 5300
Wire Wire Line
	7700 5300 7300 5300
Wire Wire Line
	7700 5700 7650 5700
Text GLabel 7650 5700 0    39   Input ~ 0
RES_INT
$Comp
L Device:R R?
U 1 1 65B71C86
P 6100 5750
AR Path="/65B71C86" Ref="R?"  Part="1" 
AR Path="/65B709D0/65B71C86" Ref="R?"  Part="1" 
F 0 "R?" V 6000 5750 50  0000 C CNN
F 1 "10" V 6100 5750 50  0000 C CNN
F 2 "" V 6030 5750 50  0001 C CNN
F 3 "~" H 6100 5750 50  0001 C CNN
	1    6100 5750
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 65B71C8D
P 6100 5550
AR Path="/65B71C8D" Ref="R?"  Part="1" 
AR Path="/65B709D0/65B71C8D" Ref="R?"  Part="1" 
F 0 "R?" V 6000 5550 50  0000 C CNN
F 1 "10" V 6100 5550 50  0000 C CNN
F 2 "" V 6030 5550 50  0001 C CNN
F 3 "~" H 6100 5550 50  0001 C CNN
	1    6100 5550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 65B71C94
P 6100 5350
AR Path="/65B71C94" Ref="R?"  Part="1" 
AR Path="/65B709D0/65B71C94" Ref="R?"  Part="1" 
F 0 "R?" V 6000 5350 50  0000 C CNN
F 1 "10" V 6100 5350 50  0000 C CNN
F 2 "" V 6030 5350 50  0001 C CNN
F 3 "~" H 6100 5350 50  0001 C CNN
	1    6100 5350
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 65B71C9B
P 6400 5900
AR Path="/65B71C9B" Ref="C?"  Part="1" 
AR Path="/65B709D0/65B71C9B" Ref="C?"  Part="1" 
F 0 "C?" H 6450 6000 50  0000 L CNN
F 1 "0.1uF" H 6450 5800 50  0000 L CNN
F 2 "" H 6438 5750 50  0001 C CNN
F 3 "~" H 6400 5900 50  0001 C CNN
	1    6400 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 65B71CA2
P 6700 5900
AR Path="/65B71CA2" Ref="C?"  Part="1" 
AR Path="/65B709D0/65B71CA2" Ref="C?"  Part="1" 
F 0 "C?" H 6750 6000 50  0000 L CNN
F 1 "0.1uF" H 6750 5800 50  0000 L CNN
F 2 "" H 6738 5750 50  0001 C CNN
F 3 "~" H 6700 5900 50  0001 C CNN
	1    6700 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 65B71CA9
P 7000 5900
AR Path="/65B71CA9" Ref="C?"  Part="1" 
AR Path="/65B709D0/65B71CA9" Ref="C?"  Part="1" 
F 0 "C?" H 7050 6000 50  0000 L CNN
F 1 "0.1uF" H 7050 5800 50  0000 L CNN
F 2 "" H 7038 5750 50  0001 C CNN
F 3 "~" H 7000 5900 50  0001 C CNN
	1    7000 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 65B71CB0
P 6100 5150
AR Path="/65B71CB0" Ref="R?"  Part="1" 
AR Path="/65B709D0/65B71CB0" Ref="R?"  Part="1" 
F 0 "R?" V 6000 5150 50  0000 C CNN
F 1 "10" V 6100 5150 50  0000 C CNN
F 2 "" V 6030 5150 50  0001 C CNN
F 3 "~" H 6100 5150 50  0001 C CNN
	1    6100 5150
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 65B71CB7
P 7300 5900
AR Path="/65B71CB7" Ref="C?"  Part="1" 
AR Path="/65B709D0/65B71CB7" Ref="C?"  Part="1" 
F 0 "C?" H 7350 6000 50  0000 L CNN
F 1 "0.1uF" H 7350 5800 50  0000 L CNN
F 2 "" H 7338 5750 50  0001 C CNN
F 3 "~" H 7300 5900 50  0001 C CNN
	1    7300 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:D D?
U 1 1 65B71CBE
P 5850 5950
AR Path="/65B71CBE" Ref="D?"  Part="1" 
AR Path="/65B709D0/65B71CBE" Ref="D?"  Part="1" 
F 0 "D?" V 5896 5871 50  0000 R CNN
F 1 "D" V 5805 5871 50  0000 R CNN
F 2 "" H 5850 5950 50  0001 C CNN
F 3 "~" H 5850 5950 50  0001 C CNN
	1    5850 5950
	0    -1   1    0   
$EndComp
Text GLabel 4900 5150 0    39   Input ~ 0
TCH_UP
Text GLabel 4900 5550 0    39   Input ~ 0
TCH_LEFT
Text GLabel 4900 5750 0    39   Input ~ 0
TCH_DOWN
Text GLabel 4900 5350 0    39   Input ~ 0
TCH_RIGHT
Wire Wire Line
	8600 5900 8700 5900
Connection ~ 8700 5900
Wire Wire Line
	8700 5800 8700 5900
Wire Wire Line
	8600 5800 8700 5800
NoConn ~ 8600 5000
NoConn ~ 8600 5100
NoConn ~ 8600 5200
NoConn ~ 8600 5300
NoConn ~ 8600 5400
NoConn ~ 8600 5500
NoConn ~ 8600 5600
NoConn ~ 8600 5700
$Comp
L croptop_rev1-rescue:BU21026MUV-E2 U?
U 1 1 65B71CD5
P 8150 5450
AR Path="/65B71CD5" Ref="U?"  Part="1" 
AR Path="/65B709D0/65B71CD5" Ref="U?"  Part="1" 
F 0 "U?" H 8150 6167 50  0000 C CNN
F 1 "BU21026MUV-E2" H 8150 6076 50  0000 C CNN
F 2 "" H 8100 5350 50  0001 C CNN
F 3 "" H 8100 5350 50  0001 C CNN
	1    8150 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 1800 5900 1800
Wire Wire Line
	5800 1700 5900 1700
Wire Wire Line
	5800 1600 5900 1600
Text GLabel 5800 1800 0    39   Input ~ 0
PMPWR
Text GLabel 5800 1600 0    39   Input ~ 0
SRAM_CS
Text GLabel 5800 1700 0    39   Input ~ 0
LCD_CS
Wire Wire Line
	2900 1500 3000 1500
Wire Wire Line
	2900 1400 3000 1400
Wire Wire Line
	3000 4700 2900 4700
Wire Wire Line
	3000 4600 2900 4600
Wire Wire Line
	3000 4500 2900 4500
Wire Wire Line
	2900 4400 3000 4400
Wire Wire Line
	2900 4300 3000 4300
Wire Wire Line
	3500 4200 3500 4300
Wire Wire Line
	2900 4200 3500 4200
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71D09
P 3500 4300
AR Path="/65B71D09" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71D09" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3500 4050 50  0001 C CNN
F 1 "DGND" H 3504 4145 50  0000 C CNN
F 2 "" H 3500 4300 50  0001 C CNN
F 3 "" H 3500 4300 50  0001 C CNN
	1    3500 4300
	1    0    0    -1  
$EndComp
Text GLabel 3000 4400 2    39   Input ~ 0
LCD_RESET
Text GLabel 3000 4500 2    39   Input ~ 0
LCD_HSYNC
Text GLabel 3000 4600 2    39   Input ~ 0
LCD_VSYNC
Text GLabel 3000 4700 2    39   Input ~ 0
LCD_DEN
Wire Wire Line
	3500 4900 3500 5000
Wire Wire Line
	2900 4900 3500 4900
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71D15
P 3500 5000
AR Path="/65B71D15" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71D15" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3500 4750 50  0001 C CNN
F 1 "DGND" H 3504 4845 50  0000 C CNN
F 2 "" H 3500 5000 50  0001 C CNN
F 3 "" H 3500 5000 50  0001 C CNN
	1    3500 5000
	1    0    0    -1  
$EndComp
NoConn ~ 2900 4800
Text GLabel 3000 4300 2    39   Input ~ 0
LCD_SHIFT
Wire Wire Line
	6750 3600 6750 3700
Wire Wire Line
	5850 3600 5850 3700
Wire Wire Line
	5900 3600 5850 3600
Connection ~ 5850 3600
Wire Wire Line
	5850 3500 5850 3600
Wire Wire Line
	5900 3500 5850 3500
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71D23
P 5850 3700
AR Path="/65B71D23" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71D23" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5850 3450 50  0001 C CNN
F 1 "DGND" H 5854 3545 50  0000 C CNN
F 2 "" H 5850 3700 50  0001 C CNN
F 3 "" H 5850 3700 50  0001 C CNN
	1    5850 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3600 6750 3600
Connection ~ 6750 3600
Wire Wire Line
	6750 3500 6750 3600
Wire Wire Line
	6700 3500 6750 3500
Text GLabel 3000 1500 2    39   Input ~ 0
LCD_LED+
Text GLabel 3000 1400 2    39   Input ~ 0
LCD_LED-
Text GLabel 3000 3600 2    39   Input ~ 0
LCD_B5
Text GLabel 3000 3500 2    39   Input ~ 0
LCD_B5
Text GLabel 3000 3400 2    39   Input ~ 0
LCD_B5
Text GLabel 3000 2700 2    39   Input ~ 0
LCD_G6
Text GLabel 3000 2600 2    39   Input ~ 0
LCD_G6
Text GLabel 3000 1900 2    39   Input ~ 0
LCD_R5
Text GLabel 3000 1800 2    39   Input ~ 0
LCD_R5
Text GLabel 3000 2000 2    39   Input ~ 0
LCD_R5
Text GLabel 3000 2400 2    39   Input ~ 0
LCD_R4
Text GLabel 3000 2300 2    39   Input ~ 0
LCD_R3
Text GLabel 3000 2200 2    39   Input ~ 0
LCD_R2
Text GLabel 3000 2100 2    39   Input ~ 0
LCD_R1
Text GLabel 3000 2500 2    39   Input ~ 0
LCD_R5
Text GLabel 3000 3200 2    39   Input ~ 0
LCD_G5
Text GLabel 3000 3100 2    39   Input ~ 0
LCD_G4
Text GLabel 3000 3000 2    39   Input ~ 0
LCD_G3
Text GLabel 3000 2900 2    39   Input ~ 0
LCD_G2
Text GLabel 3000 2800 2    39   Input ~ 0
LCD_G1
Text GLabel 3000 3300 2    39   Input ~ 0
LCD_G6
Text GLabel 3000 4000 2    39   Input ~ 0
LCD_B4
Text GLabel 3000 3900 2    39   Input ~ 0
LCD_B3
Text GLabel 3000 3800 2    39   Input ~ 0
LCD_B2
Text GLabel 3000 3700 2    39   Input ~ 0
LCD_B1
Text GLabel 3000 4100 2    39   Input ~ 0
LCD_B5
Wire Wire Line
	5900 3400 5800 3400
Wire Wire Line
	5900 3300 5800 3300
Wire Wire Line
	5900 3200 5800 3200
Wire Wire Line
	5900 3100 5800 3100
Wire Wire Line
	5900 3000 5800 3000
Wire Wire Line
	5900 2900 5800 2900
Wire Wire Line
	5900 2800 5800 2800
Wire Wire Line
	5900 2700 5800 2700
Wire Wire Line
	5900 2600 5800 2600
Wire Wire Line
	5900 2500 5800 2500
Wire Wire Line
	5900 2400 5800 2400
Wire Wire Line
	5800 2300 5900 2300
Wire Wire Line
	5900 2200 5800 2200
Wire Wire Line
	5900 2100 5800 2100
Wire Wire Line
	5900 2000 5800 2000
Wire Wire Line
	5900 1900 5800 1900
Wire Wire Line
	2900 5300 3000 5300
Wire Wire Line
	2900 5200 3000 5200
Wire Wire Line
	2900 5100 3000 5100
Wire Wire Line
	2900 5000 3000 5000
Text GLabel 3000 5300 2    39   Input ~ 0
TCH_UP
Text GLabel 3000 5200 2    39   Input ~ 0
TCH_LEFT
Text GLabel 3000 5100 2    39   Input ~ 0
TCH_DOWN
Text GLabel 3000 5000 2    39   Input ~ 0
TCH_RIGHT
Wire Wire Line
	2900 2000 3000 2000
Wire Wire Line
	2900 1900 3000 1900
Wire Wire Line
	2900 1800 3000 1800
Wire Wire Line
	2900 2700 3000 2700
Wire Wire Line
	2900 2600 3000 2600
Wire Wire Line
	2900 3600 3000 3600
Wire Wire Line
	2900 3500 3000 3500
Wire Wire Line
	2900 3400 3000 3400
Wire Wire Line
	3000 2500 2900 2500
Wire Wire Line
	3000 2400 2900 2400
Wire Wire Line
	3000 2300 2900 2300
Wire Wire Line
	3000 2200 2900 2200
Wire Wire Line
	3000 2100 2900 2100
Wire Wire Line
	3000 3300 2900 3300
Wire Wire Line
	3000 3200 2900 3200
Wire Wire Line
	3000 3100 2900 3100
Wire Wire Line
	3000 3000 2900 3000
Wire Wire Line
	3000 2900 2900 2900
Wire Wire Line
	3000 2800 2900 2800
Wire Wire Line
	3000 4100 2900 4100
Wire Wire Line
	3000 4000 2900 4000
Wire Wire Line
	3000 3900 2900 3900
Wire Wire Line
	3000 3800 2900 3800
Wire Wire Line
	3000 3700 2900 3700
Text GLabel 5800 3300 0    39   Input ~ 0
LCD_R4
Text GLabel 5800 3200 0    39   Input ~ 0
LCD_R3
Text GLabel 5800 3100 0    39   Input ~ 0
LCD_R2
Text GLabel 5800 3000 0    39   Input ~ 0
LCD_R1
Text GLabel 5800 3400 0    39   Input ~ 0
LCD_R5
Text GLabel 5800 2800 0    39   Input ~ 0
LCD_G5
Text GLabel 5800 2700 0    39   Input ~ 0
LCD_G4
Text GLabel 5800 2600 0    39   Input ~ 0
LCD_G3
Text GLabel 5800 2500 0    39   Input ~ 0
LCD_G2
Text GLabel 5800 2400 0    39   Input ~ 0
LCD_G1
Text GLabel 5800 2900 0    39   Input ~ 0
LCD_G6
Text GLabel 5800 2200 0    39   Input ~ 0
LCD_B4
Text GLabel 5800 2100 0    39   Input ~ 0
LCD_B3
Text GLabel 5800 2000 0    39   Input ~ 0
LCD_B2
Text GLabel 5800 1900 0    39   Input ~ 0
LCD_B1
Text GLabel 5800 2300 0    39   Input ~ 0
LCD_B5
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65B71D87
P 6750 3700
AR Path="/65B71D87" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/65B71D87" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6750 3450 50  0001 C CNN
F 1 "DGND" H 6754 3545 50  0000 C CNN
F 2 "" H 6750 3700 50  0001 C CNN
F 3 "" H 6750 3700 50  0001 C CNN
	1    6750 3700
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:54104-4031 J?
U 1 1 65B71D8D
P 2600 3350
AR Path="/65B71D8D" Ref="J?"  Part="1" 
AR Path="/65B709D0/65B71D8D" Ref="J?"  Part="1" 
F 0 "J?" H 2600 5400 50  0000 C CNN
F 1 "54104-4031" H 2600 1300 50  0000 C CNN
F 2 "" H 2300 4600 50  0001 C CNN
F 3 "" H 2300 4600 50  0001 C CNN
	1    2600 3350
	-1   0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:IS66WV51216EBLL U?
U 1 1 65B71D94
P 6300 2500
AR Path="/65B71D94" Ref="U?"  Part="1" 
AR Path="/65B709D0/65B71D94" Ref="U?"  Part="1" 
F 0 "U?" H 6300 3767 50  0000 C CNN
F 1 "IS66WV51216EBLL" H 6300 3676 50  0000 C CNN
F 2 "" H 6300 2350 50  0001 C CNN
F 3 "" H 6300 2350 50  0001 C CNN
	1    6300 2500
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 6608EE82
P 4400 1650
AR Path="/6608EE82" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/6608EE82" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4400 1500 50  0001 C CNN
F 1 "DVDD" H 4415 1823 50  0000 C CNN
F 2 "" H 4400 1650 50  0001 C CNN
F 3 "" H 4400 1650 50  0001 C CNN
	1    4400 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6608EE88
P 3700 1900
AR Path="/6608EE88" Ref="C?"  Part="1" 
AR Path="/65B709D0/6608EE88" Ref="C?"  Part="1" 
F 0 "C?" H 3750 2000 50  0000 L CNN
F 1 "0.1uF" H 3750 1800 50  0000 L CNN
F 2 "" H 3738 1750 50  0001 C CNN
F 3 "~" H 3700 1900 50  0001 C CNN
	1    3700 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6608EE8F
P 4050 1900
AR Path="/6608EE8F" Ref="C?"  Part="1" 
AR Path="/65B709D0/6608EE8F" Ref="C?"  Part="1" 
F 0 "C?" H 4100 2000 50  0000 L CNN
F 1 "1uF" H 4100 1800 50  0000 L CNN
F 2 "" H 4088 1750 50  0001 C CNN
F 3 "~" H 4050 1900 50  0001 C CNN
	1    4050 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6608EE96
P 4400 1900
AR Path="/6608EE96" Ref="C?"  Part="1" 
AR Path="/65B709D0/6608EE96" Ref="C?"  Part="1" 
F 0 "C?" H 4450 2000 50  0000 L CNN
F 1 "10uF" H 4450 1800 50  0000 L CNN
F 2 "" H 4438 1750 50  0001 C CNN
F 3 "~" H 4400 1900 50  0001 C CNN
	1    4400 1900
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 6608EE9E
P 4400 2150
AR Path="/6608EE9E" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/6608EE9E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4400 1900 50  0001 C CNN
F 1 "DGND" H 4404 1995 50  0000 C CNN
F 2 "" H 4400 2150 50  0001 C CNN
F 3 "" H 4400 2150 50  0001 C CNN
	1    4400 2150
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 6609A00A
P 3400 1800
AR Path="/6609A00A" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/6609A00A" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3400 1550 50  0001 C CNN
F 1 "DGND" H 3404 1645 50  0000 C CNN
F 2 "" H 3400 1800 50  0001 C CNN
F 3 "" H 3400 1800 50  0001 C CNN
	1    3400 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1600 3400 1800
Wire Wire Line
	4400 1700 4400 1650
Wire Wire Line
	2900 1700 3700 1700
Wire Wire Line
	4400 2150 4400 2100
Wire Wire Line
	3700 2100 3700 2050
Wire Wire Line
	4050 2050 4050 2100
Connection ~ 4050 2100
Wire Wire Line
	4050 2100 3700 2100
Wire Wire Line
	4400 2050 4400 2100
Wire Wire Line
	4400 2100 4050 2100
Wire Wire Line
	3700 1750 3700 1700
Connection ~ 3700 1700
Wire Wire Line
	3700 1700 4050 1700
Wire Wire Line
	4050 1750 4050 1700
Connection ~ 4050 1700
Wire Wire Line
	4050 1700 4400 1700
Wire Wire Line
	4400 1750 4400 1700
Connection ~ 4400 2100
Connection ~ 4400 1700
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 661482A8
P 7700 1050
AR Path="/661482A8" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/661482A8" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7700 900 50  0001 C CNN
F 1 "DVDD" H 7715 1223 50  0000 C CNN
F 2 "" H 7700 1050 50  0001 C CNN
F 3 "" H 7700 1050 50  0001 C CNN
	1    7700 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 661482AE
P 7000 1300
AR Path="/661482AE" Ref="C?"  Part="1" 
AR Path="/65B709D0/661482AE" Ref="C?"  Part="1" 
F 0 "C?" H 7050 1400 50  0000 L CNN
F 1 "0.1uF" H 7050 1200 50  0000 L CNN
F 2 "" H 7038 1150 50  0001 C CNN
F 3 "~" H 7000 1300 50  0001 C CNN
	1    7000 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 661482B5
P 7350 1300
AR Path="/661482B5" Ref="C?"  Part="1" 
AR Path="/65B709D0/661482B5" Ref="C?"  Part="1" 
F 0 "C?" H 7400 1400 50  0000 L CNN
F 1 "1uF" H 7400 1200 50  0000 L CNN
F 2 "" H 7388 1150 50  0001 C CNN
F 3 "~" H 7350 1300 50  0001 C CNN
	1    7350 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 661482BC
P 7700 1300
AR Path="/661482BC" Ref="C?"  Part="1" 
AR Path="/65B709D0/661482BC" Ref="C?"  Part="1" 
F 0 "C?" H 7750 1400 50  0000 L CNN
F 1 "10uF" H 7750 1200 50  0000 L CNN
F 2 "" H 7738 1150 50  0001 C CNN
F 3 "~" H 7700 1300 50  0001 C CNN
	1    7700 1300
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 661482C3
P 7700 1550
AR Path="/661482C3" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/661482C3" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7700 1300 50  0001 C CNN
F 1 "DGND" H 7704 1395 50  0000 C CNN
F 2 "" H 7700 1550 50  0001 C CNN
F 3 "" H 7700 1550 50  0001 C CNN
	1    7700 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 1100 7700 1050
Wire Wire Line
	7700 1550 7700 1500
Wire Wire Line
	7000 1500 7000 1450
Wire Wire Line
	7350 1450 7350 1500
Connection ~ 7350 1500
Wire Wire Line
	7350 1500 7000 1500
Wire Wire Line
	7700 1450 7700 1500
Wire Wire Line
	7700 1500 7350 1500
Wire Wire Line
	7000 1150 7000 1100
Connection ~ 7000 1100
Wire Wire Line
	7000 1100 7350 1100
Wire Wire Line
	7350 1150 7350 1100
Connection ~ 7350 1100
Wire Wire Line
	7350 1100 7700 1100
Wire Wire Line
	7700 1150 7700 1100
Connection ~ 7700 1500
Connection ~ 7700 1100
Wire Wire Line
	5900 1500 5850 1500
Wire Wire Line
	5850 1500 5850 1100
Wire Wire Line
	5850 1100 6800 1100
Wire Wire Line
	6700 1500 6800 1500
Wire Wire Line
	6800 1500 6800 1100
Connection ~ 6800 1100
Wire Wire Line
	6800 1100 7000 1100
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 66168E46
P 6650 4500
AR Path="/66168E46" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/66168E46" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6650 4350 50  0001 C CNN
F 1 "DVDD" H 6665 4673 50  0000 C CNN
F 2 "" H 6650 4500 50  0001 C CNN
F 3 "" H 6650 4500 50  0001 C CNN
	1    6650 4500
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 66168E4C
P 7350 4750
AR Path="/66168E4C" Ref="C?"  Part="1" 
AR Path="/65B709D0/66168E4C" Ref="C?"  Part="1" 
F 0 "C?" H 7400 4850 50  0000 L CNN
F 1 "0.1uF" H 7400 4650 50  0000 L CNN
F 2 "" H 7388 4600 50  0001 C CNN
F 3 "~" H 7350 4750 50  0001 C CNN
	1    7350 4750
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 66168E53
P 7000 4750
AR Path="/66168E53" Ref="C?"  Part="1" 
AR Path="/65B709D0/66168E53" Ref="C?"  Part="1" 
F 0 "C?" H 7050 4850 50  0000 L CNN
F 1 "1uF" H 7050 4650 50  0000 L CNN
F 2 "" H 7038 4600 50  0001 C CNN
F 3 "~" H 7000 4750 50  0001 C CNN
	1    7000 4750
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 66168E5A
P 6650 4750
AR Path="/66168E5A" Ref="C?"  Part="1" 
AR Path="/65B709D0/66168E5A" Ref="C?"  Part="1" 
F 0 "C?" H 6700 4850 50  0000 L CNN
F 1 "10uF" H 6700 4650 50  0000 L CNN
F 2 "" H 6688 4600 50  0001 C CNN
F 3 "~" H 6650 4750 50  0001 C CNN
	1    6650 4750
	-1   0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 66168E61
P 6650 5000
AR Path="/66168E61" Ref="#PWR?"  Part="1" 
AR Path="/65B709D0/66168E61" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6650 4750 50  0001 C CNN
F 1 "DGND" H 6654 4845 50  0000 C CNN
F 2 "" H 6650 5000 50  0001 C CNN
F 3 "" H 6650 5000 50  0001 C CNN
	1    6650 5000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6650 4550 6650 4500
Wire Wire Line
	6650 5000 6650 4950
Wire Wire Line
	7350 4950 7350 4900
Wire Wire Line
	7000 4900 7000 4950
Connection ~ 7000 4950
Wire Wire Line
	7000 4950 7350 4950
Wire Wire Line
	6650 4900 6650 4950
Wire Wire Line
	6650 4950 7000 4950
Wire Wire Line
	7350 4600 7350 4550
Wire Wire Line
	7350 4550 7000 4550
Wire Wire Line
	7000 4600 7000 4550
Connection ~ 7000 4550
Wire Wire Line
	7000 4550 6650 4550
Wire Wire Line
	6650 4600 6650 4550
Connection ~ 6650 4950
Connection ~ 6650 4550
Wire Wire Line
	7600 5000 7600 4550
Wire Wire Line
	7600 4550 7350 4550
Connection ~ 7350 4550
Text Notes 7050 6750 0    50   ~ 0
-Pick ESD Diodes\n-Change LCD_LED+ and LCD_LED- to PWR Flags
$EndSCHEMATC
