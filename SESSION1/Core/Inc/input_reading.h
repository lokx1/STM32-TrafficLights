/*
 * input_reading.h
 *
 *  Created on: Sep 13, 2024
 *      Author: ADMIN
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_
#include "main.h"
typedef struct {
	GPIO_TypeDef *pGPIOx;
	uint16_t pin;

} BUTTON_CONTROL;
extern BUTTON_CONTROL Button[];
void init_button();
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);
unsigned char is_button_held(unsigned char index);
void reset_flagForButtonHold(unsigned char index);
#endif /* INC_INPUT_READING_H_ */
