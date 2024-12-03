/*
 * 7SEG.h
 *
 *  Created on: Aug 31, 2024
 *      Author: ADMIN
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

#include "main.h"

void display7SEG(int num);

typedef struct {
	GPIO_TypeDef *GPIO_Port;
	uint16_t GPIO_Pin;

} LED_CONTROL;
extern int led1;
extern int led2;
extern uint8_t datasend[100];
void mode1Counter2();
void update7SEG();
void mode1Counter();
void displayMode();
#endif /* INC_7SEG_H_ */
