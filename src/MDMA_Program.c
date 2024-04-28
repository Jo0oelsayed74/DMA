/*
 * MDMA_Program.c
 *
 *  Created on: Apr 21, 2024
 *      Author: yoels
 */


/***********************LIB*************************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"


/***********************MCAL************************/
#include "../include/MDMA_Config.h"
#include "../include/MDMA_Interface.h"
#include "../include/MDMA_Private.h"



static void (*DMA2_S0_ptr[8]) (void)={((void*)0)};

void DMA2_Init(void)
{
	DMA2->s[0].CR &=~(1<<0);
	DMA2->s[0].CR =(1<<10)|(1<<9)|(1<<7)|(1<<4);
	DMA2->s[0].FCR =(1<<2)|(1<<1)|(1<<0);
}

void DMA2_SetStreamConfigration(u8 Copy_u8StreamID,
		u8 Copy_u8ChannelID,
		u32 *Copy_pu32SourceAdress,
		u32 *Copy_pu32DestinationAdress,
		u8 Copy_u8ElemntSize,
		u16 Copy_u16BlockSize)
{
DMA2->s[Copy_u8StreamID].CR &=~(1<<0);
DMA2->s[Copy_u8StreamID].CR |=(Copy_u8ChannelID<<25);
DMA2->s[Copy_u8StreamID].CR |=((Copy_u8ElemntSize<<13)|(Copy_u8ElemntSize<<11));
DMA2->s[Copy_u8StreamID].NDTR =Copy_u16BlockSize;
DMA2->s[Copy_u8StreamID].M0AR =Copy_pu32SourceAdress;
DMA2->s[Copy_u8StreamID].M1AR =Copy_pu32DestinationAdress;


}

void DMA2_enableStream(u8 Copy_u8StreamID){
	DMA2->DMA_LIFCR =(1<<0)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
	DMA2->s[Copy_u8StreamID].CR |=(1<<0);
};

void DMA2_SetCallBack(u8 Copy_u8StreamID,void(*ptr)(void))
{
	if(ptr!=NULL){
		DMA2_S0_ptr[Copy_u8StreamID]=ptr;
	}
	else
	{
		/*Do nothing */
	}
}


void DMA2_Stream0_IRQHandler(void){
	if(DMA2_S0_ptr!=NULL){
		DMA2_S0_ptr[0]();
	}
	else
	{
		/*Do nothing */
	}
}

