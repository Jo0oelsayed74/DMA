/*
 * MRCC_Private.h
 *
 *  Created on: Feb 1, 2024
 *      Author: yoels
 */
#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_


#define RCC_BASE_ADDRESS (0x40023800) //The beginning of the register from memory mapping ReferenceManual P38


typedef struct //Register map, will be the same at all of the drivers, select it by volatile pointer
{
	u32 RCC_CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 Reserved3;
	u32 Reserved4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 Reserved5;
	u32 Reserved6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 Reserved7;
	u32 Reserved8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 Reserved9;
	u32 Reserved10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 Reserved11;
	u32 Reserved12;
	u32 BDCR;
	u32 CSR;
	u32 Reserved13;
	u32 Reserved14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 Reserved15;
	u32 DCKCFGR;
}RCC_t;

//volatile pointer
// RCC is a macro will be replaced by a volatile pointer to data structure at RCC_BASE_ADDRESS
#define RCC  ((volatile RCC_t*)RCC_BASE_ADDRESS)


/*****SYS Clk****/
#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

/*****Macros****/
#define RCC_NOT_READY 	0

#define SW_BIT0	 		0
#define SW_HSI 			0b00
#define SW_HSE 			0b01
#define SW_PLL 			0b10

#define TWO_BIT_MASK 	0b11
#define THREE_BIT_MASK 	0b111

/*****CR Register Bits****/
#define RCC_CR_HSI_ON 		0
#define RCC_CR_HSI_RDY 		1
#define RCC_CR_HSE_ON 		16
#define RCC_CR_HSE_RDY 		17
#define RCC_CR_PLL_ON 		24
#define RCC_CR_PLL_RDY		25

/*****CFGR Register Bits****/
#define CFGR_PPRE1	10

#endif /* MRCC_PRIVATE_H_ */
