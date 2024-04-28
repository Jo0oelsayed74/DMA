/*
 * MDMA_Private.h
 *
 *  Created on: Apr 21, 2024
 *      Author: yoels
 */

#ifndef MDMA_PRIVATE_H_
#define MDMA_PRIVATE_H_

#define DMA1_BASE_ADRESS (0x40026000)
#define DMA2_BASE_ADRESS (0x40026400)


typedef struct
{
	u32 CR;
	u32 NDTR;
	u32 PAR;
	u32 M0AR;
	u32 M1AR;
	u32 FCR;
}DMA_stream_t;


typedef struct
{
	u32 DMA_LISR;
	u32 DMA_HISR;
	u32 DMA_LIFCR;
	u32 DMA_HIFCR;
	DMA_stream_t s[8];

}DMA_REG_t;

#define DMA1  ((volatile DMA_REG_t*)DMA1_BASE_ADRESS)

#define DMA2  ((volatile DMA_REG_t*)DMA2_BASE_ADRESS)


#endif /* MDMA_PRIVATE_H_ */
