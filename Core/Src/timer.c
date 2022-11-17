/*
 * timer.c
 *
 *  Created on: Sep 24, 2022
 *      Author: PC
 */


#include"timer.h"

int timer_counter[TIMER_COUNT] = {0};
int timer_flag[TIMER_COUNT] = {0};
int timer_delay[TIMER_COUNT] = {50, 25, 25, 25};
int index_led = 0;

void setAllTimer(int duration)
{
	for(int i = 0; i < TIMER_COUNT; i++) setTimer(duration, i);
}

void setTimer(int duration, int index)
{
	timer_flag[index] = 0;
	timer_counter[index] = duration;
}

void timerRun()
{
	for(int i = 0; i < TIMER_COUNT; i++){
	if(timer_counter[i] > 0)
	{
		timer_counter[i]--;
		if(timer_counter[i] <= 0)
		{
			timer_flag[i] = 1;
		}
	}
	}
}

int counter = 50;
int led_counter = 100;
int index = 0;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	if(counter > 0){counter--;}
	else{
		update7SEG(index++);
		index = (index==4)?0:index;
		counter = 50;
	}
	if(led_counter > 0){led_counter--;}
	else{
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		led_counter = 100;
	}
}

void exercise4()
{
	if(timer_flag[0] == 1)
	{
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		setTimer(timer_delay[0], 0);
	}
	if(timer_flag[1] == 1)
	{
		if(index_led >= 4){index_led = 0;}
		update7SEG(index_led++);
		setTimer(timer_delay[1], 1);
	}
}

int hour = 12 , minute = 30 , second = 50;

void updateClockBuffer()
{
	led_buffer[0]=hour/10;
	led_buffer[1]=hour%10;
	led_buffer[2]=minute/10;
	led_buffer[3]=minute%10;
}


void exercise5()
{
	if(timer_flag[2] == 1)
	{
		second++;
		if(second >= 4)
		{
			second = 0;
			minute++;
		}
		if(minute >= 60)
		{
			minute = 0;
			hour++;
		}
		if(hour >= 24)
		{
			hour = 0;
		}
		updateClockBuffer();
		setTimer(timer_delay[2], 2);
	}

}


int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x01, 0x06, 0x38, 0xC8, 0xC8, 0x38, 0x06, 0x01};
uint16_t row_pin[8] = {ROW0_Pin,ROW1_Pin,ROW2_Pin,ROW3_Pin,ROW4_Pin,ROW5_Pin,ROW6_Pin,ROW7_Pin};
uint16_t col_pin[8] = {ENM0_Pin,ENM1_Pin,ENM2_Pin,ENM3_Pin,ENM4_Pin,ENM5_Pin,ENM6_Pin,ENM7_Pin};
uint8_t charA[8] = {0x01, 0x06, 0x38, 0xC8, 0xC8, 0x38, 0x06, 0x01};

void updateLEDMatrix(int index) {
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, 1);
	HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin, 1);

	for(int i = 0; i < 8; i++) {
		if(matrix_buffer[index] & (0x80 >> i)) {
			HAL_GPIO_WritePin(GPIOB, row_pin[i], 0);
		}
	}

	HAL_GPIO_WritePin(GPIOA, col_pin[index], 0);
}

void exercise9()
{
	if(timer_flag[3] == 1)
	{
		if(index_led_matrix >=8){index_led_matrix=0;}
		updateLEDMatrix(index_led_matrix++);
		setTimer(timer_delay[3], 3);
	}
}
