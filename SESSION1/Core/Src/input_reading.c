/*
 * input_reading.c
 *
 *  Created on: Sep 13, 2024
 *      Author: ADMIN
 */
#include "input_reading.h"

#define N0_OF_BUTTONS 				       3

BUTTON_CONTROL Button[] =
	{ { BUTTON1_GPIO_Port, BUTTON1_Pin },
	  { BUTTON2_GPIO_Port,BUTTON2_Pin },
	  { BUTTON3_GPIO_Port, BUTTON3_Pin },
	};

//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   100
#define DURATION_FOR_HOLD					50
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
//the buffer that the final result is stored after
//debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];

//we define two buffers for debouncing

static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];

static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

static GPIO_PinState debounceButtonBuffer3[N0_OF_BUTTONS];

//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
static uint8_t flagForButtonHold[N0_OF_BUTTONS];

//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
static uint16_t counterForButtonHold[N0_OF_BUTTONS];
void init_button() {
	for (int i = 0; i < N0_OF_BUTTONS; i++) {
		buttonBuffer[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer3[i] = BUTTON_IS_RELEASED;
		flagForButtonPress1s[i] = 0;
		flagForButtonHold[i] = 0;
		counterForButtonPress1s[i] = 0;
		counterForButtonHold[i] = 0;
	}
}
void button_reading(void) {

	for (char i = 0; i < N0_OF_BUTTONS; i++) {
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Button[i].pGPIOx,Button[i].pin);

		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i] && debounceButtonBuffer3[i] == debounceButtonBuffer2[i])

			buttonBuffer[i] = debounceButtonBuffer1[i];

		if (buttonBuffer[i] == BUTTON_IS_PRESSED) {


			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,GPIO_PIN_RESET);
			//if a button is pressed,counting
			if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
				counterForButtonPress1s[i]++;
			} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
				flagForButtonPress1s[i] = 1;

				//todo
				if (counterForButtonHold[i] < DURATION_FOR_HOLD) {
					counterForButtonHold[i]++;
					if (counterForButtonHold[i] >= DURATION_FOR_HOLD) {
						counterForButtonHold[i] = 0;
						flagForButtonHold[i] = 1;
					}
				}
			}
		} else {
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
			counterForButtonHold[i] = 0;
			flagForButtonHold[i] = 0;
		}
	}
}

unsigned char is_button_pressed(unsigned char index) {
	if (index >= N0_OF_BUTTONS) return 0;

	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index) {

	if (index >= N0_OF_BUTTONS)return 0;

	return (flagForButtonPress1s[index] == 1);
}

unsigned char is_button_held(unsigned char index) {


	if (index >= N0_OF_BUTTONS)return 0;

	return (flagForButtonHold[index] == 1);
}

void reset_flagForButtonHold(unsigned char index) {
	flagForButtonHold[index] = 0;
}
