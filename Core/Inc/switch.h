/*
 * switch.h
 *
 *  Created on: Jun 19, 2025
 *      Author: admin
 */

#ifndef INC_SWITCH_H_
#define INC_SWITCH_H_

#include "stm32f4xx.h"

extern volatile uint8_t sw1_pressed;
extern volatile uint8_t sw2_pressed;
extern volatile uint32_t last_sw1_time;
extern volatile uint32_t last_sw2_time;

void Switch_Init(void);

#endif /* INC_SWITCH_H_ */
