EESchema Schematic File Version 4
LIBS:croptop-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 2 6
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
	5900 3350 5900 3000
Wire Wire Line
	5400 3350 5900 3350
$Comp
L CropTop:DVDD_UNREG #PWR?
U 1 1 5C31543C
P 5900 3000
AR Path="/64809F0C/5C31543C" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/5C31543C" Ref="#PWR0110"  Part="1" 
F 0 "#PWR0110" H 5900 2850 50  0001 C CNN
F 1 "DVDD_UNREG" H 5915 3173 50  0000 C CNN
F 2 "" H 5900 3000 50  0001 C CNN
F 3 "" H 5900 3000 50  0001 C CNN
	1    5900 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 4850 3600 4850
Wire Wire Line
	3500 4750 3600 4750
NoConn ~ 5400 4800
NoConn ~ 5400 4900
NoConn ~ 5400 4550
NoConn ~ 5400 4650
NoConn ~ 5400 5750
Wire Wire Line
	1000 1850 1500 1850
Wire Wire Line
	800  1650 1500 1650
NoConn ~ 5400 5100
NoConn ~ 5400 5000
Wire Wire Line
	3500 1950 3600 1950
Text GLabel 3500 1950 0    39   Input ~ 0
LCD_PD
NoConn ~ 3600 1850
NoConn ~ 3600 2450
NoConn ~ 3600 2550
NoConn ~ 3600 2650
NoConn ~ 3600 2750
NoConn ~ 3600 2850
NoConn ~ 3600 2950
NoConn ~ 3600 3050
NoConn ~ 3600 3150
NoConn ~ 3600 3250
NoConn ~ 3600 3350
NoConn ~ 3600 3450
NoConn ~ 3600 3550
NoConn ~ 3600 3650
NoConn ~ 3600 4000
NoConn ~ 3600 4100
NoConn ~ 3600 4250
NoConn ~ 3600 4350
NoConn ~ 3600 4450
NoConn ~ 3600 4550
NoConn ~ 3600 4650
NoConn ~ 3600 5000
NoConn ~ 3600 5100
NoConn ~ 3600 5200
NoConn ~ 3600 5300
NoConn ~ 3600 5400
NoConn ~ 3600 5500
NoConn ~ 3600 5600
NoConn ~ 3600 5700
NoConn ~ 3600 5800
NoConn ~ 3600 5900
NoConn ~ 3600 6000
NoConn ~ 3600 6100
NoConn ~ 3600 6200
NoConn ~ 3600 6300
NoConn ~ 3600 6400
NoConn ~ 3600 6500
Wire Wire Line
	3500 2350 3600 2350
Wire Wire Line
	3500 2250 3600 2250
Wire Wire Line
	3500 2150 3600 2150
Wire Wire Line
	3500 2050 3600 2050
Text GLabel 5500 5350 2    39   Input ~ 0
LCD_INT
Wire Wire Line
	5400 5350 5500 5350
Text GLabel 3500 2050 0    39   Input ~ 0
SS2
Text GLabel 3500 2150 0    39   Input ~ 0
SDO2
Text GLabel 3500 2250 0    39   Input ~ 0
SDIO2
Text GLabel 3500 2350 0    39   Input ~ 0
SCLK2
Wire Wire Line
	9450 1250 9450 1150
Wire Wire Line
	10000 1700 10000 1850
Wire Wire Line
	10000 1400 10000 1250
$Comp
L CropTop:DGND #PWR029
U 1 1 5D06EED2
P 10000 1850
F 0 "#PWR029" H 10000 1600 50  0001 C CNN
F 1 "DGND" H 10004 1695 50  0000 C CNN
F 2 "" H 10000 1850 50  0001 C CNN
F 3 "" H 10000 1850 50  0001 C CNN
	1    10000 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D05840A
P 10000 1550
AR Path="/5D05840A" Ref="C?"  Part="1" 
AR Path="/66A12209/5D05840A" Ref="C?"  Part="1" 
AR Path="/64807BBC/5D05840A" Ref="C17"  Part="1" 
F 0 "C17" H 10115 1596 50  0000 L CNN
F 1 "10uF" H 10115 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 10038 1400 50  0001 C CNN
F 3 "~" H 10000 1550 50  0001 C CNN
	1    10000 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 1550 9500 1550
Wire Wire Line
	9300 1450 9500 1450
Wire Wire Line
	9000 2000 9000 2200
Wire Wire Line
	9450 1250 9850 1250
Wire Wire Line
	9850 1250 10000 1250
Connection ~ 9850 1250
Wire Wire Line
	9850 1250 9850 2000
Connection ~ 9450 1250
Wire Wire Line
	9100 1250 9450 1250
$Comp
L CropTop:DVDD_UNREG #PWR?
U 1 1 5CAB450F
P 9450 1150
AR Path="/64809F0C/5CAB450F" Ref="#PWR?"  Part="1" 
AR Path="/64807BBC/5CAB450F" Ref="#PWR028"  Part="1" 
F 0 "#PWR028" H 9450 1000 50  0001 C CNN
F 1 "DVDD_UNREG" H 9465 1323 50  0000 C CNN
F 2 "" H 9450 1150 50  0001 C CNN
F 3 "" H 9450 1150 50  0001 C CNN
	1    9450 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 2000 9850 2000
