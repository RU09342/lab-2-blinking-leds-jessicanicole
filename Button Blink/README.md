# Button Blink
* Creator: Jessica Wozniak
* Created: September 13, 2017
* Last updated: September 23, 2017

## Libraries Used
* <msp430.h>

## Compatability:
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989
* MSP430G2553

* All MSP430FR need this line of code " PM5CTL0 &= ~LOCKLPM5; " to disable high impedance mode.
* BUTTON1 pins
** MSP430F5529: P2.1
** MSP430FR2311: P1.1
** MSP430FR5994: P5.6
** MSP430FR6989: P1.1
** MSP430G2553: P1.3

## Overall Program Capabilities
* The Button Blink program was created to blink an LED by using a button. The first set of codes were using the button as a simple switch. When the button was pressed, the LED was on and when the button was not pressed, the LED was off. The codes were the same for all of the boards except on the MSP430FR boards the line "PM5CTL0 &= ~LOCKLPM5" has to be present to disable high impedance mode. The LED pin was set as an output and the button was set as an input.
* The next set of codes were made to have the LED blinking when the button was not pressed and the LED to be off when the button was pressed. It was simple to go from the first code to this code. I essentially used the code from my simple blink, and implemented that within the "if" statement. 

## Extra Work 
### Speed Change
For the speed change, the button was to be used to switch from one speed to another to another.. etc. I chose to do five speeds: off, slow, medium, fast, and very fast. To complete this task a switch case statement was used within an infinite while loop. Inside each case statement I used code from my simple blink and just changed the delay speed for each case. 
### Color Change 
For the color change, I also used a swicth case statement. In case 0, I made the red LED blink and in case 1, the green LED blinked (using simple blink code).


 