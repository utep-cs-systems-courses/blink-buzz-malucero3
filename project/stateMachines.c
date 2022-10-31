#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#inlcude "switches.h"


static char led_state = 0;

// as button is pressed, we increment to 3 starting from 0
void toggle_green(){
  red_on = 0;
  green_on = 1;
  led_changed = 1;
  led_update();
  buzzer_set_period(0);
}