Wire Wire Line
	9400 1650 9400 1550
Wire Wire Line
	9300 1650 9300 1450
Connection ~ 9300 1450
Wire Wire Line
	9100 1450 9300 1450
Connection ~ 9400 1550
Wire Wire Line
	9100 1550 9400 1550
NoConn ~ 9700 2100
NoConn ~ 9100 2100
Wire Wire Line
	9100 2000 9000 2000
$Comp
L CropTop:DGND #PWR021
U 1 1 5C50B097
P 9000 2200
F 0 "#PWR021" H 9000 1950 50  0001 C CNN
F 1 "DGND" H 9004 2045 50  0000 C CNN
F 2 "" H 9000 2200 50  0001 C CNN
F 3 "" H 9000 2200 50  0001 C CNN
	1    9000 2200
	1    0    0    -1  
$EndComp
NoConn ~ 9500 1650
$Comp
L CropTop:PUSBM5V5X4 U16
U 1 1 5C445D5E
P 9400 1900
F 0 "U16" H 9400 1475 50  0000 C CNN
F 1 "PUSBM5V5X4" H 9400 1575 50  0000 C CNN
F 2 "croptop:PUSBM5V5X4" V 9650 1350 50  0001 C CNN
F 3 "" V 9650 1350 50  0001 C CNN
	1    9400 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 1800 2050 1750
Wire Wire Line
	2050 1350 2050 1450
Wire Wire Line
	1900 1450 1900 2150
$Comp
L Device:R R?
U 1 1 5C1DE3C9
P 2050 1600
AR Path="/5C1DE3C9" Ref="R?"  Part="1" 
AR Path="/64807BBC/5C1DE3C9" Ref="R70"  Part="1" 
F 0 "R70" H 2200 1600 50  0000 C CNN
F 1 "0" V 2050 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 1980 1600 50  0001 C CNN
F 3 "~" H 2050 1600 50  0001 C CNN
	1    2050 1600
	1    0    0    1   
$EndComp
Wire Wire Line
	1300 1250 2050 1250
Wire Wire Line
	1000 1450 1900 1450
Wire Wire Line
	800  1750 1000 1750
Wire Wire Line
	1000 1750 1000 1850
Wire Wire Line
	1000 1550 1000 1450
Wire Wire Line
	800  1550 1000 1550
Wire Wire Line
	5500 5250 5400 5250
Text GLabel 5500 5250 2    39   Input ~ 0
ADC_CS
Text Notes 8350 2850 0    98   ~ 20
Mounting Holes & Fiducials
Wire Notes Line width 20
	8300 550  8300 4550
Wire Notes Line width 20
	8300 4550 10500 4550
$Comp
L CropTop:FIDUCIAL FID2
U 1 1 5BF90139
P 9650 3800
F 0 "FID2" H 9790 3803 60  0000 L CNN
F 1 "FIDUCIAL" H 9790 3697 60  0000 L CNN
F 2 "Fiducial:Fiducial_1mm_Dia_2.54mm_Outer_CopperTop" H 9650 3800 60  0001 C CNN
F 3 "" H 9650 3800 60  0000 C CNN
	1    9650 3800
	1    0    0    -1  
$EndComp
$Comp
L CropTop:FIDUCIAL FID1
U 1 1 5BF90090
P 8850 3800
F 0 "FID1" H 8990 3803 60  0000 L CNN
F 1 "FIDUCIAL" H 8990 3697 60  0000 L CNN
F 2 "Fiducial:Fiducial_1mm_Dia_2.54mm_Outer_CopperTop" H 8850 3800 60  0001 C CNN
F 3 "" H 8850 3800 60  0000 C CNN
	1    8850 3800
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5BF8FFF2
P 9650 3450
F 0 "H4" H 9750 3496 50  0000 L CNN
F 1 "Bottom Right" H 9750 3405 50  0000 L CNN
F 2 "MountingHole:MountingHole_4mm_Pad" H 9650 3450 50  0001 C CNN
F 3 "~" H 9650 3450 50  0001 C CNN
	1    9650 3450
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5BF8FF6E
P 8850 3450
F 0 "H2" H 8950 3496 50  0000 L CNN
F 1 "Bottom Left" H 8950 3405 50  0000 L CNN
F 2 "MountingHole:MountingHole_4mm_Pad" H 8850 3450 50  0001 C CNN
F 3 "~" H 8850 3450 50  0001 C CNN
	1    8850 3450
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5BF8FEEC
P 9650 3250
F 0 "H3" H 9750 3296 50  0000 L CNN
F 1 "Top Right" H 9750 3205 50  0000 L CNN
F 2 "MountingHole:MountingHole_4mm_Pad" H 9650 3250 50  0001 C CNN
F 3 "~" H 9650 3250 50  0001 C CNN
	1    9650 3250
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5BF8FD1A
P 8850 3250
F 0 "H1" H 8950 3296 50  0000 L CNN
F 1 "Top Left" H 8950 3205 50  0000 L CNN
F 2 "MountingHole:MountingHole_4mm_Pad" H 8850 3250 50  0001 C CNN
F 3 "~" H 8850 3250 50  0001 C CNN
	1    8850 3250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR011
