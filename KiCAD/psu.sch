EESchema Schematic File Version 4
LIBS:croptop_rev1-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 3 6
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
L Connector:USB_B_Micro J?
U 1 1 6480A5F0
P 2750 3150
F 0 "J?" H 2750 3650 50  0000 C CNN
F 1 "5V USB" H 2750 3550 50  0000 C CNN
F 2 "" H 2900 3100 50  0001 C CNN
F 3 "~" H 2900 3100 50  0001 C CNN
	1    2750 3150
	1    0    0    -1  
$EndComp
NoConn ~ 3050 3150
NoConn ~ 3050 3250
NoConn ~ 3050 3350
$Comp
L Device:C C?
U 1 1 6480A606
P 3500 2950
F 0 "C?" H 3615 2996 50  0000 L CNN
F 1 "1uF" H 3615 2905 50  0000 L CNN
F 2 "" H 3538 2800 50  0001 C CNN
F 3 "~" H 3500 2950 50  0001 C CNN
	1    3500 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6480A60D
P 4800 2950
AR Path="/6480A60D" Ref="C?"  Part="1" 
AR Path="/64809F0C/6480A60D" Ref="C?"  Part="1" 
F 0 "C?" H 4915 2996 50  0000 L CNN
F 1 "1uF" H 4915 2905 50  0000 L CNN
F 2 "" H 4838 2800 50  0001 C CNN
F 3 "~" H 4800 2950 50  0001 C CNN
	1    4800 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6480A614
P 5325 2950
AR Path="/6480A614" Ref="C?"  Part="1" 
AR Path="/64809F0C/6480A614" Ref="C?"  Part="1" 
F 0 "C?" H 5440 2996 50  0000 L CNN
F 1 "1uF" H 5440 2905 50  0000 L CNN
F 2 "" H 5363 2800 50  0001 C CNN
F 3 "~" H 5325 2950 50  0001 C CNN
	1    5325 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6480A61B
P 6975 2950
F 0 "C?" H 7090 2996 50  0000 L CNN
F 1 "1uF" H 7090 2905 50  0000 L CNN
F 2 "" H 7013 2800 50  0001 C CNN
F 3 "~" H 6975 2950 50  0001 C CNN
	1    6975 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6480A622
P 4150 2150
AR Path="/6480A622" Ref="C?"  Part="1" 
AR Path="/64809F0C/6480A622" Ref="C?"  Part="1" 
F 0 "C?" V 3898 2150 50  0000 C CNN
F 1 "0.1uF" V 3989 2150 50  0000 C CNN
F 2 "" H 4188 2000 50  0001 C CNN
F 3 "~" H 4150 2150 50  0001 C CNN
	1    4150 2150
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 6480A62F
P 6525 2950
AR Path="/6480A62F" Ref="C?"  Part="1" 
AR Path="/64809F0C/6480A62F" Ref="C?"  Part="1" 
F 0 "C?" H 6640 2996 50  0000 L CNN
F 1 "470pF" H 6640 2905 50  0000 L CNN
F 2 "" H 6563 2800 50  0001 C CNN
F 3 "~" H 6525 2950 50  0001 C CNN
	1    6525 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2300 4100 2250
Wire Wire Line
	3950 2250 4100 2250
Wire Wire Line
	4200 2300 4200 2250
Wire Wire Line
	4200 2250 4350 2250
Wire Wire Line
	7800 3200 8100 3200
Wire Wire Line
	4650 2700 4800 2700
Wire Wire Line
	5325 2700 5325 2600
Wire Wire Line
	5325 2600 5425 2600
Wire Wire Line
	5325 2700 5425 2700
Connection ~ 5325 2700
Wire Wire Line
	5325 2700 5325 2800
Wire Wire Line
	5325 3100 5325 3150
Wire Wire Line
	4800 2800 4800 2700
Wire Wire Line
	4800 3150 4800 3100
Wire Wire Line
	4150 3150 4150 3100
