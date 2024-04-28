/*
 * MSPI_Program.c
 *
 *  Created on: Apr 21, 2024
 *      Author: yoels
 */

#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"
#include "../include/MSPI_Interface.h"
#include "../include/MSPI_Private.h"
#include "../include/MSPI_Config.h"

PtrToFunc_void SPI_CallBack[SPI_NUMBER];

void MSPI_voidInit (void)
{
	/*Set Data Size*/
#if MSPI1_DATA_SIZE == MSPI_16BIT_DATA
	SET_BIT (SPI1->CR1 , CR1_DFF);
#else
	CLR_BIT (SPI1->CR1 , CR1_DFF);
#endif
	/*Set slave management mode*/
#if MSPI1_SS_MANAGE == MSPI_SW_SLAVE_MANAGEMENT
	SET_BIT (SPI1->CR1 , CR1_SSM);
	SET_BIT(SPI1->CR1 , CR1_SSI);
#else
	CLR_BIT (SPI1->CR1 , CR1_SSM);
#endif
	/*Set Data Order*/
#if MSPI1_DATA_ORDER == MSPI_LSB_FIRST
	SET_BIT (SPI1->CR1 , CR1_LSBFIRST);
#else
	CLR_BIT (SPI1->CR1 , CR1_LSBFIRST);
#endif
	/*Set Clock Mode*/
	SPI1->CR1 &= ~(TWO_BIT_MASK<<CR1_CLK_SELECT);
	SPI1->CR1 |= (MSPI1_CLK_MODE<<CR1_CLK_SELECT);
	/*Set Interrupt States*/
#if MSPI1_TX_INTERRUPT_STATE == MSPI_INTERRUPT_ENABLE
	SET_BIT (SPI1->CR2 , CR2_TXEIE);
#else
	CLR_BIT (SPI1->CR2 , CR2_TXEIE);
#endif
#if MSPI1_RX_INTERRUPT_STATE == MSPI_INTERRUPT_ENABLE
	SET_BIT (SPI1->CR2 , CR2_RXNEIE);
#else
	CLR_BIT (SPI1->CR2 , CR2_RXNEIE);
#endif
	/*Set SPI Mode*/
#if MSPI1_MASTER_SLAVE == MSPI_MASTER
	SET_BIT (SPI1->CR1 , CR1_MSTR);
	/*Set Prescaler*/
	SPI1->CR1 &= ~(THREE_BIT_MASK<<CR1_BR);
	SPI1->CR1 |= (MSPI1_PRESCALER<<CR1_BR);
#else
	CLR_BIT (SPI1->CR1 , CR1_MSTR);
#endif
	/*SPI State*/
#if MSPI1_STATE == MSPI_ENABLED
	SET_BIT (SPI1->CR1 , CR1_SPE);
#else
	CLR_BIT (SPI1->CR1 , CR1_SPE);
#endif


	//SPI1->CR1 = 0x0347;
}

u16 MSPI_voidSendReceiveData (u16 A_u16Data)
{
	/*Put data in SPI Data Register*/
#if MSPI1_DATA_SIZE == MSPI_16BIT_DATA
	SPI1->DR = A_u16Data;
#else
	SPI1->DR = (u8) A_u16Data;
#endif
	/*wait until SPI finishes*/
	while (GET_BIT(SPI1->SR , SR_BSY) == SPI_BUSY);
	return (u8)SPI1->DR;
}

void MSPI_voidSetCallBack (PtrToFunc_void p_CallBackFunc)
{
	/*Set Call Back Function*/
	SPI_CallBack[0] = p_CallBackFunc;
}


void SPI1_IRQHandler (void)
{
	if (SPI_CallBack[0] != NULL)
	{
		SPI_CallBack[0]();
	}
}



