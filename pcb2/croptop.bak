EESchema Schematic File Version 4
LIBS:croptop-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 5
Title "CropTop 2.0"
Date "2019-03-18"
Rev "Revision 12"
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
SCHEMATIC:\nBOM: Reference Description Quantity Manu. MPN\nShould Power rails be software or hardware enabled?\nMake sure ohms sign is on all, make sure all are pressed 'O'\nAdd and ADC pin that reads version number from resistor divider\nTalk with Ryan about low resistances between supply and rail, to measure current\nOverspec the 3.3V Supply\nAdd over current (short circuit) protection to PMOD\nAdd LED to SPI and I2C Lines, in addition to RS232\nAdd MISO and RX resistors to MCU side, not slave\nShould VBUS and USB3V3 both be connected to 3V\nThroughole USB\nAdd pullup resistors/pulldown resistors to data lines\nAdd a second USB port\nAdd a USB switch: USB2422\nAdd a UART to USB coverter: FT232RQ\nAdd LEDs to communication channels\nAdd Series resistors to comm lines, allowing the resistor to be changed\nAdd A4988 stepper motor driver\nAdd GPIO Block with ESD protection\nAdd SPI/UART/I2C with ESD potection on terminal blocks\nAdd a stepper motor driver\nAdd an audio circuit to the FTDI chip (recommends TPA6205A1)\nAdd enough notes that even an ME can understand the circuit\nAdd missing pullups and pulldowns on temp/memory\nAdd MISO to SPI bus\nAdd resistor to Load bank for current limit\nSeries resistors: (220=20ns delay, 22=5ns delay) (or 10Mhz vs 100Mhz)\nAdd address of components to sheet\nMore protection on motor and stepper? (Stepper pg. 15)\nMake location of resistor value consistent (inside vs. outside)\nMake sure all devices have testpoint in any useful places\nChange AVDD to 5V0_REG, DVDD to 3V3\nAdd inductor to ADC\nChange nets to have directions\nRemove global nets on power\nSplit memory and adc spi bus\nAdd datasheets for components into schematic\nAdd configurable voltage to IO ports\nMove testpoints onto schematic\nMake sure all global nets are facing right direciton\nMake sure all LED resistors are selected\nDoes DRV_FLT need a pull up?\nCheck if DC and Stepper motor needs external flyback diodes\nChange accellerometer to gyro L3GD20H\nRemove buffer from ADC\nFigure out whether off board peripherals need buffer\nMake sure all CAP on motor drivers are at least 50V Rated\nCan Stepper motor driver use 3.3V for REF?\nChange name of I2C and SPI and RS232 to add numbers and what bus? (tx -> I2C_TX_1)\nMove ADC and SD to different SPI Buses\nMake NAND 1GB instead of 1Gb\nFillout partnumber and datasheet for all components\nGive all devices a 10uF and 0.1uF (100nF) capacitor, at the very least\n\nPCB:\nAll elements that have a pad, make sure that there is a pad pin and it's footprint is has the pad assigned to it\nCheck that all components with a pad are connected with solder paste in footprint\nAdd a cut out around temperature sensor (SHT35-D)\nAdd vias to mounting holes for style\nMake logo in copper layer, not silkscreen\nHow do I route a 90 ohm USB trace\nPut croptop sign in copper layer\nMove ADC over star ground\nMove memory and ADC to different busses\nAdd heat sinks to motor drivers\nGround plane on top and bottom layer\nLook into thermal vias for motor drivers\nAdd silkscreen labels to configuration resistors\nWhen laying out the footprint for the motor drivers, follow datasheet\nMove micro usb and GPU connector further forward\nAdd ground plane to top and bottom layers\nStitch top and bottom layers together with vias\nSPI I2C and RS232 testpoints should be closer to pic, or at fork point\nLabel Terminal blocks on top side\nMake test points bigger {--> R y a n   t o l d   y o u   t o o <--}\n\nCOMPLETION STEPS:\nManually check entire board with Ryan, with each datasheet\nCalculate power rail burdens\nFigure out if ESD diodes will mess up ADC measurements\nCome up with different devices configurations (using DNP for components)\nRun through pin out of every chip and verify it's connection\nVerify the package footprint of every chip\nMake sure that 3V3 rotary encoder buffer resistor is DNP\n
$EndSCHEMATC
