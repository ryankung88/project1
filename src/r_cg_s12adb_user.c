/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_s12adb_user.c
* Version      : Applilet4 for RX111 V1.00.00.05 [06 Jun 2013]
* Device(s)    : R5F51115AxFM
* Tool-Chain   : CCRX
* Description  : This file implements device driver for S12ADb module.
* Creation Date: 20/06/2013
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_s12adb.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_cg_cmt.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

/* The functions in this file are generated using "Application Leading Tool (Applilet)" for e2 studio.
 * Warnings exist for interrupt handlers. */

/* End user code. Do not edit comment generated here */



/***********************************************************************************************************************
* Function Name: r_s12ad_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_S12AD_S12ADI0
#pragma interrupt r_s12ad_interrupt(vect=VECT(S12AD,S12ADI0),fint)
#else
#pragma interrupt r_s12ad_interrupt(vect=VECT(S12AD,S12ADI0))
#endif
static void r_s12ad_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */

    /* Store the ADC value into the lower 10 bits of the variable */
    g_timer_adc_period = (uint16_t)(S12AD.ADDR0);

    /* End user code. Do not edit comment generated here */
}


/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
