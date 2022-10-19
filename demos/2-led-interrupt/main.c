//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

void change_led();

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}

static char led_state = 0;
static char nCalls = 0;

void __interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  "once we reach interrupt 250 in a second we reset and go to change_led"
  if (nCalls >= 250){
    nCalls = 0;
    change_led();
  }
  nCalls++;
} 

void change_led()
{
  "after a second we enter the switch initially start with 0, turn on the light and change to a 1"
  switch (led_state) {
  case (0):
    P1OUT |= LED_GREEN; "actually red light"
    led_state = 1;
    break;
  case(1):
    P1OUT &= ~LED_GREEN; "after another second come here and turn off the light" 
    led_state = 0;
    break;
  default:
    led_state = 0;
    break;
    "This continues to alternate infinitely unless button is pushed (resets)"
  }
}
