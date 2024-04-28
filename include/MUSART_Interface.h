/*
 * MUSART_Interface.h
 *
 *  Created on: Mar 3, 2024
 *      Author: yoels
 */

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_


/******************USARTs******************/

#define MUSART_USART1				1
#define MUSART_USART2				2
#define MUSART_USART6				6

/*******************APis*******************/

void MUSART_voidInit(void);

void MUSART_voidTransmit(u8 A_USART_Number , u8 * p_Data , u8 A_u8Length);

void MUSART_voidReceive(u8 A_USART_Number , u8 * p_Return);

void MUSART_EnableUSART (u8 A_USART_Number);

void MUSART_DisableUSART (u8 A_USART_Number);

void MSUART_voidSetCallBack(void(*ptf)(void));


#endif /* MUSART_INTERFACE_H_ */
