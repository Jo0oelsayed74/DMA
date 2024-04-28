/*
 * MUSART_private.h
 *
 *  Created on: Mar 3, 2024
 *      Author: yoels
 */
#include "../include/STD_Types.h"

#ifndef MUSART_PRIVATE_H_
#define MUSART_PRIVATE_H_

#define USART1_BASE_ADDRESS				(0x40011000)
#define USART2_BASE_ADDRESS				(0x40004400)
#define USART6_BASE_ADDRESS				(0x40011400)



typedef struct{
	u32 SBK : 1;
	u32 RWU : 1;
	u32 RE : 1;
	u32 TE : 1;
	u32 IDLEIE : 1;
	u32 RXNEIE : 1;
	u32 TCIE : 1;
	u32 TXEIE : 1;
	u32 PEIE : 1;
	u32 PS : 1;
	u32 PCE : 1;
	u32 WAKE : 1;
	u32 M : 1;
	u32 UE : 1;
	u32 RESERVED1 : 1;
	u32 OVER8 : 1;
	u32 RESERVED2 : 16;
}CR1_t;



typedef struct {
	u32 ADD : 4;
	u32 RESERVED1 : 1;
	u32 LBDL : 1;
	u32 LBDIE : 1;
	u32 RESERVED2 : 1;
	u32 LBCL : 1;
	u32 CPHA : 1;
	u32 CPOL : 1;
	u32 CLKEN : 1;
	u32 STOP : 2;
	u32 LINEN : 1;
	u32 RESERVED3 : 17;
}CR2_t;

typedef struct{
	u32 EIE : 1;
	u32 IREN : 1;
	u32 IRLP : 1;
	u32 HDSEL : 1;
	u32 NACK : 1;
	u32 SCEN : 1;
	u32 DMAR : 1;
	u32 DMAT : 1;
	u32 RTSE : 1;
	u32 CTSE : 1;
	u32 CTSIE : 1;
	u32 ONEBIT : 1;
	u32 RESERVED1 : 20;
}CR3_t;

typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	CR1_t CR1;
	CR2_t CR2;
	CR3_t CR3;
	u32 GTPR;
}USART_t;

#define USART1				((volatile USART_t * )USART1_BASE_ADDRESS)
#define USART2				((volatile USART_t * )USART2_BASE_ADDRESS)
#define USART6				((volatile USART_t * )USART6_BASE_ADDRESS)

/*******************MACRos*******************/


#define USART_DIV_VALUE(USART , BAUD)		(USART_CLK/(8.0*(2-(USART->CR1.OVER8))*BAUD))

#define USART_ON							1
#define USART_OFF							0

#define SR_TXE								7
#define SR_RXNE								5

#define USART_NOTSENT						0

#define USART_NOT_RECEIVED					0

#define MUSART_OVER_OFF						0
#define MUSART_OVER_ON						1

#define MUSART_EIGHT_BITS					0
#define MUSART_NINE_BITS					1

#define MUSART_IDEAL_LINE					0
#define MUSART_ADDRESS_MARK					1

#define MUSART_PARITY_ENABLED				1
#define MUSART_PARITY_DISABLED				0

#define MUSART_PARITY_ODD					1
#define MUSART_PARITY_EVEN					0

#define MUSART_INTERRUPT_ENABLED			1
#define MUSART_INTERRUPT_DISABLED			0

#define MUSART_TRANMITTER_ON				1
#define MUSART_TRANMITTER_OFF				0

#define MUSART_RECEIVER_ON					1
#define MUSART_RECEIVER_OFF					0

#define MUSART_SEND_BREAK_ENABLED			1
#define MUSART_SEND_BREAK_DISABLED			0

#define MUSART_1_STOP_BIT					0b00
#define MUSART_0_5_STOP_BIT					0b01
#define MUSART_2_STOP_BITS					0b10
#define MUSART_1_5_STOP_BITS				0b11

#define MUSART_MANTISSA_B0					4
#define MUSART_FRACTION_B0					0





#endif /* MUSART_PRIVATE_H_ */
