EESchema Schematic File Version 4
LIBS:croptop_rev1-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 4 6
Title "CropTop"
Date "2018-11-20"
Rev "Revision 8"
Comp "University of Idaho"
Comment1 "Kennedy Caisley, Ryan Donahue"
Comment2 "Designer 2: Ryan Donahue"
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	7900 3300 7800 3300
Wire Wire Line
	7900 3200 7800 3200
Wire Wire Line
	7900 3100 7800 3100
Wire Wire Line
	7900 3000 7800 3000
Wire Wire Line
	7900 2900 7800 2900
Wire Wire Line
	7900 2800 7800 2800
Wire Wire Line
	7900 2700 7800 2700
Wire Wire Line
	7900 2600 7800 2600
Wire Wire Line
	7900 2500 7800 2500
Wire Wire Line
	7900 2400 7800 2400
Wire Wire Line
	7900 2300 7800 2300
Wire Wire Line
	7900 2200 7800 2200
Wire Wire Line
	7900 2100 7800 2100
Wire Wire Line
	7900 2000 7800 2000
Wire Wire Line
	7900 1900 7800 1900
Wire Wire Line
	7900 1800 7800 1800
Wire Wire Line
	7900 1700 7800 1700
Wire Wire Line
	7900 1600 7800 1600
Wire Wire Line
	7900 1500 7800 1500
Text GLabel 7900 3300 2    39   Input ~ 0
SRAM_A18
Text GLabel 7900 3200 2    39   Input ~ 0
SRAM_A17
Text GLabel 7900 3100 2    39   Input ~ 0
SRAM_A16
Text GLabel 7900 3000 2    39   Input ~ 0
SRAM_A15
Text GLabel 7900 2900 2    39   Input ~ 0
SRAM_A14
Text GLabel 7900 2800 2    39   Input ~ 0
SRAM_A13
Text GLabel 7900 2700 2    39   Input ~ 0
SRAM_A12
Text GLabel 7900 2600 2    39   Input ~ 0
SRAM_A11
Text GLabel 7900 2500 2    39   Input ~ 0
SRAM_A10
Text GLabel 7900 2400 2    39   Input ~ 0
SRAM_A9
Text GLabel 7900 2300 2    39   Input ~ 0
SRAM_A8
Text GLabel 7900 2200 2    39   Input ~ 0
SRAM_A7
Text GLabel 7900 2100 2    39   Input ~ 0
SRAM_A6
Text GLabel 7900 2000 2    39   Input ~ 0
SRAM_A5
Text GLabel 7900 1900 2    39   Input ~ 0
SRAM_A4
Text GLabel 7900 1800 2    39   Input ~ 0
SRAM_A3
Text GLabel 7900 1700 2    39   Input ~ 0
SRAM_A2
Text GLabel 7900 1600 2    39   Input ~ 0
SRAM_A1
Text GLabel 7900 1500 2    39   Input ~ 0
SRAM_A0
Text Notes 550  700  0    98   ~ 20
TFT LCD Header
Text Notes 3750 700  0    98   ~ 20
Asynchronous SRAM
Text Notes 3750 4400 0    98   ~ 20
Resistive Touch Driver
Wire Wire Line
	7850 5300 7750 5300
Wire Wire Line
	7850 5200 7750 5200
Text GLabel 7750 5300 0    39   Input ~ 0
SCL_1
Text GLabel 7750 5200 0    39   Input ~ 0
SDA_1
Wire Wire Line
	7750 5100 7850 5100
Wire Wire Line
	7750 5900 7750 6000
Wire Wire Line
	7850 5900 7750 5900
Wire Wire Line
	7750 6000 7850 6000
Connection ~ 7750 6000
Wire Wire Line
	7750 6250 7750 6000
Wire Wire Line
	4600 5850 4600 5900
Wire Wire Line
	5050 5650 5050 5900
Wire Wire Line
	5500 5450 5500 5900
Wire Wire Line
	5950 5250 5950 5900
Wire Wire Line
	6450 5650 6400 5650
Wire Wire Line
	6450 5600 6450 5650
Wire Wire Line
	6450 5450 6400 5450
Wire Wire Line
	6450 5500 6450 5450
Wire Wire Line
	6450 5400 7450 5400
Wire Wire Line
	6450 5250 6400 5250
Wire Wire Line
	6450 5400 6450 5250
Wire Wire Line
	6450 5850 6400 5850
Wire Wire Line
	6450 5700 6450 5850
Wire Wire Line
	4600 6250 4600 6200
Wire Wire Line
	5050 6250 5050 6200
Wire Wire Line
	5500 6250 5500 6200
Wire Wire Line
	5950 6250 5950 6200
Wire Wire Line
	8850 6000 8850 6250
