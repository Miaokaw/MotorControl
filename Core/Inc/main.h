/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../../User/Pid.h"
#include "../../User/ServoControl.h"
#include "../../User/SteppingMotorControl.h"
#include "../../User/Key.h"
#include "../../User/Beep.h"
#include "../../User/Led.h"
#include "../../User/DMASerial.h"
#include "../../User/Process.h"
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PSC 18 - 1
#define ARR 0xFFFF - 1
#define KEY2_Pin GPIO_PIN_2
#define KEY2_GPIO_Port GPIOE
#define KEY1_Pin GPIO_PIN_3
#define KEY1_GPIO_Port GPIOE
#define KEY0_Pin GPIO_PIN_4
#define KEY0_GPIO_Port GPIOE
#define LED1_Pin GPIO_PIN_5
#define LED1_GPIO_Port GPIOE
#define KEY3_Pin GPIO_PIN_6
#define KEY3_GPIO_Port GPIOE
#define MOTOR1_EN_Pin GPIO_PIN_6
#define MOTOR1_EN_GPIO_Port GPIOF
#define MOTOR1_DIR_Pin GPIO_PIN_7
#define MOTOR1_DIR_GPIO_Port GPIOF
#define MOTOR2_EN_Pin GPIO_PIN_8
#define MOTOR2_EN_GPIO_Port GPIOF
#define MOTOR2_DIR_Pin GPIO_PIN_9
#define MOTOR2_DIR_GPIO_Port GPIOF
#define KEY_UP_Pin GPIO_PIN_0
#define KEY_UP_GPIO_Port GPIOA
#define MOTOR4_EN_Pin GPIO_PIN_1
#define MOTOR4_EN_GPIO_Port GPIOB
#define MOTOR1_TIM_Pin GPIO_PIN_6
#define MOTOR1_TIM_GPIO_Port GPIOC
#define MOTOR2_TIM_Pin GPIO_PIN_8
#define MOTOR2_TIM_GPIO_Port GPIOA
#define SERVO_TX_Pin GPIO_PIN_9
#define SERVO_TX_GPIO_Port GPIOA
#define SERVO_RX_Pin GPIO_PIN_10
#define SERVO_RX_GPIO_Port GPIOA
#define MOTOR4_TIM_Pin GPIO_PIN_15
#define MOTOR4_TIM_GPIO_Port GPIOA
#define MOTOR4_DIR_Pin GPIO_PIN_3
#define MOTOR4_DIR_GPIO_Port GPIOB
#define LED0_Pin GPIO_PIN_5
#define LED0_GPIO_Port GPIOB
#define BEEP_Pin GPIO_PIN_8
#define BEEP_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define HCLK 72000000
#define FREQ 4000000
#define NULL 0
#define WAIT(flag)  \
    while (!(flag)) \
    {               \
    }

#define waitS(motor) WAIT(motor.state == IDLE)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
