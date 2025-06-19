#include "servo.h"
#include "stm32f4xx_hal.h"

void Servo_Init(void) {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	GPIOA->MODER &= ~(3U << (SERVO_PIN * 2));
	GPIOA->MODER |= (2U << (SERVO_PIN * 2));
	GPIOA->OTYPER &= ~(1U << SERVO_PIN);
	GPIOA->OSPEEDR |= (3U << (SERVO_PIN * 2));
	GPIOA->AFR[0] |= (2U << (SERVO_PIN * 4));
	TIM3->CR1 = 0;
	TIM3->PSC = (SystemCoreClock / 1000000) - 1;
	TIM3->ARR = SERVO_PWM_PERIOD - 1;
	TIM3->CCMR1 &= ~(TIM_CCMR1_OC1M);
	TIM3->CCMR1 |= (6U << TIM_CCMR1_OC1M_Pos);
	TIM3->CCMR1 |= TIM_CCMR1_OC1PE;
	TIM3->CCER |= TIM_CCER_CC1E;
	TIM3->CCR1 = SERVO_MIN_PULSE;
	TIM3->EGR |= TIM_EGR_UG;
	TIM3->CR1 |= TIM_CR1_CEN;
}

void Servo_SetAngle(uint16_t angle) {
	if (angle > 180) angle = 180;
	uint32_t pulse = SERVO_MIN_PULSE + ((SERVO_MAX_PULSE - SERVO_MIN_PULSE) * angle) / 180;
	TIM3->CCR1 = pulse;
}

