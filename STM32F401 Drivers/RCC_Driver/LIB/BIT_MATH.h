/*
 * BIT_MATH.h
 *
 *  Created on: Jul 30, 2025
 *      Author: samsung
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_


#define REGISTER_SIZE 32
#define WRT_BIT(reg , bit , val) ((reg) = (((reg) & (~(1<<(bit))) ) | ((val) << (bit))))
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define READ_BIT(reg,bit)   ( (reg & (1<<bit))) >>bit
#define ROR(reg,num)        reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)        reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num))


#endif /* LIB_BIT_MATH_H_ */
