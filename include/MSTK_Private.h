/*
 * MSTK_Private.h
 *
 *  Created on: Mar 11, 2024
 *      Author: yoels
 */

#ifndef MSTK_PRIVATE_H_
#define MSTK_PRIVATE_H_

#include "../include/STD_Types.h"


#define STK_BASE_ADDRESS 		(0xE000E010)

typedef struct {
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
} STK_t ;

#define STK ((volatile STK_t*) STK_BASE_ADDRESS)


/* 				 Macros 				*/
/* 				 General  				*/
#define MSTK_RESERVED_MASK 			(0x00FFFFFF)

/* 				 MSTK_CLK_SOURCE Options  				*/
#define MSTK_AHB		1
#define MSTK_AHB_BY_8	2

/* 				 MSTK_CLK_SOURCE Frequency  				*/
#define MSTK_AHB_FREQUENCY		(SYS_FREQUENCY)
#define MSTK_AHB_BY_8_FREQUENCY	(MSTK_AHB_FREQUENCY/8)

/* 				 MSTK CTRL BITS  				*/
#define MSTK_CTRL_ENABLE		0
#define MSTK_CTRL_TICKINT		1
#define MSTK_CTRL_CLKSOURCE		2
#define MSTK_CTRL_COUNTFLAG		16




#endif /* MSTK_PRIVATE_H_ */
