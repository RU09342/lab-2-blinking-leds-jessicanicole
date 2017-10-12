//Button Blink Different Speeds MSP430FR2311
//Jessica Wozniak
//Created: 9/15/17
//Last updated: 10/1/17


#include <msp430.h>

#define BUTTON BIT1
#define LED1 BIT0

void main(void)
{

int speed = 0;                          //int for speed

WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer

P1DIR |= LED1;                          // Set LED1 to output

P1REN = BUTTON;                         //Enables a puller-Resistor on the button-pin
P1OUT = BUTTON;                         //Writes a "1" to the portpin, telling the resistor to pullup

PM5CTL0 &= ~LOCKLPM5;                   //disables high z mode

while(1)
{                                       // Creates infinite loop
  if(!(BUTTON & P1IN))
  {                                     // If BUTTON is pressed
    __delay_cycles(10000);              // Delay
    speed = speed + 1;                  //increments speed, which is the case select vaiable
  }

switch (speed)                          //switch depending on value of speed
{
case 0:
    P1OUT &= ~LED1;                     //LED off
         break;
case 1:
    P1OUT ^= LED1;                      // toggles LED on and off
    __delay_cycles(135000);             // delay between the toggle
         break;
case 2:
    P1OUT ^= LED1;                      // toggles LED on and off
    __delay_cycles(105000);             // delay between the toggle
         break;
case 3:
    P1OUT ^= LED1;                      // toggles LED on and off
    __delay_cycles(75000);              // delay between the toggle
         break;
case 4:
    P1OUT ^= LED1;                      // toggles LED on and off
    __delay_cycles(50000);              // delay between the toggle
         break;
case 5:
         speed = 0;                     //reset speed to 0 so switch statement repeats
         break;
}

}
}
