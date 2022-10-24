#include <msp430.h>
#indluce "switched.h"
#include "select_SM.h"

//Swithc on S2

void __interrupt_vec(PORT2_VECTOR) port_2(){
  if(P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}


void __interrupt_vec(WDT_VECTOR) WDT(){
  selcet_SM();
}