U 1 1 5C302CC8
P 6500 5800
F 0 "#PWR011" H 6500 5650 50  0001 C CNN
F 1 "DVDD" H 6515 5973 50  0000 C CNN
F 2 "" H 6500 5800 50  0001 C CNN
F 3 "" H 6500 5800 50  0001 C CNN
	1    6500 5800
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR08
U 1 1 5C2DB102
P 6150 3150
F 0 "#PWR08" H 6150 3000 50  0001 C CNN
F 1 "DVDD" H 6165 3323 50  0000 C CNN
F 2 "" H 6150 3150 50  0001 C CNN
F 3 "" H 6150 3150 50  0001 C CNN
	1    6150 3150
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR07
U 1 1 5C2C6F3F
P 5750 1450
F 0 "#PWR07" H 5750 1300 50  0001 C CNN
F 1 "DVDD" H 5765 1623 50  0000 C CNN
F 2 "" H 5750 1450 50  0001 C CNN
F 3 "" H 5750 1450 50  0001 C CNN
	1    5750 1450
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR06
U 1 1 5C2B3170
P 5500 1450
F 0 "#PWR06" H 5500 1300 50  0001 C CNN
F 1 "DVDD" H 5515 1623 50  0000 C CNN
F 2 "" H 5500 1450 50  0001 C CNN
F 3 "" H 5500 1450 50  0001 C CNN
	1    5500 1450
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR05
U 1 1 5C28B5D6
P 4750 1250
F 0 "#PWR05" H 4750 1100 50  0001 C CNN
F 1 "DVDD" H 4765 1423 50  0000 C CNN
F 2 "" H 4750 1250 50  0001 C CNN
F 3 "" H 4750 1250 50  0001 C CNN
	1    4750 1250
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR01
U 1 1 5C2775FF
P 900 1200
F 0 "#PWR01" H 900 1050 50  0001 C CNN
F 1 "DVDD" H 915 1373 50  0000 C CNN
F 2 "" H 900 1200 50  0001 C CNN
F 3 "" H 900 1200 50  0001 C CNN
	1    900  1200
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR04
U 1 1 5C26336C
P 4250 7050
F 0 "#PWR04" H 4250 6800 50  0001 C CNN
F 1 "DGND" H 4254 6895 50  0000 C CNN
F 2 "" H 4250 7050 50  0001 C CNN
F 3 "" H 4250 7050 50  0001 C CNN
	1    4250 7050
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR019
U 1 1 5C24F461
P 8750 1950
F 0 "#PWR019" H 8750 1700 50  0001 C CNN
F 1 "DGND" H 8754 1795 50  0000 C CNN
F 2 "" H 8750 1950 50  0001 C CNN
F 3 "" H 8750 1950 50  0001 C CNN
	1    8750 1950
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR03
U 1 1 5C23B664
P 3650 1450
F 0 "#PWR03" H 3650 1200 50  0001 C CNN
F 1 "DGND" H 3654 1295 50  0000 C CNN
F 2 "" H 3650 1450 50  0001 C CNN
F 3 "" H 3650 1450 50  0001 C CNN
	1    3650 1450
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR09
U 1 1 5C22783A
P 6150 3650
F 0 "#PWR09" H 6150 3400 50  0001 C CNN
F 1 "DGND" H 6154 3495 50  0000 C CNN
F 2 "" H 6150 3650 50  0001 C CNN
F 3 "" H 6150 3650 50  0001 C CNN
	1    6150 3650
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR022
U 1 1 5C213A3D
P 9750 6400
F 0 "#PWR022" H 9750 6150 50  0001 C CNN
F 1 "DGND" H 9754 6245 50  0000 C CNN
F 2 "" H 9750 6400 50  0001 C CNN
F 3 "" H 9750 6400 50  0001 C CNN
	1    9750 6400
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR020
U 1 1 5C1FFC6E
P 9300 6400
F 0 "#PWR020" H 9300 6150 50  0001 C CNN
F 1 "DGND" H 9304 6245 50  0000 C CNN
F 2 "" H 9300 6400 50  0001 C CNN
F 3 "" H 9300 6400 50  0001 C CNN
	1    9300 6400
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR018
U 1 1 5C1EBE9F
P 8850 6400
F 0 "#PWR018" H 8850 6150 50  0001 C CNN
F 1 "DGND" H 8854 6245 50  0000 C CNN
F 2 "" H 8850 6400 50  0001 C CNN
F 3 "" H 8850 6400 50  0001 C CNN
	1    8850 6400
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR017
U 1 1 5C1D80D0
P 8400 6400
F 0 "#PWR017" H 8400 6150 50  0001 C CNN
F 1 "DGND" H 8404 6245 50  0000 C CNN
F 2 "" H 8400 6400 50  0001 C CNN
F 3 "" H 8400 6400 50  0001 C CNN
	1    8400 6400
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR016
U 1 1 5C1C4301
P 7950 6400
F 0 "#PWR016" H 7950 6150 50  0001 C CNN
F 1 "DGND" H 7954 6245 50  0000 C CNN
F 2 "" H 7950 6400 50  0001 C CNN
F 3 "" H 7950 6400 50  0001 C CNN
	1    7950 6400
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR015
U 1 1 5C1B0532
P 7500 6400
F 0 "#PWR015" H 7500 6150 50  0001 C CNN
F 1 "DGND" H 7504 6245 50  0000 C CNN
F 2 "" H 7500 6400 50  0001 C CNN
F 3 "" H 7500 6400 50  0001 C CNN
	1    7500 6400
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR014
U 1 1 5C19C763
P 7050 6400
F 0 "#PWR014" H 7050 6150 50  0001 C CNN
F 1 "DGND" H 7054 6245 50  0000 C CNN
F 2 "" H 7050 6400 50  0001 C CNN
F 3 "" H 7050 6400 50  0001 C CNN
	1    7050 6400
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR012
U 1 1 5C188994
P 6600 6400
F 0 "#PWR012" H 6600 6150 50  0001 C CNN
F 1 "DGND" H 6604 6245 50  0000 C CNN
F 2 "" H 6600 6400 50  0001 C CNN
F 3 "" H 6600 6400 50  0001 C CNN
	1    6600 6400
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR013
U 1 1 5C174BC5
P 6850 4900
F 0 "#PWR013" H 6850 4650 50  0001 C CNN
F 1 "DGND" H 6854 4745 50  0000 C CNN
F 2 "" H 6850 4900 50  0001 C CNN
F 3 "" H 6850 4900 50  0001 C CNN
	1    6850 4900
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR010
U 1 1 5C14D028
P 6450 4900
F 0 "#PWR010" H 6450 4650 50  0001 C CNN
F 1 "DGND" H 6454 4745 50  0000 C CNN
F 2 "" H 6450 4900 50  0001 C CNN
F 3 "" H 6450 4900 50  0001 C CNN
	1    6450 4900
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR02
U 1 1 5C138F47
P 2050 2200
F 0 "#PWR02" H 2050 1950 50  0001 C CNN
F 1 "DGND" H 2054 2045 50  0000 C CNN
F 2 "" H 2050 2200 50  0001 C CNN
F 3 "" H 2050 2200 50  0001 C CNN
	1    2050 2200
	1    0    0    -1  
