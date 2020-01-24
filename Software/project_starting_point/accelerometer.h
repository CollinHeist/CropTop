	/* **************************************************************************
 * File name:   AccelLib.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 3/5/2018
 * Summary:     Contains register addresses and function prototypes pertaining
				to STmicroelectronics LIS3DHTR 3 axis accelerometers.
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

#ifndef __ACCELEROMETER_H__
    #define __ACCELEROMETER_H__

    // Useful macros
    #define     LIS3DHTR_ADDR   (0b0011001) //SA0 pulled high
    #define     AUTO_INCREMENT  (BIT_7)     //or with sub address

    // sub-register addresses
    #define 	STATUS_REG_AUX 	(0x07)	//r
    #define 	OUT_ADC1_L		(0x08)	//r
    #define 	OUT_ADC1_H		(0x09)	//r
    #define 	OUT_ADC2_L		(0x0A)	//r
    #define 	OUT_ADC2_H		(0x0B)	//r
    #define 	OUT_ADC3_L		(0x0C)	//r
    #define 	OUT_ADC3_H		(0x0D)	//r
    #define		WHO_AM_I		(0x0F)	//r, returns 00110011
    #define		CTRL_REG0		(0x1E)	//rw
    #define		TEMP_CFG_REG	(0x1F)	//rw
    #define		CTRL_REG1		(0x20)	//rw
    #define		CTRL_REG2		(0x21)	//rw
    #define		CTRL_REG3		(0x22)	//rw
    #define		CTRL_REG4		(0x23)	//rw
    #define		CTRL_REG5		(0x24)	//rw
    #define		CTRL_REG6		(0x25)	//rw
    #define		REFERENCE		(0x26)	//rw
    #define		STATUS_REG		(0x27)	//r
    #define		OUT_X_L			(0x28)	//r
    #define		OUT_X_H			(0x29)	//r
    #define		OUT_Y_L			(0x2A)	//r
    #define		OUT_Y_H			(0x2B)	//r
    #define		OUT_Z_L			(0x2C)	//r
    #define		OUT_Z_H			(0x2D)	//r
    #define		FIFO_CTRL_REG	(0x2E)	//rw
    #define		FIFO_SRC_REG	(0x2F)	//r
    #define		INT1_CFG		(0x30)	//rw
    #define		INT1_SRC		(0x31)	//r
    #define		INT1_THR		(0x32)	//rw
    #define		INT1_DURATION	(0x33)	//rw
    #define		INT2_CFG		(0x34)	//rw
    #define		INT2_SRC		(0x35)	//r
    #define		INT2_THR		(0x36)	//rw
    #define		INT2_DURATION	(0x37)	//rw
    #define		CLICK_CFG		(0x38)	//rw
    #define		CLICK_SRC		(0x39)	//r
    #define		CLICK_THR		(0x3A)	//rw
    #define		TIME_LIMIT		(0x3B)	//rw
    #define		TIME_LATENCY	(0x3C)	//rw
    #define		TIME_WINDOW		(0x3D)	//rw
    #define		ACT_THS			(0x3E)	//rw
    #define		ACT_DUR			(0x3F)	//rw

    //CTRL_REG0, pullup configuration
    #define    SDO_PU_DISC      (0b10010000)    //disconnect internal pullup to SA0

    //TEMP_CFG_REG (unused)

    //CTRL_REG1, resolution and axis
    #define    HR_NORMAL        (0b10010000)    //high resolution ADC, 1.344 kHz sample
    #define    LP_EN        	(0b00001000)    //low power enable
    #define    Z_EN         	(0b00000100)    //enable Z-axis measurements
    #define    Y_EN     	    (0b00000010)    //enable Y-axis measurements
    #define    X_EN		        (0b00000101)    //enable X-axis measurements

    //CRTL__REG2, high-pass filtering (unused)
    #define    HP_NORMAL        (0b00000000)    //normal mode, reset by reading REFERENCE (26h)

    //CTRL_REG3, interrupts (unused)

    //CTRL_REG4, update and scaling
    #define    BDU_ON_READ		(0b10000000)	//output registers updated on read, default is continuous
    #define    SCALE_2G			(0X00000000)	//full-scale select +/- 2g
    #define    SCALE_4G			(0X00010000)	//full-scale select +/- 4g
    #define    SCALE_8G			(0X00100000)	//full-scale select +/- 8g
    #define    SCALE_16G		(0X00110000)	//full-scale select +/- 16g
    #define    HIGH_RES_EN		(0b00001000)
    #define    ST0_EN 			(0b00000010)	//self test 0 enabled
    #define    ST1_EN			(0b00000100)	//self test 1 enabled

    //CTRL_REG5, FIFO and 4D interrupts
    #define    FIFO_EN			(0b01000000)	//disabled by default

    //CTRL_REG6, interrupt enable and configuration (unused)

    //FIFO_CTRL_REG
    #define    BYPASS			(0b00000000)	//default
    #define    FIFO_EN			(0b01000000)
    #define    STREAM_EN		(0b10000000)
    #define    STREAM_TO_FIFO	(0b11000000)


    // Function Prototypes
    unsigned int initialize_accelerometer(void);
    char AccelLib_SelfTest();
    char AccelLib_SingleWrite(char subreg, char write_val);
    char AccelLib_SingleRead(char subreg);
    void AccelLib_ContinuousRead(char subreg, char* reads, int len);
    float AccelLib_ReadZ();
    float AccelLib_ReadY();
    float AccelLib_ReadX();
    double AccelLib_ReadTilt();
#endif