Wire Wire Line
	3500 3150 3500 3100
Wire Wire Line
	3500 2750 3500 2800
Connection ~ 3500 2750
Wire Wire Line
	3500 2750 3650 2750
Wire Wire Line
	3500 2750 3500 2650
Wire Wire Line
	3500 2650 3650 2650
Wire Wire Line
	6975 2600 6975 2800
Wire Wire Line
	6525 2700 6525 2800
Wire Wire Line
	6525 3100 6525 3150
Wire Wire Line
	5925 3150 5925 3000
Wire Wire Line
	6975 3100 6975 3150
Text Notes 6950 2325 0    50   ~ 0
5V
Connection ~ 3300 2950
Text Notes 3250 2300 0    50   ~ 0
5V
Text Notes 4650 2000 0    98   ~ 20
Digital & Analog Power Supply
Text Notes 7750 3150 0    50   ~ 0
DGND & AGND\nStar Ground
Wire Wire Line
	3950 2250 3950 2150
Wire Wire Line
	3950 2150 4000 2150
Wire Wire Line
	4300 2150 4350 2150
Wire Wire Line
	4350 2150 4350 2250
Wire Wire Line
	3050 2950 3300 2950
Text Notes 7225 3475 0    50   ~ 0
3.3V
Wire Wire Line
	3300 2750 3500 2750
$Comp
L Device:C C?
U 1 1 6480A6D9
P 5900 4050
AR Path="/6480A6D9" Ref="C?"  Part="1" 
AR Path="/64809F0C/6480A6D9" Ref="C?"  Part="1" 
F 0 "C?" H 5785 4004 50  0000 R CNN
F 1 "560pF" H 5785 4095 50  0000 R CNN
F 2 "" H 5938 3900 50  0001 C CNN
F 3 "~" H 5900 4050 50  0001 C CNN
	1    5900 4050
	-1   0    0    1   
$EndComp
NoConn ~ 5700 3950
Wire Wire Line
	5700 4050 5750 4050
Wire Wire Line
	5700 3750 5750 3750
Wire Wire Line
	4700 3750 4700 3850
Wire Wire Line
	4700 3850 4800 3850
Wire Wire Line
	4700 3750 4800 3750
Wire Wire Line
	4800 3950 4700 3950
Wire Wire Line
	4700 3950 4700 4050
Wire Wire Line
	4800 4050 4700 4050
Connection ~ 4700 4050
Wire Wire Line
	4700 4050 4700 4300
Wire Wire Line
	3500 4300 3500 4200
Wire Wire Line
	6050 3750 6200 3750
Wire Wire Line
	2650 3550 2650 3600
Wire Wire Line
	2750 3600 2750 3550
Wire Wire Line
	2650 3600 2700 3600
Wire Wire Line
	2700 3600 2700 3650
Connection ~ 2700 3600
Wire Wire Line
	2700 3600 2750 3600
Wire Wire Line
	5700 3850 5900 3850
Wire Wire Line
	5900 3850 5900 3900
Wire Wire Line
	6200 3850 6200 3750
Wire Wire Line
	5900 3850 6200 3850
Connection ~ 5900 3850
$Comp
L Device:L L?
U 1 1 6480A72C
P 5150 4750
AR Path="/6480A72C" Ref="L?"  Part="1" 
AR Path="/64809F0C/6480A72C" Ref="L?"  Part="1" 
F 0 "L?" V 5340 4750 50  0000 C CNN
F 1 "10uH" V 5249 4750 50  0000 C CNN
F 2 "" H 5150 4750 50  0001 C CNN
F 3 "~" H 5150 4750 50  0001 C CNN
	1    5150 4750
	0    1    -1   0   
$EndComp
Wire Wire Line
	5500 5500 5600 5500
Wire Wire Line
	5600 5500 5600 5600
