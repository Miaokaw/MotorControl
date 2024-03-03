#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"

#define KEY0        HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)     /* 读取KEY0引脚 */
#define KEY1        HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)     /* 读取KEY1引脚 */
#define KEY_UP      HAL_GPIO_ReadPin(KEY_UP_GPIO_Port, KEY_UP_Pin)     /* 读取WKUP引脚 */

#define KEY0_PRES    1              /* KEY0按下 */
#define KEY1_PRES    2              /* KEY1按下 */
#define KEY_UP_PRES  3              /* KEY_UP按下(即WK_UP) */

uint8_t  key_scan(uint8_t mode);

#endif /*__KEY_H__*/
