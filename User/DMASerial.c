/**
 * @file ServoControl.c
 * @author MSuperHero (320314609@qq.com)
 * @brief 通信
 * @date 2024-01-27
 *
 */
#include "DMASerial.h"

ServoData servoData;

/**
 * @brief 数据初始化
 *
 * @param Data
 * @retval 无
 */
void ServoDataInit(ServoData *Data)
{
    memset(Data, 0, sizeof(ServoData)); /* 初始化 */
}
