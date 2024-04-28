/*
 * MGPIO_Program.c
 *
 *  Created on: Feb 5, 2024
 *      Author: yoels
 */

/* STEPS
 * 1. Includes
 * 2. Base Address from memory map P38 in private
 * 3. Struct
 * 4. Volatile Pointers
 * 5. Function Prototypes
 * 6. Function Definition
 * 7. General Macros
 *
 * */

/*			LIB					*/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"


/*			MCAL						*/
#include "../include/MGPIO_Config.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MGPIO_Private.h"


/*			Functions Definitions			*/
void MGPIO_voidSetPinMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8Mode)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Logic of project*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Logic of project*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->GPIO_MODER &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOA->GPIO_MODER |= (copyu8Mode<<(copyu8Pin *2));
			break;

		case GPIO_PORTB:
			GPIOB->GPIO_MODER &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOB->GPIO_MODER |= (copyu8Mode<<(copyu8Pin *2));
			break;

		case GPIO_PORTC:
			GPIOC->GPIO_MODER &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOC->GPIO_MODER |= (copyu8Mode<<(copyu8Pin *2));
			break;

		default:
			break;
		}
	}
}

void MGPIO_voidSetPinOutputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8OutputMode , u8 copyu8Speed)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Logic of project*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Logic of project*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			/*Set speed*/
			GPIOA->OSPEEDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOA->OSPEEDR |= (copyu8Speed<<(copyu8Pin *2));

			/*Pin output mode*/
			GPIOA->OTYPER &= ~(ONE_BIT_MASK <<(copyu8Pin));
			GPIOA->OTYPER |= (copyu8OutputMode<<(copyu8Pin));
			break;

		case GPIO_PORTB:
			GPIOB->OSPEEDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOB->OSPEEDR |= (copyu8Speed<<(copyu8Pin *2));

			GPIOB->OTYPER &= ~(ONE_BIT_MASK <<(copyu8Pin));
			GPIOB->OTYPER |= (copyu8OutputMode<<(copyu8Pin));
			break;

		case GPIO_PORTC:
			GPIOC->OSPEEDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOC->OSPEEDR |= (copyu8Speed<<(copyu8Pin *2));

			GPIOC->OTYPER &= ~(ONE_BIT_MASK <<(copyu8Pin));
			GPIOC->OTYPER |= (copyu8OutputMode<<(copyu8Pin));
			break;

		default:
			break;
		}
	}

}

void MGPIO_voidSetPinInputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8InputMode)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Logic*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Logic*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->PUPDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOA->PUPDR |= (copyu8InputMode<<(copyu8Pin *2));
			break;

		case GPIO_PORTB:
			GPIOB->PUPDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOB->PUPDR |= (copyu8InputMode<<(copyu8Pin *2));
			break;

		case GPIO_PORTC:
			GPIOC->PUPDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOC->PUPDR |= (copyu8InputMode<<(copyu8Pin *2));
			break;

		default:
			break;
		}
	}
}

void MGPIO_voidSetPinValue(u8 copyu8Port, u8 copyu8Pin, u8 copyu8Output)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Logic*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Logic*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			switch(copyu8Output)
			{
			case GPIO_PIN_HIGH:
				SET_BIT(GPIOA->ODR , copyu8Pin);
				break;

			case GPIO_PIN_LOW:
				CLR_BIT(GPIOA->ODR , copyu8Pin);
				break;

			default:
				break;
			}
			break;

			case GPIO_PORTB:
				switch(copyu8Output)
				{
				case GPIO_PIN_HIGH:
					SET_BIT(GPIOB->ODR , copyu8Pin);
					break;

				case GPIO_PIN_LOW:
					CLR_BIT(GPIOB->ODR , copyu8Pin);
					break;

				default:
					break;
				}
				break;

				case GPIO_PORTC:
					switch(copyu8Output)
					{
					case GPIO_PIN_HIGH:
						SET_BIT(GPIOC->ODR , copyu8Pin);
						break;

					case GPIO_PIN_LOW:
						CLR_BIT(GPIOC->ODR , copyu8Pin);
						break;

					default:
						break;
					}
					break;

					default:
						break;
		}
	}
}

void MGPIO_voidGetPinValue(u8 copyu8Port, u8 copyu8Pin, u8 *pu8Return)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Logic*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Logic*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			*pu8Return = GET_BIT(GPIOA->IDR ,copyu8Pin);
			break;

		case GPIO_PORTB:
			*pu8Return = GET_BIT(GPIOB->IDR ,copyu8Pin);
			break;

		case GPIO_PORTC:
			*pu8Return = GET_BIT(GPIOC->IDR ,copyu8Pin);
			break;

		default:
			break;
		}
	}
}

void MGPIO_voidSetResetPin(u8 copyu8Port, u8 copyu8Pin, u8 copyu8SetResetValue)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Logic*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Logic*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			switch(copyu8SetResetValue)
			{
			case GPIO_SET:
				GPIOA->BSRR = (1 <<copyu8Pin);
				break;

			case GPIO_RESET:
				GPIOA->BSRR = (1 <<(copyu8Pin +16));
				break;

			default:
				break;
			}
			break;

			case GPIO_PORTB:
				switch(copyu8SetResetValue)
				{
				case GPIO_SET:
					GPIOB->BSRR = (1 <<copyu8Pin);
					break;

				case GPIO_RESET:
					GPIOB->BSRR = (1 <<(copyu8Pin +16));
					break;

				default:
					break;
				}
				break;

				case GPIO_PORTC:
					switch(copyu8SetResetValue)
					{
					case GPIO_SET:
						GPIOC->BSRR = (1 <<copyu8Pin);
						break;

					case GPIO_RESET:
						GPIOC->BSRR = (1 <<(copyu8Pin +16));
						break;

					default:
						break;
					}
					break;

					default:
						break;
		}
	}
}

void MGPIO_voidSetAltFunction(u8 copyu8Port, u8 copyu8Pin, u8 copyu8AltFunc)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		if(copyu8Pin <= 7)
		{
			switch(copyu8Port)
			{
			case GPIO_PORTA:
				GPIOA->AFRL |= (u32)(copyu8AltFunc << (4U*copyu8Pin));
				break;

			case GPIO_PORTB:
				GPIOB->AFRL |= (u32)(copyu8AltFunc << (4U*copyu8Pin));
				break;

			case GPIO_PORTC:
				GPIOC->AFRL |= (u32)(copyu8AltFunc << (4U*copyu8Pin));
				break;

			default:
				break;
			}
		}
		else
		{
			switch(copyu8Port)
			{
			case GPIO_PORTA:
				GPIOA->AFRH |= (u32)(copyu8AltFunc << (4U*(copyu8Pin%8)));
				break;

			case GPIO_PORTB:
				GPIOB->AFRH |= (u32)(copyu8AltFunc << (4U*(copyu8Pin%8)));
				break;

			case GPIO_PORTC:
				GPIOC->AFRH |= (u32)(copyu8AltFunc << (4U*(copyu8Pin%8)));
				break;

			default:
				break;
			}
		}
	}
}





