//macros
#define BUTTON_A    BIT_14                  //port c
#define BUTTON_B    BIT_13                  //port c
#define BUTTONS     (BUTTON_A | BUTTON_B)   //port c
#define LED_A       (0x01)<<1               //port c
#define LED_B       (0x01)<<2               //port c
#define LEDS        (LED_A | LED_B)         //port c