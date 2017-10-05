//Button Blink on the MSP430G2553
//Jessica Wozniak
//Created: 09/13/17
//Last updated: 9/23/17

#include <msp430g2553.h>

#define BUTTON BIT3  //defines BUTTON as BIT3
#define LED1 BIT0    //Defines LED1 as BIT0

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

P1OUT &= ~LED1;                         // sets initial state of LED1 (P1.0)
P1DIR = LED1;                          // Set LED as an output

P1DIR &= ~BUTTON; // sets button as an input
P1REN ^= BUTTON; //Enables a puller-Resistor on the button-pin
P1OUT ^= BUTTON; //Writes a "1" to the portpin, telling the resistor to pullup

while(1)  //creates infinite loop
{
    if (!(BUTTON & P1IN))  //if BUTTON is not pressed
    {
       P1OUT |= LED1;  // LED on
    }
    else
       P1OUT &= ~LED1; //LED off when button is pressed
}
}
