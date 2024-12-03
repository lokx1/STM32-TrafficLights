/*
 * 7SEG.c
 *
 *  Created on: Aug 31, 2024
 *      Author: ADMIN
 */

#include "7SEG.h"
#include "global.h"
#include "timer.h"
#include "FSM.h"
#include "i2c-lcd.h"
#include <stdio.h>
#include "string.h"
/*void display7SEG(int num) {
	// Turn off all segments first (for common anode, set all to HIGH)
	HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(D_SEG_GPIO_Port, D_SEG_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(E_SEG_GPIO_Port, E_SEG_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(F_SEG_GPIO_Port, F_SEG_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(G_SEG_GPIO_Port, G_SEG_Pin, GPIO_PIN_SET);

	switch (num) {
	case 0:
		HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_SEG_GPIO_Port, D_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_SEG_GPIO_Port, E_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_SEG_GPIO_Port, F_SEG_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_SEG_GPIO_Port, G_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_SEG_GPIO_Port, E_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_SEG_GPIO_Port, D_SEG_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_SEG_GPIO_Port, D_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_SEG_GPIO_Port, G_SEG_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(F_SEG_GPIO_Port, F_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_SEG_GPIO_Port, G_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_SEG_GPIO_Port, F_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_SEG_GPIO_Port, G_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_SEG_GPIO_Port, D_SEG_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_SEG_GPIO_Port, F_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_SEG_GPIO_Port, G_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_SEG_GPIO_Port, D_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_SEG_GPIO_Port, E_SEG_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_SEG_GPIO_Port, D_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(E_SEG_GPIO_Port, E_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_SEG_GPIO_Port, F_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_SEG_GPIO_Port, G_SEG_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D_SEG_GPIO_Port, D_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(F_SEG_GPIO_Port, F_SEG_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_SEG_GPIO_Port, G_SEG_Pin, GPIO_PIN_RESET);
		break;
	default:
		// Invalid number, turn off all segments
		HAL_GPIO_WritePin(A_SEG_GPIO_Port, A_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(B_SEG_GPIO_Port, B_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(C_SEG_GPIO_Port, C_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D_SEG_GPIO_Port, D_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E_SEG_GPIO_Port, E_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(F_SEG_GPIO_Port, F_SEG_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_SEG_GPIO_Port, G_SEG_Pin, GPIO_PIN_SET);
		break;
	}
}*/
int led1 = RED_TIME;
int led2 = GREEN_TIME;
int state1 = AUTO_RED;
int state2 = AUTO_GREEN;
void resetCountValue() {

	led1 = red_value;
	led2 = green_value;
	state1 = AUTO_RED;
	state2 = AUTO_GREEN;


}
char str1[20];
char str2[20];
void mode1Counter() {

	led1--;
	led2--;

	switch (state1) {

	case AUTO_RED:
		//HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
		//HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
		strcpy(str1,"RED:");
		if (led1 <= 0) {
			led1 = green_value;
			state1 = AUTO_GREEN;
			strcpy(str1,"GREEN:");
			//HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			//HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			//HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);

		}
		break;
	case AUTO_YELLOW:
		//HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
		//HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
		strcpy(str1,"YELLOW:");
		if (led1 <= 0) {
			led1 = red_value;
	 		state1 = AUTO_RED;
	 		strcpy(str1,"RED:");
			//HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
			//HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			//HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		}
		break;
	case AUTO_GREEN:
		//HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
		if (led1 <= 0) {
			led1 = yellow_value;
			state1 = AUTO_YELLOW;
			strcpy(str1,"YELLOW:");
			//HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			//HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
			//HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

		}
		break;
	default:
		break;
	}
	switch (state2) {
			case AUTO_RED:
				//HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
				//HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,GPIO_PIN_SET);
				//HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
				strcpy(str2,"RED:");
				if (led2 <= 0) {
					led2 = green_value;
					state2 = AUTO_GREEN;
					strcpy(str2,"GREEN:");
					//HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
					//HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,GPIO_PIN_SET);
					//HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin,GPIO_PIN_RESET);

				}
				break;
			case AUTO_YELLOW:
				//HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
				//HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,GPIO_PIN_RESET);
				//HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
				strcpy(str2,"YELLOW:");
				if (led2 <= 0) {
					led2 = red_value;
					state2 = AUTO_RED;
					strcpy(str2,"RED:");
					//HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
					//HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,GPIO_PIN_SET);
					//HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);

				}
				break;
			case AUTO_GREEN:
				//HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
				//HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,GPIO_PIN_SET);
				//HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
				strcpy(str2,"GREEN:");
				if (led2 <= 0) {
					led2 = yellow_value;
					state2 = AUTO_YELLOW;
					strcpy(str2,"YELLOW:");
					//HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
					//HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,GPIO_PIN_RESET);
					//HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);

				}
				break;
			default:
				break;
			}


}

static int get7SEG1() {
	switch (mode) {
	case 1:
		return led1;
	case 2:
		return red_temp;
	case 3:
		return green_temp;
	case 4:
		return yellow_temp;
	default:
		break;
	}
	return 0;
}
static int get7SEG2() {
	switch (mode) {
	case 1:
		return led2;
	case 2:
		return red_temp;
	case 3:
		return green_temp;
	case 4:
		return yellow_temp;
	default:
		break;
	}
	return 0;
}
char dataframe1[20];
char dataframe2[20];
char dataframe3[50];
char dataframe4[50];
char dataframe5[50];
char dataframe6[50];
/*void update7SEG() {

	switch (mode) {
		case 1:


			sprintf(dataframe1,"Light 1: %d",led1);
			lcd_goto_XY(1,0);
			lcd_send_string(dataframe1);

			sprintf(dataframe2,"Light 2: %d",led2);
			lcd_goto_XY(0,0);
			lcd_send_string(dataframe2);
			break;
		case 2 :

			c
			sprintf(dataframe1,"Red Mode:%d",red_temp);
			lcd_goto_XY(1,0);
			lcd_send_string(dataframe1);

			sprintf(dataframe2,"Mode: %d",mode);
			lcd_goto_XY(0,0);
			lcd_send_string(dataframe2);
			break;
		case 3:


			sprintf(dataframe1,"Green Mode:%d",green_temp);
			lcd_goto_XY(1,0);
			lcd_send_string(dataframe1);

			sprintf(dataframe2,"Mode: %d",mode);
			lcd_goto_XY(0,0);
			lcd_send_string(dataframe2);
			break;
		case 4:


			sprintf(dataframe1,"Yellow Mode:%d",yellow_temp);
			lcd_goto_XY(1,0);
			lcd_send_string(dataframe1);

			sprintf(dataframe2,"Mode: %d",mode);
			lcd_goto_XY(0,0);
			lcd_send_string(dataframe2);
			break;
		default:
			break;
	}


}
*/


void displayMode() {



	switch (mode) {


	case 1:


		if(get0flag()){

			lcd_clear_display();
			sprintf(dataframe1,"ROAD 1 %s%d",str1,get7SEG1());
			lcd_goto_XY(1,0);
			lcd_send_string(dataframe1);


			sprintf(dataframe2,"ROAD 2 %s%d",str2,get7SEG2());
			lcd_goto_XY(0,0);
			lcd_send_string(dataframe2);


			setTimer0(100);
			mode1Counter();




			}


		break;
	case 2:



		if(get3flag()){
			lcd_clear_display();
			sprintf(dataframe1,"Red Mode:%d",red_temp);
			lcd_goto_XY(1,0);
			lcd_send_string(dataframe1);

			sprintf(dataframe2,"Mode: %d",mode);
			lcd_goto_XY(0,0);
			lcd_send_string(dataframe2);
		setTimer3(50);

		HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
		HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);

		HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
		HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);

		}
		break;
	case 3:
		if(get3flag()){
			lcd_clear_display();
			sprintf(dataframe1,"Green Mode:%d",green_temp);
			lcd_goto_XY(1,0);
			lcd_send_string(dataframe1);

			sprintf(dataframe2,"Mode: %d",mode);
			lcd_goto_XY(0,0);
			lcd_send_string(dataframe2);
			setTimer3(50);

		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin,GPIO_PIN_RESET);
		HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin,GPIO_PIN_RESET);
		HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
		}
		break;
	case 4:
		if(get3flag()){
			lcd_clear_display();
			sprintf(dataframe1,"Yellow Mode:%d",yellow_temp);
			lcd_goto_XY(1,0);
			lcd_send_string(dataframe1);

			sprintf(dataframe2,"Mode: %d",mode);
			lcd_goto_XY(0,0);
			lcd_send_string(dataframe2);

		setTimer3(50);

		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin,GPIO_PIN_RESET);
		HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,GPIO_PIN_RESET);
		HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
		}
		break;

	default:
		break;
	}

}

