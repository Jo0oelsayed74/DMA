/*
 * HTFT_Program.c
 *
 *  Created on: Apr 21, 2024
 *      Author: yoels
 */

#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"
#include "../include/MRCC_Interface.h"
#include "../include/MSTK_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MSPI_Interface.h"

#include "../include/HTFT_Interface.h"
#include "../include/HTFT_Private.h"
#include "../include/HTFT_Config.h"
//#include "../include/HTFT/TFT_Monir.h"


void HTFT_voidReset (void)
{
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	MSTK_voidDelayms(100);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	MSTK_voidDelayms(1);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	MSTK_voidDelayms(100);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	MSTK_voidDelayms(100);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	MSTK_voidDelayms(120);

	/**********************************************************************/
	//	MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_HIGH);
	//	MSTK_voidDelayms(2000);
	/**********************************************************************/



	/*Send command sleep out*/
	HTFT_voidSendCommand(0x11);

	/*wait 150 msec*/
	MSTK_voidDelayms(150);

	/*color mode command*/
	HTFT_voidSendCommand(0x3A);
	/*RGB565*/
	HTFT_voidSendData(0x05);

	/*Display command*/
	HTFT_voidSendCommand(0x29);

}

void HTFT_voidInit (void)
{
	MGPIO_voidSetPinMode(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_PUSH_PULL , GPIO_MED_SPEED);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	MGPIO_voidSetPinMode(TFT_CS_PORT , TFT_CS_PIN , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(TFT_CS_PORT , TFT_CS_PIN , GPIO_PUSH_PULL , GPIO_MED_SPEED);
	MGPIO_voidSetResetPin(TFT_CS_PORT , TFT_CS_PIN , GPIO_RESET);
	MGPIO_voidSetPinMode(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_PUSH_PULL , GPIO_MED_SPEED);
	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN5 , GPIO_ALT_FUN);
	MGPIO_voidSetAltFunction(GPIO_PORTA , GPIO_PIN5 , 0b0101);
	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN6 , GPIO_ALT_FUN);
	MGPIO_voidSetAltFunction(GPIO_PORTA , GPIO_PIN6 , 0b0101);
	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN7 , GPIO_ALT_FUN);
	MGPIO_voidSetAltFunction(GPIO_PORTA , GPIO_PIN7 , 0b0101);
	MSTK_voidInit();
	MSTK_voidDisableInterrupt();
	MSPI_voidInit();
	HTFT_voidReset();
	HTFT_voidSendCommand(SLEEP_OUT);
	MSTK_voidDelayms(150);
	HTFT_voidSendCommand(MODE_SET_COLOR);
	HTFT_voidSendData(TFT_COLOR_MODE);
	HTFT_voidSendCommand(DISPLAY_ON);
	MSTK_voidDelayms(1);


	/***************************************************************/
	//	/*Reset sequence*/
	//	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	//	MSTK_voidDelayms(100);
	//
	//	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	//	MSTK_voidDelayms(1);
	//
	//	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	//	MSTK_voidDelayms(100);
	//
	//	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	//	MSTK_voidDelayms(100);
	//
	//	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	//	MSTK_voidDelayms(120);
	//
	//
	//	/*Send command sleep out*/
	//	HTFT_voidSendCommand(0x11);
	//
	//	/*wait 150 msec*/
	//	MSTK_voidDelayms(150);
	//
	//	/*color mode command*/
	//	HTFT_voidSendCommand(0x3A);
	//	/*RGB565*/
	//	HTFT_voidSendData(0x05);
	//
	//	/*Display command*/
	//	HTFT_voidSendCommand(0x29);
}

void HTFT_voidSendPicture (const u16 *p_Picture)
{
	/*******************Send TFT Size******************/

	HTFT_voidSendCommand(SET_X);
	HTFT_voidSendData(TFT_START_PIXEL_Y);
	HTFT_voidSendData(TFT_START_PIXEL_X);
	HTFT_voidSendData(TFT_START_PIXEL_Y);
	HTFT_voidSendData(TFT_PIXELS_X-1);
	HTFT_voidSendCommand(SET_Y);
	HTFT_voidSendData(TFT_START_PIXEL_X);
	HTFT_voidSendData(TFT_START_PIXEL_Y);
	HTFT_voidSendData(TFT_START_PIXEL_X);
	HTFT_voidSendData(TFT_PIXELS_Y-1);

	/****************Send Pixels***********************/
	u16 local_u16Iterator = 0;
	HTFT_voidSendCommand(MEMORY_WRITE);
	for (local_u16Iterator = 0 ; local_u16Iterator < (TFT_PIXELS_X*TFT_PIXELS_Y) ; local_u16Iterator++)
	{
		HTFT_voidSendData((u8)(p_Picture[local_u16Iterator]>>HIGH_BITS));
		HTFT_voidSendData((u8)p_Picture[local_u16Iterator]);

		if(local_u16Iterator==20400)
		{
			MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_HIGH);
			MSTK_voidDelayms(1000);
			MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_LOW);
			MSTK_voidDelayms(1000);
			MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_HIGH);
			MSTK_voidDelayms(1000);
		}
		MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_LOW);
	}
	/***************************************************************************************/
	//	u16 counter = 0;
	//	u8 data;
	//
	//	/*Set x*/
	//	HTFT_voidSendCommand(0x2A);
	//
	//	/*start*/
	//	HTFT_voidSendData(0);
	//	HTFT_voidSendData(0);
	//
	//	/*stop*/
	//	HTFT_voidSendData(0);
	//	HTFT_voidSendData(127);
	//
	//
	//	/*Set y*/
	//	HTFT_voidSendCommand(0x2B);
	//
	//	/*start*/
	//	HTFT_voidSendData(0);
	//	HTFT_voidSendData(0);
	//
	//	/*stop*/
	//	HTFT_voidSendData(0);
	//	HTFT_voidSendData(159);
	//
	//	/*Display command*/
	//	HTFT_voidSendCommand(0x2c);
	//
	//	for(counter =0;counter <20480 ;counter++)
	//	{
	//		data = p_Picture[counter] >> 8;
	//		/*Write data for high byte*/
	//		HTFT_voidSendData(data);
	//
	//		data = p_Picture[counter] & 0x00FF;
	//		/*Write data for low byte*/
	//		HTFT_voidSendData(data);
	//	}
}

static void HTFT_voidSendCommand (u8 A_u8Command)
{
	MGPIO_voidSetResetPin(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_RESET);
	MSPI_voidSendReceiveData(A_u8Command);
}

static void HTFT_voidSendData (u8 A_u8Data)
{
	MGPIO_voidSetResetPin(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_SET);
	MSPI_voidSendReceiveData(A_u8Data);
}


