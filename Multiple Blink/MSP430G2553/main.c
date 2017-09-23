#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   //stop watchdog timer

    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    P1OUT &= ~BIT6;                         // Clear P2.0 output latch for a defined power-on state
    P1DIR |= BIT6;                          // Set P2.0 to output direction

    int count = 0;
    int count1 = 0;

    // loop allows 2 LED to blink continuously
    while(1)
    {
      if (count >= 15000)
      {
          P1OUT ^= BIT0;
          count = 0;
      }
      if (count1 >= 30000)
      {
          P1OUT ^= BIT6;
          count1 = 0;
      }

      count++;
      count1++;
    }
}
