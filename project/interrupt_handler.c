#include <msp430.h>
#indluce "switched.h"
#include "select_SM.h"

//Swithc on S2

void __interrupt_vec(PORT2_VECTOR) port_2(){
  if(P2IFG & SWITCHES){ //did a button cause this interrupt?
    P2IFG &= ~SWITCHES; //clear pending sw interrupts
    switch_interrupt_handler(); //single handler for all switches
  }
}


void __interrupt_vec(WDT_VECTOR) WDT(){ //250 interrupts/sec
  selcet_SM();
}
