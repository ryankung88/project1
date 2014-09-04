/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*******************************************************************************/
/* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.   */
/*******************************************************************************
* File Name     : flashled.c
* Version       : 1.00
* Device(s)     : R5F10JGC
* Tool-Chain    : CA78K0R
* H/W Platform  : RSKL78/G1C
* Description   : Defines functions used for flashing the LEDs
*******************************************************************************/
/*******************************************************************************
* History       : _#DATE#_  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
#include "r_cg_macrodriver.h"

/* Switch controlling function prototypes & macro definitions */
#include "switch.h"

/* Defines used within the project scope */
#include "r_cg_port.h"

/* Flashing LED function definitions */
#include "flashled.h"

/*******************************************************************************
* Global Variables
*******************************************************************************/

/*******************************************************************************
* Function Name : Flash_LED
* Description   : The LED flash function used at the beginning of the program
* Argument      : none
* Return value  : none
*******************************************************************************/
void Flash_LED (void)
{
     /* Variable used to count down the number of LED flashes */
    static uint16_t flash_count = 0xC8;
    
    /* Declare a delay count variable */
    uint32_t        ulLed_Delay = 0;

    /* Flash the LEDs for 200 times or until a user switch is pressed */
    while ((0 == g_switch_flag ) && (--flash_count > 0))
    {
        for (ulLed_Delay = 0; ulLed_Delay < 100000; ++ulLed_Delay)
        {
            /* delay */
        }
        
        /* Toggles the LEDs after a specific delay. */
        Toggle_LED();
    }
    
    /* Reset the g_switch_flag flag variable */
    g_switch_flag = 0;
    
    /* Disable switch interrupts */
    //ControlSwitchInterrupts(0);
}
/*******************************************************************************
* End of function Flash_LED
*******************************************************************************/

/*******************************************************************************
* Function Name : Toggle_LED
* Description   : Function used to toggle the output of all user LEDs
* Argument      : none
* Return value  : none
*******************************************************************************/
void Toggle_LED (void)
{
    /* Toggle the state of the user LEDs */
    LED0_Toggle();
    LED1_Toggle();
    LED2_Toggle();
    LED3_Toggle();
}
/*******************************************************************************
* End of function Toggle_LED
*******************************************************************************/