Wire Wire Line
	7450 6150 7450 6250
Wire Wire Line
	7150 6150 7150 6250
Wire Wire Line
	6850 6150 6850 6250
Wire Wire Line
	6550 6150 6550 6250
Wire Wire Line
	6450 5700 6550 5700
Wire Wire Line
	6550 5700 7850 5700
Connection ~ 6550 5700
Wire Wire Line
	6550 5850 6550 5700
Wire Wire Line
	6450 5600 6850 5600
Wire Wire Line
	6850 5600 7850 5600
Connection ~ 6850 5600
Wire Wire Line
	6850 5850 6850 5600
Wire Wire Line
	6450 5500 7150 5500
Wire Wire Line
	7150 5500 7850 5500
Connection ~ 7150 5500
Wire Wire Line
	7150 5850 7150 5500
Wire Wire Line
	7450 5850 7450 5400
Connection ~ 7450 5400
Wire Wire Line
	7850 5400 7450 5400
Wire Wire Line
	7850 5800 7800 5800
Text GLabel 7800 5800 0    39   Input ~ 0
RES_INT
$Comp
L Device:R R?
U 1 1 65B71C86
P 6250 5850
AR Path="/65B71C86" Ref="R?"  Part="1" 
AR Path="/65B709D0/65B71C86" Ref="R?"  Part="1" 
F 0 "R?" V 6150 5850 50  0000 C CNN
F 1 "10" V 6250 5850 50  0000 C CNN
F 2 "" V 6180 5850 50  0001 C CNN
F 3 "~" H 6250 5850 50  0001 C CNN
	1    6250 5850
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 65B71C8D
P 6250 5650
AR Path="/65B71C8D" Ref="R?"  Part="1" 
AR Path="/65B709D0/65B71C8D" Ref="R?"  Part="1" 
F 0 "R?" V 6150 5650 50  0000 C CNN
F 1 "10" V 6250 5650 50  0000 C CNN
F 2 "" V 6180 5650 50  0001 C CNN
F 3 "~" H 6250 5650 50  0001 C CNN
	1    6250 5650
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 65B71C94
P 6250 5450
AR Path="/65B71C94" Ref="R?"  Part="1" 
AR Path="/65B709D0/65B71C94" Ref="R?"  Part="1" 
F 0 "R?" V 6150 5450 50  0000 C CNN
F 1 "10" V 6250 5450 50  0000 C CNN
F 2 "" V 6180 5450 50  0001 C CNN
F 3 "~" H 6250 5450 50  0001 C CNN
	1    6250 5450
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 65B71C9B
P 6550 6000
AR Path="/65B71C9B" Ref="C?"  Part="1" 
AR Path="/65B709D0/65B71C9B" Ref="C?"  Part="1" 
F 0 "C?" H 6600 6100 50  0000 L CNN
F 1 "0.1uF" H 6600 5900 50  0000 L CNN
F 2 "" H 6588 5850 50  0001 C CNN
F 3 "~" H 6550 6000 50  0001 C CNN
	1    6550 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 65B71CA2
P 6850 6000
AR Path="/65B71CA2" Ref="C?"  Part="1" 
AR Path="/65B709D0/65B71CA2" Ref="C?"  Part="1" 
F 0 "C?" H 6900 6100 50  0000 L CNN
F 1 "0.1uF" H 6900 5900 50  0000 L CNN
F 2 "" H 6888 5850 50  0001 C CNN
F 3 "~" H 6850 6000 50  0001 C CNN
	1    6850 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 65B71CA9
P 7150 6000
AR Path="/65B71CA9" Ref="C?"  Part="1" 
AR Path="/65B709D0/65B71CA9" Ref="C?"  Part="1" 
F 0 "C?" H 7200 6100 50  0000 L CNN
F 1 "0.1uF" H 7200 5900 50  0000 L CNN
F 2 "" H 7188 5850 50  0001 C CNN
F 3 "~" H 7150 6000 50  0001 C CNN
	1    7150 6000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 65B71CB0
P 6250 5250
AR Path="/65B71CB0" Ref="R?"  Part="1" 
AR Path="/65B709D0/65B71CB0" Ref="R?"  Part="1" 
F 0 "R?" V 6150 5250 50  0000 C CNN
F 1 "10" V 6250 5250 50  0000 C CNN
F 2 "" V 6180 5250 50  0001 C CNN
F 3 "~" H 6250 5250 50  0001 C CNN
	1    6250 5250
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 65B71CB7
P 7450 6000
AR Path="/65B71CB7" Ref="C?"  Part="1" 
AR Path="/65B709D0/65B71CB7" Ref="C?"  Part="1" 
F 0 "C?" H 7500 6100 50  0000 L CNN
F 1 "0.1uF" H 7500 5900 50  0000 L CNN
F 2 "" H 7488 5850 50  0001 C CNN
F 3 "~" H 7450 6000 50  0001 C CNN
	1    7450 6000
	1    0    0    -1  
