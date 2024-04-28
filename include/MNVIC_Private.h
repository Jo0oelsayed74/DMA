/*
 * MNVIC_Private.h
 *
 *  Created on: Feb 7, 2024
 *      Author: yoels
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS (0xE000E100)

typedef struct
{
	u32 ISER	  	[8]; //array take place from 0:7
	u32 RESERVED  	[24];
	u32 ICER 	  	[8];
	u32 RESERVED1 	[24];
	u32 ISPR	  	[8];
	u32 RESERVED2 	[24];
	u32 ICPR 	  	[8];
	u32 RESERVED3 	[24];
	u32 IABR 	  	[8];
	u32 RESERVED4 	[56];
	u8 IPR			[240]; 	//Byte Accessible
	u32 RESERVED5 	[580];
	u32 STIR			;
}NVIC_t;

#define NVIC  ((volatile NVIC_t*)NVIC_BASE_ADDRESS)

#define SCB_AIRCR (*(volatile u32*)0xE000ED0C)

#define Bits_In_register			32
#define AIRCR_PTIGROUP_BIT0			8
#define THREE_BIT_MASK				0b111
#define SCB_AIRCR_VECT_KEY			0x05FA0000

#endif /* MNVIC_PRIVATE_H_ */
