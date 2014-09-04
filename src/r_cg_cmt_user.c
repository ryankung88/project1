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
* File Name    : r_cg_cmt_user.c
* Version      : Applilet4 for RX111 V1.00.00.05 [06 Jun 2013]
* Device(s)    : R5F51115AxFM
* Tool-Chain   : CCRX
* Description  : This file implements device driver for CMT module.
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
#include "r_cg_cmt.h"
/* Start user code for include. Do not edit comment generated here */
#include "switch.h"
#include <stddef.h>
#include "r_cg_icu.h"
#include "flashled.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

/* The functions in this file are generated using "Application Leading Tool (Applilet)" for e2 studio.
 * Warnings exist for interrupt handlers and callback functions. */

volatile uint8_t switchPressCallBackFlag = 0U;

/* Variable for storing the ADC value used to control the timer */
volatile uint16_t g_timer_adc_period;

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_cmt_cmi0_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_CMT0_CMI0
#pragma interrupt r_cmt_cmi0_interrupt(vect=VECT(CMT0,CMI0),fint)
#else
#pragma interrupt r_cmt_cmi0_interrupt(vect=VECT(CMT0,CMI0))
#endif
static void r_cmt_cmi0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */

    /* Stop the CMT0 timer running */
    R_CMT0_Stop();

    /* clear interrupt flag */
    IR(CMT0,CMI0) = 0U;

 
    /* Check if switch 1 hold flag is set, IRQ0 */
    if ((g_switch_flag & 0x0F) & SWITCHHOLD_1)
    {
        /* Check if switch 1 pin level is high (switch press duration
           less than debounce, invalid switch press) */
        if (0x1 == SW1_PORT_VALUE)
        {
            /* Reset detection direction to falling edge */
            ICU.IRQCR[0].BIT.IRQMD = 0x1;

            /* Clear switch press flag */
            /* type cast required to remove warning for
                Implicit conversion: unsigned int to unsigned char*/
            g_switch_flag &= ((uint8_t)0xF0 | ~SWITCHHOLD_1);

        }
        else
        {
            /* Switch 1 pin level is low (valid switch press) */
            /* So set flag to run function in main */
            switchPressCallBackFlag = 1U;
        }
    }

    /* Check if switch 2 hold flag is set, IRQ1 */
    if ((g_switch_flag & 0x0F) & SWITCHHOLD_2)
    {
        /* Check if switch 2 pin level is high (switch press duration
           less than debounce, invalid switch press) */
        if (0x1 == SW2_PORT_VALUE)
        {
            /* Reset detection direction to falling edge */
            ICU.IRQCR[1].BIT.IRQMD = 0x1;

            /* Clear switch press flag */
            /* type cast required to remove warning for
                Implicit conversion: unsigned int to unsigned char*/
            g_switch_flag &= ((uint8_t)0xF0 | ~SWITCHHOLD_2);
        }
        else
        {
            /* Switch 2 pin level is low (valid switch press) */
            /* So set flag to run function in main */
            switchPressCallBackFlag = 1U;
        }
    }

    /* Check if switch 3 hold flag is set, IRQ4 */
    if ((g_switch_flag & 0x0F) & SWITCHHOLD_3)
    {
        /* Check if switch 3 pin level is high (switch press duration
           less than debounce, invalid switch press) */
        if (SW3_PORT_VALUE)
        {
            /* Reset detection direction to falling edge */
            ICU.IRQCR[4].BIT.IRQMD = 0x1;

            /* Clear switch press flag */
            /* type cast required to remove warning for
                Implicit conversion: unsigned int to unsigned char*/
            g_switch_flag &= ((uint8_t)0xF0 | ~SWITCHHOLD_3);
        }
        else
        {
            /* Switch 3 pin level is low (valid switch press) */
            /* So set flag to run function in main */
            switchPressCallBackFlag = 1U;
        }
    }

    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_cmt_cmi1_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#if FAST_INTERRUPT_VECTOR == VECT_CMT1_CMI1
#pragma interrupt r_cmt_cmi1_interrupt(vect=VECT(CMT1,CMI1),fint)
#else
#pragma interrupt r_cmt_cmi1_interrupt(vect=VECT(CMT1,CMI1))
#endif
static void r_cmt_cmi1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* Toggle user LEDs */
    Toggle_LED();

    /* Ensure that the timer period is never set below 0x10 */
    if (g_timer_adc_period < 0x0010)
    {
        g_timer_adc_period = 0x0010;
    }

    /* Update timer period with respect to a scaled adc value */
    CMT1.CMCOR = (uint16_t)(g_timer_adc_period << 4);

    /* Clear interrupt flag */
    IR(CMT1,CMI1) = 0U;
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
