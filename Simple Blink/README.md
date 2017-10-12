# Simple Blink
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
* All MSP430FR need this line of code " PM5CTL0 &= ~LOCKLPM5; " to disable high impedance mode.

## Program Description
The Simple Blink program was created to blink a single LED. Fortunately LED1(Red LED) was P1.0 for all boards, and almost no manipulation was needed between the five boards. While in an infinite loop, a bitwise XOR was performed to the toggle LED1 output. A delay was implented after each toggle using predefined __delay_cycles(). The infinite loop continues to toggle the LED after the delay. 
