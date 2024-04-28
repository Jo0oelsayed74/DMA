/*
 * MRCC_Program.c
 *
 *  Created on: Feb 1, 2024
 *      Author: yoels
 */


/*****LIB****/
#include"../include/STD_Types.h"
#include"../include/BIT_MATH.h"

/*****MCAL****/
#include"../include/MRCC_Config.h"
#include"../include/MRCC_Interface.h"
#include"../include/MRCC_Private.h"

/*					Functions Definitions					*/
void MRCC_voidInit(void)
{
#if SYS_CLK == RCC_HSI
/*		HSI EN		*/
SET_BIT(RCC->RCC_CR ,RCC_CR_HSI_ON);
/*		WAIT TILL HSI IS READY		*/
while(GET_BIT(RCC->RCC_CR, RCC_CR_HSI_RDY)== RCC_NOT_READY);

/*		MASKING SWITCHING BITS		*/
RCC->CFGR &= ~(TWO_BIT_MASK);
/*	Select HSI as SYS CLK	*/
RCC->CFGR |= (SW_HSI << SW_BIT0);


#elif SYS_CLK == RCC_HSE

/*					HSE EN					*/
SET_BIT(RCC->CR ,RCC_CR_HSE_ON);
/*					WAIT TILL HSI IS READY					*/
while(GET_BIT(RCC->CR, RCC_CR_HSE_RDY)== RCC_NOT_READY);

/*					MASKING SWITCHING BITS					*/
RCC->CFGR &= ~(TWO_BIT_MASK);
/*					Select HSI as SYS CLK					*/
RCC->CFGR |= (SW_HSE << SW_BIT0);


#elif SYS_CLK == RCC_PLL

/*					Enable PLL					*/
SET_BIT(RCC->RCC_CR ,RCC_CR_PLL_ON);
/*					WAIT TILL HSI IS READY					*/
while(GET_BIT(RCC->RCC_CR, RCC_CR_PLL_RDY)== RCC_NOT_READY);

/*					MASKING THE SWITCHING BITS					*/
RCC->CFGR &= ~(TWO_BIT_MASK);
/*					Select HSI as SYS CLK					*/
RCC->CFGR |= (SW_PLL << SW_BIT0);
#else
#error "Wrong SYS_CLK Config Parameter"

#endif
}

void MRCC_voidEnablePeripheral(u32 copyu32_BusAddress, u32 copyu32_Peripheral)
{
	switch(copyu32_BusAddress)
	{
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,copyu32_Peripheral);
		break;

	case RCC_APB2:
		SET_BIT(RCC->APB2ENR,copyu32_Peripheral);
		break;

	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,copyu32_Peripheral);
		break;

	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,copyu32_Peripheral);
		break;

	default:
		break;
	}

}
void MRCC_voidDisablePeripheral(u32 copyu32_BusAddress, u32 copyu32_Peripheral)
{
	switch(copyu32_BusAddress)
		{
		case RCC_APB1:
			CLR_BIT(RCC->APB1ENR,copyu32_Peripheral);
			break;

		case RCC_APB2:
			CLR_BIT(RCC->APB2ENR,copyu32_Peripheral);
			break;

		case RCC_AHB1:
			CLR_BIT(RCC->AHB1ENR,copyu32_Peripheral);
			break;

		case RCC_AHB2:
			CLR_BIT(RCC->AHB2ENR,copyu32_Peripheral);
			break;

		default:
			break;
		}
}

