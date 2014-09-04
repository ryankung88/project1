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
* File Name    : r_cg_intprg.c
* Version      : Applilet4 for RX111 V1.00.00.05 [06 Jun 2013]
* Device(s)    : R5F51115AxFM
* Tool-Chain   : CCRX
* Description  : Setting of B.
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
#include <machine.h>
#include "r_cg_vect.h"
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/

#pragma section IntPRG

/* Exception(Supervisor Instruction) */
void Excep_SuperVisorInst(void){/* brk(){  } */}

/* Exception(Undefined Instruction) */
void Excep_UndefinedInst(void){/* brk(){  } */}

/* Exception(Floating Point) */
void Excep_FloatingPoint(void){/* brk(){  } */}

/* NMI */
void NonMaskableInterrupt(void){/* brk(){  } */}

/* Dummy */
void Dummy(void){/* brk(){  } */}

/* BRK */
void Excep_BRK(void){ wait(); }

/* BSC BUSERR */
void Excep_BSC_BUSERR(void){ }

/* ICU SWINT */
void Excep_ICU_SWINT(void){ }

/* CMT0 CMI0 */

/* CMT1 CMI1 */

/* CAC FERRF */
void Excep_CAC_FERRF(void){ }

/* CAC MENDF */
void Excep_CAC_MENDF(void){ }

/* CAC OVFF */
void Excep_CAC_OVFF(void){ }

/* USB0 D0FIFO0 */
void Excep_USB0_D0FIFO0(void){ }

/* USB0 D1FIFO0 */
void Excep_USB0_D1FIFO0(void){ }

/* USB0 USBI0 */
void Excep_USB0_USBI0(void){ }

/* RSPI0 SPEI0 */
void Excep_RSPI0_SPEI0(void){ }

/* RSPI0 SPRI0 */
void Excep_RSPI0_SPRI0(void){ }

/* RSPI0 SPTI0 */
void Excep_RSPI0_SPTI0(void){ }

/* RSPI0 SPII0 */
void Excep_RSPI0_SPII0(void){ }

/* DOC DOPCF */
void Excep_DOC_DOPCF(void){ }

/* RTC CUP */
void Excep_RTC_CUP(void){ }

/* ICU IRQ0 */

/* ICU IRQ1 */

/* ICU IRQ2 */
void Excep_ICU_IRQ2(void){ }

/* ICU IRQ3 */
void Excep_ICU_IRQ3(void){ }

/* ICU IRQ4 */

/* ICU IRQ5 */
void Excep_ICU_IRQ5(void){ }

/* ICU IRQ6 */
void Excep_ICU_IRQ6(void){ }

/* ICU IRQ7 */
void Excep_ICU_IRQ7(void){ }

/* LVD LVD1 */
void Excep_LVD_LVD1(void){ }

/* LVD LVD2 */
void Excep_LVD_LVD2(void){ }

/* USB0 USBR0 */
void Excep_USB0_USBR0(void){ }

/* RTC ALM */
void Excep_RTC_ALM(void){ }

/* RTC PRD */
void Excep_RTC_PRD(void){ }

/* S12AD S12ADI0 */

/* S12AD GBADI */
void Excep_S12AD_GBADI(void){ }

/* ELC ELSR18I */
void Excep_ELC_ELSR18I(void){ }

/* MTU0 TGIA0 */
void Excep_MTU0_TGIA0(void){ }

/* MTU0 TGIB0 */
void Excep_MTU0_TGIB0(void){ }

/* MTU0 TGIC0 */
void Excep_MTU0_TGIC0(void){ }

/* MTU0 TGID0 */
void Excep_MTU0_TGID0(void){ }

/* MTU0 TCIV0 */
void Excep_MTU0_TCIV0(void){ }

/* MTU0 TGIE0 */
void Excep_MTU0_TGIE0(void){ }

/* MTU0 TGIF0 */
void Excep_MTU0_TGIF0(void){ }

/* MTU1 TGIA1 */
void Excep_MTU1_TGIA1(void){ }

/* MTU1 TGIB1 */
void Excep_MTU1_TGIB1(void){ }

/* MTU1 TCIV1 */
void Excep_MTU1_TCIV1(void){ }

/* MTU1 TCIU1 */
void Excep_MTU1_TCIU1(void){ }

/* MTU2 TGIA2 */
void Excep_MTU2_TGIA2(void){ }

/* MTU2 TGIB2 */
void Excep_MTU2_TGIB2(void){ }

/* MTU2 TCIV2 */
void Excep_MTU2_TCIV2(void){ }

/* MTU2 TCIU2 */
void Excep_MTU2_TCIU2(void){ }

/* MTU3 TGIA3 */
void Excep_MTU3_TGIA3(void){ }

/* MTU3 TGIB3 */
void Excep_MTU3_TGIB3(void){ }

/* MTU3 TGIC3 */
void Excep_MTU3_TGIC3(void){ }

/* MTU3 TGID3 */
void Excep_MTU3_TGID3(void){ }

/* MTU3 TCIV3 */
void Excep_MTU3_TCIV3(void){ }

/* MTU4 TGIA4 */
void Excep_MTU4_TGIA4(void){ }

/* MTU4 TGIB4 */
void Excep_MTU4_TGIB4(void){ }

/* MTU4 TGIC4 */
void Excep_MTU4_TGIC4(void){ }

/* MTU4 TGID4 */
void Excep_MTU4_TGID4(void){ }

/* MTU4 TCIV4 */
void Excep_MTU4_TCIV4(void){ }

/* MTU5 TGIU5 */
void Excep_MTU5_TGIU5(void){ }

/* MTU5 TGIV5 */
void Excep_MTU5_TGIV5(void){ }

/* MTU5 TGIW5 */
void Excep_MTU5_TGIW5(void){ }

/* POE OEI1 */
void Excep_POE_OEI1(void){ }

/* POE OEI2 */
void Excep_POE_OEI2(void){ }

/* SCI1 ERI1 */

/* SCI1 RXI1 */

/* SCI1 TXI1 */

/* SCI1 TEI1 */

/* SCI5 ERI5 */
void Excep_SCI5_ERI5(void){ }

/* SCI5 RXI5 */
void Excep_SCI5_RXI5(void){ }

/* SCI5 TXI5 */

/* SCI5 TEI5 */

/* SCI12 ERI12 */

/* SCI12 RXI12 */

/* SCI12 TXI12 */

/* SCI12 TEI12 */

/* SCI12 SCIX0 */
void Excep_SCI12_SCIX0(void){ }

/* SCI12 SCIX1 */
void Excep_SCI12_SCIX1(void){ }

/* SCI12 SCIX2 */
void Excep_SCI12_SCIX2(void){ }

/* SCI12 SCIX3 */
void Excep_SCI12_SCIX3(void){ }

/* RIIC0 EEI0 */
void Excep_RIIC0_EEI0(void){ }

/* RIIC0 RXI0 */
void Excep_RIIC0_RXI0(void){ }

/* RIIC0 TXI0 */
void Excep_RIIC0_TXI0(void){ }

/* RIIC0 TEI0 */
void Excep_RIIC0_TEI0(void){ }

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
