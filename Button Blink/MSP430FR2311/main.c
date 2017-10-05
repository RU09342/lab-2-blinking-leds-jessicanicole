//Button Blink on the MSP430FR2311
//Jessica Wozniak
//Created: 09/13/17
//Last updated: 9/23/17

#include <msp430.h>

#define BUTTON BIT1
#define LED1 BIT0

void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

P1OUT &= ~LED1;                         // Sets initial state of LED to off
P1DIR = LED1;                          // Set LED as output

P1DIR &= ~BUTTON;  //Sets BUTTON as an input
P1REN ^= BUTTON; //Enables a puller-Resistor on the button-pin
P1OUT ^= BUTTON; //Writes a "1" to the portpin, telling the resistor to pullup
PM5CTL0 &= ~LOCKLPM5;   //disables high impedance mode

while(1)   //creates infinite loop
{
    if (!(BUTTON & P1IN))  //if button is not pressed
        P1OUT |= LED1;  // LED on
    else
       P1OUT &= ~LED1; //if button is pressed, LED off
}
}
