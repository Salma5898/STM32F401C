/*
 * GPIO_cfg.c
 *
 *  Created on: Jul 31, 2025
 *      Author: Salma Hisham
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../MRCC/RCC_init.h"

#include "GPIO_init.h"
#include "GPIO_private.h"
#include "GPIO_reg.h"

/*		User Configurations			*/

GPIO_CFG_t Config_Output_Pin_Push_Pull =
{
		.Mode        	= GPIO_MODE_OUTPUT              ,
		.OutputSpeed 	= GPIO_SPEED_LOW     		,
		.OutputType	= GPIO_OutputType_PushPull	,
		.InputPull	= GPIO_NO_PULL
};

GPIO_CFG_t Config_Output_Pin_Open_Drain =
{
		.Mode         	 = GPIO_MODE_OUTPUT             ,
		.OutputSpeed	 = GPIO_SPEED_LOW     		,
		.OutputType	 = GPIO_OutputType_OpenDrain	,
		.InputPull	 = GPIO_NO_PULL
};

GPIO_CFG_t Config_Input_Pin_No_Pull =
{
		.Mode            = GPIO_MODE_INPUT              ,
		.OutputSpeed	 = GPIO_SPEED_LOW     		,
		.OutputType	 = GPIO_OutputType_PushPull	,
		.InputPull	 = GPIO_NO_PULL
};

GPIO_CFG_t Config_Input_Pin_Pull_Up =
{
		.Mode            = GPIO_MODE_INPUT              ,
		.OutputSpeed	 = GPIO_SPEED_LOW     		,
		.OutputType	 = GPIO_OutputType_PushPull	,
		.InputPull	 = GPIO_PullUp

};

GPIO_CFG_t Config_Input_Pin_Pull_Down =
{
		.Mode           = GPIO_MODE_INPUT               ,
		.OutputSpeed	= GPIO_SPEED_LOW     		,
		.OutputType	= GPIO_OutputType_PushPull	,
		.InputPull	= GPIO_PullDown
};

GPIO_CFG_t Config_Input_Analog =
{
		.Mode            = GPIO_MODE_ANALOG             ,
		.OutputSpeed	 = GPIO_SPEED_LOW     		,
		.OutputType	 = GPIO_OutputType_PushPull	,
		.InputPull	 = GPIO_NO_PULL
};

GPIO_CFG_t Config_Pin_Alt =
{
		.Mode            = GPIO_MODE_ALF                ,
		.OutputSpeed	 = GPIO_SPEED_LOW    		,
		.OutputType	 = GPIO_OutputType_PushPull	,
		.InputPull	 = GPIO_NO_PULL
};

