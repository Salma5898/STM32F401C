/*
 * RCC_init.h
 *
 *  Created on: Jul 28, 2025
 *      Author: samsung
 */

#ifndef MCAL_MRCC_RCC_INIT_H_
#define MCAL_MRCC_RCC_INIT_H_

#define ENABLE	1
#define DISABLE	0

#define HSI_FREQ	16000000
#define HSE_FREQ	25000000

/*			AHB1 Peripherals
	From the Enable Register AHB1ENR
	in STM32f401 development board there are only 3 GPIOs
	so, No need to define all the GPIO in the registers*/
#define RCC_ENABLE_GPIOA	0
#define RCC_ENABLE_GPIOB	1
#define RCC_ENABLE_GPIOC	2
#define RCC_ENABLE_CRC		12
#define RCC_ENABLE_DMA1		21
#define RCC_ENABLE_DMA2		22

/*			AHB2 Peripherals (from AHB2ENR)		*/
#define RCC_ENABLE_OTGFS	7

/*			APB1 Peripherals (from APB1ENR)		*/
#define RCC_ENABLE_TIM2		0
#define RCC_ENABLE_TIM3		1
#define RCC_ENABLE_TIM4		2
#define RCC_ENABLE_TIM5		3
#define RCC_ENABLE_WWDG		11
#define RCC_ENABLE_SPI2		14
#define RCC_ENABLE_SPI3		15
#define RCC_ENABLE_USART2	17
#define RCC_ENABLE_I2C1		21
#define RCC_ENABLE_I2C2		22
#define RCC_ENABLE_I2C3		23
#define RCC_ENABLE_PWR		28

/*			APB2 Peripherals (from APB2ENR)		*/
#define RCC_ENABLE_TIM1		0
#define RCC_ENABLE_USART1	4
#define RCC_ENABLE_USART6	5
#define RCC_ENABLE_ADC1		8
#define RCC_ENABLE_SDIO		11
#define RCC_ENABLE_SPI1		12
#define RCC_ENABLE_SPI4		13
#define RCC_ENABLE_SYSCFG	14
#define RCC_ENABLE_TIM9		16
#define RCC_ENABLE_TIM10	17
#define RCC_ENABLE_TIM11	18

/*		APB1 & APB2 PRESCALER		*/
#define APB_AHB_not_divided     0b000
#define APB_AHB_divided_by_2    0b100
#define APB_AHB_divided_by_4    0b101
#define APB_AHB_divided_by_8    0b110
#define APB_AHB_divided_by_16   0b111

/*		AHB1 & AHB2 PRESCALER		*/
#define AHB_not_divided     0b0000
#define AHB_divided_by_2    0b1000
#define AHB_divided_by_4    0b1001
#define AHB_divided_by_8    0b1010
#define AHB_divided_by_16   0b1011
#define AHB_divided_by_64   0b1100
#define AHB_divided_by_128  0b1101
#define AHB_divided_by_256  0b1110
#define AHB_divided_by_512  0b1111

/*		Clock Source			*/
#define HSI_CLOCK		0b00
#define HSE_CLOCK		0b01
#define PLL_CLOCK		0b10

/*		PLL Source			*/
#define HSI		0
#define HSE		1

#define AHB1_BUS   1
#define AHB2_BUS   2
#define APB1_BUS   3
#define APB2_BUS   4

/*	RCC configurations (The user can control)	*/
typedef struct
{
//	u8  HSI_ENABLE		;
	u8  HSE_ENABLE		;
	u8  PLL_ENABLE		;
	u8  CSS_ENABLE		;
	u8  CLOCK_SOURCE	;
	u8 	PLL_SOURCE		;
	u8	AHB_PRESCALER	;
	u8	APB1_PRESCALER	;
	u8	APB2_PRESCALER	;
	u8  PLL_P			;
	u8  PLL_M			;
	u16 PLL_N			;

}RCC_CFG_t;

/*	a struct to return the Frequency	*/
typedef struct
{
	f32	System_Freq	;
	f32	AHB_Freq	;
	f32	APB1_Freq	;
	f32	APB2_Freq	;
}Freq_t;

void MRCC_voidInit	(void);
void MRCC_voidEnablePeripheral	(u8 A_u8BusID, u8 A_u8PeripheralNum);
void MRCC_voidDisablePeripheral	(u8 A_u8BusID, u8 A_u8PeripheralNum);
Freq_t MRCC_xGetSystemClock	(void);


#endif /* MCAL_MRCC_RCC_INIT_H_ */
