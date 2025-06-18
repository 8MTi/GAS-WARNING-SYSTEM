#include "servo.h"
#include "stm32f4xx_hal.h"

void Servo_Init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    GPIOB->MODER &= ~(3U << (0 * 2));
    GPIOB->MODER |= (2U << (0 * 2));
    GPIOB->OTYPER &= ~(1U << 0);
    GPIOB->OSPEEDR |= (3U << (0 * 2));
    GPIOB->AFR[0] |= (2U << (0 * 4));
    TIM3->CR1 = 0;
    TIM3->PSC = (SystemCoreClock / 1000000) - 1;
    TIM3->ARR = 20000 - 1;
    TIM3->CCMR2 &= ~(TIM_CCMR2_OC3M);
    TIM3->CCMR2 |= (6U << TIM_CCMR2_OC3M_Pos);
    TIM3->CCMR2 |= TIM_CCMR2_OC3PE;
    TIM3->CCER |= TIM_CCER_CC3E;
    TIM3->CCR3 = 1000;
    TIM3->EGR |= TIM_EGR_UG;
    TIM3->CR1 |= TIM_CR1_CEN;
}

void Servo_SetAngle(uint16_t angle) {
    if (angle > 180) angle = 180;
    uint32_t pulse = SERVO_MIN_PULSE + ((SERVO_MAX_PULSE - SERVO_MIN_PULSE) * angle) / 180;
    TIM3->CCR3 = pulse;
}