$EndComp
Text GLabel 4500 5250 0    39   Input ~ 0
TCH_UP
Text GLabel 4500 5650 0    39   Input ~ 0
TCH_LEFT
Text GLabel 4500 5850 0    39   Input ~ 0
TCH_DOWN
Text GLabel 4500 5450 0    39   Input ~ 0
TCH_RIGHT
Wire Wire Line
	8750 6000 8850 6000
Connection ~ 8850 6000
Wire Wire Line
	8850 5900 8850 6000
Wire Wire Line
	8750 5900 8850 5900
NoConn ~ 8750 5100
NoConn ~ 8750 5200
NoConn ~ 8750 5300
NoConn ~ 8750 5400
NoConn ~ 8750 5500
NoConn ~ 8750 5600
NoConn ~ 8750 5700
NoConn ~ 8750 5800
Wire Wire Line
	6900 1700 7000 1700
Wire Wire Line
	6900 1600 7000 1600
Wire Wire Line
	6900 1500 7000 1500
Text GLabel 6900 1700 0    39   Input ~ 0
PMPWR
Text GLabel 6900 1500 0    39   Input ~ 0
SRAM_CS
Text GLabel 6900 1600 0    39   Input ~ 0
LCD_CS
Wire Wire Line
	1850 2650 1950 2650
Wire Wire Line
	1850 2550 1950 2550
Wire Wire Line
	1950 5850 1850 5850
Wire Wire Line
	1950 5750 1850 5750
Wire Wire Line
	1950 5650 1850 5650
Wire Wire Line
	1850 5550 1950 5550
Wire Wire Line
	1850 5450 1950 5450
Wire Wire Line
	2450 5350 2450 5450
Wire Wire Line
	1850 5350 2450 5350
Text GLabel 1950 5550 2    39   Input ~ 0
LCD_RESET
Text GLabel 1950 5650 2    39   Input ~ 0
LCD_HSYNC
Text GLabel 1950 5750 2    39   Input ~ 0
LCD_VSYNC
Text GLabel 1950 5850 2    39   Input ~ 0
LCD_DEN
Wire Wire Line
	2450 6050 2450 6150
Wire Wire Line
	1850 6050 2450 6050
NoConn ~ 1850 5950
Text GLabel 1950 5450 2    39   Input ~ 0
LCD_SHIFT
Wire Wire Line
	7850 3500 7850 3600
Wire Wire Line
	6950 3500 6950 3600
Wire Wire Line
	7000 3500 6950 3500
Connection ~ 6950 3500
Wire Wire Line
	6950 3400 6950 3500
Wire Wire Line
	7000 3400 6950 3400
Wire Wire Line
	7800 3500 7850 3500
Connection ~ 7850 3500
Wire Wire Line
	7850 3400 7850 3500
Wire Wire Line
	7800 3400 7850 3400
Text GLabel 1950 2650 2    39   Input ~ 0
LCD_ANODE
Text GLabel 1950 2550 2    39   Input ~ 0
LCD_CATHODE
Text GLabel 1950 4750 2    39   Input ~ 0
LCD_B5
Text GLabel 1950 4650 2    39   Input ~ 0
LCD_B5
Text GLabel 1950 4550 2    39   Input ~ 0
LCD_B5
Text GLabel 1950 3850 2    39   Input ~ 0
LCD_G6
Text GLabel 1950 3750 2    39   Input ~ 0
LCD_G6
Text GLabel 1950 3050 2    39   Input ~ 0
LCD_R5
Text GLabel 1950 2950 2    39   Input ~ 0
LCD_R5
Text GLabel 1950 3150 2    39   Input ~ 0
LCD_R5
Text GLabel 1950 3550 2    39   Input ~ 0
LCD_R4
Text GLabel 1950 3450 2    39   Input ~ 0
LCD_R3
Text GLabel 1950 3350 2    39   Input ~ 0
LCD_R2
Text GLabel 1950 3250 2    39   Input ~ 0
LCD_R1
Text GLabel 1950 3650 2    39   Input ~ 0
LCD_R5
Text GLabel 1950 4350 2    39   Input ~ 0
LCD_G5
Text GLabel 1950 4250 2    39   Input ~ 0
LCD_G4
Text GLabel 1950 4150 2    39   Input ~ 0
LCD_G3
Text GLabel 1950 4050 2    39   Input ~ 0
LCD_G2
Text GLabel 1950 3950 2    39   Input ~ 0
LCD_G1
Text GLabel 1950 4450 2    39   Input ~ 0
LCD_G6
Text GLabel 1950 5150 2    39   Input ~ 0
LCD_B4
Text GLabel 1950 5050 2    39   Input ~ 0
LCD_B3
Text GLabel 1950 4950 2    39   Input ~ 0
LCD_B2
Text GLabel 1950 4850 2    39   Input ~ 0
LCD_B1
Text GLabel 1950 5250 2    39   Input ~ 0
LCD_B5
Wire Wire Line
	7000 3300 6900 3300