$EndComp
$Comp
L CropTop:PIC32MX795F512L U1
U 1 1 5C138A86
P 4500 4150
F 0 "U1" H 4500 4300 50  0000 C CNN
F 1 "PIC32MX795F512L" H 4500 4200 50  0000 C CNN
F 2 "Package_QFP:TQFP-100_12x12mm_P0.4mm" H 4500 4150 50  0001 C CNN
F 3 "DOCUMENTATION" H 4500 4150 50  0001 C CNN
	1    4500 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3250 6150 3250
Wire Wire Line
	6150 3650 6150 3600
Wire Wire Line
	6150 3300 6150 3250
Wire Wire Line
	5900 4200 5900 4500
Wire Wire Line
	5400 4100 6000 4100
$Comp
L Device:C C?
U 1 1 5C15A197
P 6150 3450
AR Path="/5C15A197" Ref="C?"  Part="1" 
AR Path="/66A12209/5C15A197" Ref="C?"  Part="1" 
AR Path="/64807BBC/5C15A197" Ref="C3"  Part="1" 
F 0 "C3" H 6265 3496 50  0000 L CNN
F 1 "0.1uF" H 6265 3405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6188 3300 50  0001 C CNN
F 3 "~" H 6150 3450 50  0001 C CNN
	1    6150 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1300 4750 1300
Wire Wire Line
	4250 1300 4250 1500
Wire Wire Line
	4250 1300 4300 1300
Text Notes 6700 6050 0    50   ~ 0
Bulk
Text Notes 9850 6050 0    50   ~ 0
No Pin
$Comp
L Device:L L?
U 1 1 5C076B8A
P 4450 1300
AR Path="/5C076B8A" Ref="L?"  Part="1" 
AR Path="/64809F0C/5C076B8A" Ref="L?"  Part="1" 
AR Path="/64807BBC/5C076B8A" Ref="L1"  Part="1" 
F 0 "L1" V 4640 1300 50  0000 C CNN
F 1 "10uH" V 4549 1300 50  0000 C CNN
F 2 "Inductor_SMD:L_1210_3225Metric" H 4450 1300 50  0001 C CNN
F 3 "~" H 4450 1300 50  0001 C CNN
	1    4450 1300
	0    1    -1   0   
$EndComp
Wire Notes Line width 20
	8300 2600 10500 2600
Wire Notes Line width 20
	2600 2600 2600 500 
Wire Notes Line width 20
	500  2600 2600 2600
Wire Wire Line
	6600 5900 6500 5900
Connection ~ 6600 5900
Wire Wire Line
	6600 6050 6600 5900
Wire Wire Line
	6600 6400 6600 6350
