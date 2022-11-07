#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "select_SM.h"

void select_SM()
{
  static char blink_cout = 0;
  static char buzzCount = 0;

  switch (n_switch_down){
  case 1:
    toggle_green();
      break;
  case 2:
    dimming_state_machines();
    break;
  case 3:
    imp();
    break;
  case 4:
  default:
    off_leds_buzzer();
  }
}