$Comp
L Device:R R?
U 1 1 6480A751
P 5850 5650
AR Path="/6480A751" Ref="R?"  Part="1" 
AR Path="/64809F0C/6480A751" Ref="R?"  Part="1" 
F 0 "R?" H 5920 5696 50  0000 L CNN
F 1 "10" H 5920 5605 50  0000 L CNN
F 2 "" V 5780 5650 50  0001 C CNN
F 3 "~" H 5850 5650 50  0001 C CNN
	1    5850 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 5450 5850 5500
Wire Wire Line
	5850 5850 5850 5800
Wire Wire Line
	7150 4750 7150 4950
Wire Wire Line
	7150 5250 7150 5450
Text GLabel 7250 5450 2    39   Input ~ 0
LCD_CATHODE
Text GLabel 7250 4750 2    39   Input ~ 0
LCD_ANODE
Wire Wire Line
	7150 4750 7250 4750
Wire Wire Line
	7150 5450 7250 5450
Text GLabel 4500 5650 0    39   Input ~ 0
BLK_PWM
$Comp
L Device:R R?
U 1 1 6480A7CE
P 6250 5650
AR Path="/6480A7CE" Ref="R?"  Part="1" 
AR Path="/64809F0C/6480A7CE" Ref="R?"  Part="1" 
F 0 "R?" H 6320 5696 50  0000 L CNN
F 1 "22" H 6320 5605 50  0000 L CNN
F 2 "" V 6180 5650 50  0001 C CNN
F 3 "~" H 6250 5650 50  0001 C CNN
	1    6250 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 5850 6250 5800
Wire Wire Line
	6250 5500 6250 5450
Connection ~ 6250 5450
$Comp
L Device:C C?
U 1 1 5BFAB6F0
P 3500 4050
F 0 "C?" H 3615 4096 50  0000 L CNN
F 1 "10uF" H 3615 4005 50  0000 L CNN
F 2 "" H 3538 3900 50  0001 C CNN
F 3 "~" H 3500 4050 50  0001 C CNN
	1    3500 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 4200 3900 4300
$Comp
L Device:C C?
U 1 1 5BFC2FA2
P 4300 4050
F 0 "C?" H 4415 4096 50  0000 L CNN
F 1 "0.1uF" H 4415 4005 50  0000 L CNN
F 2 "" H 4338 3900 50  0001 C CNN
F 3 "~" H 4300 4050 50  0001 C CNN
	1    4300 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5BFC3036
P 3900 4050
F 0 "C?" H 4015 4096 50  0000 L CNN
F 1 "1uF" H 4015 4005 50  0000 L CNN
F 2 "" H 3938 3900 50  0001 C CNN
F 3 "~" H 3900 4050 50  0001 C CNN
	1    3900 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 4200 4300 4300
Wire Wire Line
	3300 2950 3300 3750
Wire Wire Line
	4700 3750 4300 3750
Connection ~ 4700 3750
Wire Wire Line
	3500 3750 3500 3900
Connection ~ 3500 3750
Wire Wire Line
	3500 3750 3300 3750
Wire Wire Line
	3900 3750 3900 3900
Connection ~ 3900 3750
Wire Wire Line
	3900 3750 3500 3750
Wire Wire Line
	4300 3750 4300 3900
Connection ~ 4300 3750
Wire Wire Line
	4300 3750 3900 3750
Connection ~ 6200 3750
Wire Wire Line
	7300 4300 7300 4200
$Comp
L Device:C C?
U 1 1 5C0134A8
P 7300 4050
F 0 "C?" H 7415 4096 50  0000 L CNN
F 1 "10uF" H 7415 4005 50  0000 L CNN
F 2 "" H 7338 3900 50  0001 C CNN
F 3 "~" H 7300 4050 50  0001 C CNN
	1    7300 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 4200 6850 4300
$Comp
L Device:C C?
U 1 1 5C0134B6
P 6400 4050
F 0 "C?" H 6515 4096 50  0000 L CNN
F 1 "0.1uF" H 6515 4005 50  0000 L CNN
F 2 "" H 6438 3900 50  0001 C CNN
F 3 "~" H 6400 4050 50  0001 C CNN
	1    6400 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5C0134BD
