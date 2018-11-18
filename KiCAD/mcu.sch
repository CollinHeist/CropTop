EESchema Schematic File Version 4
LIBS:croptop_rev1-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 2 8
Title "CropTop"
Date ""
Rev "Revision 1"
Comp "University of Idaho"
Comment1 "Designer 1: Kennedy Caisley"
Comment2 "Designer 2: Ryan Donahue"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x06_Male J?
U 1 1 65F75D3A
P 8450 4850
AR Path="/65F75D3A" Ref="J?"  Part="1" 
AR Path="/64807BBC/65F75D3A" Ref="J?"  Part="1" 
F 0 "J?" H 8600 5200 50  0000 R CNN
F 1 "PICKit Header" H 8850 4450 50  0000 R CNN
F 2 "" H 8450 4850 50  0001 C CNN
F 3 "~" H 8450 4850 50  0001 C CNN
	1    8450 4850
	1    0    0    -1  
$EndComp
Text GLabel 8750 4950 2    39   Input ~ 0
PKT_PGED
Text GLabel 8750 5050 2    39   Input ~ 0
PKT_PGEC
NoConn ~ 8650 5150
Wire Wire Line
	8650 5050 8750 5050
Wire Wire Line
	8650 4950 8750 4950
Text GLabel 9400 4650 2    39   Input ~ 0
PKT_MCLR
Wire Wire Line
	3800 1400 3650 1400
Wire Wire Line
	3650 1400 3650 1450
Text GLabel 5850 1850 2    39   Input ~ 0
SDA_1
Text GLabel 5850 1950 2    39   Input ~ 0
SCL_1
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65F75D8E
P 9300 5100
AR Path="/65F75D8E" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75D8E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 9300 4850 50  0001 C CNN
F 1 "DGND" H 9304 4945 50  0000 C CNN
F 2 "" H 9300 5100 50  0001 C CNN
F 3 "" H 9300 5100 50  0001 C CNN
	1    9300 5100
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65F75DB2
P 3650 1450
AR Path="/65F75DB2" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75DB2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3650 1200 50  0001 C CNN
F 1 "DGND" H 3654 1295 50  0000 C CNN
F 2 "" H 3650 1450 50  0001 C CNN
F 3 "" H 3650 1450 50  0001 C CNN
	1    3650 1450
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 65F75DBE
P 4750 1250
AR Path="/65F75DBE" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75DBE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4750 1100 50  0001 C CNN
F 1 "DVDD" H 4765 1423 50  0000 C CNN
F 2 "" H 4750 1250 50  0001 C CNN
F 3 "" H 4750 1250 50  0001 C CNN
	1    4750 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 1500 4150 1400
Wire Wire Line
	4150 1400 4100 1400
Text GLabel 5500 4800 2    39   Input ~ 0
BTN_A
Text GLabel 5500 4900 2    39   Input ~ 0
BTN_B
Text GLabel 5500 5000 2    39   Input ~ 0
BTN_C
Text GLabel 5500 5100 2    39   Input ~ 0
BTN_D
Text GLabel 5500 4350 2    39   Input ~ 0
LED_A
Text GLabel 5500 4450 2    39   Input ~ 0
LED_B
Text GLabel 5500 4550 2    39   Input ~ 0
LED_C
Text GLabel 5500 4650 2    39   Input ~ 0
LED_D
$Comp
L Device:R R?
U 1 1 65F75DCE
P 5750 1650
AR Path="/65F75DCE" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75DCE" Ref="R?"  Part="1" 
F 0 "R?" H 5810 1650 50  0000 L CNN
F 1 "2.2k" V 5750 1570 50  0000 L CNN
F 2 "" V 5680 1650 50  0001 C CNN
F 3 "~" H 5750 1650 50  0001 C CNN
	1    5750 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 65F75DD5
P 5500 1650
AR Path="/65F75DD5" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75DD5" Ref="R?"  Part="1" 
F 0 "R?" H 5560 1650 50  0000 L CNN
F 1 "2.2k" V 5500 1570 50  0000 L CNN
F 2 "" V 5430 1650 50  0001 C CNN
F 3 "~" H 5500 1650 50  0001 C CNN
	1    5500 1650
	1    0    0    -1  
$EndComp
Text GLabel 5500 6500 2    39   Input ~ 0
PKT_PGED
Text GLabel 5500 6400 2    39   Input ~ 0
PKT_PGEC
Text GLabel 5500 6300 2    39   Input ~ 0
PKT_MCLR
Text GLabel 5500 2450 2    39   Input ~ 0
SCLK_1
Text GLabel 5500 2550 2    39   Input ~ 0
MOSI_1
Text GLabel 6150 2650 2    39   Input ~ 0
MISO_1
$Comp
L Device:C C?
U 1 1 65F75DE2
P 3950 1400
AR Path="/65F75DE2" Ref="C?"  Part="1" 
AR Path="/64807BBC/65F75DE2" Ref="C?"  Part="1" 
F 0 "C?" V 3698 1400 50  0000 C CNN
F 1 "10uF" V 3789 1400 50  0000 C CNN
F 2 "" H 3988 1250 50  0001 C CNN
F 3 "~" H 3950 1400 50  0001 C CNN
	1    3950 1400
	0    1    1    0   
