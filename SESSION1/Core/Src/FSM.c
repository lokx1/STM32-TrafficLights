/*
 * FSM.c
 *
 *  Created on: Sep 14, 2024
 *      Author: ADMIN
 */

#include "FSM.h"
#include "7SEG.h"
#include "input_reading.h"
#include "input_process.h"

/*void fsm_run() {
	switch (status) {
	case INIT:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		status = AUTO_RED;
		setTimer0(500);

		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		if (timer0_flag == 1) {
			status = AUTO_GREEN;
			setTimer0(300);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
		if (timer0_flag == 1) {
			status = AUTO_YELLOW;
			setTimer0(200);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
		if (timer0_flag == 1) {
			status = AUTO_RED;
			setTimer0(500);
		}

		break;
	default:
		break;
	}

}
void fsm2_run() {

	switch (status1) {
	case INIT1:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
		status1 = AUTO_GREEN1;
		setTimer1(300);

		break;
	case AUTO_GREEN1:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,
				GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin,
				GPIO_PIN_RESET);
		if (timer1_flag == 1) {
			status1 = AUTO_YELLOW1;
			setTimer1(200);
		}
		break;
	case AUTO_YELLOW1:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
		if (timer1_flag == 1) {
			status1 = AUTO_RED1;
			setTimer1(500);
		}
		break;
	case AUTO_RED1:
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin,
				GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
		if (timer1_flag == 1) {
			status1 = AUTO_GREEN1;
			setTimer1(300);
		}

		break;
	default:
		break;
	}
}
void OtherMode(){
		switch (mode) {
			case 2:
				if(get3flag()){
					setTimer3(50);
					HAL_GPIO_TogglePin(LED_RED_GPIO_Port,LED_RED_Pin);
					HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port,LED_RED_2_Pin);
					HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);

				}
				break;
			case 3:
				if(get3flag()){
					setTimer3(50);
				HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port,LED_YELLOW_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port,LED_YELLOW_2_Pin);
				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
				}
				break;
			case 4:
				if(get3flag()){
					setTimer3(50);
				HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin);
				HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port,LED_GREEN_2_Pin);
				HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
				}
				break;
			default:
				break;
		}



}
*/
