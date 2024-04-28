/*
 * MNVIC_Interface.h
 *
 *  Created on: Feb 7, 2024
 *      Author: yoels
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_

typedef enum{
	Groups16_NoSub = 3,
	Groups8_Sub2,
	Groups2_Sub8,
	Groups4_Sub4,
	NoGroup_Sub16
}MNVIC_GROUP_t;

void MNVIC_voidEnablePeripheralInterrupt(u8 copy_u8Peripheral);

void MNVIC_voidDisblePeripheralInterrupt(u8 copy_u8Peripheral);

void MNVIC_voidSetPeripheralInterruptPending(u8 copy_u8Peripheral);

void MNVIC_voidClearPeripheralInterruptPending(u8 copy_u8Peripheral);

void MNVIC_voidGetInterruptState(u8 copy_u8Peripheral , u8 *p_Read);

void MNVIC_voidSetInterruptGroupMode(MNVIC_GROUP_t MNVIC_Group_t_Mode);

void MNVIC_voidSetInterruptPriority(u8 copy_u8Peripheral , u8 copy_u8GroupNumber , u8 copy_u8Sub);





#endif /* MNVIC_INTERFACE_H_ */
