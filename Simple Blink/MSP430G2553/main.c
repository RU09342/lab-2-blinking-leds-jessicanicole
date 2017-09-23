#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   //stop watchdog timer

    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    int count = 0;

    while(1)                     //created infinite loop
    {
      P1OUT ^= 0x01;              // toggles LED on and off
      for (count=0;count<20000;count++);    // delay between the toggle
    }
}
