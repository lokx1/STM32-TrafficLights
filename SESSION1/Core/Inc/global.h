/*
 * global.h
 *
 *  Created on: Sep 14, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "timer.h"
#include "main.h"
#include "7SEG.h"
#include "input_reading.h"




#define INIT 				1
#define AUTO_RED 			2
#define AUTO_GREEN 			3
#define AUTO_YELLOW			4

#define INIT1				1
#define AUTO_RED1 			2
#define AUTO_GREEN1 		3
#define AUTO_YELLOW1		4


#define RED_TIME 		5
#define YELLOW_TIME		2
#define GREEN_TIME		3
extern int status;
extern int status1;
void LedInit();
extern int mode;
extern int red_value, yellow_value, green_value;
extern int red_temp, yellow_temp, green_temp;
#endif /* INC_GLOBAL_H_ */
