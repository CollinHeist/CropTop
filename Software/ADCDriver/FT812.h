#define BUTTON_A    BIT_14

//------------SPI Prefixes-------------
#


//------------Host commands macros------------
//Power Modes
#define ACTIVE          0x00
#define STANDBY         0x41
#define SLEEP           0x42
#define PWRDOWN         0x43
#define PD_ROMS         0x49

//Clock and Reset
#define CLKEXT          0x44
#define CLKINT          0x48
#define CLKSEL          0x61
#define RST_PULSE       0x68

//Configuration
#define PINDRIVE        0x70
#define PIN_PD_STATE    0x71

//------------Register address macros------------
#define REG_ID 					0x302000
#define REG_FRAMES 				0x302004
#define REG_CLOCK 				0x302008
#define REG_FREQUENCY 			0x30200C
#define REG_RENDERMODE 			0x302010
#define REG_SNAPY 				0x302014
#define REG_SNAPSHOT 			0x302018
#define REG_SNAPFORMAT 			0x30201C
#define REG_CPURESET 			0x302020
#define REG_TAP_CRC 			0x302024
#define REG_TAP_MASK 			0x302028
#define REG_HCYCLE 				0x30202C
#define REG_HOFFSET 			0x302030
#define REG_HSIZE 				0x302034
#define REG_HSYNC0 				0x302038
#define REG_HSYNC1 				0x30203C
#define REG_VCYCLE 				0x302040
#define REG_VOFFSET 			0x302044
#define REG_VSIZE 				0x302048
#define REG_VSYNC0				0x30204C
#define REG_VSYNC1 				0x302050
#define REG_DLSWAP 				0x302054
#define REG_ROTATE 				0x302058
#define REG_OUTBITS 			0x30205C
#define REG_DITHER 				0x302060
#define REG_SWIZZLE 			0x302064
#define REG_CSPREAD 			0x302068
#define REG_PCLK_POL 			0x30206C
#define REG_PCLK 				0x302070
#define REG_TAG_X 				0x302074
#define REG_TAG_Y 				0x302078
#define REG_TAG 				0x30207C
#define REG_VOL_PB 				0x302080
#define REG_VOL_SOUND 			0x302084
#define REG_SOUND 				0x302088
#define REG_PLAY 				0x30208C
#define REG_GPIO_DIR 			0x302090
#define REG_GPIO 				0x302094
#define REG_GPIOX_DIR 			0x302098
#define REG_GPIOX 				0x30209C
#define REG_INT_FLAGS 			0x3020A8
#define REG_INT_EN 				0x3020AC
#define REG_INT_MASK 			0x3020B0
#define REG_PLAYBACK_START 		0x3020B4
#define REG_PLAYBACK_LENGTH 	0x3020B8
#define REG_PLAYBACK_READPTR 	0x3020BC
#define REG_PLAYBACK_FREQ 		0x3020C0
#define REG_PLAYBACK_FORMAT 	0x3020C4
#define REG_PLAYBACK_LOOP 		0x3020C8
#define REG_PLAYBACK_PLAY 		0x3020CC
#define REG_PWM_HZ 				0x3020D0
#define REG_PWM_DUTY 			0x3020D4
#define REG_MACRO_0 			0x3020D8
#define REG_MACRO_1 			0x3020DC
#define REG_CMD_READ 			0x3020F8
#define REG_CMD_WRITE 			0x3020FC
#define REG_CMD_DL 				0x302100
#define REG_TOUCH_MODE 			0x302104
#define REG_TOUCH_ADC_MODE 		0x302108
#define REG_TOUCH_CHARGE 		0x30210C
#define REG_TOUCH_SETTLE 		0x302110
#define REG_TOUCH_OVERSAMPLE 	0x302114
#define REG_TOUCH_RZTHRESH 		0x302118
#define REG_TOUCH_RAW_XY 		0x30211C
#define REG_TOUCH_RZ 			0x302120
#define REG_TOUCH_SCREEN_XY  	0x302124
#define REG_TOUCH_TAG_XY 		0x302128
#define REG_TOUCH_TAG 			0x30212C
#define REG_TOUCH_TAG1_XY 		0x302130
#define REG_TOUCH_TAG1 			0x302134
#define REG_TOUCH_TAG2_XY 		0x302138
#define REG_TOUCH_TAG2 			0x30213C
#define REG_TOUCH_TAG3_XY 		0x302140
#define REG_TOUCH_TAG3 			0x302144
#define REG_TOUCH_TAG4_XY 		0x302148
#define REG_TOUCH_TAG4 			0x30214C
#define REG_TOUCH_TRANSFORM_A 	0x302150
#define REG_TOUCH_TRANSFORM_B 	0x302154
#define REG_TOUCH_TRANSFORM_C 	0x302158
#define REG_TOUCH_TRANSFORM_D 	0x30215C
#define REG_TOUCH_TRANSFORM_E 	0x302160
#define REG_TOUCH_TRANSFORM_F 	0x302164
#define REG_TOUCH_CONFIG 		0x302168
#define REG_BIST_EN 			0x302174
#define REG_TRIM 				0x302180
#define REG_ANA_COMP 			0x302184
#define REG_SPI_WIDTH 			0x302188
#define REG_TOUCH_DIRECT_XY 	0x30218C
#define REG_TOUCH_DIRECT_Z1Z 	0x302190
#define REG_DATESTAMP 			0x302564
#define REG_CMDB_SPACE 			0x302574
#define REG_CMDB_WRITE 			0x302578








void wr8(a,b);
void wr16(a,b);


unsigned char 
unsigned short
unsigned int



void wr32(a,b)
