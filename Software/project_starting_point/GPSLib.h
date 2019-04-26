	/* **************************************************************************
 * File name:   GPSLib.h
 * Association: University of Idaho
 * Author:      Ryan Donahue
 * Dates:       Created 4/12/2018
 * Summary:     
 * *************************************************************************/
#define _SUPPRESS_PLIB_WARNING

//macros
#define 	GPS_ADDR 	0x42
#define 	SYNC_1 		0xb5
#define		SYNC_2		0x62
#define		MSG_LEN_MSB	0xFD
#define		MSG_LEN_LSB	0xFE
#define		GPS_DATA	0xFF

//UBX Class IDs, classes are groupings of messages related to each other
#define		NAV			0x01	//Navigation Results Messages: Position, Speed, Time, Acceleration, Heading, DOP, SVs used
#define		RXM			0x02	//Receiver Manager Messages: Satellite Status, RTC Status
#define		INF			0x04	//Information Messages: Printf-Style Messages, with IDs such as Error, Warning, Notice
#define		ACK			0x05	//Ack-Nak Messages: Acknowledge or Reject messages to UBX-CFG input messages
#define		CFG			0x06	//Configuration Input Messages: Set Dynamic Model, Set DOP Mask, Set Baud Rate, etc
#define		UPD			0x09	//Firmware Update Messages: Memory/Flash erase/write, Reboot, Flash identification, etc.
#define		MON			0x0A	//Monitoring Messages: Communication Status, CPU Load, Stack Usage, Task Status
#define		AID			0x0B	//AssistNow Aiding Messages: Ephemeris, Almanac, other A-GPS data input
#define		TIM			0x0D	//Timing Messages: Time Pulse Output, Time Mark Results
#define		ESF			0x10	//External Sensor Fusion Messages: External Sensor Measurements and Status Information
#define		MGA			0x13	//Multiple GNSS Assistance Messages: Assistance data for various GNSS
#define		LOG			0x21	//Logging Messages: Log creation, deletion, info and retrieval
#define		SEC			0x27	//Security Feature Messages
#define		HNR			0x28	//High Rate Navigation Results Messages: High rate time, position, speed, heading

//NAV message IDs
#define     NAV_CLK     0x22    //time of week, clk bias, clk drift, time accuracy, frequency accuracy (20-bytes)
#define     NAV_PVT     0x07    //Navigation Position Velocity Time Solution (92-bytes)
#define     NAV_STATUS  0x03
#define     NAV_POSLLH  0x02

//MON message IDs
#define     MON_VER     0x04    //Poll Receiver/Software Version

//CFG message IDs
#define     CFG_NAV5    0x24    //Navigation Engine Settings
#define     CFG_NMEA    0x17
#define     CFG_GNSS    0x3E

//HNR message IDs
#define     HNR_PVT     0x00

//function prototypes
char GPSLib_Init();
int GPSLib_MessageCount();
char GPSLib_Read(char* read);
char GPSLib_UBXWrite(unsigned char class_id,unsigned char msg_id, unsigned char* payload,unsigned short payload_len);
void GPSLib_UBXChecksum(unsigned char* data,int payload_len);