Wire Wire Line
	7000 3200 6900 3200
Wire Wire Line
	7000 3100 6900 3100
Wire Wire Line
	7000 3000 6900 3000
Wire Wire Line
	7000 2900 6900 2900
Wire Wire Line
	7000 2800 6900 2800
Wire Wire Line
	7000 2700 6900 2700
Wire Wire Line
	7000 2600 6900 2600
Wire Wire Line
	7000 2500 6900 2500
Wire Wire Line
	7000 2400 6900 2400
Wire Wire Line
	7000 2300 6900 2300
Wire Wire Line
	6900 2200 7000 2200
Wire Wire Line
	7000 2100 6900 2100
Wire Wire Line
	7000 2000 6900 2000
Wire Wire Line
	7000 1900 6900 1900
Wire Wire Line
	7000 1800 6900 1800
Wire Wire Line
	1850 6450 1950 6450
Wire Wire Line
	1850 6350 1950 6350
Wire Wire Line
	1850 6250 1950 6250
Wire Wire Line
	1850 6150 1950 6150
Text GLabel 1950 6450 2    39   Input ~ 0
TCH_UP
Text GLabel 1950 6350 2    39   Input ~ 0
TCH_LEFT
Text GLabel 1950 6250 2    39   Input ~ 0
TCH_DOWN
Text GLabel 1950 6150 2    39   Input ~ 0
TCH_RIGHT
Wire Wire Line
	1850 3150 1950 3150
Wire Wire Line
	1850 3050 1950 3050
Wire Wire Line
	1850 2950 1950 2950
Wire Wire Line
	1850 3850 1950 3850
Wire Wire Line
	1850 3750 1950 3750
Wire Wire Line
	1850 4750 1950 4750
Wire Wire Line
	1850 4650 1950 4650
Wire Wire Line
	1850 4550 1950 4550
Wire Wire Line
	1950 3650 1850 3650
Wire Wire Line
	1950 3550 1850 3550
Wire Wire Line
	1950 3450 1850 3450
Wire Wire Line
	1950 3350 1850 3350
Wire Wire Line
	1950 3250 1850 3250
Wire Wire Line
	1950 4450 1850 4450
Wire Wire Line
	1950 4350 1850 4350
Wire Wire Line
	1950 4250 1850 4250
Wire Wire Line
	1950 4150 1850 4150
Wire Wire Line
	1950 4050 1850 4050
Wire Wire Line
	1950 3950 1850 3950
Wire Wire Line
	1950 5250 1850 5250
Wire Wire Line
	1950 5150 1850 5150
Wire Wire Line
	1950 5050 1850 5050
Wire Wire Line
	1950 4950 1850 4950
Wire Wire Line
	1950 4850 1850 4850
Text GLabel 6900 3200 0    39   Input ~ 0
LCD_R4
Text GLabel 6900 3100 0    39   Input ~ 0
LCD_R3
Text GLabel 6900 3000 0    39   Input ~ 0
LCD_R2
Text GLabel 6900 2900 0    39   Input ~ 0
LCD_R1
Text GLabel 6900 3300 0    39   Input ~ 0
LCD_R5
Text GLabel 6900 2700 0    39   Input ~ 0
LCD_G5
Text GLabel 6900 2600 0    39   Input ~ 0
LCD_G4
Text GLabel 6900 2500 0    39   Input ~ 0
LCD_G3
Text GLabel 6900 2400 0    39   Input ~ 0
LCD_G2
Text GLabel 6900 2300 0    39   Input ~ 0
LCD_G1
Text GLabel 6900 2800 0    39   Input ~ 0
LCD_G6
Text GLabel 6900 2100 0    39   Input ~ 0
LCD_B4
Text GLabel 6900 2000 0    39   Input ~ 0
LCD_B3
Text GLabel 6900 1900 0    39   Input ~ 0
LCD_B2
Text GLabel 6900 1800 0    39   Input ~ 0
LCD_B1
Text GLabel 6900 2200 0    39   Input ~ 0
LCD_B5
Wire Wire Line
	6900 1400 7000 1400
Wire Notes Line width 20
	3650 500  3650 8000
Wire Wire Line
	1850 2750 2450 2750
