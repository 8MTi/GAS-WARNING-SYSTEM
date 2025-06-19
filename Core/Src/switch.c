#include "switch.h"
#include "system_config.h"

volatile uint8_t sw1_pressed = 0;
volatile uint8_t sw2_pressed = 0;
volatile uint32_t last_sw1_time = 0;
volatile uint32_t last_sw2_time = 0;

void Switch_Init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    GPIOC->MODER &= ~((3U << (13 * 2)) | (3U << (0 * 2)));
    GPIOC->PUPDR |= (1U << (13 * 2)) | (1U << (0 * 2));
    GPIOC->OSPEEDR |= (3U << (13 * 2)) | (3U << (0 * 2));

    EXTI->PR |= (1U << 0) | (1U << 13);
    SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0;
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PC;
    SYSCFG->EXTICR[3] &= ~SYSCFG_EXTICR4_EXTI13;
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;
    EXTI->IMR |= (1U << 0) | (1U << 13);
    EXTI->FTSR |= ((1U << 0) | (1U << 13)); // Phát hiện cạnh xuống
    EXTI->RTSR &= ~((1U << 0) | (1U << 13));

    NVIC_SetPriority(EXTI0_IRQn, 1);
    NVIC_SetPriority(EXTI15_10_IRQn, 2);
    NVIC_EnableIRQ(EXTI0_IRQn);
    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI0_IRQHandler(void) {
    if (EXTI->PR & (1U << 0)) {
        EXTI->PR = (1U << 0);
        if ((tick - last_sw2_time > 200) && !(GPIOC->IDR & (1U << 0))) {
            sw2_pressed = 1;
            last_sw2_time = tick;
        }
    }
}

void EXTI15_10_IRQHandler(void) {
    if (EXTI->PR & (1U << 13)) {
        EXTI->PR = (1U << 13);
        if ((tick - last_sw1_time > 200) && !(GPIOC->IDR & (1U << 13))) {
            sw1_pressed = 1;
            last_sw1_time = tick;
        }
    }
}
