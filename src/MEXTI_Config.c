/*
 * MEXTI_Config.c
 *
 *  Created on: Feb 10, 2024
 *      Author: yoels
 */


/*
 * MEXTI_Configuartions {
	 * Line
	 * Port
	 * Mode
	 * Initial Value
 * }
 */

#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"
#include "../include/MEXTI_Interface.h"
#include "../include/MEXTI_private.h"
#include "../include/MEXTI_Config.h"


/*
 * Line
 * Port
 * Mode
 * Initial Value
*/


MEXTI_Configuartions MEXTI_Config [MEXTI_NUMBER] =
{
		{
				MEXTI_LINE0,
				MEXTI_PORTB,
				MEXTI_RISING_EDGE,
				MEXTI_ENABLED
		}
		,
		{
				MEXTI_LINE1,
				MEXTI_PORTB,
				MEXTI_RISING_EDGE,
				MEXTI_ENABLED
		}
};