Wire Wire Line
	7800 1400 7900 1400
$Comp
L Device:C C?
U 1 1 5D0FDD1E
P 1950 1800
AR Path="/5D0FDD1E" Ref="C?"  Part="1" 
AR Path="/65B709D0/5D0FDD1E" Ref="C?"  Part="1" 
AR Path="/66A12230/5D0FDD1E" Ref="C?"  Part="1" 
AR Path="/669AB112/5D0FDD1E" Ref="C?"  Part="1" 
F 0 "C?" H 2000 1900 50  0000 L CNN
F 1 "0.1uF" H 2000 1700 50  0000 L CNN
F 2 "" H 1988 1650 50  0001 C CNN
F 3 "~" H 1950 1800 50  0001 C CNN
	1    1950 1800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D0FDD2C
P 1600 1800
AR Path="/5D0FDD2C" Ref="C?"  Part="1" 
AR Path="/65B709D0/5D0FDD2C" Ref="C?"  Part="1" 
AR Path="/66A12230/5D0FDD2C" Ref="C?"  Part="1" 
AR Path="/669AB112/5D0FDD2C" Ref="C?"  Part="1" 
F 0 "C?" H 1650 1900 50  0000 L CNN
F 1 "10uF" H 1650 1700 50  0000 L CNN
F 2 "" H 1638 1650 50  0001 C CNN
F 3 "~" H 1600 1800 50  0001 C CNN
	1    1600 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1650 1950 1600
Wire Wire Line
	1600 2000 1600 1950
Wire Wire Line
	1950 2000 1950 1950
Wire Wire Line
	1600 1650 1600 1600
Wire Wire Line
	1600 1550 1600 1600
Connection ~ 1600 1600
Wire Wire Line
	1850 2850 2550 2850
Wire Wire Line
	2550 2850 2550 2750
Wire Wire Line
	2450 2750 2450 2950
Wire Wire Line
	7750 5000 7750 5100
Wire Wire Line
	6900 1300 6900 1400
Wire Wire Line
	7900 1300 7900 1400
Wire Notes Line width 20
	3650 4150 10500 4150
$Comp
L Device:D_Schottky D?
U 1 1 5C3CD02E
P 5950 6050
AR Path="/669AB112/5C3CD02E" Ref="D?"  Part="1" 
AR Path="/65B709D0/5C3CD02E" Ref="D?"  Part="1" 
F 0 "D?" V 5904 6129 50  0000 L CNN
F 1 "BAT42W" V 5995 6129 50  0000 L CNN
F 2 "" H 5950 6050 50  0001 C CNN
F 3 "~" H 5950 6050 50  0001 C CNN
	1    5950 6050
	0    1    1    0   
$EndComp
$Comp
L Device:D_Schottky D?
U 1 1 5C40B7AE
P 5500 6050
AR Path="/669AB112/5C40B7AE" Ref="D?"  Part="1" 
AR Path="/65B709D0/5C40B7AE" Ref="D?"  Part="1" 
F 0 "D?" V 5454 6129 50  0000 L CNN
F 1 "BAT42W" V 5545 6129 50  0000 L CNN
F 2 "" H 5500 6050 50  0001 C CNN
F 3 "~" H 5500 6050 50  0001 C CNN
	1    5500 6050
	0    1    1    0   
$EndComp
$Comp
L Device:D_Schottky D?
U 1 1 5C40B7F0
P 5050 6050
AR Path="/669AB112/5C40B7F0" Ref="D?"  Part="1" 
AR Path="/65B709D0/5C40B7F0" Ref="D?"  Part="1" 
F 0 "D?" V 5004 6129 50  0000 L CNN
F 1 "BAT42W" V 5095 6129 50  0000 L CNN
F 2 "" H 5050 6050 50  0001 C CNN
F 3 "~" H 5050 6050 50  0001 C CNN
	1    5050 6050
	0    1    1    0   
$EndComp
$Comp
L Device:D_Schottky D?
U 1 1 5C40B832
P 4600 6050
AR Path="/669AB112/5C40B832" Ref="D?"  Part="1" 
AR Path="/65B709D0/5C40B832" Ref="D?"  Part="1" 
F 0 "D?" V 4554 6129 50  0000 L CNN
F 1 "BAT42W" V 4645 6129 50  0000 L CNN
F 2 "" H 4600 6050 50  0001 C CNN
F 3 "~" H 4600 6050 50  0001 C CNN
	1    4600 6050
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 5850 6100 5850
Wire Wire Line
	5050 5650 6100 5650
Wire Wire Line
	5500 5450 6100 5450
Wire Wire Line
	5950 5250 6100 5250
Wire Wire Line
	4500 5850 4600 5850
