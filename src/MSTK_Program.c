/*
 * MSTK_Program.c
 *
 *  Created on: Mar 11, 2024
 *      Author: yoels
 */

#include "../include/STD_Types.h"

#include "../include/MSTK_Config.h"
#include "../include/MSTK_Interface.h"
#include "../include/MSTK_Private.h"
#include "../include/BIT_MATH.h"

/*MCAL*/

/*Function Definitions*/
void MSTK_voidInit(void){
	/* Select Clock Source */
#if MSTK_CLK_SOURCE == MSTK_AHB
	SET_BIT(STK->CTRL , MSTK_CTRL_CLKSOURCE);
#elif MSTK_CLK_SOURCE == MSTK_AHB_BY_8
	CLR_BIT(STK->CTRL , MSTK_CTRL_CLKSOURCE);
#else
#error "Wrong MSTK CLK Source Configuration Parameter"
#endif
}

void MSTK_voidClearCurrentValue(void){
	STK->VAL = 0;
}

void MSTK_voidSetPreloadValue(u32 copy_u32PreloadValue){
	STK->LOAD = copy_u32PreloadValue & MSTK_RESERVED_MASK;
}

void MSTK_voidGetFlagValue(u8* p_u8Read){
	*p_u8Read = GET_BIT(STK->CTRL , MSTK_CTRL_COUNTFLAG);
}

void MSTK_voidEnableSTK(){
	SET_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
}
void MSTK_voidDisableSTK(){
	CLR_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
}

void MSTK_voidGetElapsedTime(u32* p_u32Read){
	*p_u32Read = (STK->LOAD) - (STK->VAL) ;
}
void MSTK_voidGetRemainingTime(u32* p_u32Read){
	*p_u32Read = STK->VAL ;
}

void MSTK_voidEnableInterrupt(void){
	SET_BIT(STK->CTRL , MSTK_CTRL_TICKINT);
}
void MSTK_voidDisableInterrupt(void){
	CLR_BIT(STK->CTRL , MSTK_CTRL_TICKINT);
}

void MSTK_voidDelayms(u32 copy_u32Delayms){
	/* Calculate Preload Value */
	u32 local_u32PreLoadValue = copy_u32Delayms * (STK_FREQ / 1e3);
	STK->LOAD = local_u32PreLoadValue;
	STK->VAL = 0;
	SET_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
	while(GET_BIT(STK->CTRL , MSTK_CTRL_COUNTFLAG) == 0);
	CLR_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
}
void MSTK_voidDelayus(u32 copy_u32Delayus){
	/* Calculate Preload Value */
	u32 local_u32PreLoadValue = copy_u32Delayus * (STK_FREQ / 1e6);
	STK->LOAD = local_u32PreLoadValue;
	STK->VAL = 0;
	SET_BIT(STK->CTRL , MSTK_CTRL_ENABLE);
	while(GET_BIT(STK->CTRL , MSTK_CTRL_COUNTFLAG) == 0);
	CLR_BIT(STK->CTRL , MSTK_CTRL_ENABLE);

}

