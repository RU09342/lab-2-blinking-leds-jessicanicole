# Button Blink
 Creator: Jessica Wozniak
 Created: September 13, 2017
 Last updated: September 23, 2017
 
# Basic Program Capabilities
These programs were created to blink an LED by using a button five different development boards : MSP430FR2311, MSP430FR5994, MSP430FR6989, MSP430F5529 and, MSP430G2553. The first set of codes were using the button as a simple switch. When the button was pressed, the LED was on and when the button was not pressed, the LED was off. The codes were the same for all of the boards, with the exception of pin numbers, and on the MSP430FR boards the line "PM5CTL0 &= ~LOCKLPM5" has to be present to disable high impedance mode. The LED pin had to be set as output and the button pin had to be set as an input.
The next set of codes were made to have the led blinking when the button was not pressed and the LED to be off when the button was pressed. It was simple to go from the first code to this code. I essentially used the code from my simple blink, and implemented that within the "if" statement. 

# Extra Work 


 