EESchema Schematic File Version 4
LIBS:croptop-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 6
Title "CropTop"
Date "2018-11-20"
Rev "Revision 8"
Comp "University of Idaho"
Comment1 "Kennedy Caisley, Ryan Donahue"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 12650 2650 1200 900 
U 64807BBC
F0 "Microcontroller" 50
F1 "croptop_mcu.sch" 50
$EndSheet
$Sheet
S 12650 5050 1200 900 
U 64809F0C
F0 "Power Supply" 50
F1 "croptop_psu.sch" 50
$EndSheet
$Sheet
S 14050 2650 1200 900 
U 65B709D0
F0 "Display" 50
F1 "croptop_lcd.sch" 50
$EndSheet
$Sheet
S 14050 3850 1200 900 
U 669AB112
F0 "IO Peripherals" 50
F1 "croptop_io.sch" 50
$EndSheet
$Sheet
S 12650 3850 1200 900 
U 66A12230
F0 "Onboard Peripherals" 50
F1 "croptop_onboard.sch" 50
$EndSheet
Text Notes 12650 2300 0    138  ~ 28
List of Schematic Sheets
Text Notes -4350 1950 0    138  ~ 28
System Block Diagram
Text Notes -3000 5100 0    50   ~ 0
List of things to do:\nRemove electrolytic input on DC motor driver\nChange AVDD to 5V0_REG, DVDD to 3V3\nAdd inductor to ADC\nChange nets to have directions\nRemove global nets on power\nAdd missing pullups and pulldowns on temp/memory\nAdd MISO to SPI bus\nAdd resistor to Load bank for current limit\nMake board larger at top, add header blocks\nRemove electrolytic input on DC motor driver\nChange AVDD to 5V0_REG, DVDD to 3V3\nCheck regulators can carry high current\nMove micro usb and lcd connector further forward\nSplit memory and adc spi bus\nFlip direction of motor diode\nMap out extra I2C and SPI busses to terminal blocks\nAdd a stepper motor driver\nAdd heat sinks to motor drivers\nRun through pin out of every chip and verify it's connection\nVerify the package footprint of every chip\nAdd ground plane to top and bottom layers\nStitch top and bottom layers together with vias\nAdd pullup resistors/pulldown resistors to data lines\nAdd a second USB port\nAdd a USB switch: USB2422\nAdd a UART to USB coverter: FT232RQ\nAdd LEDs to communication channels\nAdd Series resistors to comm lines, allowing the resistor to be changed\nAdd A4988 stepper motor driver\nAdd GPIO Block with ESD protection\nAdd SPI/UART/I2C with ESD potection on terminal blocks\nAdd labels to terminal blocks, on underside\n
$EndSCHEMATC
