/*
 * GPIO_prog.c
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

/*
 * The debug pins are in AF pull-up/pull-down after reset:
• PA15: JTDI in pull-up
• PA14: JTCK/SWCLK in pull-down
• PA13: JTMS/SWDAT in pull-up
• PB4: NJTRST in pull-up
• PB3: JTDO in floating state
 */

void MGPIO_voidSetMode	(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Mode)
{
	/* Input Validation */
	if (	A_u8PortName == GPIO_PORTA	||
			A_u8PortName == GPIO_PORTB	||
			A_u8PortName == GPIO_PORTC	)
	{
		switch(A_u8PortName)
		{
			case GPIO_PORTA:
				if	(A_u8PinNum < GPIO_PIN13) /* Input Validation */
				{
					//clear
					GPIOA->MODER &= ~( ( 0b11 << (2*A_u8PinNum)));
					GPIOA->MODER |= ( A_u8Mode << (2*A_u8PinNum));
				}
				break;
			case GPIO_PORTB:
				if	(A_u8PinNum != GPIO_PIN3 && A_u8PinNum != GPIO_PIN4) /* Input Validation */
				{
					//clear
					GPIOB->MODER &= ~( ( 0b11 << (2*A_u8PinNum)));
					GPIOB->MODER |= ( A_u8Mode << (2*A_u8PinNum));
				}
				break;
			case GPIO_PORTC:
				if	(A_u8PinNum >= GPIO_PIN13 && A_u8PinNum <= GPIO_PIN15) /* Input Validation */
				{
					//clear
					GPIOC->MODER &= ~(( 0b11 << (2*A_u8PinNum)));
					GPIOC->MODER |= ( A_u8Mode << (2*A_u8PinNum));
				}
				break;
		}
	}
}


void MGPIO_voidSetOutputType	(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Type)
{
	/* Input Validation */
	if (	A_u8PortName == GPIO_PORTA	||
			A_u8PortName == GPIO_PORTB	||
			A_u8PortName == GPIO_PORTC	)
	{
		switch(A_u8PortName)
		{
			case GPIO_PORTA:
				if	(A_u8PinNum < GPIO_PIN13) /* Input Validation */
				{
					//clear
					CLR_BIT(GPIOA->OTYPER,A_u8PinNum);
					GPIOA->OTYPER |= ( A_u8Type << A_u8PinNum);
				}
			break;
			case GPIO_PORTB:
				if	(A_u8PinNum != GPIO_PIN3 && A_u8PinNum != GPIO_PIN4) /* Input Validation */
				{
					//clear
					CLR_BIT(GPIOB->OTYPER,A_u8PinNum);
					GPIOB->OTYPER |= ( A_u8Type << A_u8PinNum);
				}
			break;
			case GPIO_PORTC:
				if	(A_u8PinNum >= GPIO_PIN13 && A_u8PinNum <= GPIO_PIN15) /* Input Validation */
				{
					//clear
					CLR_BIT(GPIOC->OTYPER,A_u8PinNum);
					GPIOC->OTYPER |= ( A_u8Type << A_u8PinNum);
				}
			break;
		}
	}
}

void MGPIO_voidSetOutputSpeed	(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Speed)
{
	/* Input Validation */
	if (	A_u8PortName == GPIO_PORTA	||
			A_u8PortName == GPIO_PORTB	||
			A_u8PortName == GPIO_PORTC	)
	{
		switch(A_u8PortName)
		{
			case GPIO_PORTA:
				if	(A_u8PinNum < GPIO_PIN13) /* Input Validation */
				{
					//clear
					GPIOA->OSPEEDR &= ~( 0b11 << (2*A_u8PinNum));
					GPIOA->OSPEEDR |= ( A_u8Speed << (2*A_u8PinNum));
				}
			break;
			case GPIO_PORTB:
				if	(A_u8PinNum != GPIO_PIN3 && A_u8PinNum != GPIO_PIN4) /* Input Validation */
				{
					//clear
					GPIOB->OSPEEDR &= ~( 0b11 << (2*A_u8PinNum));
					GPIOB->OSPEEDR |= ( A_u8Speed << (2*A_u8PinNum));
				}
			break;
			case GPIO_PORTC:
				if	(A_u8PinNum >= GPIO_PIN13 && A_u8PinNum <= GPIO_PIN15) /* Input Validation */
				{
					//clear
					GPIOC->OSPEEDR &= ~( 0b11 << (2*A_u8PinNum));
					GPIOC->OSPEEDR |= ( A_u8Speed << (2*A_u8PinNum));
				}
			break;
		}
	}
}

