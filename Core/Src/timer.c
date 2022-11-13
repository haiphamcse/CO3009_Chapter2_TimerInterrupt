/*
 * timer.c
 *
 *  Created on: Sep 24, 2022
 *      Author: PC
 */


#include"timer.h"

int timer_counter[TIMER_COUNT] = {0};
int timer_flag[TIMER_COUNT] = {0};
int timer_delay[TIMER_COUNT] = {100, 10, 10};
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

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	timerRun();
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


