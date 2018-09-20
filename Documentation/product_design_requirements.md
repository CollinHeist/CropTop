# Product Design Requirements

### 1 Peripheral Subsystem
#### 1.1 Microcontroller:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Micocontroller Architecture | 32 bit | High
A to D Converter Count | >4 ADCs | High
A to D Converter Resolution | >16bit | High
A to D Converter Sampling Rate | ? | High
I2C/SPI Pin Count | >6 | High
Supply Voltage | 3.3V | Medium
On Current | <1mA | Medium
Off Current | <1uA | Medium
Clock Speed | >20MHz | Medium
Component Cost | <$10.00| Low

#### 1.2 Temperature and Humidity Sensor:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Relative Humidity Accuracy | <±2 %RH | High
Range of Accurate Operation | >10 to 90 %RH | High
Relative Humidity Resolution | <0.1 %RH | High
Temperature Accuracy | <±0.1 °C | High
Range of Accurate Operation | >-40 to 125 °C | High
Relative Humidity Resolution | <0.1 °C | High
Communication Protocol | I2C or SPI | Medium
Supply Voltage | 3.3V | Medium
On Current | <10mA | Medium
Off Current | <20uA | Medium
Data Sampling Rate | >2Hz | Low
Component Cost | <$30.00 | Low

#### 1.3 GPS Module:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Position Accuracy | <2 meters | High
Reception | ? | High
Communication Protocol | I2C or SPI | Medium
Supply Voltage | 3.3V | Medium
On Current | <25mA | Medium
Off Current | <20uA | Medium
Data Sampling Rate | >1Hz | Low
Component Cost | <$40.00 | Low

#### 1.4 SoM Graphics Processing:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Python Compatible | Linux Compatible | High
Capable of Driving Display | ? | High
Display Connectivity | HDMI/MicroHDMI | High
Communication Protocol | I2C or SPI | Medium
Small Form Factor | SODIMM Package | Medium
Supply Voltage | 3.3V | Medium
On Current | ? | Medium
Off Current | ? | Medium
Component Cost | <$35.00 | Low

#### 1.5-1.8:
- Accelerometer/Position Sensor
- Motor Control for Linear Actuator
- Force Sensor Interface
- 3rd System?

### 2 Display Subsystem
#### 2.1 Display Screen:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Resolution | >800x480 pixels | Medium
Dimensions | >7 inch | Medium
Ruggedness | Scratch, Drop, and Water Proof | Medium
Integration | OEM Component | Medium
Component Cost | <$100 | Low

#### 2.2 Display Driver:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Connectivity | HDMI/MicroHDMI | Medium
Compatibility | Linux and Display | Medium
Component Cost | <$40 | Low

#### 2.3 Touch Screen:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Screen Type | Capacitive or Resistive? | High
Dimensions | Same as Display Screen | High
Integration | With Screen | Medium
Connectivity | USB/I2C/PMP | Medium
Component Cost | <$100 | Low

#### 2.4 Touch Screen Driver:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Screen Type | Capacitive or Resistive? | High
Dimensions | Same as Display Screen | High
Integration | With Screen | Medium
Connectivity | USB/I2C/PMP | Medium
Component Cost | <$100 | Low



#### Battery:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Capacity | ? mAh | High
Water Proof | ? | High
Weight | ? lbs | Medium
Availability | Amazon? | Medium
Connection | USB | Medium
Voltage | 3.3-5V? | Medium
Component Cost | ? $ | Low

#### Case:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Weight | ? lbs | Medium
RF Penetrable | ? | High
Waterproof | ? | High
Dimensions | ? | Medium
Modifiable | Can drill through | Medium
Component Cost | ? $ | Low

#### Barcode Scanner:
Requirements | Measurement | Priority
:------------: | :-------------: | :------------:
Barcode Compatibility | 1D Reflective | High
Connectivity | Wireless USB | High
Battery Life | ? hrs | Medium
Device Cost | < $100 | Low

Questions 
- Data/Programming/OS interface?
- Battery Interface
- How does the force sensor amplifiers work?
- What is the extra opamp for
