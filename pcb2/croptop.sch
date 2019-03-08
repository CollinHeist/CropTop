EESchema Schematic File Version 4
LIBS:croptop-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 7
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
S 6300 2750 1200 900 
U 64807BBC
F0 "Microcontroller" 50
F1 "croptop_mcu.sch" 50
$EndSheet
$Sheet
S 6300 5150 1200 900 
U 64809F0C
F0 "Power Supply" 50
F1 "croptop_psu.sch" 50
$EndSheet
$Sheet
S 7700 2750 1200 900 
U 65B709D0
F0 "Display" 50
F1 "croptop_lcd.sch" 50
$EndSheet
$Sheet
S 7700 3950 1200 900 
U 669AB112
F0 "IO Peripherals" 50
F1 "croptop_io.sch" 50
$EndSheet
$Sheet
S 6300 3950 1200 900 
U 66A12230
F0 "Onboard Peripherals" 50
F1 "croptop_onboard.sch" 50
$EndSheet
Text Notes 6300 2400 0    138  ~ 28
List of Schematic Sheets
Text Notes 6250 1600 0    138  ~ 28
System Block Diagram
Text Notes 1250 7850 0    50   ~ 0
List of things to do:\nHow do I route a 90 ohm USB trace\nPut croptop sign in copper layer\nMake sure ohms sign is on all, make sure all are pressed 'O'\nCheck that all components with a pad are connected with solder paste in footprint\nManually check entire board with Ryan, with each datasheet\nCalculate power rail burdens\nAdd and ADC pin that reads version number from resistor divider\nTalk with Ryan about low resistances between supply and rail, to measure current\nOverspec the 3.3V Supply\nAdd over current (short circuit) protection to PMOD\nAdd LED to SPI and I2C Lines, in addition to RS232\nAdd MISO and RX resistors to MCU side, not slave\nShould VBUS and USB3V3 both be connected to 3V\nSeries resistors: (220=20ns delay, 22=5ns delay) (or 10Mhz vs 100Mhz)\nFigure out if ESD diodes will mess up ADC measurements\nAdd enough notes that even an ME can understand the circuit\n\nImplement all 4 types of protection:\nReverse polarity protection: PMOS\nFOLLOW PCB Layout tips (temp, GPS, etc)\nAdd a ground pour to empty planes\nESD protection: TVS diodes\nOvervoltage protection: Buffers and schokttky diodes\nOvercurrent protection: PTC fuses AND eFuses\ndv/dt (rise time) protection: series diodes\nRC filters on the input\nLook into Chris Gammel's powerpoint for more info\n\nCome up with different devices configurations (using DNP for components)\n5 Terminal block pins were used for each force sensor\nDoes DRV_FLT need a pull up?\nLook into thermal vias for motor drivers\nAdd silkscreen labels to configuration resistors\nAdd address of components to sheet\nMore protection on motor and stepper? (Stepper pg. 15)\nMake location of resistor value consistent (inside vs. outside)\nMake sure all devices have testpoint in any useful places\nWhen laying out the footprint for the motor drivers, follow datasheet\nRe add isolation dotted box around ADI ADC\nRemove electrolytic input on DC motor driver\nChange AVDD to 5V0_REG, DVDD to 3V3\nAdd inductor to ADC\nChange nets to have directions\nRemove global nets on power\nAdd missing pullups and pulldowns on temp/memory\nAdd MISO to SPI bus\nAdd resistor to Load bank for current limit\nMake board larger at top, add header blocks\nRemove electrolytic input on DC motor driver\nChange AVDD to 5V0_REG, DVDD to 3V3\nCheck regulators can carry high current\nMove micro usb and lcd connector further forward\nSplit memory and adc spi bus\nFlip direction of motor diode\nMap out extra I2C and SPI busses to terminal blocks\nAdd a stepper motor driver\nAdd heat sinks to motor drivers\nRun through pin out of every chip and verify it's connection\nVerify the package footprint of every chip\nAdd ground plane to top and bottom layers\nStitch top and bottom layers together with vias\nAdd pullup resistors/pulldown resistors to data lines\nAdd a second USB port\nAdd a USB switch: USB2422\nAdd a UART to USB coverter: FT232RQ\nAdd LEDs to communication channels\nAdd Series resistors to comm lines, allowing the resistor to be changed\nAdd A4988 stepper motor driver\nAdd GPIO Block with ESD protection\nAdd SPI/UART/I2C with ESD potection on terminal blocks\nAdd labels to terminal blocks, on underside\nThroughole USB\nGround plane on top and bottom layer\nAdd configurable voltage to IO ports\nMove testpoints onto schematic\nPut I2C address on I2C chips\nMake sure all global nets are facing right direciton\nMake sure all LED resistors are selected\nSPI I2C and RS232 testpoints should be closer to pic, or at fork point\nCheck if DC and Stepper motor needs external flyback diodes\nAll elements that have a pad, make sure that there is a pad pin and it's footprint is has the pad assigned to it\nMake sure all CAP on motor drivers are at least 50V Rated\nChange name of I2C and SPI and RS232 to add numbers and what bus? (tx -> I2C_TX_1)\nMove memory and ADC to different busses\nAdd datasheets for components into schematic\nMake sure that 3V3 rotary encoder buffer resistor is DNP\nLabel Terminal blocks on top side\nChange accellerometer to gyro L3GD20H\nRemove buffer from ADC\nMove ADC over star ground\nFigure out whether off board peripherals need buffer\nGive all devices a 10uF and 0.1uF (100nF) capacitor, at the very least\nCan Stepper motor driver use 3.3V for REF?\nAdd an audio circuit to the FTDI chip (recommends TPA6205A1)\nMove ADC and NAND to different SPI Buses\nMake NAND 1GB instead of 1Gb\n\n\n\n
$Sheet
S 7700 5150 1200 900 
U 5EC973C3
F0 "Connectors" 50
F1 "croptop_conn.sch" 50
$EndSheet
$EndSCHEMATC