$EndComp
Text GLabel 5500 3750 2    39   Input ~ 0
DRV_IN1
Text GLabel 5500 3850 2    39   Input ~ 0
DRV_IN2
Text GLabel 5500 3950 2    39   Input ~ 0
DRV_FLT
Wire Wire Line
	5400 3750 5500 3750
Wire Wire Line
	5400 3850 5500 3850
Wire Wire Line
	5400 3950 5500 3950
Wire Wire Line
	5400 2350 5500 2350
Wire Wire Line
	5400 2450 5500 2450
Wire Wire Line
	5400 2550 5500 2550
Wire Wire Line
	5500 4650 5400 4650
Wire Wire Line
	5500 4550 5400 4550
Wire Wire Line
	5500 4450 5400 4450
Wire Wire Line
	5500 4350 5400 4350
Wire Wire Line
	5500 4800 5400 4800
Wire Wire Line
	5500 4900 5400 4900
Wire Wire Line
	5500 5000 5400 5000
Wire Wire Line
	5500 5100 5400 5100
Wire Wire Line
	5500 1800 5500 1950
Wire Wire Line
	5500 1950 5850 1950
Wire Wire Line
	5750 1800 5750 1850
Wire Wire Line
	5750 1850 5850 1850
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 65F75DFE
P 5500 1450
AR Path="/65F75DFE" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75DFE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5500 1300 50  0001 C CNN
F 1 "DVDD" H 5515 1623 50  0000 C CNN
F 2 "" H 5500 1450 50  0001 C CNN
F 3 "" H 5500 1450 50  0001 C CNN
	1    5500 1450
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 65F75E04
P 5750 1450
AR Path="/65F75E04" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75E04" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5750 1300 50  0001 C CNN
F 1 "DVDD" H 5765 1623 50  0000 C CNN
F 2 "" H 5750 1450 50  0001 C CNN
F 3 "" H 5750 1450 50  0001 C CNN
	1    5750 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 1500 5500 1450
Wire Wire Line
	5750 1500 5750 1450
Wire Wire Line
	4750 1400 4850 1400
Wire Wire Line
	4850 1400 4850 1500
Connection ~ 4750 1400
Wire Wire Line
	4750 1400 4750 1500
Wire Wire Line
	4750 1400 4650 1400
Wire Wire Line
	4650 1400 4650 1500
Wire Wire Line
	4650 1400 4550 1400
Wire Wire Line
	4350 1400 4350 1500
Connection ~ 4650 1400
Wire Wire Line
	4450 1400 4450 1500
Connection ~ 4450 1400
Wire Wire Line
	4450 1400 4350 1400
Wire Wire Line
	4550 1400 4550 1500
Connection ~ 4550 1400
Wire Wire Line
	4550 1400 4450 1400
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65F75E1B
P 4250 7050
AR Path="/65F75E1B" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75E1B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4250 6800 50  0001 C CNN
F 1 "DGND" H 4254 6895 50  0000 C CNN
F 2 "" H 4250 7050 50  0001 C CNN
F 3 "" H 4250 7050 50  0001 C CNN
	1    4250 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 6950 4350 6950
Wire Wire Line
	4750 6950 4750 6850
Wire Wire Line
	4650 6850 4650 6950
Connection ~ 4650 6950
Wire Wire Line
	4650 6950 4750 6950
Wire Wire Line
	4550 6850 4550 6950
Connection ~ 4550 6950
Wire Wire Line
	4550 6950 4650 6950
Wire Wire Line
	4450 6850 4450 6950
Connection ~ 4450 6950
Wire Wire Line
	4450 6950 4550 6950
Wire Wire Line
	4350 6850 4350 6950
Connection ~ 4350 6950
Wire Wire Line
	4350 6950 4450 6950
Wire Wire Line
	4250 6850 4250 6950
Wire Wire Line
	4250 7050 4250 6950
Connection ~ 4250 6950
Wire Wire Line
	5400 6300 5500 6300
Wire Wire Line
	5500 6400 5400 6400
Wire Wire Line
	5500 6500 5400 6500
$Comp
L croptop_rev1-rescue:PIC32MX795F512L U?
U 1 1 65F75E35
P 4500 4150
AR Path="/65F75E35" Ref="U?"  Part="1" 
AR Path="/64807BBC/65F75E35" Ref="U?"  Part="1" 
F 0 "U?" H 4500 4150 50  0000 C CNN
F 1 "PIC32MX795F512L" H 4500 4050 50  0000 C CNN
F 2 "MODULE" H 4500 4150 50  0001 C CNN
F 3 "DOCUMENTATION" H 4500 4150 50  0001 C CNN
	1    4500 4150
	1    0    0    -1  
$EndComp
Text GLabel 3500 4000 0    39   Input ~ 0
SRAM_CS
NoConn ~ 5400 5650
NoConn ~ 5400 5550
NoConn ~ 5400 5450
NoConn ~ 5400 5250
Text GLabel 1900 4300 0    39   Input ~ 0
LCD_CS
Text GLabel 3500 4250 0    39   Input ~ 0
BLK_PWM
Text GLabel 1900 4600 0    39   Input ~ 0
LCD_SHIFT
Text GLabel 1900 4750 0    39   Input ~ 0
LCD_DEN
Text GLabel 1900 4150 0    39   Input ~ 0
LCD_VSYNC
Text GLabel 1900 4000 0    39   Input ~ 0
LCD_HSYNC
Text GLabel 1900 4450 0    39   Input ~ 0
LCD_RESET
Wire Wire Line
	3500 4250 3600 4250
