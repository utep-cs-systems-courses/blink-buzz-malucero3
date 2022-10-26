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

      break;
  case 2:

    break;
  case 3:

    break;
  case 4:
  default:
    off_leds_buzzer();
  }
}

