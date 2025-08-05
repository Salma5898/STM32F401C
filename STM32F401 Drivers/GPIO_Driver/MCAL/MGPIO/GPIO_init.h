/*
 * GPIO_init.h
 *
 *  Created on: Jul 31, 2025
 *      Author: Salma Hisham
 */

#ifndef MCAL_MGPIO_GPIO_INIT_H_
#define MCAL_MGPIO_GPIO_INIT_H_

/*		User Configurations	Parameters		*/
typedef struct
{
	u8 Mode		;
	u8 OutputType	;
	u8 OutputSpeed	;
	u8 InputPull	;
}GPIO_CFG_t;


/*		GPIO_MODER	(MODE)				*/
#define GPIO_MODE_INPUT			0b00
#define GPIO_MODE_OUTPUT		0b01
#define GPIO_MODE_ALF			0b10
#define GPIO_MODE_ANALOG		0b11

/*		GPIO_OTYPER	(Output Type)		*/
#define GPIO_OutputType_PushPull	0
#define GPIO_OutputType_OpenDrain	1

/*		GPIO_OSPEEDR (Output Speed)		*/
#define GPIO_SPEED_LOW			0b00
#define GPIO_SPEED_MED			0b01
#define GPIO_SPEED_HIGH			0b10
#define GPIO_SPEED_VHIGH		0b11

/*		GPIO_PUPDR (PullUp/Down)		*/
#define GPIO_NO_PULL			0b00
#define GPIO_PullUp			0b01
#define GPIO_PullDown			0b10

/*		GPIO_ODR 	(Output Value)		*/
#define GPIO_OUTPUT_LOW		0
#define GPIO_OUTPUT_HIGH	1

/*		Alternative Function		*/
#define GPIO_AF0_System         0
#define GPIO_AF1_TIM1_2         1
#define GPIO_AF2_TIM3_5         2
#define GPIO_AF3_TIM9_11        3
#define GPIO_AF4_I2C1_3         4
#define GPIO_AF5_SPI1_TO_4      5
#define GPIO_AF6_SPI3           6
#define GPIO_AF7_USART1_2       7
#define GPIO_AF8_USART6         8
#define GPIO_AF9_I2C2_3         9
#define GPIO_AF10_OTG_FS        10
#define GPIO_AF11               11
#define GPIO_AF12_SDIO          12
#define GPIO_AF13               13
#define GPIO_AF14               14
#define GPIO_AF15_EvenOut       15



/*		Port Name		*/
#define GPIO_PORTA	0
#define GPIO_PORTB	1
#define GPIO_PORTC	2

/*		Pin Number		*/
#define GPIO_PIN0	  0
#define GPIO_PIN1	  1
#define GPIO_PIN2	  2
#define GPIO_PIN3	  3
#define GPIO_PIN4	  4
#define GPIO_PIN5	  5
#define GPIO_PIN6	  6
#define GPIO_PIN7	  7
#define GPIO_PIN8	  8
#define GPIO_PIN9	  9
#define GPIO_PIN10	  10
#define GPIO_PIN11	  11
#define GPIO_PIN12	  12
#define GPIO_PIN13	  13
#define GPIO_PIN14	  14
#define GPIO_PIN15	  15

void MGPIO_voidSetMode		(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Mode);
void MGPIO_voidSetOutputType	(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Type);
void MGPIO_voidSetOutputSpeed	(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Speed);
void MGPIO_voidSetIOPull	(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Pull);
void MGPIO_voidSetOutputValue	(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8Value);
u8   MGPIO_u8ReadInputValue	(u8 A_u8PortName, u8 A_u8PinNum);
void MGPIO_voidTogOutputValue	(u8 A_u8PortName, u8 A_u8PinNum);
void MGPIO_voidSetAltFun	(u8 A_u8PortName, u8 A_u8PinNum, u8 A_u8AltFun);
void MGPIO_voidInit		(u8 A_u8PortName, u8 A_u8PinNum, GPIO_CFG_t *A_ptrCfg);

#endif /* MCAL_MGPIO_GPIO_INIT_H_ */


