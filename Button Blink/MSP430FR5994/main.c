//Button Blink on the MSP430FR5994
//Jessica Wozniak
//Created: 09/13/17
//Last updated: 9/23/17

#include <msp430FR5994.h>

#define BUTTON BIT6  //defines BUTTON as BIT6
#define LED1 BIT0   //defines LED as BIT0

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

P1OUT &= ~LED1;                         // Clears LED bit
P1DIR = LED1;                          // Set LED as output
P5DIR &= ~BUTTON;                   //sets button as input
P5REN ^= BUTTON; //Enables a puller-Resistor on the button-pin
P5OUT ^= BUTTON; //Writes a "1" to the portpin, telling the resistor to pullup
PM5CTL0 &= ~LOCKLPM5;   // disables high impedance mode

while(1)    // creates infinite loop
{
    if (!(BUTTON & P5IN))   // if button is not pressed
       P1OUT |= LED1;  // LED on
    else
       P1OUT &= ~LED1;  //If button is pressed, LED off
}
}
