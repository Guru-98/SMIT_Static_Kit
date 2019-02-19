/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012, 2018 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_timer_user.c
* Version      : CodeGenerator for RL78/F13 V2.03.03.01 [28 Oct 2018]
* Device(s)    : R5F10BGG
* Tool-Chain   : CCRL
* Description  : This file implements device driver for TAU module.
* Creation Date: 19/2/2019
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_tau1_channel0_interrupt(vect=INTTM10)
#pragma interrupt r_tau1_channel2_interrupt(vect=INTTM12)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
volatile char _usdelay_f = 0;
volatile char _msdelay_f = 0;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_tau1_channel0_interrupt
* Description  : This function is INTTM10 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_tau1_channel0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	R_TAU1_Channel0_Stop();
	_msdelay_f = 1;
	/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_tau1_channel2_interrupt
* Description  : This function is INTTM12 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_tau1_channel2_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	R_TAU1_Channel2_Stop();
	_usdelay_f = 1;
	/* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void delay_us(uint16_t usec) {
	while (usec){
		_delay_1us();
		usec--;
	}
}

#if 0
void delay(uint16_t msec){
	while (msec){
		_delay_1ms();
		msec--;
	}
}
#else
void delay(uint16_t msec){
	while (msec--);
}
#endif

void _delay_1us(void) {
	_usdelay_f = 0;
	R_TAU1_Channel2_Start();
	while(_usdelay_f == 1);
}

void _delay_1ms(void) {
	_msdelay_f = 0;
	R_TAU1_Channel0_Start();
	while(_msdelay_f == 1);
}


/* End user code. Do not edit comment generated here */
