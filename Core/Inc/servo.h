/*
 * servo.h
 *
 *  Created on: Jun 18, 2025
 *      Author: admin
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include <stdint.h>

#define SERVO_PIN            0
#define SERVO_GPIO_PORT      GPIOB
#define SERVO_RCC_AHB1ENR    RCC_AHB1ENR_GPIOBEN
#define SERVO_PWM_PERIOD     20000
#define SERVO_MIN_PULSE      1000
#define SERVO_MAX_PULSE      2000

void Servo_Init(void);
void Servo_SetAngle(uint16_t angle);

#endif /* INC_SERVO_H_ */