Text GLabel 3500 4100 0    39   Input ~ 0
PMPWR
Wire Wire Line
	3500 4000 3600 4000
Wire Wire Line
	3500 4100 3600 4100
Text GLabel 5500 2100 2    39   Input ~ 0
ROT_Y1
Text GLabel 5500 2200 2    39   Input ~ 0
ROT_Y2
Wire Wire Line
	5400 2100 5500 2100
Wire Wire Line
	5400 2200 5500 2200
Text GLabel 5500 2350 2    39   Input ~ 0
NAND_CS
Wire Wire Line
	5400 1850 5750 1850
Connection ~ 5750 1850
Wire Wire Line
	5400 1950 5500 1950
Connection ~ 5500 1950
$Comp
L Device:Crystal Y?
U 1 1 65F75E60
P 6450 4150
AR Path="/65F75E60" Ref="Y?"  Part="1" 
AR Path="/64807BBC/65F75E60" Ref="Y?"  Part="1" 
F 0 "Y?" V 6404 4281 50  0000 L CNN
F 1 "CXO" V 6495 4281 50  0000 L CNN
F 2 "" H 6450 4150 50  0001 C CNN
F 3 "~" H 6450 4150 50  0001 C CNN
	1    6450 4150
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 65F75E67
P 6450 4550
AR Path="/65F75E67" Ref="C?"  Part="1" 
AR Path="/64807BBC/65F75E67" Ref="C?"  Part="1" 
F 0 "C?" H 6565 4596 50  0000 L CNN
F 1 "18pF" H 6565 4505 50  0000 L CNN
F 2 "" H 6488 4400 50  0001 C CNN
F 3 "~" H 6450 4550 50  0001 C CNN
	1    6450 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 65F75E6E
P 6850 4550
AR Path="/65F75E6E" Ref="C?"  Part="1" 
AR Path="/64807BBC/65F75E6E" Ref="C?"  Part="1" 
F 0 "C?" H 6965 4596 50  0000 L CNN
F 1 "18pF" H 6965 4505 50  0000 L CNN
F 2 "" H 6888 4400 50  0001 C CNN
F 3 "~" H 6850 4550 50  0001 C CNN
	1    6850 4550
	1    0    0    -1  
$EndComp
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65F75E75
P 6850 4750
AR Path="/65F75E75" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75E75" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6850 4500 50  0001 C CNN
F 1 "DGND" H 6854 4595 50  0000 C CNN
F 2 "" H 6850 4750 50  0001 C CNN
F 3 "" H 6850 4750 50  0001 C CNN
	1    6850 4750
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_A J?
U 1 1 65F75E7B
P 8525 2000
AR Path="/65F75E7B" Ref="J?"  Part="1" 
AR Path="/64807BBC/65F75E7B" Ref="J?"  Part="1" 
F 0 "J?" H 8580 2467 50  0000 C CNN
F 1 "USB_A" H 8580 2376 50  0000 C CNN
F 2 "" H 8675 1950 50  0001 C CNN
F 3 " ~" H 8675 1950 50  0001 C CNN
	1    8525 2000
	1    0    0    -1  
$EndComp
Text GLabel 5500 3600 2    39   Input ~ 0
LIN_VOLT
Wire Wire Line
	5400 3600 5500 3600
NoConn ~ 5400 3450
Text GLabel 5500 3050 2    39   Input ~ 0
USB_D+
Text GLabel 5500 3150 2    39   Input ~ 0
USB_D-
Wire Wire Line
	5400 3050 5500 3050
Wire Wire Line
	5400 3150 5500 3150
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65F75E89
P 8475 2500
AR Path="/65F75E89" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75E89" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8475 2250 50  0001 C CNN
F 1 "DGND" H 8479 2345 50  0000 C CNN
F 2 "" H 8475 2500 50  0001 C CNN
F 3 "" H 8475 2500 50  0001 C CNN
	1    8475 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8425 2400 8425 2450
Wire Wire Line
	8425 2450 8475 2450
Wire Wire Line
	8475 2450 8475 2500
Wire Wire Line
	8475 2450 8525 2450
Wire Wire Line
	8525 2450 8525 2400
Connection ~ 8475 2450
Text GLabel 8925 2000 2    39   Input ~ 0
USB_D+
Text GLabel 8925 2100 2    39   Input ~ 0
USB_D-
Wire Wire Line
	8825 2000 8925 2000
Wire Wire Line
	8825 2100 8925 2100
Text GLabel 5500 5350 2    39   Input ~ 0
RES_INT
Wire Wire Line
	5400 5350 5500 5350
Text GLabel 5500 6050 2    39   Input ~ 0
NAND_HOLD
Text GLabel 5500 6150 2    39   Input ~ 0
NAND_WP
Wire Wire Line
	5400 6050 5500 6050
