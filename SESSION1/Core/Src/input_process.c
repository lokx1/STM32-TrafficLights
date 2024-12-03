/*
 * input_processing.c
 *
 *  Created on: Jul 25, 2023
 *      Author: BAO LONG
 */

#include "input_process.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState[3] = {BUTTON_RELEASED};

void ModeBuffer() {
	switch (buttonState[0]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(0)) {
				buttonState[0] = BUTTON_PRESSED;
				mode++;
				if (mode > 4) {
					mode = 1;
					resetCountValue();
				}
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(0)) {
				buttonState[0] = BUTTON_RELEASED;
			}
			break;
		default:
			break;
	}
}

static void increaseDraftValue() {
	switch (mode) {
		case 2:
			red_temp++;
			if (red_temp > 99) red_temp = 0;
			break;
		case 3:

			green_temp++;
			if (green_temp > 99) green_temp = 0;
			break;
		case 4:
			yellow_temp++;
			if (yellow_temp > 99) yellow_temp = 0;
			break;
		default:
			break;
	}
}

static void setDurationValue() {
	int diff = 0;
	switch (mode) {
		case 2:
			diff = red_temp - red_value;
			red_value = red_temp;
			green_value += diff;
			green_temp += diff;
			break;
		case 3:

			diff = green_temp - green_value;
			green_value = green_temp;
			red_value += diff;
			red_temp += diff;
			break;
		case 4:
			diff = yellow_temp - yellow_value;
			yellow_value = yellow_temp;
			red_value += diff;
			red_temp += diff;

			break;
		default:
			break;
	}
}

void Update() {
	switch (buttonState[1]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(1)) {
				buttonState[1] = BUTTON_PRESSED;
				increaseDraftValue();
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(1)) {
				buttonState[1] = BUTTON_RELEASED;
			}
			if (is_button_pressed_1s(1)) {
				buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				increaseDraftValue();
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(1)) {
				buttonState[1] = BUTTON_RELEASED;
			}
			if (is_button_held(1)) {
				reset_flagForButtonHold(1);
				increaseDraftValue();
			}
			break;
		default:
			break;
	}

	switch (buttonState[2]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(2)) {
				buttonState[2] = BUTTON_PRESSED;
				setDurationValue();
				mode=1;
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(2)) {
				buttonState[2] = BUTTON_RELEASED;
			}
			break;
		default:
			break;
	}
}
