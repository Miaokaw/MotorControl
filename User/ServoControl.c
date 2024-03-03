/**
 * @file ServoControl.c
 * @author MSuperHero (320314609@qq.com)
 * @brief 舵机驱动（幻尔舵机驱动板）
 * @date 2024-01-27
 *
 */
#include "ServoControl.h"

#define UART_TIMEOUT 0xFFFF

uint8_t servoTxBuf[SERVO_NUM * 3 + 7];
int16_t batteryVolt;
Servo servo[SERVO_NUM];
/**
 * @brief 舵机位置初始化
 * @fn 1500即为中间位置
 */
void servoInit(void)
{
    ServoDataInit(&servoData);
    for (uint8_t i = 0; i < SERVO_NUM; i++)
    {
        servo[i].servoID = i;        /* 下标即为编号 */
        servo[i].targetAngel = 1500; /* 90度 */
    }
}

/**
 * @brief 控制任意个舵机的转动
 * @retval 无
 */
void runServosAction(void)
{
    uint8_t index = SERVO_NUM - 1;
    servoTxBuf[0] = servoTxBuf[1] = FRAME_HEAD;
    servoTxBuf[2] = SERVO_NUM * 3 + 5;
    servoTxBuf[3] = CMD_SERVO_MOVE;
    servoTxBuf[4] = SERVO_NUM;
    servoTxBuf[5] = GET_LOW_BYTE(DT);
    servoTxBuf[6] = GET_HIGH_BYTE(DT);

    for (uint8_t i = 7; i < SERVO_NUM * 3 + 7; i += 3)
    {
        servoTxBuf[i] = servo[index].servoID;
        servoTxBuf[i + 1] = GET_LOW_BYTE(servo[index].targetAngel);
        servoTxBuf[i + 2] = GET_HIGH_BYTE(servo[index].targetAngel);
        index--;
    }
    HAL_UART_Transmit(&huart1, servoTxBuf, SERVO_NUM * 3 + 7, UART_TIMEOUT);
}

/**
 * @brief 控制动作组运行
 * @param actionGroupNum 动作组编号
 * @param runTimes 运行次数 0则无限次、
 * @retval 无
 */
void runServosActionGroup(uint8_t actionGroupNum, uint8_t runTimes)
{
    uint8_t num = 2;
    servoData.rxFlag = 0;
    servoTxBuf[0] = servoTxBuf[1] = FRAME_HEAD;
    servoTxBuf[2] = 0x05;
    servoTxBuf[3] = CMD_ACTION_GROUP_RUN;
    servoTxBuf[4] = actionGroupNum;
    servoTxBuf[5] = GET_LOW_BYTE(runTimes);
    servoTxBuf[6] = GET_HIGH_BYTE(runTimes);

    HAL_UART_Transmit(&huart1, servoTxBuf, 0x07, UART_TIMEOUT);
    /* 这里缺少一句 */
}

/**
 * @brief 停止动作组运行
 * @retval 无
 */
void stopServosActionGroup(void)
{
    servoTxBuf[0] = servoTxBuf[1] = FRAME_HEAD;
    servoTxBuf[2] = 0x02;
    servoTxBuf[3] = CMD_ACTION_GROUP_STOP;

    HAL_UART_Transmit(&huart1, servoTxBuf, 0x04, UART_TIMEOUT);
}

/**
 * @brief 更改动作组速度
 * @param actionGroupNum 动作组编号 如 0xFF 则表示全部
 * @param runSpeed 速度比例 %
 * @retval 无
 */
void changeServosActionGroupSpeed(uint8_t actionGroupNum, uint16_t runSpeed)
{
    servoTxBuf[0] = servoTxBuf[1] = FRAME_HEAD;
    servoTxBuf[2] = 0x05;
    servoTxBuf[3] = CMD_ACTION_GROUP_SPEED;
    servoTxBuf[4] = actionGroupNum;
    servoTxBuf[5] = GET_LOW_BYTE(runSpeed);
    servoTxBuf[6] = GET_HIGH_BYTE(runSpeed);

    HAL_UART_Transmit(&huart1, servoTxBuf, 0x07, UART_TIMEOUT);
}