Connection ~ 4600 5850
Connection ~ 5050 5650
Wire Wire Line
	4500 5650 5050 5650
Connection ~ 5500 5450
Wire Wire Line
	4500 5450 5500 5450
Wire Wire Line
	4500 5250 5950 5250
Connection ~ 5950 5250
$Comp
L CropTop:54104-4031 J?
U 1 1 5BFE9F50
P 1550 4500
F 0 "J?" H 1495 6675 50  0000 C CNN
F 1 "54104-4031" H 1495 6584 50  0000 C CNN
F 2 "" H 1250 5750 50  0001 C CNN
F 3 "" H 1250 5750 50  0001 C CNN
	1    1550 4500
	-1   0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5BFEA332
P 2450 6150
F 0 "#PWR?" H 2450 5900 50  0001 C CNN
F 1 "DGND" H 2454 5995 50  0000 C CNN
F 2 "" H 2450 6150 50  0001 C CNN
F 3 "" H 2450 6150 50  0001 C CNN
	1    2450 6150
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5BFEA3D9
P 2450 5450
F 0 "#PWR?" H 2450 5200 50  0001 C CNN
F 1 "DGND" H 2454 5295 50  0000 C CNN
F 2 "" H 2450 5450 50  0001 C CNN
F 3 "" H 2450 5450 50  0001 C CNN
	1    2450 5450
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5BFF49A9
P 2450 2950
F 0 "#PWR?" H 2450 2700 50  0001 C CNN
F 1 "DGND" H 2454 2795 50  0000 C CNN
F 2 "" H 2450 2950 50  0001 C CNN
F 3 "" H 2450 2950 50  0001 C CNN
	1    2450 2950
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5BFFEF64
P 1950 2000
F 0 "#PWR?" H 1950 1750 50  0001 C CNN
F 1 "DGND" H 1954 1845 50  0000 C CNN
F 2 "" H 1950 2000 50  0001 C CNN
F 3 "" H 1950 2000 50  0001 C CNN
	1    1950 2000
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C013B4E
P 7850 3600
F 0 "#PWR?" H 7850 3350 50  0001 C CNN
F 1 "DGND" H 7854 3445 50  0000 C CNN
F 2 "" H 7850 3600 50  0001 C CNN
F 3 "" H 7850 3600 50  0001 C CNN
	1    7850 3600
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C01E0BE
P 6950 3600
F 0 "#PWR?" H 6950 3350 50  0001 C CNN
F 1 "DGND" H 6954 3445 50  0000 C CNN
F 2 "" H 6950 3600 50  0001 C CNN
F 3 "" H 6950 3600 50  0001 C CNN
	1    6950 3600
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C02876F
P 7750 6250
F 0 "#PWR?" H 7750 6000 50  0001 C CNN
F 1 "DGND" H 7754 6095 50  0000 C CNN
F 2 "" H 7750 6250 50  0001 C CNN
F 3 "" H 7750 6250 50  0001 C CNN
	1    7750 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C032CDF
P 7450 6250
F 0 "#PWR?" H 7450 6000 50  0001 C CNN
F 1 "DGND" H 7454 6095 50  0000 C CNN
F 2 "" H 7450 6250 50  0001 C CNN
F 3 "" H 7450 6250 50  0001 C CNN
	1    7450 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C03D24F
P 7150 6250
F 0 "#PWR?" H 7150 6000 50  0001 C CNN
F 1 "DGND" H 7154 6095 50  0000 C CNN
F 2 "" H 7150 6250 50  0001 C CNN
F 3 "" H 7150 6250 50  0001 C CNN
	1    7150 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C0477BF
P 6850 6250
F 0 "#PWR?" H 6850 6000 50  0001 C CNN
F 1 "DGND" H 6854 6095 50  0000 C CNN
F 2 "" H 6850 6250 50  0001 C CNN
F 3 "" H 6850 6250 50  0001 C CNN
	1    6850 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C051D2F
P 6550 6250
F 0 "#PWR?" H 6550 6000 50  0001 C CNN
F 1 "DGND" H 6554 6095 50  0000 C CNN
F 2 "" H 6550 6250 50  0001 C CNN
F 3 "" H 6550 6250 50  0001 C CNN
	1    6550 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C05C29F
P 5950 6250
F 0 "#PWR?" H 5950 6000 50  0001 C CNN
F 1 "DGND" H 5954 6095 50  0000 C CNN
F 2 "" H 5950 6250 50  0001 C CNN
F 3 "" H 5950 6250 50  0001 C CNN
	1    5950 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C06680F
P 5500 6250
F 0 "#PWR?" H 5500 6000 50  0001 C CNN
F 1 "DGND" H 5504 6095 50  0000 C CNN
F 2 "" H 5500 6250 50  0001 C CNN
F 3 "" H 5500 6250 50  0001 C CNN
	1    5500 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C070D7F
