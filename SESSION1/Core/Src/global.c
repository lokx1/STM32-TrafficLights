/*
 * global.c
 *
 *  Created on: Sep 14, 2024
 *      Author: ADMIN
 */

#include "global.h"

int mode;
int red_value, yellow_value, green_value;
int red_temp, yellow_temp, green_temp;
int status = 0;
int status1 = 0;
void LedInit() {
	red_value = RED_TIME;
	yellow_value = YELLOW_TIME;
	green_value = GREEN_TIME;
	red_temp = red_value;
	yellow_temp = yellow_value;
	green_temp = green_value;

}