Wire Wire Line
	5400 6150 5500 6150
Text GLabel 5500 5950 2    39   Input ~ 0
GPS_TX
Text GLabel 5500 5850 2    39   Input ~ 0
GPS_RX
Wire Wire Line
	5400 5850 5500 5850
Wire Wire Line
	5400 5950 5500 5950
Text Notes 7825 1400 0    98   ~ 20
Peripheral USB Port
Text Notes 3700 925  0    98   ~ 20
PIC32 Microcontroller
Text GLabel 1400 5700 0    39   Input ~ 0
LCD_B5
Text GLabel 1400 5100 0    39   Input ~ 0
LCD_B1
Text GLabel 1400 5250 0    39   Input ~ 0
LCD_B2
Text GLabel 1400 5400 0    39   Input ~ 0
LCD_B3
Text GLabel 1400 5550 0    39   Input ~ 0
LCD_B4
Text GLabel 1400 6600 0    39   Input ~ 0
LCD_G6
Text GLabel 1400 5850 0    39   Input ~ 0
LCD_G1
Text GLabel 1400 6000 0    39   Input ~ 0
LCD_G2
Text GLabel 1400 6150 0    39   Input ~ 0
LCD_G3
Text GLabel 1400 6300 0    39   Input ~ 0
LCD_G4
Text GLabel 1400 6450 0    39   Input ~ 0
LCD_G5
Text GLabel 1400 7350 0    39   Input ~ 0
LCD_R5
Text GLabel 1400 6750 0    39   Input ~ 0
LCD_R1
Text GLabel 1400 6900 0    39   Input ~ 0
LCD_R2
Text GLabel 1400 7050 0    39   Input ~ 0
LCD_R3
Text GLabel 1400 7200 0    39   Input ~ 0
LCD_R4
$Comp
L Device:C C?
U 1 1 65F75EDB
P 9300 4850
AR Path="/65F75EDB" Ref="C?"  Part="1" 
AR Path="/64807BBC/65F75EDB" Ref="C?"  Part="1" 
F 0 "C?" H 9415 4896 50  0000 L CNN
F 1 "0.1uF" H 9415 4805 50  0000 L CNN
F 2 "" H 9338 4700 50  0001 C CNN
F 3 "~" H 9300 4850 50  0001 C CNN
	1    9300 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 4850 9150 4850
Wire Wire Line
	9150 5050 9300 5050
Wire Wire Line
	9300 4650 9300 4700
Connection ~ 9300 4650
Wire Wire Line
	9300 5100 9300 5050
Wire Wire Line
	9300 5000 9300 5050
Connection ~ 9300 5050
Wire Wire Line
	8650 4650 9300 4650
$Comp
L Device:R R?
U 1 1 65F75EEB
P 9000 4550
AR Path="/65F75EEB" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75EEB" Ref="R?"  Part="1" 
F 0 "R?" V 9100 4500 50  0000 L CNN
F 1 "10k" V 8995 4480 50  0000 L CNN
F 2 "" V 8930 4550 50  0001 C CNN
F 3 "~" H 9000 4550 50  0001 C CNN
	1    9000 4550
	0    -1   -1   0   
$EndComp
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 65F75EF2
P 8750 4500
AR Path="/65F75EF2" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75EF2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8750 4350 50  0001 C CNN
F 1 "DVDD" H 8765 4673 50  0000 C CNN
F 2 "" H 8750 4500 50  0001 C CNN
F 3 "" H 8750 4500 50  0001 C CNN
	1    8750 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 4750 8750 4750
Wire Wire Line
	8750 4750 8750 4550
Wire Wire Line
	9300 4650 9400 4650
Text Notes 9650 4925 0    50   ~ 0
Possibly\nD.N.P.
$Comp
L Device:R R?
U 1 1 65F75EFC
P 6150 3950
AR Path="/65F75EFC" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75EFC" Ref="R?"  Part="1" 
F 0 "R?" V 6075 3950 50  0000 C CNN
F 1 "0" V 6150 3950 50  0000 C CNN
F 2 "" V 6080 3950 50  0001 C CNN
F 3 "~" H 6150 3950 50  0001 C CNN
	1    6150 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	6450 3950 6450 4000
$Comp
L croptop_rev1-rescue:DGND-croptop #PWR?
U 1 1 65F75F0A
P 6450 4750
AR Path="/65F75F0A" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75F0A" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6450 4500 50  0001 C CNN
F 1 "DGND" H 6454 4595 50  0000 C CNN
F 2 "" H 6450 4750 50  0001 C CNN
F 3 "" H 6450 4750 50  0001 C CNN
	1    6450 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4700 6450 4750
Wire Wire Line
	6850 3950 6850 4400
Wire Wire Line
	6850 4700 6850 4750
Wire Wire Line
	6450 3950 6850 3950
Text GLabel 8925 1800 2    39   Input ~ 0
VBUS
Wire Wire Line
	8825 1800 8925 1800
Text GLabel 5500 3350 2    39   Input ~ 0
VBUS
Wire Wire Line
	5400 3350 5500 3350