P 5050 6250
F 0 "#PWR?" H 5050 6000 50  0001 C CNN
F 1 "DGND" H 5054 6095 50  0000 C CNN
F 2 "" H 5050 6250 50  0001 C CNN
F 3 "" H 5050 6250 50  0001 C CNN
	1    5050 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C07B2EF
P 4600 6250
F 0 "#PWR?" H 4600 6000 50  0001 C CNN
F 1 "DGND" H 4604 6095 50  0000 C CNN
F 2 "" H 4600 6250 50  0001 C CNN
F 3 "" H 4600 6250 50  0001 C CNN
	1    4600 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C085878
P 8850 6250
F 0 "#PWR?" H 8850 6000 50  0001 C CNN
F 1 "DGND" H 8854 6095 50  0000 C CNN
F 2 "" H 8850 6250 50  0001 C CNN
F 3 "" H 8850 6250 50  0001 C CNN
	1    8850 6250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR?
U 1 1 5C09A46E
P 2550 2750
F 0 "#PWR?" H 2550 2600 50  0001 C CNN
F 1 "DVDD" H 2565 2923 50  0000 C CNN
F 2 "" H 2550 2750 50  0001 C CNN
F 3 "" H 2550 2750 50  0001 C CNN
	1    2550 2750
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR?
U 1 1 5C0A4A70
P 7900 1300
F 0 "#PWR?" H 7900 1150 50  0001 C CNN
F 1 "DVDD" H 7915 1473 50  0000 C CNN
F 2 "" H 7900 1300 50  0001 C CNN
F 3 "" H 7900 1300 50  0001 C CNN
	1    7900 1300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR?
U 1 1 5C0AEFE0
P 6900 1300
F 0 "#PWR?" H 6900 1150 50  0001 C CNN
F 1 "DVDD" H 6915 1473 50  0000 C CNN
F 2 "" H 6900 1300 50  0001 C CNN
F 3 "" H 6900 1300 50  0001 C CNN
	1    6900 1300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR?
U 1 1 5C0B9641
P 7750 5000
F 0 "#PWR?" H 7750 4850 50  0001 C CNN
F 1 "DVDD" H 7765 5173 50  0000 C CNN
F 2 "" H 7750 5000 50  0001 C CNN
F 3 "" H 7750 5000 50  0001 C CNN
	1    7750 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 1600 1950 1600
$Comp
L CropTop:DVDD #PWR?
U 1 1 5C0D8152
P 1600 1550
F 0 "#PWR?" H 1600 1400 50  0001 C CNN
F 1 "DVDD" H 1615 1723 50  0000 C CNN
F 2 "" H 1600 1550 50  0001 C CNN
F 3 "" H 1600 1550 50  0001 C CNN
	1    1600 1550
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C0E229E
P 1600 2000
F 0 "#PWR?" H 1600 1750 50  0001 C CNN
F 1 "DGND" H 1604 1845 50  0000 C CNN
F 2 "" H 1600 2000 50  0001 C CNN
F 3 "" H 1600 2000 50  0001 C CNN
	1    1600 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5C11B512
P 6200 1550
AR Path="/5C11B512" Ref="C?"  Part="1" 
AR Path="/65B709D0/5C11B512" Ref="C?"  Part="1" 
AR Path="/66A12230/5C11B512" Ref="C?"  Part="1" 
AR Path="/669AB112/5C11B512" Ref="C?"  Part="1" 
F 0 "C?" H 6250 1650 50  0000 L CNN
F 1 "0.1uF" H 6250 1450 50  0000 L CNN
F 2 "" H 6238 1400 50  0001 C CNN
F 3 "~" H 6200 1550 50  0001 C CNN
	1    6200 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5C11B519
P 5850 1550
AR Path="/5C11B519" Ref="C?"  Part="1" 
AR Path="/65B709D0/5C11B519" Ref="C?"  Part="1" 
AR Path="/66A12230/5C11B519" Ref="C?"  Part="1" 
AR Path="/669AB112/5C11B519" Ref="C?"  Part="1" 
F 0 "C?" H 5900 1650 50  0000 L CNN
F 1 "10uF" H 5900 1450 50  0000 L CNN
F 2 "" H 5888 1400 50  0001 C CNN
F 3 "~" H 5850 1550 50  0001 C CNN
	1    5850 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1400 6200 1350
Wire Wire Line
	5850 1750 5850 1700
Wire Wire Line
	6200 1750 6200 1700
Wire Wire Line
	5850 1400 5850 1350
Wire Wire Line
	5850 1300 5850 1350