P 6850 4050
F 0 "C?" H 6965 4096 50  0000 L CNN
F 1 "1uF" H 6965 4005 50  0000 L CNN
F 2 "" H 6888 3900 50  0001 C CNN
F 3 "~" H 6850 4050 50  0001 C CNN
	1    6850 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 4200 6400 4300
Wire Wire Line
	7300 3750 7300 3900
Wire Wire Line
	6850 3750 6850 3900
Wire Wire Line
	6400 3750 6400 3900
Connection ~ 6400 3750
Connection ~ 6850 3750
Wire Wire Line
	6200 3750 6400 3750
Wire Wire Line
	6400 3750 6850 3750
Wire Wire Line
	6850 3750 7300 3750
Wire Wire Line
	7300 3700 7300 3750
Connection ~ 7300 3750
Wire Wire Line
	3500 5300 3500 5200
$Comp
L Device:C C?
U 1 1 5C0595EA
P 3500 5050
F 0 "C?" H 3615 5096 50  0000 L CNN
F 1 "10uF" H 3615 5005 50  0000 L CNN
F 2 "" H 3538 4900 50  0001 C CNN
F 3 "~" H 3500 5050 50  0001 C CNN
	1    3500 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 5200 3900 5300
$Comp
L Device:C C?
U 1 1 5C0595F8
P 4300 5050
F 0 "C?" H 4415 5096 50  0000 L CNN
F 1 "0.1uF" H 4415 5005 50  0000 L CNN
F 2 "" H 4338 4900 50  0001 C CNN
F 3 "~" H 4300 5050 50  0001 C CNN
	1    4300 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5C0595FF
P 3900 5050
F 0 "C?" H 4015 5096 50  0000 L CNN
F 1 "1uF" H 4015 5005 50  0000 L CNN
F 2 "" H 3938 4900 50  0001 C CNN
F 3 "~" H 3900 5050 50  0001 C CNN
	1    3900 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5200 4300 5300
Wire Wire Line
	3500 4750 3500 4900
Wire Wire Line
	3900 4750 3900 4900
Wire Wire Line
	4300 4750 4300 4900
Wire Wire Line
	3300 4750 3500 4750
Connection ~ 3500 4750
Wire Wire Line
	3500 4750 3900 4750
Connection ~ 3900 4750
Wire Wire Line
	3900 4750 4300 4750
Connection ~ 4300 4750
Wire Wire Line
	4300 4750 4700 4750
Wire Wire Line
	4800 5100 4700 5100
Wire Wire Line
	4700 5100 4700 4750
Connection ~ 4700 4750
Wire Wire Line
	4700 4750 5000 4750
Wire Wire Line
	4500 5650 4600 5650
Wire Wire Line
	4600 5650 4600 5500
Wire Wire Line
	4600 5500 4800 5500
Wire Wire Line
	7050 5800 7050 5900
$Comp
L Device:C C?
U 1 1 5C085369
P 6600 5650
F 0 "C?" H 6715 5696 50  0000 L CNN
F 1 "0.1uF" H 6715 5605 50  0000 L CNN
F 2 "" H 6638 5500 50  0001 C CNN
F 3 "~" H 6600 5650 50  0001 C CNN
	1    6600 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 5800 6600 5900
Wire Wire Line
	6600 5500 6600 5450
Wire Wire Line
	7050 5500 7050 5450
Wire Wire Line
	5500 5300 5650 5300
Wire Wire Line
	5650 5300 5650 5450
Wire Wire Line
	5650 5450 5850 5450
Wire Wire Line
	5500 5100 5650 5100
Wire Wire Line
	5650 5100 5650 4750
Wire Wire Line
	5650 4750 5750 4750
Wire Wire Line
	5300 4750 5650 4750