$Comp
L Device:R R?
U 1 1 65F75F1B
P 5900 3250
AR Path="/65F75F1B" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75F1B" Ref="R?"  Part="1" 
F 0 "R?" V 5825 3250 50  0000 C CNN
F 1 "0" V 5900 3250 50  0000 C CNN
F 2 "" V 5830 3250 50  0001 C CNN
F 3 "~" H 5900 3250 50  0001 C CNN
	1    5900 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 3250 5750 3250
$Comp
L croptop_rev1-rescue:DVDD-croptop #PWR?
U 1 1 65F75F23
P 6150 3150
AR Path="/65F75F23" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/65F75F23" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6150 3000 50  0001 C CNN
F 1 "DVDD" H 6165 3323 50  0000 C CNN
F 2 "" H 6150 3150 50  0001 C CNN
F 3 "" H 6150 3150 50  0001 C CNN
	1    6150 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 3250 6150 3250
Wire Wire Line
	6150 3150 6150 3250
Wire Wire Line
	4750 1250 4750 1400
Wire Wire Line
	4350 1400 4250 1400
Wire Wire Line
	4250 1400 4250 1500
Connection ~ 4350 1400
Wire Wire Line
	9150 4550 9300 4550
Wire Wire Line
	9300 4550 9300 4650
Wire Wire Line
	8850 4550 8750 4550
Wire Wire Line
	8750 4500 8750 4550
Connection ~ 8750 4550
NoConn ~ 5400 2800
NoConn ~ 5400 2900
$Comp
L Device:R R?
U 1 1 65F75F3A
P 5900 2650
AR Path="/65F75F3A" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75F3A" Ref="R?"  Part="1" 
F 0 "R?" V 5800 2650 50  0000 C CNN
F 1 "10" V 5900 2650 50  0000 C CNN
F 2 "" V 5830 2650 50  0001 C CNN
F 3 "~" H 5900 2650 50  0001 C CNN
	1    5900 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 2650 5750 2650
Wire Wire Line
	6050 2650 6150 2650
Text GLabel 5500 5750 2    39   Input ~ 0
GPS_INT
Wire Wire Line
	5400 5750 5500 5750
Text GLabel 3500 1850 0    39   Input ~ 0
SRAM_A0
Text GLabel 3500 1950 0    39   Input ~ 0
SRAM_A1
Text GLabel 3500 2050 0    39   Input ~ 0
SRAM_A2
Text GLabel 3500 2150 0    39   Input ~ 0
SRAM_A3
Text GLabel 3500 2250 0    39   Input ~ 0
SRAM_A4
Text GLabel 3500 2350 0    39   Input ~ 0
SRAM_A5
Text GLabel 3500 2450 0    39   Input ~ 0
SRAM_A6
Text GLabel 3500 2550 0    39   Input ~ 0
SRAM_A7
Text GLabel 3500 2650 0    39   Input ~ 0
SRAM_A8
Text GLabel 3500 2750 0    39   Input ~ 0
SRAM_A9
Text GLabel 3500 2850 0    39   Input ~ 0
SRAM_A10
Text GLabel 3500 2950 0    39   Input ~ 0
SRAM_A11
Text GLabel 3500 3050 0    39   Input ~ 0
SRAM_A12
Text GLabel 3500 3150 0    39   Input ~ 0
SRAM_A13
Text GLabel 3500 3250 0    39   Input ~ 0
SRAM_A14
Text GLabel 3500 3350 0    39   Input ~ 0
SRAM_A15
Text GLabel 3500 3450 0    39   Input ~ 0
SRAM_A16
Text GLabel 3500 3550 0    39   Input ~ 0
SRAM_A17
Text GLabel 3500 3650 0    39   Input ~ 0
SRAM_A18
Wire Wire Line
	3500 1850 3600 1850
Wire Wire Line
	3500 1950 3600 1950
Wire Wire Line
	3500 2050 3600 2050
Wire Wire Line
	3500 2150 3600 2150
Wire Wire Line
	3500 2250 3600 2250
Wire Wire Line
	3500 2350 3600 2350
Wire Wire Line
	3500 2450 3600 2450
Wire Wire Line
	3500 2550 3600 2550
Wire Wire Line
	3500 2650 3600 2650
Wire Wire Line
	3500 2750 3600 2750
Wire Wire Line
	3500 2850 3600 2850
Wire Wire Line
	3500 2950 3600 2950
Wire Wire Line
	3500 3050 3600 3050
Wire Wire Line
	3500 3150 3600 3150
Wire Wire Line
	3500 3250 3600 3250
Wire Wire Line
	3500 3350 3600 3350
Wire Wire Line
	3500 3450 3600 3450
Wire Wire Line
	3500 3550 3600 3550
Wire Wire Line
	3500 3650 3600 3650