$Comp
L Device:C C?
U 1 1 5CC429B9
P 6600 6200
AR Path="/5CC429B9" Ref="C?"  Part="1" 
AR Path="/66A12209/5CC429B9" Ref="C?"  Part="1" 
AR Path="/64807BBC/5CC429B9" Ref="C5"  Part="1" 
F 0 "C5" H 6715 6246 50  0000 L CNN
F 1 "10uF" H 6715 6155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6638 6050 50  0001 C CNN
F 3 "~" H 6600 6200 50  0001 C CNN
	1    6600 6200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5CC1B2E0
P 7050 6200
AR Path="/5CC1B2E0" Ref="C?"  Part="1" 
AR Path="/66A12209/5CC1B2E0" Ref="C?"  Part="1" 
AR Path="/64807BBC/5CC1B2E0" Ref="C7"  Part="1" 
F 0 "C7" H 7165 6246 50  0000 L CNN
F 1 "0.1uF" H 7165 6155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7088 6050 50  0001 C CNN
F 3 "~" H 7050 6200 50  0001 C CNN
	1    7050 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 5900 6500 5800
$Comp
L Device:C C?
U 1 1 5CC1B2D5
P 7500 6200
AR Path="/5CC1B2D5" Ref="C?"  Part="1" 
AR Path="/66A12209/5CC1B2D5" Ref="C?"  Part="1" 
AR Path="/64807BBC/5CC1B2D5" Ref="C8"  Part="1" 
F 0 "C8" H 7615 6246 50  0000 L CNN
F 1 "0.1uF" H 7615 6155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7538 6050 50  0001 C CNN
F 3 "~" H 7500 6200 50  0001 C CNN
	1    7500 6200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5CC1B2CE
P 7950 6200
AR Path="/5CC1B2CE" Ref="C?"  Part="1" 
AR Path="/66A12209/5CC1B2CE" Ref="C?"  Part="1" 
AR Path="/64807BBC/5CC1B2CE" Ref="C9"  Part="1" 
F 0 "C9" H 8065 6246 50  0000 L CNN
F 1 "0.1uF" H 8065 6155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 7988 6050 50  0001 C CNN
F 3 "~" H 7950 6200 50  0001 C CNN
	1    7950 6200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5CC1B2C7
P 8400 6200
AR Path="/5CC1B2C7" Ref="C?"  Part="1" 
AR Path="/66A12209/5CC1B2C7" Ref="C?"  Part="1" 
AR Path="/64807BBC/5CC1B2C7" Ref="C10"  Part="1" 
F 0 "C10" H 8515 6246 50  0000 L CNN
F 1 "0.1uF" H 8515 6155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8438 6050 50  0001 C CNN
F 3 "~" H 8400 6200 50  0001 C CNN
	1    8400 6200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5CC1B2C0
P 8850 6200
AR Path="/5CC1B2C0" Ref="C?"  Part="1" 
AR Path="/66A12209/5CC1B2C0" Ref="C?"  Part="1" 
AR Path="/64807BBC/5CC1B2C0" Ref="C11"  Part="1" 
F 0 "C11" H 8965 6246 50  0000 L CNN
F 1 "0.1uF" H 8965 6155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 8888 6050 50  0001 C CNN
F 3 "~" H 8850 6200 50  0001 C CNN
	1    8850 6200
	1    0    0    -1  
$EndComp
Text Notes 7150 6450 0    50   ~ 0
No Pin
Text Notes 7150 6050 0    50   ~ 0
Pin 2
Wire Wire Line
	6600 5900 7050 5900
Connection ~ 7050 5900
Wire Wire Line
	7050 5900 7050 6050
Wire Wire Line
	7050 6350 7050 6400
Wire Wire Line
	7050 5900 7500 5900
Connection ~ 7500 5900
Wire Wire Line
	7500 5900 7500 6050
Wire Wire Line
	8850 5900 8850 6050
Connection ~ 8850 5900
Wire Wire Line
	8850 5900 9300 5900
Wire Wire Line
	7500 5900 7950 5900
Connection ~ 7950 5900
Wire Wire Line
	7950 5900 7950 6050
Wire Wire Line
	8400 5900 8850 5900
Wire Wire Line
	7950 5900 8400 5900
Connection ~ 8400 5900
Wire Wire Line
	8400 5900 8400 6050
Text Notes 7600 6050 0    50   ~ 0
Pin 16
Text Notes 7600 6450 0    50   ~ 0
Pin 15
Text Notes 8050 6050 0    50   ~ 0
Pin 30
Text Notes 8050 6450 0    50   ~ 0
Pin 31\n
Text Notes 8950 6050 0    50   ~ 0
Pin 46
Text Notes 8950 6450 0    50   ~ 0
Pin 45
Text Notes 8500 6050 0    50   ~ 0
Pin 37
Text Notes 8500 6450 0    50   ~ 0
Pin 36
Wire Wire Line
	8850 6350 8850 6400
Wire Wire Line
	8400 6350 8400 6400
Wire Wire Line
	7950 6350 7950 6400
Wire Wire Line
	7500 6350 7500 6400
