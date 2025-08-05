/*
 * RCC_prog.c
 *
 *  Created on: Jul 28, 2025
 *      Author: samsung
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "RCC_init.h"
#include "RCC_private.h"
#include "RCC_reg.h"

extern RCC_CFG_t RCC_User_cfg;
void MRCC_voidInit()
{
	/*************** Clock security system enable ***************/
	CLR_BIT(RCC->CR,CSSON);
	RCC->CR |= (RCC_User_cfg.CSS_ENABLE)<<CSSON;

	/*************** Disable HSE Bypass ***************/
	CLR_BIT(RCC->CR,HSEBYP);

	/***************	PLL Configurations	***************/
	//M, N, P values
	RCC->PLLCFGR = 	( (RCC_User_cfg.PLL_M) << PLL_M0 )	|
					( (RCC_User_cfg.PLL_N) << PLL_N0 )	|
					( (RCC_User_cfg.PLL_P) << PLL_P0 );
	//PLL source
	CLR_BIT(RCC->PLLCFGR,PLL_SRC);
	RCC->PLLCFGR |= ((RCC_User_cfg.PLL_SOURCE) << PLL_SRC);

	//AHB , APB1 , APB2 prescaler
	RCC->CFGR &= ~(0b1111 << HPRE);
	RCC->CFGR &= ~(0b111 << PPRE1);
	RCC->CFGR &= ~(0b111 << PPRE2);

	RCC->CFGR |= (RCC_User_cfg.AHB_PRESCALER << HPRE);
	RCC->CFGR |= (RCC_User_cfg.APB1_PRESCALER << PPRE1);
	RCC->CFGR |= (RCC_User_cfg.APB2_PRESCALER << PPRE2);

	//System Clock Source
	CLR_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);
	RCC->CFGR |= (RCC_User_cfg.CLOCK_SOURCE)<<SW0;

	/*************** 	ENABLE/DISABLE HSE, PLL ***************/

	CLR_BIT(RCC->CR,HSEON);
	CLR_BIT(RCC->CR,PLLON);
	RCC->CR |= (	(RCC_User_cfg.HSE_ENABLE)<<HSEON |
					(RCC_User_cfg.PLL_ENABLE)<<PLLON );
}
void MRCC_voidEnablePeripheral	(u8 A_u8BusID, u8 A_u8PeripheralNum)
{
	switch (A_u8BusID)
	{
		case AHB1_BUS: SET_BIT(RCC->AHB1ENR,A_u8PeripheralNum); break;
		case AHB2_BUS: SET_BIT(RCC->AHB2ENR,A_u8PeripheralNum); break;
		case APB1_BUS: SET_BIT(RCC->APB1ENR,A_u8PeripheralNum); break;
		case APB2_BUS: SET_BIT(RCC->APB2ENR,A_u8PeripheralNum); break;
	}
}
void MRCC_voidDisablePeripheral	(u8 A_u8BusID, u8 A_u8PeripheralNum)
{
	switch (A_u8BusID)
	{
		case AHB1_BUS: CLR_BIT(RCC->AHB1ENR,A_u8PeripheralNum); break;
		case AHB2_BUS: CLR_BIT(RCC->AHB2ENR,A_u8PeripheralNum); break;
		case APB1_BUS: CLR_BIT(RCC->APB1ENR,A_u8PeripheralNum); break;
		case APB2_BUS: CLR_BIT(RCC->APB2ENR,A_u8PeripheralNum); break;
	}
}
Freq_t MRCC_xGetSystemClock()
{
	Freq_t SystemClock;

	/*	Check System Frequency	*/
	switch(RCC_User_cfg.CLOCK_SOURCE)
	{
		case HSI_CLOCK: SystemClock.System_Freq = HSI_FREQ; break;
		case HSE_CLOCK: SystemClock.System_Freq = HSE_FREQ; break;
		case PLL_CLOCK:
			switch(RCC_User_cfg.PLL_SOURCE)
			{
				case HSI: SystemClock.System_Freq = (HSI_FREQ*RCC_User_cfg.PLL_N)/(RCC_User_cfg.PLL_M*RCC_User_cfg.PLL_P); break;
				case HSE: SystemClock.System_Freq = (HSE_FREQ*RCC_User_cfg.PLL_N)/(RCC_User_cfg.PLL_M*RCC_User_cfg.PLL_P); break;
			}
	}

	/*	Check AHB Frequency	*/
	switch(RCC_User_cfg.AHB_PRESCALER)
	{
		case AHB_not_divided     : SystemClock.AHB_Freq=SystemClock.System_Freq; break;
		case AHB_divided_by_2    : SystemClock.AHB_Freq=SystemClock.System_Freq/2.0; break;
		case AHB_divided_by_4    : SystemClock.AHB_Freq=SystemClock.System_Freq/4.0; break;
		case AHB_divided_by_8    : SystemClock.AHB_Freq=SystemClock.System_Freq/8.0; break;
		case AHB_divided_by_16   : SystemClock.AHB_Freq=SystemClock.System_Freq/16.0; break;
		case AHB_divided_by_64   : SystemClock.AHB_Freq=SystemClock.System_Freq/64.0; break;
		case AHB_divided_by_128  : SystemClock.AHB_Freq=SystemClock.System_Freq/128.0; break;
		case AHB_divided_by_256  : SystemClock.AHB_Freq=SystemClock.System_Freq/256.0; break;
		case AHB_divided_by_512  : SystemClock.AHB_Freq=SystemClock.System_Freq/512.0; break;
	}

	/*	Check APB1 Frequency	*/
		switch(RCC_User_cfg.APB1_PRESCALER)
		{
			case APB_AHB_not_divided     : SystemClock.APB1_Freq=SystemClock.System_Freq; break;
			case APB_AHB_divided_by_2    : SystemClock.APB1_Freq=SystemClock.System_Freq/2.0; break;
			case APB_AHB_divided_by_4    : SystemClock.APB1_Freq=SystemClock.System_Freq/4.0; break;
			case APB_AHB_divided_by_8    : SystemClock.APB1_Freq=SystemClock.System_Freq/8.0; break;
			case APB_AHB_divided_by_16   : SystemClock.APB1_Freq=SystemClock.System_Freq/16.0; break;
		}
		/*	Check APB1 Frequency	*/
		switch(RCC_User_cfg.APB2_PRESCALER)
		{
			case APB_AHB_not_divided     : SystemClock.APB2_Freq=SystemClock.System_Freq; break;
			case APB_AHB_divided_by_2    : SystemClock.APB2_Freq=SystemClock.System_Freq/2.0; break;
			case APB_AHB_divided_by_4    : SystemClock.APB2_Freq=SystemClock.System_Freq/4.0; break;
			case APB_AHB_divided_by_8    : SystemClock.APB2_Freq=SystemClock.System_Freq/8.0; break;
			case APB_AHB_divided_by_16   : SystemClock.APB2_Freq=SystemClock.System_Freq/16.0; break;
		}
	return SystemClock;
}
