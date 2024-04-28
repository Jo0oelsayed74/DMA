/*
 * MUSART_Program.c
 *
 *  Created on: Mar 3, 2024
 *      Author: yoels
 */

/*****LIB****/
#include "../include/MUSART_Private.h"
#include"../include/STD_Types.h"
#include"../include/BIT_MATH.h"

/*****MCAL****/
#include"../include/MUSART_Config.h"
#include"../include/MUSART_Interface.h"


/**********************************************************************/
/********************MUSART CallBacks**********************************/
static void(*MSUART_CallBack)(void) = NULL;

/********************Functions Definitions*****************************/
void MUSART_voidInit(void)
{
	u8 local_u8Fraction = 0;
	/********************USART1 Configurations**********************/
	/*Set Oversampling mode*/
#if MUSART1_OVERSAMPLING_MODE == MUSART_OVER_ON
	USART1->CR1.OVER8 = 1;
#else
	USART1->CR1.OVER8 = 0;
#endif
	/*Set Data Size*/
#if MUSART1_DATA_SIZE == MUSART_NINE_BITS
	USART1->CR1.M = 1;
#else
	USART1->CR1.M = 0;
#endif
	/*Set Wake mode*/
#if MUSART1_WAKE_MODE == MUSART_ADDRESS_MARK
	USART1->CR1.WAKE = 1;
#else
	USART1->CR1.WAKE = 0;
#endif
	/*Set Parity Configurations*/
#if MUSART1_PARITY_CONTROL == MUSART_PARITY_ENABLED
	USART1->CR1.PCE = 1;
#if MUSART1_PARITY_SELECTION == MUSART_PARITY_ODD
	USART1->CR1.PS = 1;
#else
	USART1->CR1.PS = 0;
#endif
#else
	USART1->CR1.PCE = 0;
#endif
	/*Set Interrupts States*/
#if MUSART1_PARITY_ERROR_INTERRUPT_STATE == MUSART_INTERRUPT_ENABLED
	USART1->CR1.PEIE = 1;
#else
	USART1->CR1.PEIE = 0;
#endif
#if MUSART1_TRANSMIT_REGISTER_EMPTY_INTERRPUT_STATE == MUSART_INTERRUPT_ENABLED
	USART1->CR1.TXEIE = 1;
#else
	USART1->CR1.TXEIE = 0;
#endif
#if MUSART1_TRANSMITTION_COMPLETE_INTERRPUT_STATE == MUSART_INTERRUPT_ENABLED
	USART1->CR1.TCIE = 1;
#else
	USART1->CR1.TCIE = 0;
#endif
#if MUSART1_RECEIVER_REGISTER_NOT_EMPTY_INTERRPUT_STATE == MUSART_INTERRUPT_ENABLED
	USART1->CR1.RXNEIE = 1;
#else
	USART1->CR1.RXNEIE = 0;
#endif
#if MUSART1_IDLE_LINE_INTERRUPT_STATE == MUSART_INTERRUPT_ENABLED
	USART1->CR1.IDLEIE = 1;
#else
	USART1->CR1.IDLEIE = 0;
#endif
	/*Set Send Break Mode*/
#if MUSART1_SEND_BREAK_MODE == MUSART_SEND_BREAK_ENABLED
	USART1->CR1.SBK = 1;
#else
	USART1->CR1.SBK = 0;
#endif
	/*Set Baud Rate*/
	USART1->BRR = ((u16)USART_DIV_VALUE(USART1 , MUSART1_BAUD_RATE)) << MUSART_MANTISSA_B0;
	local_u8Fraction = ((u8)((USART_DIV_VALUE(USART1 , MUSART1_BAUD_RATE) - (u16)USART_DIV_VALUE(USART1 , MUSART1_BAUD_RATE))*16))&0x0F;
	USART1->BRR |= local_u8Fraction<<MUSART_FRACTION_B0;
	//USART1->BRR = 0x00000683;
	/*Set Tranmitter Mode*/
#if MUSART1_TRANSMITTER_MODE == MUSART_TRANMITTER_ON
	USART1->CR1.TE = 1;
#else
	USART1->CR1.TE = 0;
#endif
	/*Set Receiver Mode*/
#if MUSART1_RECEIVER_MODE == MUSART_RECEIVER_ON
	USART1->CR1.RE = 1;
#else
	USART1->CR1.RE = 0;
#endif

//
//	/********************USART2 Configurations**********************/
//
//	/*Set Oversampling mode*/
//#if MUSART2_OVERSAMPLING_MODE == MUSART_OVER_ON
//	USART2->CR1.OVER8 = 1;
//#else
//	USART2->CR1.OVER8 = 0;
//#endif
//	/*Set Data Size*/
//#if MUSART2_DATA_SIZE == MUSART_NINE_BITS
//	USART2->CR1.M = 1;
//#else
//	USART2->CR1.M = 0;
//#endif
//	/*Set Wake mode*/
//#if MUSART2_WAKE_MODE == MUSART_ADDRESS_MARK
//	USART2->CR1.WAKE = 1;
//#else
//	USART2->CR1.WAKE = 0;
//#endif
//	/*Set Parity Configurations*/
//#if MUSART2_PARITY_CONTROL == MUSART_PARITY_ENABLED
//	USART2->CR1.PCE = 1;
//#if MUSART2_PARITY_SELECTION == MUSART_PARITY_ODD
//	USART2->CR1.PS = 1;
//#else
//	USART2->CR1.PS = 0;
//#endif
//#else
//	USART2->CR1.PCE = 0;
//#endif
//	/*Set Interrupts States*/
//#if MUSART2_PARITY_ERROR_INTERRUPT_STATE == MUSART_INTERRUPT_ENABLED
//	USART2->CR1.PEIE = 1;
//#else
//	USART2->CR1.PEIE = 0;
//#endif
//#if MUSART2_TRANSMIT_REGISTER_EMPTY_INTERRPUT_STATE == MUSART_INTERRUPT_ENABLED
//	USART2->CR1.TXEIE = 1;
//#else
//	USART2->CR1.TXEIE = 0;
//#endif
//#if MUSART2_TRANSMITTION_COMPLETE_INTERRPUT_STATE == MUSART_INTERRUPT_ENABLED
//	USART2->CR1.TCIE = 1;
//#else
//	USART2->CR1.TCIE = 0;
//#endif
//#if MUSART2_RECEIVER_REGISTER_NOT_EMPTY_INTERRPUT_STATE == MUSART_INTERRUPT_ENABLED
//	USART2->CR1.RXNEIE = 1;
//#else
//	USART2->CR1.RXNEIE = 0;
//#endif
//#if MUSART2_IDLE_LINE_INTERRUPT_STATE == MUSART_INTERRUPT_ENABLED
//	USART2->CR1.IDLEIE = 1;
//#else
//	USART2->CR1.IDLEIE = 0;
//#endif
//	/*Set Send Break Mode*/
//#if MUSART2_SEND_BREAK_MODE == MUSART_SEND_BREAK_ENABLED
//	USART2->CR1.SBK = 1;
//#else
//	USART2->CR1.SBK = 0;
//#endif
//	/*Set Baud Rate*/
//	USART2->BRR = ((u16)USART_DIV_VALUE(USART2 , MUSART2_BAUD_RATE)) << MUSART_MANTISSA_B0;
//	local_u8Fraction = ((u8)((USART_DIV_VALUE(USART2 , MUSART2_BAUD_RATE) - (u16)USART_DIV_VALUE(USART2 , MUSART2_BAUD_RATE))*16))&0x0F;
//	USART2->BRR |= local_u8Fraction<<MUSART_FRACTION_B0;
//	/*Set Tranmitter Mode*/
//#if MUSART2_TRANSMITTER_MODE == MUSART_TRANMITTER_ON
//	USART2->CR1.TE = 1;
//#else
//	USART2->CR1.TE = 0;
//#endif
//	/*Set Receiver Mode*/
//#if MUSART2_RECEIVER_MODE == MUSART_RECEIVER_ON
//	USART2->CR1.RE = 1;
//#else
//	USART2->CR1.RE = 0;
//#endif
//
//	/********************USART6 Configurations**********************/
//
//	/*Set Oversampling mode*/
//#if MUSART6_OVERSAMPLING_MODE == MUSART_OVER_ON
//	USART6->CR1.OVER8 = 1;
//#else
//	USART6->CR1.OVER8 = 0;
//#endif
//	/*Set Data Size*/
//#if MUSART6_DATA_SIZE == MUSART_NINE_BITS
//	USART6->CR1.M = 1;
//#else
//	USART6->CR1.M = 0;
//#endif
//	/*Set Wake mode*/
//#if MUSART6_WAKE_MODE == MUSART_ADDRESS_MARK
//	USART6->CR1.WAKE = 1;
//#else
//	USART6->CR1.WAKE = 0;
//#endif
//	/*Set Parity Configurations*/
//#if MUSART6_PARITY_CONTROL == MUSART_PARITY_ENABLED
//	USART6->CR1.PCE = 1;
//#if MUSART6_PARITY_SELECTION == MUSART_PARITY_ODD
//	USART6->CR1.PS = 1;
//#else
//	USART6->CR1.PS = 0;
//#endif
//#else
//	USART6->CR1.PCE = 0;
//#endif
//	/*Set Interrupts States*/
//#if MUSART6_PARITY_ERROR_INTERRUPT_STATE == MUSART_INTERRUPT_ENABLED
//	USART6->CR1.PEIE = 1;
//#else
//	USART6->CR1.PEIE = 0;
//#endif
//#if MUSART6_TRANSMIT_REGISTER_EMPTY_INTERRPUT_STATE == MUSART_INTERRUPT_ENABLED
//	USART6->CR1.TXEIE = 1;
//#else
//	USART6->CR1.TXEIE = 0;
//#endif
//#if MUSART6_TRANSMITTION_COMPLETE_INTERRPUT_STATE == MUSART_INTERRUPT_ENABLED
//	USART6->CR1.TCIE = 1;
//#else
//	USART6->CR1.TCIE = 0;
//#endif
//#if MUSART6_RECEIVER_REGISTER_NOT_EMPTY_INTERRPUT_STATE == MUSART_INTERRUPT_ENABLED
//	USART6->CR1.RXNEIE = 1;
//#else
//	USART6->CR1.RXNEIE = 0;
//#endif
//#if MUSART6_IDLE_LINE_INTERRUPT_STATE == MUSART_INTERRUPT_ENABLED
//	USART6->CR1.IDLEIE = 1;
//#else
//	USART6->CR1.IDLEIE = 0;
//#endif
//	/*Set Send Break Mode*/
//#if MUSART6_SEND_BREAK_MODE == MUSART_SEND_BREAK_ENABLED
//	USART6->CR1.SBK = 1;
//#else
//	USART6->CR1.SBK = 0;
//#endif
//	/*Set Baud Rate*/
//	USART6->BRR = ((u16)USART_DIV_VALUE(USART6 , MUSART6_BAUD_RATE)) << MUSART_MANTISSA_B0;
//	local_u8Fraction = ((u8)((USART_DIV_VALUE(USART6 , MUSART6_BAUD_RATE) - (u16)USART_DIV_VALUE(USART6 , MUSART6_BAUD_RATE))*16))&0x0F;
//	USART6->BRR |= local_u8Fraction<<MUSART_FRACTION_B0;
//	/*Set Tranmitter Mode*/
//#if MUSART6_TRANSMITTER_MODE == MUSART_TRANMITTER_ON
//	USART6->CR1.TE = 1;
//#else
//	USART6->CR1.TE = 0;
//#endif
//	/*Set Receiver Mode*/
//#if MUSART6_RECEIVER_MODE == MUSART_RECEIVER_ON
//	USART6->CR1.RE = 1;
//#else
//	USART6->CR1.RE = 0;
//#endif

}

