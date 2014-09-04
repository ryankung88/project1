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
* File Name    : r_cg_main.c
* Version      : Applilet4 for RX111 V1.00.00.05 [06 Jun 2013]
* Device(s)    : R5F51115AxFM
* Tool-Chain   : CCRX
* Description  : This file implements main function.
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
#include "r_cg_cgc.h"
#include "r_cg_icu.h"
#include "r_cg_port.h"
#include "r_cg_mtu2.h"
#include "r_cg_cmt.h"
#include "r_cg_sci.h"
#include "r_cg_s12adb.h"
/* Start user code for include. Do not edit comment generated here */

/* Contains functions and macro definitions for RSK Switches */
#include "switch.h"

/* Contains functions and macro definitions for LCD Module */
#include "lcd.h"

/* Flashing LED function definitions */
#include "flashled.h"

/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

/* Define the RSK short name */
#define NICKNAME "RX111   "
#define NAME	"Ryan Kung"
#define CLASS	"ECE 600"

/* Switch press callback function which sets the g_switch_pressed_flag */
static void timer_adc(void);

/* static_test function prototype */
static void static_test(void);

/* End user code. Do not edit comment generated here */

/* Set option bytes */
#pragma address OFS0_location = 0xFFFFFF8CUL
#pragma address OFS1_location = 0xFFFFFF88UL
volatile const uint32_t OFS0_location = 0xFFFFFFFFUL;
volatile const uint32_t OFS1_location = 0xFFFFFF7FUL;

void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
	R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */

    /* Display Splash Screen */
    DisplayCenter(0, (uint8_t *)NAME);
    DisplayCenter(1, (uint8_t *)CLASS);

    //LED Sequence function
    Sequence_LED();

    /* Start the timer_adc function */
    //timer_adc();
    
    /* static_test function */
    //static_test();
   
    while (1U)
    {
        /* Wait */
    }
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */

	/* start SW3 on IRQ4 */
    R_ICU_IRQ4_Start();

    /* start SW1 on IRQ0 */
    R_ICU_IRQ0_Start();

    /* start SW2 on IRQ1 */
    R_ICU_IRQ1_Start();

    /* Initialise the Debug LCD */
    Init_LCD();

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/******************************************************************************
* Function Name : timer_adc
* Description   : Uses the ADC to change the timer period, used to flash
*                 the LEDs.
* Arguments     : none
* Return value  : none
******************************************************************************/
static void timer_adc (void)
{
    /* Start ADC operations */
    R_S12ADb_Start();

    /* Start timer TM02 operations */
    R_CMT1_Start();
}
/*******************************************************************************
End of function timer_adc
*******************************************************************************/

/*******************************************************************************
* Function Name: static_test
* Description  : Static variable test routine. The function replaces the
*                contents of the string ucStr with that of ucReplace, one
*                element at a time. Right-click the variable c_str, and
*                select instant watch - click add in the subsequent dialog.
*                If you step through the function, you can watch the string
*                elements being overwritten with the new data.
* Arguments    : none
* Return value : none
*******************************************************************************/
static void static_test (void)
{
     /* Declare loop count variable */
    uint8_t     ui_count = 0;

     /* Declare string variable to hold the string to be copied */
    char        c_str[] = "STATIC  \0";

    /* Declare variable buffer to store the copied string */
    const char  c_replace[] = "TESTTEST\0";

    /* Declare a delay count variable */
    uint32_t    ul_delay;

    /* Write ucStr variable, "STATIC" to LCD */
    Display_LCD(1, (uint8_t *)c_str);

    /* Delay */
    for (ul_delay = 0; ul_delay < 1500000; ul_delay++)
    {
        /* Delay */
    }

    /* Begin for loop which writes one letter of ucReplace to the LCD at a time
       The nested while loops generate the delay between each letter change */
    for (ui_count = 0; ui_count < 8; ui_count++)
    {
        /* Replace letter number uiCount of ucStr from ucReplace */
        c_str[ui_count] = c_replace[ui_count];

        /* Display the character on the debug LCD */
        Display_LCD(1, (uint8_t *)c_str);

            /* LED Flashing Delay */
        for (ul_delay = 0; ul_delay < 1500000; ul_delay++)
        {
             /* Delay */
        }
    }

    /* Clear LCD Display */
    c_str[ui_count] = '\0';

    /* Write MCU nickname to LCD again */
    Display_LCD(1, (uint8_t *)NICKNAME);
}
/*******************************************************************************
End of function static_test
*******************************************************************************/
/* End user code. Do not edit comment generated here */
