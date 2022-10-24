#include led_included
#define led_included
#include <msp430.h>

#define LED_GREEN BIT0 // P1.0
#define LED_RED BIT6 //P1.6
#define LEDS (BIT0 | PIT6)

extern unsigned char redOn, greenOn;
extern unsigned char led_changed;

void led_init();
void led_update();


extern unsigned char leds_changed, green_led_state, red_led_state;

#endif //included
