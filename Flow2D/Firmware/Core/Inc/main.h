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
#include "stm32g0xx_hal.h"

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
#define ADC_TRIGGER_FREQ (US_FREQ * 4)
#define US_FREQ 40000
#define TIM3_CH1_COMPARE 1
#define TIM1_RELOAD ((TIM1_CLOCK_FREQ/US_FREQ)-1)
#define TIM3_RELOAD ((TIM3_CLOCK_FREQ/ADC_TRIGGER_FREQ)-1)
#define TIM3_CLOCK_FREQ 64000000
#define TIM1_CLOCK_FREQ 64000000
#define CHA_A_Pin GPIO_PIN_0
#define CHA_A_GPIO_Port GPIOA
#define CHA_B_Pin GPIO_PIN_1
#define CHA_B_GPIO_Port GPIOA
#define CHA_C_Pin GPIO_PIN_2
#define CHA_C_GPIO_Port GPIOA
#define PULSE_N_Pin GPIO_PIN_7
#define PULSE_N_GPIO_Port GPIOA
#define PULSE_Pin GPIO_PIN_8
#define PULSE_GPIO_Port GPIOA
#define PWM_Y_Pin GPIO_PIN_9
#define PWM_Y_GPIO_Port GPIOA
#define PWM_X_Pin GPIO_PIN_10
#define PWM_X_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */
#define ISR_FREQ 400
#define OUTPUT_UPDATE_FREQ 20
#define TRIANGLE_EDGE_IN_METERS 0.034641f
#define DEFAULT_SPEED_OF_SOUND 340.0f
#define GAIN (TRIANGLE_EDGE_IN_METERS * 6.283185307179586f * ((float)US_FREQ) / (DEFAULT_SPEED_OF_SOUND * DEFAULT_SPEED_OF_SOUND))
#define RANGE 20.0f
#define OUTPUT_FILTER_FREQ 10.0f
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