$Comp
L Device:C C?
U 1 1 5CC1B278
P 9300 6200
AR Path="/5CC1B278" Ref="C?"  Part="1" 
AR Path="/66A12209/5CC1B278" Ref="C?"  Part="1" 
AR Path="/64807BBC/5CC1B278" Ref="C12"  Part="1" 
F 0 "C12" H 9415 6246 50  0000 L CNN
F 1 "0.1uF" H 9415 6155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 9338 6050 50  0001 C CNN
F 3 "~" H 9300 6200 50  0001 C CNN
	1    9300 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 5900 9300 6050
Connection ~ 9300 5900
Wire Wire Line
	9300 5900 9750 5900
Text Notes 9400 6050 0    50   ~ 0
Pin 62
Text Notes 9400 6450 0    50   ~ 0
Pin 65
Wire Wire Line
	9300 6350 9300 6400
$Comp
L Device:C C?
U 1 1 5CC1B265
P 9750 6200
AR Path="/5CC1B265" Ref="C?"  Part="1" 
AR Path="/66A12209/5CC1B265" Ref="C?"  Part="1" 
AR Path="/64807BBC/5CC1B265" Ref="C13"  Part="1" 
F 0 "C13" H 9865 6246 50  0000 L CNN
F 1 "0.1uF" H 9865 6155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 9788 6050 50  0001 C CNN
F 3 "~" H 9750 6200 50  0001 C CNN
	1    9750 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 5900 9750 6050
Text Notes 9850 6450 0    50   ~ 0
Pin 75
Wire Wire Line
	9750 6350 9750 6400
Text Notes 550  700  0    98   ~ 20
PICKit3 Header
Wire Wire Line
	6450 4500 6450 4550
Wire Wire Line
	5900 4200 5400 4200
Wire Wire Line
	6450 4500 5900 4500
Connection ~ 6450 4500
Wire Wire Line
	6450 4450 6450 4500
Wire Wire Line
	5400 5450 5500 5450
Text GLabel 5500 5450 2    39   Input ~ 0
GPS_INT
Wire Wire Line
	6050 2650 6150 2650
Wire Wire Line
	5400 2650 5750 2650
$Comp
L Device:R R?
U 1 1 65F75F3A
P 5900 2650
AR Path="/65F75F3A" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75F3A" Ref="R26"  Part="1" 
F 0 "R26" V 5800 2650 50  0000 C CNN
F 1 "10" V 5900 2650 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5830 2650 50  0001 C CNN
F 3 "~" H 5900 2650 50  0001 C CNN
	1    5900 2650
	0    1    1    0   
$EndComp
NoConn ~ 5400 2900
NoConn ~ 5400 2800
Wire Wire Line
	900  1200 900  1250
Wire Wire Line
	1000 1250 900  1250
Wire Wire Line
	2050 1250 2050 1350
Connection ~ 4750 1300
Wire Wire Line
	4750 1250 4750 1300
Connection ~ 6150 3250
Wire Wire Line
	6150 3150 6150 3250
Wire Wire Line
	6850 4850 6850 4900
Wire Wire Line
	6850 4100 6850 4550
Wire Wire Line
	6450 4850 6450 4900
Wire Wire Line
	6300 4100 6450 4100
Wire Wire Line
	6450 4100 6850 4100
Connection ~ 6450 4100
Wire Wire Line
	6450 4100 6450 4150
$Comp
L Device:R R?
U 1 1 65F75EFC
P 6150 4100
AR Path="/65F75EFC" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75EFC" Ref="R27"  Part="1" 
F 0 "R27" V 6075 4100 50  0000 C CNN
F 1 "0" V 6150 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6080 4100 50  0001 C CNN
F 3 "~" H 6150 4100 50  0001 C CNN
	1    6150 4100
	0    1    1    0   
$EndComp
Connection ~ 900  1250
Wire Wire Line
	900  1450 900  1250
Wire Wire Line
	800  1450 900  1450
$Comp
L Device:R R?
U 1 1 65F75EEB
P 1150 1250
AR Path="/65F75EEB" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75EEB" Ref="R1"  Part="1" 
F 0 "R1" V 1250 1200 50  0000 L CNN
F 1 "10k" V 1145 1180 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 1080 1250 50  0001 C CNN
F 3 "~" H 1150 1250 50  0001 C CNN
	1    1150 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	800  1350 2050 1350
Wire Wire Line
	2050 1350 2150 1350
Connection ~ 2050 1350
Wire Wire Line
	2050 2100 2050 2150
Wire Wire Line
	2050 2200 2050 2150
Connection ~ 2050 2150
Wire Wire Line
	1900 2150 2050 2150
$Comp
L Device:C C?
U 1 1 65F75EDB
P 2050 1950
AR Path="/65F75EDB" Ref="C?"  Part="1" 
AR Path="/64807BBC/65F75EDB" Ref="C1"  Part="1" 
F 0 "C1" H 2165 1996 50  0000 L CNN
F 1 "0.1uF" H 2165 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 2088 1800 50  0001 C CNN
F 3 "~" H 2050 1950 50  0001 C CNN
	1    2050 1950
	1    0    0    -1  
