#include <msp430fr5994.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   //stop watchdog timer

    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    P1OUT &= ~BIT1;                         // Clear P2.0 output latch for a defined power-on state
    P1DIR |= BIT1;                          // Set P2.0 to output direction

   PM5CTL0 &= ~LOCKLPM5;

    int count = 0;
    int count1 = 0;
    // loop allows 2 LED to blink continuously
    while(1)
    {
     // P1OUT ^= BIT0;              // toggles red LED on and off
    //  for (count=0;count<15000;count++);    //delay between the toggle
     // P1OUT ^= BIT1;            // toggles green LED on and off
   //   for (count1=0;count1<30000;count1++);    // delay between the toggle (different than delay on red LED) allows for different speed blinks

      if (count >= 15000)
      {
          P1OUT ^= BIT0;
          count = 0;
      }
      if (count1 >= 30000)
      {
          P1OUT ^= BIT1;
          count1 = 0;
      }

      count++;
      count1++;

    }
}