void MGPIO_voidSetIOPull		(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Pull)
{
	/* Input Validation */
	if (	A_u8PortName == GPIO_PORTA	||
			A_u8PortName == GPIO_PORTB	||
			A_u8PortName == GPIO_PORTC	)
	{
		switch(A_u8PortName)
		{
			case GPIO_PORTA:
				if	(A_u8PinNum < GPIO_PIN13) /* Input Validation */
				{
					//clear
					GPIOA->PUPDR &= ~( 0b11 << (2*A_u8PinNum));
					GPIOA->PUPDR |= ( A_u8Pull << (2*A_u8PinNum));
				}
			break;
			case GPIO_PORTB:
				if	(A_u8PinNum != GPIO_PIN3 && A_u8PinNum != GPIO_PIN4) /* Input Validation */
				{
					//clear
					GPIOB->PUPDR &= ~( 0b11 << (2*A_u8PinNum));
					GPIOB->PUPDR |= ( A_u8Pull << (2*A_u8PinNum));
				}
			break;
			case GPIO_PORTC:
				if	(A_u8PinNum >= GPIO_PIN13 && A_u8PinNum <= GPIO_PIN15) /* Input Validation */
				{
					//clear
					GPIOC->PUPDR &= ~( 0b11 << (2*A_u8PinNum));
					GPIOC->PUPDR |= ( A_u8Pull << (2*A_u8PinNum));
				}
			break;
		}
	}
}

void MGPIO_voidSetOutputValue	(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Value)
{
	/* Input Validation */
	if (	A_u8PortName == GPIO_PORTA	||
			A_u8PortName == GPIO_PORTB	||
			A_u8PortName == GPIO_PORTC	)
	{
		switch(A_u8PortName)
		{
			case GPIO_PORTA:
				if	(A_u8PinNum < GPIO_PIN13) /* Input Validation */
				{
					//clear
					CLR_BIT(GPIOA->ODR,A_u8PinNum);
					GPIOA->ODR |= ( A_u8Value << A_u8PinNum);
				}
			break;
			case GPIO_PORTB:
				if	(A_u8PinNum != GPIO_PIN3 && A_u8PinNum != GPIO_PIN4) /* Input Validation */
				{
					//clear
					CLR_BIT(GPIOB->ODR,A_u8PinNum);
					GPIOB->ODR |= ( A_u8Value << A_u8PinNum);
				}
			break;
			case GPIO_PORTC:
				if	(A_u8PinNum >= GPIO_PIN13 && A_u8PinNum <= GPIO_PIN15) /* Input Validation */
				{
					//clear
					CLR_BIT(GPIOC->ODR,A_u8PinNum);
					GPIOC->ODR |= ( A_u8Value << A_u8PinNum);
				}
			break;
		}
	}
}

u8 	 MGPIO_u8ReadInputValue		(u8 A_u8PortName, u8 A_u8PinNum)
{
	u8 L_u8PinVal;
	/* Input Validation */
	if (	A_u8PortName == GPIO_PORTA	||
			A_u8PortName == GPIO_PORTB	||
			A_u8PortName == GPIO_PORTC	)
	{
		switch(A_u8PortName)
		{
			case GPIO_PORTA:
				if	(A_u8PinNum < GPIO_PIN13) /* Input Validation */
					L_u8PinVal = READ_BIT(GPIOA->IDR,A_u8PinNum);
			break;
			case GPIO_PORTB:
				if	(A_u8PinNum != GPIO_PIN3 && A_u8PinNum != GPIO_PIN4) /* Input Validation */
					L_u8PinVal = READ_BIT(GPIOB->IDR,A_u8PinNum);
			break;
			case GPIO_PORTC:
				if	(A_u8PinNum >= GPIO_PIN13 && A_u8PinNum <= GPIO_PIN15) /* Input Validation */
					L_u8PinVal = READ_BIT(GPIOC->IDR,A_u8PinNum);
			break;
		}
	}
	return L_u8PinVal;
}


