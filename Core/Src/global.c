/*
 * global.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include"global.h"

int led_buffer[4] = {1, 2, 3, 0};

void display7SEG(int seg_counter)
{
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 1);
	switch(seg_counter){
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, 0);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB,SEG1_Pin|SEG2_Pin,0);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG6_Pin,0);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin |SEG6_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin| SEG5_Pin|SEG6_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin, 0);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, 0);
		break;
	}
}

void update7SEG (int index) {
switch ( index ) {
	case 0:
	// Display the first 7 SEG with led_buffer [0]
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN3_Pin, 1);
		display7SEG(led_buffer[0]);
	break ;
	case 1:
	// Display the second 7 SEG with led_buffer [1]
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin|EN3_Pin, 1);
		display7SEG(led_buffer[1]);
	break ;
	case 2:
	// Display the third 7 SEG with led_buffer [2]
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN3_Pin, 1);
		display7SEG(led_buffer[2]);
	break ;
	case 3:
	// Display the forth 7 SEG with led_buffer [3]
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin, 1);
		display7SEG(led_buffer[3]);
	break ;

	default :
	break ;
}
}