$EndComp
Text Notes 2700 700  0    98   ~ 20
PIC32 Microcontroller
Text Notes 8350 700  0    98   ~ 20
Peripheral USB Port
Wire Wire Line
	5400 5950 5500 5950
Wire Wire Line
	5400 5850 5500 5850
Text GLabel 5500 5850 2    39   Input ~ 0
RX
Text GLabel 5500 5950 2    39   Input ~ 0
TX
Wire Wire Line
	5400 6150 5500 6150
Wire Wire Line
	5400 6050 5500 6050
Text GLabel 5500 6150 2    39   Input ~ 0
NAND_WP
Text GLabel 5500 6050 2    39   Input ~ 0
NAND_HOLD
Text GLabel 9500 1550 2    39   Input ~ 0
USB_D-
Text GLabel 9500 1450 2    39   Input ~ 0
USB_D+
Wire Wire Line
	8800 1900 8800 1850
Wire Wire Line
	8750 1900 8800 1900
Wire Wire Line
	8750 1900 8750 1950
Connection ~ 8750 1900
Wire Wire Line
	8700 1900 8750 1900
Wire Wire Line
	8700 1850 8700 1900
Wire Wire Line
	5400 3150 5500 3150
Wire Wire Line
	5400 3050 5500 3050
Text GLabel 5500 3150 2    39   Input ~ 0
USB_D-
Text GLabel 5500 3050 2    39   Input ~ 0
USB_D+
NoConn ~ 5400 3450
Wire Wire Line
	5400 3600 5500 3600
Text GLabel 5500 3600 2    39   Input ~ 0
LIN_VOLT
$Comp
L Connector:USB_A J?
U 1 1 65F75E7B
P 8800 1450
AR Path="/65F75E7B" Ref="J?"  Part="1" 
AR Path="/64807BBC/65F75E7B" Ref="J2"  Part="1" 
F 0 "J2" H 8800 1875 50  0000 C CNN
F 1 "USB_A" H 8800 1800 50  0000 C CNN
F 2 "croptop:USB_A_Assmann_Horizontal" H 8950 1400 50  0001 C CNN
F 3 " ~" H 8950 1400 50  0001 C CNN
	1    8800 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 65F75E6E
P 6850 4700
AR Path="/65F75E6E" Ref="C?"  Part="1" 
AR Path="/64807BBC/65F75E6E" Ref="C6"  Part="1" 
F 0 "C6" H 6965 4746 50  0000 L CNN
F 1 "26pF" H 6965 4655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6888 4550 50  0001 C CNN
F 3 "~" H 6850 4700 50  0001 C CNN
	1    6850 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 65F75E67
P 6450 4700
AR Path="/65F75E67" Ref="C?"  Part="1" 
AR Path="/64807BBC/65F75E67" Ref="C4"  Part="1" 
F 0 "C4" H 6565 4746 50  0000 L CNN
F 1 "26pF" H 6565 4655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 6488 4550 50  0001 C CNN
F 3 "~" H 6450 4700 50  0001 C CNN
	1    6450 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y?
U 1 1 65F75E60
P 6450 4300
AR Path="/65F75E60" Ref="Y?"  Part="1" 
AR Path="/64807BBC/65F75E60" Ref="Y1"  Part="1" 
F 0 "Y1" V 6404 4431 50  0000 L CNN
F 1 "CXO" V 6495 4431 50  0000 L CNN
F 2 "croptop:ABLS_OX" H 6450 4300 50  0001 C CNN
F 3 "~" H 6450 4300 50  0001 C CNN
	1    6450 4300
	0    1    1    0   
$EndComp
Text GLabel 5500 2350 2    39   Input ~ 0
NAND_CS
Wire Wire Line
	5400 2200 5500 2200
Wire Wire Line
	5400 2100 5500 2100
Text GLabel 5500 2200 2    39   Input ~ 0
ROT_Y2
Text GLabel 5500 2100 2    39   Input ~ 0
ROT_Y1
NoConn ~ 5400 5550
NoConn ~ 5400 5650
Wire Wire Line
	5500 6500 5400 6500
Wire Wire Line
	5500 6400 5400 6400
Wire Wire Line
	5400 6300 5500 6300
Wire Wire Line
	4350 6850 4350 6950
Wire Wire Line
	4350 6950 4450 6950
Connection ~ 4450 6950
Wire Wire Line
	4450 6850 4450 6950
Wire Wire Line
	4450 6950 4550 6950
Connection ~ 4550 6950
Wire Wire Line
	4550 6850 4550 6950
Wire Wire Line
	4550 6950 4650 6950
Wire Wire Line
	4650 6950 4750 6950
Connection ~ 4650 6950
Wire Wire Line
	4650 6850 4650 6950
Wire Wire Line
	4750 6950 4750 6850
Connection ~ 4350 6950
Wire Wire Line
	4250 7050 4250 6950
Wire Wire Line
	4250 6850 4250 6950
Connection ~ 4250 6950
Wire Wire Line
	4250 6950 4350 6950
Wire Wire Line
	4550 1400 4550 1500
Wire Wire Line
	4550 1400 4450 1400
Wire Wire Line
	4450 1400 4350 1400