Connection ~ 5650 4750
$Comp
L Device:C C?
U 1 1 5C0EBB76
P 6600 4950
F 0 "C?" H 6715 4996 50  0000 L CNN
F 1 "0.1uF" H 6715 4905 50  0000 L CNN
F 2 "" H 6638 4800 50  0001 C CNN
F 3 "~" H 6600 4950 50  0001 C CNN
	1    6600 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 5100 6600 5200
Wire Wire Line
	6600 4800 6600 4750
Wire Wire Line
	6600 5450 7050 5450
Wire Wire Line
	6250 5450 6600 5450
Connection ~ 6600 5450
Wire Wire Line
	3300 3750 3300 4750
Connection ~ 3300 3750
Wire Wire Line
	5850 5450 6250 5450
Connection ~ 5850 5450
Wire Wire Line
	7800 3200 7800 3300
Wire Wire Line
	8100 3200 8100 3300
Wire Wire Line
	5900 4250 5900 4200
Wire Wire Line
	5750 4050 5750 4250
Wire Wire Line
	5750 4250 5900 4250
Wire Wire Line
	3300 2750 3300 2950
Wire Wire Line
	3300 2750 3300 2550
Connection ~ 3300 2750
Wire Wire Line
	6975 2600 6975 2550
Connection ~ 6975 2600
Wire Wire Line
	4800 2700 5325 2700
Connection ~ 4800 2700
Text Notes 2050 3350 0    79   ~ 16
Check\nCurrent\nLimit
Text Notes 7350 4700 0    50   ~ 0
25.6V
Text Notes 2700 4150 0    79   ~ 16
add led
$Comp
L Device:D_Zener D?
U 1 1 5C1C0D13
P 7150 5100
F 0 "D?" V 7104 5179 50  0000 L CNN
F 1 "3SMAJ5935B" V 7195 5179 50  0000 L CNN
F 2 "" H 7150 5100 50  0001 C CNN
F 3 "~" H 7150 5100 50  0001 C CNN
	1    7150 5100
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5C085370
P 7050 5650
F 0 "C?" H 7165 5696 50  0000 L CNN
F 1 "1uF" H 7165 5605 50  0000 L CNN
F 2 "" H 7088 5500 50  0001 C CNN
F 3 "~" H 7050 5650 50  0001 C CNN
	1    7050 5650
	1    0    0    -1  
$EndComp
Connection ~ 7150 4750
Wire Wire Line
	7050 5450 7150 5450
Connection ~ 7050 5450
Connection ~ 7150 5450
Connection ~ 6600 4750
Wire Wire Line
	6600 4750 7150 4750
Wire Wire Line
	6050 4750 6600 4750
$Comp
L Device:D_Schottky D?
U 1 1 5C3C7D9F
P 5900 4750
AR Path="/669AB112/5C3C7D9F" Ref="D?"  Part="1" 
AR Path="/64809F0C/5C3C7D9F" Ref="D?"  Part="1" 
F 0 "D?" H 5900 4534 50  0000 C CNN
F 1 "BAT42W" H 5900 4625 50  0000 C CNN
F 2 "" H 5900 4750 50  0001 C CNN
F 3 "~" H 5900 4750 50  0001 C CNN
	1    5900 4750
	-1   0    0    1   
$EndComp
$Comp
L Device:L L?
U 1 1 5C51BB97
P 5900 3750
AR Path="/5C51BB97" Ref="L?"  Part="1" 
AR Path="/64809F0C/5C51BB97" Ref="L?"  Part="1" 
F 0 "L?" V 6090 3750 50  0000 C CNN
F 1 "1uH" V 5999 3750 50  0000 C CNN
F 2 "" H 5900 3750 50  0001 C CNN
F 3 "~" H 5900 3750 50  0001 C CNN
	1    5900 3750
	0    1    -1   0   
$EndComp
$Comp
L CropTop:FAN5333BSX U?
U 1 1 5C32B4BA
P 5150 5500
F 0 "U?" H 5150 6167 50  0000 C CNN
F 1 "FAN5333BSX" H 5150 6076 50  0000 C CNN
F 2 "" H 5150 5500 50  0001 C CNN
F 3 "" H 5150 5500 50  0001 C CNN
	1    5150 5500
	1    0    0    -1  