void MUSART_voidTransmit(u8 A_USART_Number , u8 * p_Data , u8 A_u8Length)
{
	u8 local_u8Iterator = 0;
	switch (A_USART_Number)
	{
	case MUSART_USART1:
		for (local_u8Iterator = 0 ; local_u8Iterator < A_u8Length ; local_u8Iterator++)
		{
			USART1->DR=p_Data[local_u8Iterator];
			while(GET_BIT(USART1->SR , SR_TXE) == USART_NOTSENT);
		}
		break;
	case MUSART_USART2:
		for (local_u8Iterator = 0 ; local_u8Iterator < A_u8Length ; local_u8Iterator++)
		{
			USART2->DR=p_Data[local_u8Iterator];
			while(GET_BIT(USART2->SR , SR_TXE) == USART_NOTSENT);
		}
		break;
	case MUSART_USART6:
		for (local_u8Iterator = 0 ; local_u8Iterator < A_u8Length ; local_u8Iterator++)
		{
			USART6->DR=p_Data[local_u8Iterator];
			while(GET_BIT(USART6->SR , SR_TXE) == USART_NOTSENT);
		}
		break;
	default :
		break;
	}

}

void MUSART_voidReceive(u8 A_USART_Number , u8 * p_Return)
{
	switch (A_USART_Number)
	{
	case MUSART_USART1:
		while(GET_BIT(USART1->SR , SR_RXNE) == USART_NOT_RECEIVED);
		*p_Return = USART1->DR;
		break;
	case MUSART_USART2:
		while(GET_BIT(USART2->SR , SR_RXNE) == USART_NOT_RECEIVED);
		*p_Return = USART2->DR;
		break;
	case MUSART_USART6:
		while(GET_BIT(USART6->SR , SR_RXNE) == USART_NOT_RECEIVED);
		*p_Return = USART6->DR;
		break;
	default :
		break;
	}

}

void MUSART_EnableUSART (u8 A_USART_Number)
{
	switch (A_USART_Number)
	{
	case MUSART_USART1:
		USART1->CR1.UE=USART_ON;
		break;
	case MUSART_USART2:
		USART2->CR1.UE=USART_ON;
		break;
	case MUSART_USART6:
		USART6->CR1.UE=USART_ON;
		break;
	default :
		break;
	}
}

void MUSART_DisableUSART (u8 A_USART_Number)
{
	switch (A_USART_Number)
	{
	case MUSART_USART1:
		USART1->CR1.UE=USART_OFF;
		break;
	case MUSART_USART2:
		USART2->CR1.UE=USART_OFF;
		break;
	case MUSART_USART6:
		USART6->CR1.UE=USART_OFF;
		break;
	default :
		break;
	}
}

/**********************************************************************/
void MSUART_voidSetCallBack(void(*ptf)(void))
{
	MSUART_CallBack = ptf;
}


void USART1_IRQHandler(void)
{
	MSUART_CallBack();
}


