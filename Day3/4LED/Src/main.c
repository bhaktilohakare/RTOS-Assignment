/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void vLED1AperiodicTask(void *pvParam)
{
	while(1) {
			LedBlink(LED_GREEN, 200);
			vTaskDelay(1000);
		}
	vTaskDelete(NULL);
}


void vLED2AperiodicTask(void *pvParam)
{
	while(1) {

			LedBlink(LED_ORANGE, 200);
			vTaskDelay(2000);

		}
	vTaskDelete(NULL);
}

void vLED3AperiodicTask(void *pvParam)
{
	while(1) {

			LedBlink(LED_RED, 200);
			vTaskDelay(1000);
		}
	vTaskDelete(NULL);
}
void vLED4AperiodicTask(void *pvParam)
{
	while(1) {
			LedBlink(LED_BLUE, 200);
			vTaskDelay(2000);
		}
	vTaskDelete(NULL);
}



int main(void)
{
	SystemInit();
	DelayMs(1);
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);
	LedInit(LED_BLUE);
	xTaskCreate(vLED1AperiodicTask, "LED1 Toggle", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(vLED2AperiodicTask, "LED2 Toggle", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(vLED3AperiodicTask, "LED3 Toggle", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(vLED4AperiodicTask, "LED4 Toggle", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

		vTaskStartScheduler();
		while(1);
		return 0;
}


