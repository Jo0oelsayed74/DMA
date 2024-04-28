/*
 * MSTK_Interface.h
 *
 *  Created on: Mar 11, 2024
 *      Author: yoels
 */

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

#include "../include/STD_Types.h"

/* 				 STK FREQUENCY  				*/
#if MSTK_CLK_SOURCE == MSTK_AHB
#define STK_FREQ MSTK_AHB_FREQUENCY
#elif MSTK_CLK_SOURCE == MSTK_AHB_BY_8
#define STK_FREQ MSTK_AHB_BY_8_FREQUENCY
#else
#error "Wrong MSTK CLK Source Configuration Parameter"
#endif

/* 				 Function Prototypes 				*/
void MSTK_voidInit(void);

void MSTK_voidClearCurrentValue(void);

void MSTK_voidSetPreloadValue(u32 copy_u32PreloadValue);

void MSTK_voidGetFlagValue(u8* p_u8Read);

void MSTK_voidEnableSTK();
void MSTK_voidDisableSTK();

void MSTK_voidGetElapsedTime(u32* p_u32Read);
void MSTK_voidGetRemainingTime(u32* p_u32Read);

void MSTK_voidEnableInterrupt(void);
void MSTK_voidDisableInterrupt(void);

void MSTK_voidDelayms(u32 copy_u32Delayms);
void MSTK_voidDelayus(u32 copy_u32Delayus);



#endif /* MSTK_INTERFACE_H_ */
