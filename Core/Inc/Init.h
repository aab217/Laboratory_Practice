#include "../../CMSIS/Devices/STM32F4xx/Inc/STM32F429ZI/stm32f429xx.h"
#include "../../CMSIS/Devices/STM32F4xx/Inc/stm32f4xx.h"
#include <stdbool.h>
#include <stdint.h>

#define RCC_AHB1ENR                         *(uint32_t *)(0x40023800UL + 0x30UL)
#define RCC_GPIO_G_EN                        0x040UL

#define GPIO_G_MODER                         *(uint32_t *)(0x40021800UL + 0x00UL)
#define GPIO_G02_OUTPUT                     0x10UL
#define GPIO_G03_OUTPUT                     0x40UL

void GPIO_G_Init(void);
void GPIO_D_Init(void);

void task1(void);
void task2(void);