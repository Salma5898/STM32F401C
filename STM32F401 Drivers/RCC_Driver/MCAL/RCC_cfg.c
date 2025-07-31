/*
 * RCC_cfg.c
 *
 *  Created on: Jul 28, 2025
 *      Author: Salma Hisham
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "RCC_init.h"
#include "RCC_private.h"
#include "RCC_reg.h"

/*		User Configurations			*/
RCC_CFG_t RCC_User_cfg =
{
    .HSI_ENABLE		=		DISABLE	        ,
    .HSE_ENABLE		=		ENABLE	        ,
    .PLL_ENABLE		=		DISABLE	        ,
    .CSS_ENABLE		=		DISABLE	        ,
    .CLOCK_SOURCE	=		HSE_CLOCK	,
    .PLL_SOURCE		=		HSE	    	,
    .AHB_PRESCALER	=	AHB_not_divided		,
    .APB1_PRESCALER	=	APB_AHB_not_divided	,
    .APB2_PRESCALER	=	APB_AHB_not_divided	,
    .PLL_P		=		2           	,
    .PLL_M		=		30          	,
    .PLL_N		=		200
};
