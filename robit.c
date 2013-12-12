#include "robit.h"
#include <msp430.h>
/*
 * robot.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Alex.Strom
 */
void initRobot(){
	   P1DIR |= BIT1;                // TA0CCR1 on P1.1
	   P1SEL |= BIT1;                // TA0CCR1 on P1.1
	   P1DIR |= BIT2;                // TA0CCR1 on P1.2
	   P1SEL |= BIT2;                // TA0CCR1 on P1.2
	   P2DIR |= BIT1;                // TA0CCR1 on P1.2
	   P2SEL |= BIT1;                // TA0CCR1 on P1.2
	   P2DIR |= BIT0;                // TA0CCR1 on P1.2
	   P2SEL |= BIT0;                // TA0CCR1 on P1.2

}

void initTimer(){



   TA0CTL &= ~(MC1|MC0);            // stop timer A0
   TA1CTL &= ~(MC1|MC0);

   TA0CTL |= TACLR;
   TA1CTL |= TACLR;

   TA0CTL |= TASSEL1;
   TA1CTL |= TASSEL1;

   TA0CCR0 = 100;
   TA0CCR1 = 45;

   TA1CCR0 = 100;
   TA1CCR1 = 55;

   TA0CCTL1 &= ~OUTMOD_5;
   TA0CCTL0 &= ~OUTMOD_5;
   TA1CCTL1 &= ~OUTMOD_5;
   TA1CCTL0 &= ~OUTMOD_5;

   TA0CTL |= MC0;
   TA1CTL |= MC0;

  }



void moveRightMotorB(){ //turns out went opposite way
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

	TA1CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_7;

	TA0CTL |= MC0; // count up
	TA1CTL |= MC0;
}

void moveLeftMotorF(){
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

	TA0CCTL0 |= OUTMOD_5;
	TA0CCTL1 |= OUTMOD_7;

	TA0CTL |= MC0; // count up
	TA1CTL |= MC0;

}

void moveRightMotorF(){
	TA1CTL &= ~MC0;
	TA1CTL &= ~MC1;

	TA1CCTL0 &= ~OUTMOD_4;
	TA1CCTL0 &= ~OUTMOD_5;
	TA1CCTL1 &= ~OUTMOD_7;
	TA1CCTL1 &= ~OUTMOD_5;

	TA1CCTL0 |= OUTMOD_4;  //reset/set mode
	TA1CCTL1 |= OUTMOD_5;

	TA0CTL |= MC0; // count up
	TA1CTL |= MC0;
}

void moveLeftMotorB(){
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

	TA0CCTL0 &= ~OUTMOD_4;
	TA0CCTL0 &= ~OUTMOD_5;
	TA0CCTL1 &= ~OUTMOD_7;
	TA0CCTL1 &= ~OUTMOD_5;

	TA0CCTL0 |= OUTMOD_4;  //reset/set mode
	TA0CCTL1 |= OUTMOD_5;

	TA0CTL |= MC0; // count up
	TA1CTL |= MC0;
}

void moveForward(){
	moveRightMotorF();
	moveLeftMotorF();
}
void moveBack(){
	moveRightMotorB();
	moveLeftMotorB();
}

void moveRight(){
	moveLeftMotorF();
	moveRightMotorB();
}
void moveLeft(){
	moveRightMotorF();
	moveLeftMotorB();
}