$Comp
L Device:R R?
U 1 1 661B8915
P 2350 4000
AR Path="/661B8915" Ref="R?"  Part="1" 
AR Path="/64807BBC/661B8915" Ref="R?"  Part="1" 
F 0 "R?" V 2275 4000 50  0000 C CNN
F 1 "10" V 2350 4000 50  0000 C CNN
F 2 "" V 2280 4000 50  0001 C CNN
F 3 "~" H 2350 4000 50  0001 C CNN
	1    2350 4000
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661B89EC
P 2150 4150
AR Path="/661B89EC" Ref="R?"  Part="1" 
AR Path="/64807BBC/661B89EC" Ref="R?"  Part="1" 
F 0 "R?" V 2075 4150 50  0000 C CNN
F 1 "10" V 2150 4150 50  0000 C CNN
F 2 "" V 2080 4150 50  0001 C CNN
F 3 "~" H 2150 4150 50  0001 C CNN
	1    2150 4150
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661B8A24
P 2350 4300
AR Path="/661B8A24" Ref="R?"  Part="1" 
AR Path="/64807BBC/661B8A24" Ref="R?"  Part="1" 
F 0 "R?" V 2275 4300 50  0000 C CNN
F 1 "10" V 2350 4300 50  0000 C CNN
F 2 "" V 2280 4300 50  0001 C CNN
F 3 "~" H 2350 4300 50  0001 C CNN
	1    2350 4300
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661B8B73
P 2150 4450
AR Path="/661B8B73" Ref="R?"  Part="1" 
AR Path="/64807BBC/661B8B73" Ref="R?"  Part="1" 
F 0 "R?" V 2075 4450 50  0000 C CNN
F 1 "10" V 2150 4450 50  0000 C CNN
F 2 "" V 2080 4450 50  0001 C CNN
F 3 "~" H 2150 4450 50  0001 C CNN
	1    2150 4450
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661B8B7A
P 2350 4600
AR Path="/661B8B7A" Ref="R?"  Part="1" 
AR Path="/64807BBC/661B8B7A" Ref="R?"  Part="1" 
F 0 "R?" V 2275 4600 50  0000 C CNN
F 1 "10" V 2350 4600 50  0000 C CNN
F 2 "" V 2280 4600 50  0001 C CNN
F 3 "~" H 2350 4600 50  0001 C CNN
	1    2350 4600
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661BE50D
P 2150 4750
AR Path="/661BE50D" Ref="R?"  Part="1" 
AR Path="/64807BBC/661BE50D" Ref="R?"  Part="1" 
F 0 "R?" V 2075 4750 50  0000 C CNN
F 1 "10" V 2150 4750 50  0000 C CNN
F 2 "" V 2080 4750 50  0001 C CNN
F 3 "~" H 2150 4750 50  0001 C CNN
	1    2150 4750
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661BE514
P 1650 5100
AR Path="/661BE514" Ref="R?"  Part="1" 
AR Path="/64807BBC/661BE514" Ref="R?"  Part="1" 
F 0 "R?" V 1575 5100 50  0000 C CNN
F 1 "10" V 1650 5100 50  0000 C CNN
F 2 "" V 1580 5100 50  0001 C CNN
F 3 "~" H 1650 5100 50  0001 C CNN
	1    1650 5100
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661BE51B
P 1850 5250
AR Path="/661BE51B" Ref="R?"  Part="1" 
AR Path="/64807BBC/661BE51B" Ref="R?"  Part="1" 
F 0 "R?" V 1775 5250 50  0000 C CNN
F 1 "10" V 1850 5250 50  0000 C CNN
F 2 "" V 1780 5250 50  0001 C CNN
F 3 "~" H 1850 5250 50  0001 C CNN
	1    1850 5250
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661BE522
P 1650 5400
AR Path="/661BE522" Ref="R?"  Part="1" 
AR Path="/64807BBC/661BE522" Ref="R?"  Part="1" 
F 0 "R?" V 1575 5400 50  0000 C CNN
F 1 "10" V 1650 5400 50  0000 C CNN
F 2 "" V 1580 5400 50  0001 C CNN
F 3 "~" H 1650 5400 50  0001 C CNN
	1    1650 5400
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661C982E
P 1850 5550
AR Path="/661C982E" Ref="R?"  Part="1" 
AR Path="/64807BBC/661C982E" Ref="R?"  Part="1" 
F 0 "R?" V 1775 5550 50  0000 C CNN
F 1 "10" V 1850 5550 50  0000 C CNN
F 2 "" V 1780 5550 50  0001 C CNN
F 3 "~" H 1850 5550 50  0001 C CNN
	1    1850 5550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661C9835
