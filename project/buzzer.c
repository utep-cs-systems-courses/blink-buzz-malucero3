#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
  /* Directed timer A output "TA0.1" to P2.6. 

   */
  timerAUpmode();
  P2SEL2 &= ~(BIT6 |BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

unsigned short curr_rate = 125;
unsigned short curr_period = 0;

void buzzer_set_period(unsigned short cycles) //buzzer clock = 2Mhz
{
  CCR0 = cycles;
  CCR1 = cycles >> 1; // one half cycle
}
  