$EndComp
$Comp
L CropTop:MIC23050 U?
U 1 1 5C32F829
P 5250 3900
F 0 "U?" H 5250 4317 50  0000 C CNN
F 1 "MIC23050" H 5250 4226 50  0000 C CNN
F 2 "" H 5200 3950 50  0001 C CNN
F 3 "" H 5200 3950 50  0001 C CNN
	1    5250 3900
	1    0    0    -1  
$EndComp
$Comp
L CropTop:REG71055 U?
U 1 1 5C32F8B9
P 4150 2700
F 0 "U?" H 4275 2950 50  0000 L CNN
F 1 "REG71055" H 4200 2450 50  0000 L CNN
F 2 "" H 4150 2700 50  0001 C CNN
F 3 "" H 4150 2700 50  0001 C CNN
	1    4150 2700
	1    0    0    -1  
$EndComp
$Comp
L CropTop:TC1014 U?
U 1 1 5C32FA92
P 5925 2600
F 0 "U?" H 5925 2867 50  0000 C CNN
F 1 "TC1014" H 5925 2776 50  0000 C CNN
F 2 "" H 5925 2600 50  0001 C CNN
F 3 "" H 5925 2600 50  0001 C CNN
	1    5925 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6425 2700 6525 2700
Wire Wire Line
	6425 2600 6975 2600
$Comp
L CropTop:DGND #PWR?
U 1 1 5C334015
P 2700 3650
F 0 "#PWR?" H 2700 3400 50  0001 C CNN
F 1 "DGND" H 2704 3495 50  0000 C CNN
F 2 "" H 2700 3650 50  0001 C CNN
F 3 "" H 2700 3650 50  0001 C CNN
	1    2700 3650
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C33C34A
P 3500 3150
F 0 "#PWR?" H 3500 2900 50  0001 C CNN
F 1 "DGND" H 3504 2995 50  0000 C CNN
F 2 "" H 3500 3150 50  0001 C CNN
F 3 "" H 3500 3150 50  0001 C CNN
	1    3500 3150
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C3446F7
P 4150 3150
F 0 "#PWR?" H 4150 2900 50  0001 C CNN
F 1 "DGND" H 4154 2995 50  0000 C CNN
F 2 "" H 4150 3150 50  0001 C CNN
F 3 "" H 4150 3150 50  0001 C CNN
	1    4150 3150
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C348AB1
P 4800 3150
F 0 "#PWR?" H 4800 2900 50  0001 C CNN
F 1 "DGND" H 4804 2995 50  0000 C CNN
F 2 "" H 4800 3150 50  0001 C CNN
F 3 "" H 4800 3150 50  0001 C CNN
	1    4800 3150
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C34CCDF
P 3500 4300
F 0 "#PWR?" H 3500 4050 50  0001 C CNN
F 1 "DGND" H 3504 4145 50  0000 C CNN
F 2 "" H 3500 4300 50  0001 C CNN
F 3 "" H 3500 4300 50  0001 C CNN
	1    3500 4300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C350E6D
P 3900 4300
F 0 "#PWR?" H 3900 4050 50  0001 C CNN
F 1 "DGND" H 3904 4145 50  0000 C CNN
F 2 "" H 3900 4300 50  0001 C CNN
F 3 "" H 3900 4300 50  0001 C CNN
	1    3900 4300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C354FFB
P 4300 4300
F 0 "#PWR?" H 4300 4050 50  0001 C CNN
F 1 "DGND" H 4304 4145 50  0000 C CNN
F 2 "" H 4300 4300 50  0001 C CNN
F 3 "" H 4300 4300 50  0001 C CNN
	1    4300 4300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C359229
