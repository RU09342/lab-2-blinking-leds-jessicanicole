# Multiple Blink
* Creator: Jessica Wozniak
* Created: Septeber 13, 2017
* Last updated: September 23, 2017

## Libraries Used
* <msp430.h>

## Compatability:
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989
* MSP430G2553

## Differences between Boards
* LED2 pins
** MSP430F5529: P4.7 
** MSP430FR2311: P2.0
** MSP430FR5994: P1.1
** MSP430FR6989: P9.7
** MSP430G2553: P1.6

* All MSP430FR need this line of code " PM5CTL0 &= ~LOCKLPM5; " to disable high impedance mode.

## Overall Program Description
The Multiple Blink Program was made to blink two LEDS at different rates. LED1 (P1.0) was the same on all five board. The remainder of the code was the same for all boards. LED1 and LED2 were set as outputs. Two ints were declared: count and count1. Within an infinite loop, two if statements were used to see if count <= 15000 and count1 <= 30000. Each int was incremented at the end of the while loop. This allowed for the LEDs to blink at different rates.