void MGPIO_voidTogOutputValue	(u8 A_u8PortName, u8 A_u8PinNum)
{
	/* Input Validation */
	if (	A_u8PortName == GPIO_PORTA	||
			A_u8PortName == GPIO_PORTB	||
			A_u8PortName == GPIO_PORTC	)
	{
		switch(A_u8PortName)
		{
			case GPIO_PORTA:
				if	(A_u8PinNum < GPIO_PIN13) /* Input Validation */
					TOG_BIT(GPIOA->ODR,A_u8PinNum);
			break;
			case GPIO_PORTB:
				if	(A_u8PinNum != GPIO_PIN3 && A_u8PinNum != GPIO_PIN4) /* Input Validation */
					TOG_BIT(GPIOB->ODR,A_u8PinNum);
			break;
			case GPIO_PORTC:
				if	(A_u8PinNum >= GPIO_PIN13 && A_u8PinNum <= GPIO_PIN15) /* Input Validation */
					TOG_BIT(GPIOC->ODR,A_u8PinNum);
			break;
		}
	}
}

void MGPIO_voidSetAltFun		(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8AltFun)
{
	/* Input Validation */
	if (	A_u8PortName == GPIO_PORTA	||
			A_u8PortName == GPIO_PORTB	||
			A_u8PortName == GPIO_PORTC	)
	{
		switch(A_u8PortName)
		{
			case GPIO_PORTA:
				if	(A_u8PinNum < GPIO_PIN13) /* Input Validation */
				{
					if (A_u8PinNum < GPIO_PIN8)
					{
						GPIOA->AFRL &= ~( 0b1111 << (4*A_u8PinNum));
						GPIOA->AFRL |=  ( A_u8AltFun << (4*A_u8PinNum));
					}
					if (A_u8PinNum >= GPIO_PIN8)
					{
						GPIOA->AFRH &= ~( 0b1111 << (4*(A_u8PinNum-8)));
						GPIOA->AFRH |=  ( A_u8AltFun << (4*(A_u8PinNum-8)) );
					}
				}
			break;
			case GPIO_PORTB:
				if	(A_u8PinNum != GPIO_PIN3 && A_u8PinNum != GPIO_PIN4) /* Input Validation */
				{
					if (A_u8PinNum < GPIO_PIN8)
					{
						GPIOB->AFRL &= ~( 0b1111 << (4*A_u8PinNum));
						GPIOB->AFRL |=  ( A_u8AltFun << (4*A_u8PinNum));
					}
					if (A_u8PinNum >= GPIO_PIN8)
					{
						GPIOB->AFRH &= ~( 0b1111 << (4*(A_u8PinNum-8)));
						GPIOB->AFRH |=  ( A_u8AltFun << (4*(A_u8PinNum-8)) );
					}
				}
			break;
			case GPIO_PORTC:
				if	(A_u8PinNum >= GPIO_PIN13 && A_u8PinNum <= GPIO_PIN15) /* Input Validation */
				{
					GPIOC->AFRH &= ~( 0b1111 << (4*(A_u8PinNum-8)));
					GPIOC->AFRH |=  ( A_u8AltFun << (4*(A_u8PinNum-8)) );
				}
			break;
		}
	}
}

void MGPIO_voidInit (u8 A_u8PortName, u8 A_u8PinNum, GPIO_CFG_t *A_ptrCfg)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(AHB1_BUS,A_u8PortName);
	MGPIO_voidSetMode 	 (A_u8PortName, A_u8PinNum, A_ptrCfg->Mode);
	MGPIO_voidSetOutputType	 (A_u8PortName, A_u8PinNum, A_ptrCfg->OutputType);
	MGPIO_voidSetOutputSpeed (A_u8PortName, A_u8PinNum, A_ptrCfg->OutputSpeed);
	MGPIO_voidSetIOPull	 (A_u8PortName, A_u8PinNum, A_ptrCfg->InputPull);
}

