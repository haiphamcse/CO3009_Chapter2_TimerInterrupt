/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#define TIMER_COUNT 4

void display7SEG(int);
void update7SEG(int);

extern int index_led;
extern int led_buffer[4];
#endif /* INC_GLOBAL_H_ */
