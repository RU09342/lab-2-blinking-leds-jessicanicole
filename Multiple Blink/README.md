# Multiple Blink
### Creator: Jessica Wozniak
### Created: Septeber 13, 2017
### Last updated: September 23, 2017

## Compatability:
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989
* MSP430G2553

# Program Description
The Multiple Blink Program was made to blink two LEDS at different rates. LED1 (P1.0) was the same on all five board. As for LED2 each board was different:
* MSP430F5529: P4.7 
* MSP430FR2311: P2.0
* MSP430FR5994: P1.1
* MSP430FR6989: P9.7
* MSP430G2553: P1.6

The remainder of the code was the same for all boards. Each LED was set as an output. Two ints were declared: count and count1. Within an infinite loop, two if statements were used to see if count and count1 were less than or equal to a chosen value. I chose to make the two numbers 15000 and 30000. Each int was incremented at the end of the while loop. When This allowed for the LEDs to blink at different rates.

# Extra Work