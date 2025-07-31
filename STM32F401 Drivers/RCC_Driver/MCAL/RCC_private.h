/*
 * RCC_private.h
 *
 *  Created on: Jul 28, 2025
 *      Author: Salma Hisham
 */

#ifndef MCAL_MRCC_RCC_PRIVATE_H_
#define MCAL_MRCC_RCC_PRIVATE_H_



/*		RCC_CR bits		*/
#define HSION	0
#define HSEON	16
#define HSEBYP	18		//bypassed with an external clock
#define CSSON	19
#define PLLON	24

/*		RCC_PLLCFGR bits		*/
#define PLL_M0	0
#define PLL_N0	6
#define PLL_P0	16
#define PLL_SRC	22

/*		RCC_CFGR bits			*/
#define SW0		0
#define SW1		1
#define HPRE	4	//AHB Prescaler
#define PPRE1	10	//APB1 Prescaler
#define PPRE2	13	//APB2 Prescaler

#endif /* MCAL_MRCC_RCC_PRIVATE_H_ */