Connection ~ 5850 1350
$Comp
L CropTop:DGND #PWR?
U 1 1 5C11B526
P 6200 1750
F 0 "#PWR?" H 6200 1500 50  0001 C CNN
F 1 "DGND" H 6204 1595 50  0000 C CNN
F 2 "" H 6200 1750 50  0001 C CNN
F 3 "" H 6200 1750 50  0001 C CNN
	1    6200 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 1350 6200 1350
$Comp
L CropTop:DVDD #PWR?
U 1 1 5C11B52D
P 5850 1300
F 0 "#PWR?" H 5850 1150 50  0001 C CNN
F 1 "DVDD" H 5865 1473 50  0000 C CNN
F 2 "" H 5850 1300 50  0001 C CNN
F 3 "" H 5850 1300 50  0001 C CNN
	1    5850 1300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C11B533
P 5850 1750
F 0 "#PWR?" H 5850 1500 50  0001 C CNN
F 1 "DGND" H 5854 1595 50  0000 C CNN
F 2 "" H 5850 1750 50  0001 C CNN
F 3 "" H 5850 1750 50  0001 C CNN
	1    5850 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5C124BB4
P 9700 5250
AR Path="/5C124BB4" Ref="C?"  Part="1" 
AR Path="/65B709D0/5C124BB4" Ref="C?"  Part="1" 
AR Path="/66A12230/5C124BB4" Ref="C?"  Part="1" 
AR Path="/669AB112/5C124BB4" Ref="C?"  Part="1" 
F 0 "C?" H 9750 5350 50  0000 L CNN
F 1 "0.1uF" H 9750 5150 50  0000 L CNN
F 2 "" H 9738 5100 50  0001 C CNN
F 3 "~" H 9700 5250 50  0001 C CNN
	1    9700 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5C124BBB
P 9350 5250
AR Path="/5C124BBB" Ref="C?"  Part="1" 
AR Path="/65B709D0/5C124BBB" Ref="C?"  Part="1" 
AR Path="/66A12230/5C124BBB" Ref="C?"  Part="1" 
AR Path="/669AB112/5C124BBB" Ref="C?"  Part="1" 
F 0 "C?" H 9400 5350 50  0000 L CNN
F 1 "10uF" H 9400 5150 50  0000 L CNN
F 2 "" H 9388 5100 50  0001 C CNN
F 3 "~" H 9350 5250 50  0001 C CNN
	1    9350 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 5100 9700 5050
Wire Wire Line
	9350 5450 9350 5400
Wire Wire Line
	9700 5450 9700 5400
Wire Wire Line
	9350 5100 9350 5050
Wire Wire Line
	9350 5000 9350 5050
Connection ~ 9350 5050
$Comp
L CropTop:DGND #PWR?
U 1 1 5C124BC8
P 9700 5450
F 0 "#PWR?" H 9700 5200 50  0001 C CNN
F 1 "DGND" H 9704 5295 50  0000 C CNN
F 2 "" H 9700 5450 50  0001 C CNN
F 3 "" H 9700 5450 50  0001 C CNN
	1    9700 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 5050 9700 5050
$Comp
L CropTop:DVDD #PWR?
U 1 1 5C124BCF
P 9350 5000
F 0 "#PWR?" H 9350 4850 50  0001 C CNN
F 1 "DVDD" H 9365 5173 50  0000 C CNN
F 2 "" H 9350 5000 50  0001 C CNN
F 3 "" H 9350 5000 50  0001 C CNN
	1    9350 5000
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C124BD5
P 9350 5450
F 0 "#PWR?" H 9350 5200 50  0001 C CNN
F 1 "DGND" H 9354 5295 50  0000 C CNN
F 2 "" H 9350 5450 50  0001 C CNN
F 3 "" H 9350 5450 50  0001 C CNN
	1    9350 5450
	1    0    0    -1  
$EndComp
$Comp
L CropTop:IS66WV51216EBLL U?
U 1 1 5C12E688
P 7400 2400
F 0 "U?" H 7400 3667 50  0000 C CNN
F 1 "IS66WV51216EBLL" H 7400 3576 50  0000 C CNN
F 2 "" H 7400 2250 50  0001 C CNN
F 3 "" H 7400 2250 50  0001 C CNN
	1    7400 2400
	1    0    0    -1  
$EndComp
$Comp
L CropTop:BU21026MUV-E2 U?
U 1 1 5C12E7E0
P 8300 5550
F 0 "U?" H 8300 6267 50  0000 C CNN
F 1 "BU21026MUV-E2" H 8300 6176 50  0000 C CNN
F 2 "" H 8250 5450 50  0001 C CNN
F 3 "" H 8250 5450 50  0001 C CNN
	1    8300 5550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