Connection ~ 4450 1400
Wire Wire Line
	4450 1400 4450 1500
Wire Wire Line
	4350 1400 4350 1500
Connection ~ 4550 1400
Wire Wire Line
	4650 1400 4550 1400
Wire Wire Line
	4650 1400 4650 1500
Connection ~ 4650 1400
Wire Wire Line
	4750 1400 4650 1400
Wire Wire Line
	4750 1300 4750 1400
Wire Wire Line
	4750 1400 4750 1500
Connection ~ 4750 1400
Wire Wire Line
	4850 1400 4850 1500
Wire Wire Line
	4750 1400 4850 1400
Wire Wire Line
	5750 1500 5750 1450
Wire Wire Line
	5500 1500 5500 1450
Wire Wire Line
	5400 1850 5750 1850
Wire Wire Line
	5750 1850 5850 1850
Connection ~ 5750 1850
Wire Wire Line
	5750 1800 5750 1850
Wire Wire Line
	5400 1950 5500 1950
Wire Wire Line
	5500 1950 5850 1950
Connection ~ 5500 1950
Wire Wire Line
	5500 1800 5500 1950
Wire Wire Line
	5500 4350 5400 4350
Wire Wire Line
	5500 4450 5400 4450
Wire Wire Line
	5400 2550 5500 2550
Wire Wire Line
	5400 2450 5500 2450
Wire Wire Line
	5400 2350 5500 2350
Wire Wire Line
	5400 3950 5500 3950
Wire Wire Line
	5400 3850 5500 3850
Wire Wire Line
	5400 3750 5500 3750
Text GLabel 5500 3950 2    39   Input ~ 0
DRV_FLT
Text GLabel 5500 3850 2    39   Input ~ 0
DRV_IN2
Text GLabel 5500 3750 2    39   Input ~ 0
DRV_IN1
$Comp
L Device:C C?
U 1 1 65F75DE2
P 3950 1400
AR Path="/65F75DE2" Ref="C?"  Part="1" 
AR Path="/64807BBC/65F75DE2" Ref="C2"  Part="1" 
F 0 "C2" V 3698 1400 50  0000 C CNN
F 1 "10uF" V 3789 1400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3988 1250 50  0001 C CNN
F 3 "~" H 3950 1400 50  0001 C CNN
	1    3950 1400
	0    1    1    0   
$EndComp
Text GLabel 6150 2650 2    39   Input ~ 0
MISO
Text GLabel 5500 2550 2    39   Input ~ 0
MOSI
Text GLabel 5500 2450 2    39   Input ~ 0
SCLK
Text GLabel 5500 6300 2    39   Input ~ 0
PKT_MCLR
Text GLabel 5500 6400 2    39   Input ~ 0
PKT_PGEC
Text GLabel 5500 6500 2    39   Input ~ 0
PKT_PGED
$Comp
L Device:R R?
U 1 1 65F75DD5
P 5500 1650
AR Path="/65F75DD5" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75DD5" Ref="R24"  Part="1" 
F 0 "R24" H 5560 1650 50  0000 L CNN
F 1 "2K" V 5500 1600 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5430 1650 50  0001 C CNN
F 3 "~" H 5500 1650 50  0001 C CNN
	1    5500 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 65F75DCE
P 5750 1650
AR Path="/65F75DCE" Ref="R?"  Part="1" 
AR Path="/64807BBC/65F75DCE" Ref="R25"  Part="1" 
F 0 "R25" H 5810 1650 50  0000 L CNN
F 1 "2K" V 5750 1600 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 5680 1650 50  0001 C CNN
F 3 "~" H 5750 1650 50  0001 C CNN
	1    5750 1650
	1    0    0    -1  
$EndComp
Text GLabel 5500 4450 2    39   Input ~ 0
LED_B
Text GLabel 5500 4350 2    39   Input ~ 0
LED_A
Text GLabel 3500 4750 0    39   Input ~ 0
BTN_B
Text GLabel 3500 4850 0    39   Input ~ 0
BTN_A
Wire Wire Line
	4150 1400 4100 1400
Wire Wire Line
	4150 1500 4150 1400
Text GLabel 5850 1950 2    39   Input ~ 0
SCL
Text GLabel 5850 1850 2    39   Input ~ 0
SDA
Wire Wire Line
	3650 1400 3650 1450
Wire Wire Line
	3800 1400 3650 1400
Text GLabel 2150 1350 2    39   Input ~ 0
PKT_MCLR
NoConn ~ 800  1850
Text GLabel 1500 1850 2    39   Input ~ 0
PKT_PGEC
Text GLabel 1500 1650 2    39   Input ~ 0
PKT_PGED
$Comp
L Connector:Conn_01x06_Male J?
U 1 1 65F75D3A
P 600 1550
AR Path="/65F75D3A" Ref="J?"  Part="1" 
AR Path="/64807BBC/65F75D3A" Ref="J1"  Part="1" 
F 0 "J1" H 750 1900 50  0000 R CNN
F 1 "PICKit Header" H 1000 1150 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 600 1550 50  0001 C CNN
F 3 "~" H 600 1550 50  0001 C CNN
	1    600  1550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
