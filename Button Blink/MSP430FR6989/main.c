//Button Blink on the MSP430FR6989
//Jessica Wozniak
//Created: 09/13/17
//Last updated: 9/23/17

#include <msp430FR6989.h>

#define BUTTON BIT1  //defines Button as BIT1
#define LED1 BIT0   //deinfes LED as BIT0

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

P1OUT &= ~LED1;                         // Clear LED bit
P1DIR = LED1;                          // Sets LED as output
P1DIR &= ~BUTTON; //sets BUTTON as input
P1REN ^= BUTTON; //Enables a puller-Resistor on the button-pin
P1OUT ^= BUTTON; //Writes a "1" to the portpin, telling the resistor to pullup
PM5CTL0 &= ~LOCKLPM5;

while(1)
{
    if (!(BUTTON & P1IN)) // if button is not pressed
       P1OUT |= LED1;  // LED on
    else
       P1OUT &= ~LED1; //LED off, if button is not pressed
}
}