P 4700 4300
F 0 "#PWR?" H 4700 4050 50  0001 C CNN
F 1 "DGND" H 4704 4145 50  0000 C CNN
F 2 "" H 4700 4300 50  0001 C CNN
F 3 "" H 4700 4300 50  0001 C CNN
	1    4700 4300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C35D3B7
P 6400 4300
F 0 "#PWR?" H 6400 4050 50  0001 C CNN
F 1 "DGND" H 6404 4145 50  0000 C CNN
F 2 "" H 6400 4300 50  0001 C CNN
F 3 "" H 6400 4300 50  0001 C CNN
	1    6400 4300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C361545
P 6850 4300
F 0 "#PWR?" H 6850 4050 50  0001 C CNN
F 1 "DGND" H 6854 4145 50  0000 C CNN
F 2 "" H 6850 4300 50  0001 C CNN
F 3 "" H 6850 4300 50  0001 C CNN
	1    6850 4300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C3656D3
P 7300 4300
F 0 "#PWR?" H 7300 4050 50  0001 C CNN
F 1 "DGND" H 7304 4145 50  0000 C CNN
F 2 "" H 7300 4300 50  0001 C CNN
F 3 "" H 7300 4300 50  0001 C CNN
	1    7300 4300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C369861
P 3500 5300
F 0 "#PWR?" H 3500 5050 50  0001 C CNN
F 1 "DGND" H 3504 5145 50  0000 C CNN
F 2 "" H 3500 5300 50  0001 C CNN
F 3 "" H 3500 5300 50  0001 C CNN
	1    3500 5300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C36D9EF
P 3900 5300
F 0 "#PWR?" H 3900 5050 50  0001 C CNN
F 1 "DGND" H 3904 5145 50  0000 C CNN
F 2 "" H 3900 5300 50  0001 C CNN
F 3 "" H 3900 5300 50  0001 C CNN
	1    3900 5300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C371B7D
P 4300 5300
F 0 "#PWR?" H 4300 5050 50  0001 C CNN
F 1 "DGND" H 4304 5145 50  0000 C CNN
F 2 "" H 4300 5300 50  0001 C CNN
F 3 "" H 4300 5300 50  0001 C CNN
	1    4300 5300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C375D0B
P 5600 5600
F 0 "#PWR?" H 5600 5350 50  0001 C CNN
F 1 "DGND" H 5604 5445 50  0000 C CNN
F 2 "" H 5600 5600 50  0001 C CNN
F 3 "" H 5600 5600 50  0001 C CNN
	1    5600 5600
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C379E99
P 5850 5850
F 0 "#PWR?" H 5850 5600 50  0001 C CNN
F 1 "DGND" H 5854 5695 50  0000 C CNN
F 2 "" H 5850 5850 50  0001 C CNN
F 3 "" H 5850 5850 50  0001 C CNN
	1    5850 5850
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C37E027
P 6250 5850
F 0 "#PWR?" H 6250 5600 50  0001 C CNN
F 1 "DGND" H 6254 5695 50  0000 C CNN
F 2 "" H 6250 5850 50  0001 C CNN
F 3 "" H 6250 5850 50  0001 C CNN
	1    6250 5850
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C3821B5
P 6600 5900
F 0 "#PWR?" H 6600 5650 50  0001 C CNN
F 1 "DGND" H 6604 5745 50  0000 C CNN
F 2 "" H 6600 5900 50  0001 C CNN
F 3 "" H 6600 5900 50  0001 C CNN
	1    6600 5900
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C386343
P 7050 5900
F 0 "#PWR?" H 7050 5650 50  0001 C CNN
F 1 "DGND" H 7054 5745 50  0000 C CNN
F 2 "" H 7050 5900 50  0001 C CNN
F 3 "" H 7050 5900 50  0001 C CNN
	1    7050 5900
	1    0    0    -1  
