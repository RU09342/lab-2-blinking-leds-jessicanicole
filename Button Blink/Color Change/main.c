//Button Blink Color Change  MSP430FR2311
//Jessica Wozniak
//Created: 9/15/17
//Last updated: 10/1/17

#include <msp430fr2311.h>

#define BUTTON BIT1
#define REDLED BIT0
#define GREENLED BIT0

void main(void)
 {

  WDTCTL = WDTPW|WDTHOLD;       // Disables the Watchdog Timer

  int color = 1;                  //int for LED

  P1DIR |= REDLED;                  // Sets REDLED as output
  P2DIR |= GREENLED;                // Sets GREENLED as output

  P1REN = BUTTON;                     //Enables a puller-Resistor on the button-pin
  P1OUT = BUTTON;                     //Writes a "1" to the portpin, telling the resistor to pullup

  PM5CTL0 &= ~LOCKLPM5;   //disables high impedance mode

  while(1)
  {                                   // Creates an infinite loop
    if(!(BUTTON & P1IN))
    {                                 // If button is pressed
      __delay_cycles(5000);           // Delay
     color = !color;                  // Toggles the value of the LED
    }

    switch (color)                    // Creates a switch statement to chose the LED color
    {
      case 0 :
      P1OUT ^= (REDLED);              // Blink REDLED
      P2OUT &= ~GREENLED;             // GREENLED off
      __delay_cycles(75000);          // delay between blink (The REDLED blinks faster than GREENLED)
      break;

      case 1  :
      P2OUT ^= (GREENLED);            // Blink GREENLED
      P1OUT &= ~REDLED;               // REDLED off
      __delay_cycles(175000);          // delay between blink (GreenLED binks slower than REDLED
      break;

    }
  }
 }