P 1650 5700
AR Path="/661C9835" Ref="R?"  Part="1" 
AR Path="/64807BBC/661C9835" Ref="R?"  Part="1" 
F 0 "R?" V 1575 5700 50  0000 C CNN
F 1 "10" V 1650 5700 50  0000 C CNN
F 2 "" V 1580 5700 50  0001 C CNN
F 3 "~" H 1650 5700 50  0001 C CNN
	1    1650 5700
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661C983C
P 1850 5850
AR Path="/661C983C" Ref="R?"  Part="1" 
AR Path="/64807BBC/661C983C" Ref="R?"  Part="1" 
F 0 "R?" V 1775 5850 50  0000 C CNN
F 1 "10" V 1850 5850 50  0000 C CNN
F 2 "" V 1780 5850 50  0001 C CNN
F 3 "~" H 1850 5850 50  0001 C CNN
	1    1850 5850
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661C9843
P 1650 6000
AR Path="/661C9843" Ref="R?"  Part="1" 
AR Path="/64807BBC/661C9843" Ref="R?"  Part="1" 
F 0 "R?" V 1575 6000 50  0000 C CNN
F 1 "10" V 1650 6000 50  0000 C CNN
F 2 "" V 1580 6000 50  0001 C CNN
F 3 "~" H 1650 6000 50  0001 C CNN
	1    1650 6000
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661C984A
P 1850 6150
AR Path="/661C984A" Ref="R?"  Part="1" 
AR Path="/64807BBC/661C984A" Ref="R?"  Part="1" 
F 0 "R?" V 1775 6150 50  0000 C CNN
F 1 "10" V 1850 6150 50  0000 C CNN
F 2 "" V 1780 6150 50  0001 C CNN
F 3 "~" H 1850 6150 50  0001 C CNN
	1    1850 6150
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661C9851
P 1650 6300
AR Path="/661C9851" Ref="R?"  Part="1" 
AR Path="/64807BBC/661C9851" Ref="R?"  Part="1" 
F 0 "R?" V 1575 6300 50  0000 C CNN
F 1 "10" V 1650 6300 50  0000 C CNN
F 2 "" V 1580 6300 50  0001 C CNN
F 3 "~" H 1650 6300 50  0001 C CNN
	1    1650 6300
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661C9858
P 1850 6450
AR Path="/661C9858" Ref="R?"  Part="1" 
AR Path="/64807BBC/661C9858" Ref="R?"  Part="1" 
F 0 "R?" V 1775 6450 50  0000 C CNN
F 1 "10" V 1850 6450 50  0000 C CNN
F 2 "" V 1780 6450 50  0001 C CNN
F 3 "~" H 1850 6450 50  0001 C CNN
	1    1850 6450
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661D5A86
P 1650 6600
AR Path="/661D5A86" Ref="R?"  Part="1" 
AR Path="/64807BBC/661D5A86" Ref="R?"  Part="1" 
F 0 "R?" V 1575 6600 50  0000 C CNN
F 1 "10" V 1650 6600 50  0000 C CNN
F 2 "" V 1580 6600 50  0001 C CNN
F 3 "~" H 1650 6600 50  0001 C CNN
	1    1650 6600
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661D5A8D
P 1850 6750
AR Path="/661D5A8D" Ref="R?"  Part="1" 
AR Path="/64807BBC/661D5A8D" Ref="R?"  Part="1" 
F 0 "R?" V 1775 6750 50  0000 C CNN
F 1 "10" V 1850 6750 50  0000 C CNN
F 2 "" V 1780 6750 50  0001 C CNN
F 3 "~" H 1850 6750 50  0001 C CNN
	1    1850 6750
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661D5A94
P 1650 6900
AR Path="/661D5A94" Ref="R?"  Part="1" 
AR Path="/64807BBC/661D5A94" Ref="R?"  Part="1" 
F 0 "R?" V 1575 6900 50  0000 C CNN
F 1 "10" V 1650 6900 50  0000 C CNN
F 2 "" V 1580 6900 50  0001 C CNN
F 3 "~" H 1650 6900 50  0001 C CNN
	1    1650 6900
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661D5A9B
P 1850 7050
AR Path="/661D5A9B" Ref="R?"  Part="1" 
AR Path="/64807BBC/661D5A9B" Ref="R?"  Part="1" 
F 0 "R?" V 1775 7050 50  0000 C CNN
F 1 "10" V 1850 7050 50  0000 C CNN
F 2 "" V 1780 7050 50  0001 C CNN
F 3 "~" H 1850 7050 50  0001 C CNN
	1    1850 7050
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661D5AA2
P 1650 7200
AR Path="/661D5AA2" Ref="R?"  Part="1" 
AR Path="/64807BBC/661D5AA2" Ref="R?"  Part="1" 
F 0 "R?" V 1575 7200 50  0000 C CNN
F 1 "10" V 1650 7200 50  0000 C CNN
F 2 "" V 1580 7200 50  0001 C CNN
F 3 "~" H 1650 7200 50  0001 C CNN
	1    1650 7200
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 661D5AA9
P 1850 7350
AR Path="/661D5AA9" Ref="R?"  Part="1" 
AR Path="/64807BBC/661D5AA9" Ref="R?"  Part="1" 
F 0 "R?" V 1775 7350 50  0000 C CNN
F 1 "10" V 1850 7350 50  0000 C CNN
F 2 "" V 1780 7350 50  0001 C CNN
F 3 "~" H 1850 7350 50  0001 C CNN
	1    1850 7350
	0    1    1    0   
$EndComp
Wire Wire Line
	2300 5550 2300 5300
Wire Wire Line
	2400 5700 2400 5400
Wire Wire Line
	2500 5850 2500 5500
Wire Wire Line
	2600 6000 2600 5600
Wire Wire Line
	2700 6150 2700 5700
Wire Wire Line
	2800 6300 2800 5800
Wire Wire Line
	2900 6450 2900 5900
Wire Wire Line
	3000 6600 3000 6000
Wire Wire Line
	3100 6750 3100 6100
Wire Wire Line
	3200 6900 3200 6200
Wire Wire Line
	3300 7050 3300 6300
Wire Wire Line
	3400 7200 3400 6400
Wire Wire Line
	3500 7350 3500 6500
