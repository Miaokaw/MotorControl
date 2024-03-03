#ifndef __LED_H__
#define __LED_H__

#include "main.h"

#define LED0(x)                                                                                                                      \
    do                                                                                                                               \
    {                                                                                                                                \
        x ? HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET); \
    } while (0)

#define LED1(x)                                                                                                                      \
    do                                                                                                                               \
    {                                                                                                                                \
        x ? HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); \
    } while (0)

#define LED0_TOGGLE()                                 \
    do                                                \
    {                                                 \
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin); \
    } while (0)
#define LED1_TOGGLE()                                 \
    do                                                \
    {                                                 \
        HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin); \
    } while (0)

#define LED(x, state)                                                                                                                                                                                                                                                              \
    do                                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                                              \
        x ? (state ? HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET)) : (state ? HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET) : HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)); \
    } while (0)

typedef enum
{
    GREEN = 0,
    RED = 1,
} COLOR;

void ledLed(COLOR color, uint8_t num);

#endif /*__LED_H__*/
