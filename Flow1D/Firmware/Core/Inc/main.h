/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SYS_FREQ 32000000
#define US_FREQ 40000
#define SAMPLES_PER_CYCLE 8
#define TIM2_RELOAD ((((SYS_FREQ/US_FREQ)/SAMPLES_PER_CYCLE)*SAMPLES_PER_CYCLE)-1)
#define TIM21_RELOAD (SYS_FREQ/(SAMPLES_PER_CYCLE*US_FREQ)-1)
#define TIM2_CH3_PULSE (TIM2_RELOAD/2)
#define TIM21_CH1_PULSE (TIM21_RELOAD/2)
#define ANOUT_RESOLUTION 1024
#define TIM22_RELOAD ((SYS_FREQ/ANOUT_RESOLUTION)-1)
#define ADC_IN_Pin GPIO_PIN_0
#define ADC_IN_GPIO_Port GPIOA
#define PULSE_Pin GPIO_PIN_2
#define PULSE_GPIO_Port GPIOA
#define DIR_Pin GPIO_PIN_3
#define DIR_GPIO_Port GPIOA
#define ANOUT_PWM_Pin GPIO_PIN_7
#define ANOUT_PWM_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