Wire Wire Line
	3500 6500 3600 6500
Wire Wire Line
	3400 6400 3600 6400
Wire Wire Line
	3300 6300 3600 6300
Wire Wire Line
	3200 6200 3600 6200
Wire Wire Line
	3100 6100 3600 6100
Wire Wire Line
	3000 6000 3600 6000
Wire Wire Line
	2900 5900 3600 5900
Wire Wire Line
	2800 5800 3600 5800
Wire Wire Line
	2700 5700 3600 5700
Wire Wire Line
	2200 5400 2200 5200
Wire Wire Line
	2100 5250 2100 5100
Wire Wire Line
	2000 5100 2000 5000
Wire Wire Line
	2000 5000 3600 5000
Wire Wire Line
	2100 5100 3600 5100
Wire Wire Line
	2200 5200 3600 5200
Wire Wire Line
	2300 5300 3600 5300
Wire Wire Line
	2400 5400 3600 5400
Wire Wire Line
	2500 5500 3600 5500
Wire Wire Line
	2600 5600 3600 5600
Wire Wire Line
	2000 7350 3500 7350
Wire Wire Line
	1800 7200 3400 7200
Wire Wire Line
	1400 5100 1500 5100
Wire Wire Line
	1800 5100 2000 5100
Wire Wire Line
	2100 5250 2000 5250
Wire Wire Line
	1700 5250 1400 5250
Wire Wire Line
	1500 5400 1400 5400
Wire Wire Line
	1800 5400 2200 5400
Wire Wire Line
	2000 5550 2300 5550
Wire Wire Line
	1700 5550 1400 5550
Wire Wire Line
	1400 5700 1500 5700
Wire Wire Line
	1800 5700 2400 5700
Wire Wire Line
	2000 5850 2500 5850
Wire Wire Line
	1700 5850 1400 5850
Wire Wire Line
	1500 6000 1400 6000
Wire Wire Line
	1800 6000 2600 6000
Wire Wire Line
	2000 6150 2700 6150
Wire Wire Line
	1700 6150 1400 6150
Wire Wire Line
	1500 6300 1400 6300
Wire Wire Line
	1800 6300 2800 6300
Wire Wire Line
	2000 6450 2900 6450
Wire Wire Line
	1700 6450 1400 6450
Wire Wire Line
	1500 6600 1400 6600
Wire Wire Line
	1800 6600 3000 6600
Wire Wire Line
	2000 6750 3100 6750
Wire Wire Line
	1700 6750 1400 6750
Wire Wire Line
	1400 6900 1500 6900
Wire Wire Line
	1800 6900 3200 6900
Wire Wire Line
	2000 7050 3300 7050
Wire Wire Line
	1700 7050 1400 7050
Wire Wire Line
	1500 7200 1400 7200
Wire Wire Line
	1400 7350 1700 7350
Wire Wire Line
	2500 4850 2500 4750
Wire Wire Line
	2500 4750 2300 4750
Wire Wire Line
	2600 4750 2600 4600
Wire Wire Line
	2600 4600 2500 4600
Wire Wire Line
	2700 4650 2700 4450
Wire Wire Line
	2700 4450 2300 4450
Wire Wire Line
	2800 4550 2800 4300
Wire Wire Line
	2800 4300 2500 4300
Wire Wire Line
	2900 4450 2900 4150
Wire Wire Line
	2900 4150 2300 4150
Wire Wire Line
	3000 4350 3000 4000
Wire Wire Line
	3000 4000 2500 4000
Wire Wire Line
	2200 4000 1900 4000
Wire Wire Line
	1900 4150 2000 4150
Wire Wire Line
	2200 4300 1900 4300
Wire Wire Line
	1900 4450 2000 4450
Wire Wire Line
	2200 4600 1900 4600
Wire Wire Line
	1900 4750 2000 4750
Wire Wire Line
	3000 4350 3600 4350
Wire Wire Line
	3600 4450 2900 4450
Wire Wire Line
	2800 4550 3600 4550
Wire Wire Line
	3600 4650 2700 4650
Wire Wire Line
	2600 4750 3600 4750
Wire Wire Line
	3600 4850 2500 4850
Wire Wire Line
	5400 4100 5900 4100
Wire Wire Line
	5900 4100 5900 3950
Wire Wire Line
	5900 3950 6000 3950
Wire Wire Line
	6300 3950 6450 3950
Connection ~ 6450 3950
Wire Wire Line
	6450 4300 6450 4350
Wire Wire Line
	6450 4350 5900 4350
Wire Wire Line
	5900 4350 5900 4200
Wire Wire Line
	5900 4200 5400 4200
Connection ~ 6450 4350
Wire Wire Line
	6450 4350 6450 4400
Text Notes 6950 4400 0    50   ~ 0
Consider increasing caps\nto compensate for \nstray capacitance
Text Notes 8500 4200 0    98   ~ 20
PICKit3 Header
Wire Wire Line
	9150 4850 9150 5050
Wire Notes Line
	5700 4300 5750 4300
Wire Notes Line
	5750 4300 5750 5150
Wire Notes Line
	5750 5150 5700 5150
Text Notes 5800 4750 0    50   ~ 0
Temporary
$EndSCHEMATC
