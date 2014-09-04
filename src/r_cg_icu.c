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
* File Name    : r_cg_icu.c
* Version      : Applilet4 for RX111 V1.00.00.05 [06 Jun 2013]
* Device(s)    : R5F51115AxFM
* Tool-Chain   : CCRX
* Description  : This file implements device driver for ICU module.
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
#include "r_cg_icu.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


/***********************************************************************************************************************
* Function Name: R_ICU_Create
* Description  : This function initializes ICU module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ICU_Create(void)
{
    /* Disable IRQ0~7 interrupts */
    ICU.IER[0x08].BYTE = _00_ICU_IRQ0_DISABLE | _00_ICU_IRQ1_DISABLE | _00_ICU_IRQ2_DISABLE | _00_ICU_IRQ3_DISABLE | _00_ICU_IRQ4_DISABLE | _00_ICU_IRQ5_DISABLE | _00_ICU_IRQ6_DISABLE | _00_ICU_IRQ7_DISABLE;

    /* Set IRQ settings */
    ICU.IRQCR[0].BYTE = _04_ICU_IRQ_EDGE_FALLING;
    ICU.IRQCR[1].BYTE = _04_ICU_IRQ_EDGE_FALLING;
    ICU.IRQCR[4].BYTE = _04_ICU_IRQ_EDGE_FALLING;

    /* Set IRQ0 priority level */
    IPR(ICU,IRQ0) = _07_ICU_PRIORITY_LEVEL7;

    /* Set IRQ1 priority level */
    IPR(ICU,IRQ1) = _07_ICU_PRIORITY_LEVEL7;

    /* Set IRQ4 priority level */
    IPR(ICU,IRQ4) = _07_ICU_PRIORITY_LEVEL7;

    /* Set IRQ0 pin */
    MPC.P30PFS.BYTE = 0x40U;
    PORT3.PDR.BYTE &= 0xFEU;
    PORT3.PMR.BYTE &= 0xFEU;

    /* Set IRQ1 pin */
    MPC.P31PFS.BYTE = 0x40U;
    PORT3.PDR.BYTE &= 0xFDU;
    PORT3.PMR.BYTE &= 0xFDU;

    /* Set IRQ4 pin */
    MPC.PE4PFS.BYTE = 0x40U;
    PORTE.PDR.BYTE &= 0xEFU;
    PORTE.PMR.BYTE &= 0xEFU;
}
/***********************************************************************************************************************
* Function Name: R_ICU_IRQ0_Start
* Description  : This function enables IRQ0 interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ICU_IRQ0_Start(void)
{
    /* Enable IRQ0 interrupt */
    IEN(ICU,IRQ0) = 1U; 
}
/***********************************************************************************************************************
* Function Name: R_ICU_IRQ0_Stop
* Description  : This function disables IRQ0 interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ICU_IRQ0_Stop(void)
{
    /* Disable IRQ0 interrupt */
    IEN(ICU,IRQ0) = 0U; 
}
/***********************************************************************************************************************
* Function Name: R_ICU_IRQ1_Start
* Description  : This function enables IRQ1 interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ICU_IRQ1_Start(void)
{
    /* Enable IRQ1 interrupt */
    IEN(ICU,IRQ1) = 1U; 
}
/***********************************************************************************************************************
* Function Name: R_ICU_IRQ1_Stop
* Description  : This function disables IRQ1 interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ICU_IRQ1_Stop(void)
{
    /* Disable IRQ1 interrupt */
    IEN(ICU,IRQ1) = 0U; 
}
/***********************************************************************************************************************
* Function Name: R_ICU_IRQ4_Start
* Description  : This function enables IRQ4 interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ICU_IRQ4_Start(void)
{
    /* Enable IRQ4 interrupt */
    IEN(ICU,IRQ4) = 1U; 
}
/***********************************************************************************************************************
* Function Name: R_ICU_IRQ4_Stop
* Description  : This function disables IRQ4 interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ICU_IRQ4_Stop(void)
{
    /* Disable IRQ4 interrupt */
    IEN(ICU,IRQ4) = 0U; 
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
