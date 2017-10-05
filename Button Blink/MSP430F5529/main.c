//Button Blink on the MSP430F5529
//Jessica Wozniak
//Created: 09/13/17
//Last updated: 9/23/17

#include <msp430f5529.h>

#define BUTTON BIT1
#define LED1 BIT0

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

P1OUT &= ~LED1;                         //Clears LED bit
P1DIR = LED1;                          // Sets LED as output

P2DIR &= ~BUTTON; //Sets BUTTON as intput
P2REN ^= BUTTON; //Enables a puller-Resistor on the button-pin
P2OUT ^= BUTTON; //Writes a "1" to the portpin, telling the resistor to pullup

while(1) //creates infinite loop
{
    if (!(BUTTON & P2IN)) //if button is not pressed
        P1OUT |= LED1;  // LED on
    else
       P1OUT &= ~LED1; // if button is pressed, LED off
}
}
