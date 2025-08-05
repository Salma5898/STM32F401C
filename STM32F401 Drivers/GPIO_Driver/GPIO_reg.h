/*
 * GPIO_reg.h
 *
 *  Created on: Jul 31, 2025
 *      Author: samsung
 */

#ifndef MCAL_MGPIO_GPIO_REG_H_
#define MCAL_MGPIO_GPIO_REG_H_

#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800

typedef struct
{
	u32 MODER	;
	u32 OTYPER	;
	u32 OSPEEDR ;
	u32 PUPDR	;
	u32 IDR		;
	u32 ODR		;
	u32 BSRR	;
	u32 LCKR	;
	u32 AFRL	;
	u32 AFRH	;

}GPIO_MemoryMap_t;

#define GPIOA ( (volatile GPIO_MemoryMap_t*)(GPIOA_BASE_ADDRESS) )
#define GPIOB ( (volatile GPIO_MemoryMap_t*)(GPIOB_BASE_ADDRESS) )
#define GPIOC ( (volatile GPIO_MemoryMap_t*)(GPIOC_BASE_ADDRESS) )

#endif /* MCAL_MGPIO_GPIO_REG_H_ */