$EndComp
$Comp
L CropTop:AGND #PWR?
U 1 1 5C38E778
P 5325 3150
F 0 "#PWR?" H 5325 2900 50  0001 C CNN
F 1 "AGND" H 5330 2977 50  0000 C CNN
F 2 "" H 5325 3150 50  0001 C CNN
F 3 "" H 5325 3150 50  0001 C CNN
	1    5325 3150
	1    0    0    -1  
$EndComp
$Comp
L CropTop:AGND #PWR?
U 1 1 5C392906
P 5925 3150
F 0 "#PWR?" H 5925 2900 50  0001 C CNN
F 1 "AGND" H 5930 2977 50  0000 C CNN
F 2 "" H 5925 3150 50  0001 C CNN
F 3 "" H 5925 3150 50  0001 C CNN
	1    5925 3150
	1    0    0    -1  
$EndComp
$Comp
L CropTop:AGND #PWR?
U 1 1 5C396A94
P 6525 3150
F 0 "#PWR?" H 6525 2900 50  0001 C CNN
F 1 "AGND" H 6530 2977 50  0000 C CNN
F 2 "" H 6525 3150 50  0001 C CNN
F 3 "" H 6525 3150 50  0001 C CNN
	1    6525 3150
	1    0    0    -1  
$EndComp
$Comp
L CropTop:AGND #PWR?
U 1 1 5C39AC22
P 6975 3150
F 0 "#PWR?" H 6975 2900 50  0001 C CNN
F 1 "AGND" H 6980 2977 50  0000 C CNN
F 2 "" H 6975 3150 50  0001 C CNN
F 3 "" H 6975 3150 50  0001 C CNN
	1    6975 3150
	1    0    0    -1  
$EndComp
$Comp
L CropTop:AGND #PWR?
U 1 1 5C39EE47
P 8100 3300
F 0 "#PWR?" H 8100 3050 50  0001 C CNN
F 1 "AGND" H 8105 3127 50  0000 C CNN
F 2 "" H 8100 3300 50  0001 C CNN
F 3 "" H 8100 3300 50  0001 C CNN
	1    8100 3300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C3A3017
P 7800 3300
F 0 "#PWR?" H 7800 3050 50  0001 C CNN
F 1 "DGND" H 7804 3145 50  0000 C CNN
F 2 "" H 7800 3300 50  0001 C CNN
F 3 "" H 7800 3300 50  0001 C CNN
	1    7800 3300
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD #PWR?
U 1 1 5C3AB91C
P 7300 3700
F 0 "#PWR?" H 7300 3550 50  0001 C CNN
F 1 "DVDD" H 7315 3873 50  0000 C CNN
F 2 "" H 7300 3700 50  0001 C CNN
F 3 "" H 7300 3700 50  0001 C CNN
	1    7300 3700
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DVDD_UNREG #PWR?
U 1 1 5C3AFB03
P 3300 2550
F 0 "#PWR?" H 3300 2400 50  0001 C CNN
F 1 "DVDD_UNREG" H 3315 2723 50  0000 C CNN
F 2 "" H 3300 2550 50  0001 C CNN
F 3 "" H 3300 2550 50  0001 C CNN
	1    3300 2550
	1    0    0    -1  
$EndComp
$Comp
L CropTop:AVDD #PWR?
U 1 1 5C3AFB9C
P 6975 2550
F 0 "#PWR?" H 6975 2400 50  0001 C CNN
F 1 "AVDD" H 6990 2723 50  0000 C CNN
F 2 "" H 6975 2550 50  0001 C CNN
F 3 "" H 6975 2550 50  0001 C CNN
	1    6975 2550
	1    0    0    -1  
$EndComp
$Comp
L CropTop:DGND #PWR?
U 1 1 5C3AFC09
P 6600 5200
F 0 "#PWR?" H 6600 4950 50  0001 C CNN
F 1 "DGND" H 6604 5045 50  0000 C CNN
F 2 "" H 6600 5200 50  0001 C CNN
F 3 "" H 6600 5200 50  0001 C CNN
	1    6600 5200
	1    0    0    -1  
$EndComp
$EndSCHEMATC
