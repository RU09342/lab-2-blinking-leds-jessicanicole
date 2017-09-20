#include <msp430f5529.h>

#define BUTTON BIT1
#define LED1 BIT0

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

P1OUT &= ~LED1;                         // Clear P1.0 output latch for a defined power-on state
P1DIR = LED1;                          // Set P1.0 to output direction

P2DIR &= ~BUTTON;
P2REN ^= BUTTON; //Enables a puller-Resistor on the button-pin
P2OUT ^= BUTTON; //Writes a "1" to the portpin, telling the resistor to pullup

while(1)
{
    if (!(BUTTON & P2IN))
        P1OUT |= LED1;  // Blink Led
    else
       P1OUT &= ~LED1;
}
}
