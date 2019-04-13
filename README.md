# CropTop
CropTop is a small-form data acquisition platform being developed by [Kennedy Caisley](https://github.com/kcaisley) and [Ryan Donahue](https://github.com/ryand323), two undergraduate electrical engineering students at the University of Idaho. It is designed to support the cereal grain crop strength research being conducted by [Dr. Daniel Roberston](https://www.uidaho.edu/engr/departments/me/our-people/faculty/daniel-robertson) in the UI Department of Mechanical Engineering.

## What can CropTop do?
Croptop is based around a 32 bit PIC32MX795F512L microcontroller and includes the following peripherals onboard:
* 12 bit temperature/humidity sensor
* 3-axis accelerometer
* ΔΣ 24 bit 1kSPS ADC
* GNSS receiver
* USB 2.0 OTG interface
* 5A DC motor controller
* TFT LCD controller
* Resistive touch controller
* Rotary encoder interface
* Linear encoder interface
* 1GB NAND flash
* User programmable push buttons
* User programmable LEDs
* 14 additional GPIO

#### Assembled Prototype
![Prototype Front](docs/images/IMG_7746.JPG?raw=true "Title")
![Prototype Back](docs/images/IMG_7747.JPG?raw=true "Title")

#### Gerber
![Gerber of board](docs/images/gerb.PNG?raw=true "Title")

## Understanding and Configuring Hardware

#### Installing KiCAD
KiCAD EDA offers open source schematic capture and PCB layout tools. The software can be downloaded [here](http://kicad-pcb.org/download/)

A video tutorial covering basic work-flow can be found here: (eventually) 

KICAD community suggested training modules can be found: [here](http://kicad-pcb.org/help/tutorials/)

#### File Locations
links to
* Schematic
* BOM
* Gerbers
* Project files

#### Hardware Configuration 
* Voltage levels
* Resistor divider for software modes.)

#### Making a Daughter Board
instruction/guide to mating a board to the croptop board

#### Manufacturing and Ordering Boards
* Logging into Macrofab
* Specifying chips for populate or do not populate (DNP)

## Understanding and Creating Software
How to get the MPLAB environment up and running, understand the control flow of drivers and IC drivers, and program the device

#### MPLAB Installation
MPLAB is Microchip's Interactive Development Environment (IDE) 
The tool offers dedicated debug, programming, and configuration tools for Microchip's processors.

Setup requires three steps:
1. Install [MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide "MPLAB X IDE")
2. Install [XC32 Compiler](https://www.microchip.com/mplab/compilers "XC32 Compilers")
3. Install the [Legacy Peripheral Libraries](https://www.microchip.com/SWLibraryWeb/product.aspx?product=PIC32%20Peripheral%20Library "legacy peripheral libraries")

Microchip's help guide for installation is found here: [Microchip Developer](http://microchipdeveloper.com/tls0101:get-mplabx "Microchip Developer")

#### Git Installation
The Git project chose guarantee your freedom to share and change free software. CropTop was developed with this tool and offers the most efficient method of distributing and controlling the project.

Install [Git](https://git-scm.com/downloads "Git")

A tutorial covering basic work-flow can be found [here](https://evanwill.github.io/get-git/), but many others exist

To pull a repository to a new device, run git bash and execute the following
```
git clone https://github.com/kcaisley/CropTop.git
```

A few other useful commands are:
```
git pull
git status
git add
git commit
git branch
git merge
```

#### Using MPLAB 
A [video tutorial](https://vimeo.com/user96989107/review/328287810/0cc609795f) on using MPLAB

A highly recommended [tutorial](http://cslibrary.stanford.edu/101/EssentialC.pdf) from Stanford will teach you the basics of
* Data types and operators
* Control structures
* Functions

But, asking questions on [stack exchange](https://stackexchange.com/) is essential to learning the nuances of C programming

#### Control Flow Diagram 
* drivers
* peripheral libraries
* middleware 
* application

#### CropTop Drivers
Every driver PIC32 peripheral or Integrated Circuit (IC) driver has an associated .c and .h file adhering to a [CropTop coding standard](https://github.com/kcaisley/CropTop/tree/master/Software)

For longevity of the project, it is encouraged to be consistent with the project structure.

#### Creating New Screens
instructions

#### Device Programming
using the PICKIT programming header in MPLAB, and photo of connection to croptop

## Integration Guide
How the board interacts with system

#### Calibrating Sensors
How to calibrate guide

#### Powering the Device
How to power on devices

### Specifications
Electrical Characteristics of sensors and power supplies

#### Creating and Using Data
How to export, interpret, and use the data CropTop logs