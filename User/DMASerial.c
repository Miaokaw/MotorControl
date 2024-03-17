/**
 * @file ServoControl.c
 * @author MSuperHero (320314609@qq.com)
 * @brief 通信
 * @date 2024-01-27
 *
 */
#include "DMASerial.h"

ServoData servoData = {0};

/**
 * @brief 数据初始化
 *
 * @param Data
 * @retval 无
 */
void ServoDataInit(ServoData *Data)
{
    for (uint8_t i = 0; i < SERVO_RXBUFFER_LEN; i++)
        Data->rxBuffer[i] = 0;
    Data->rxFlag = 0;
    Data->rxLen = 0;
}
