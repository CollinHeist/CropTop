	/* **************************************************************************
 * File name:   AccelLib.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 3/5/2018
 * Summary:     Contains register addresses and function prototypes pertaining
				to STmicroelectronics LIS3DHTR 3 axis accelerometers.
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

//macros
#define     _ADDR   (0b0011001)

// sub-register addresses

//function prototypes
char GPSLib_Init();
char GPSLib_SingleWrite(char subreg, char write_val);
char GPSLib_SingleRead(char subreg);
void GPSLib_ContinuousRead(char subreg, char* reads, int len);