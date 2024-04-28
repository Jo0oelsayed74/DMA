/*
 * MNVIC.c
 *
 *  Created on: Feb 7, 2024
 *      Author: yoels
 */



/* STEPS
 * 1. Includes
 * 2. Core peripherals register regions (ProgrammingManual - Core Peripherals - P193)
 * 3. Struct (NVIC register map - P219)
 * 4. Volatile Pointer
 * 5. Function Prototypes
 * 6. Enum for priority grouping (ProgrammingManual - Core Peripherals 4.4.5 - P229)
 * */

/*****LIB****/
#include"../include/STD_Types.h"
#include"../include/BIT_MATH.h"

/*****MCAL****/
#include"../include/MNVIC_Config.h"
#include"../include/MNVIC_Interface.h"
#include"../include/MNVIC_Private.h"

static MNVIC_GROUP_t sglobal_NVIC_Group_t_Mode;

void MNVIC_voidEnablePeripheralInterrupt(u8 copy_u8Peripheral){
	SET_BIT(NVIC->ISER[(copy_u8Peripheral/Bits_In_register)] , (copy_u8Peripheral%Bits_In_register));
}
void MNVIC_voidDisablePreipheralInterrupt(u8 copy_u8Peripheral){
	SET_BIT(NVIC->ICER[(copy_u8Peripheral/Bits_In_register)] , (copy_u8Peripheral%Bits_In_register));
}

void MNVIC_voidSetPreipheralInterruptPending(u8 copy_u8Peripheral){
	SET_BIT(NVIC->ISPR[(copy_u8Peripheral/Bits_In_register)] , (copy_u8Peripheral%Bits_In_register));
}
void MNVIC_voidClearPreipheralInterruptPending(u8 copy_u8Peripheral){
	SET_BIT(NVIC->ICPR[(copy_u8Peripheral/Bits_In_register)] , (copy_u8Peripheral%Bits_In_register));
}

void MNVIC_voidGetInterruptState(u8 copy_u8Peripheral , u8* p_u8Read){
	*p_u8Read = GET_BIT(NVIC->IABR[(copy_u8Peripheral/Bits_In_register)] , (copy_u8Peripheral%Bits_In_register));
}
void MNVIC_voidSetInterruptGroupMode(MNVIC_GROUP_t MNVIC_GROUP_t_Mode){
	sglobal_NVIC_Group_t_Mode = MNVIC_GROUP_t_Mode;
	SCB_AIRCR = (SCB_AIRCR_VECT_KEY | MNVIC_GROUP_t_Mode << AIRCR_PTIGROUP_BIT0);
}

void MNVIC_voidSetInterruptPriority(u8 copy_u8Peripheral , u8 copy_u8GroupNumber , u8 copy_u8SubNumber){
	switch (sglobal_NVIC_Group_t_Mode) {
		case Groups16_NoSub:
			NVIC->IPR[copy_u8Peripheral] = (copy_u8GroupNumber << 4);
			break;
		case Groups8_Sub2:
			NVIC->IPR[copy_u8Peripheral] = (copy_u8GroupNumber << 5 | copy_u8SubNumber << 4);
			break;
		case Groups4_Sub4:
			NVIC->IPR[copy_u8Peripheral] = (copy_u8GroupNumber << 6 | copy_u8SubNumber << 4);
			break;
		case Groups2_Sub8:
			NVIC->IPR[copy_u8Peripheral] = (copy_u8GroupNumber << 7 | copy_u8SubNumber << 4);
			break;
		case NoGroup_Sub16:
			NVIC->IPR[copy_u8Peripheral] = (copy_u8SubNumber << 4);
			break;
		default:
			break;
	}
}


