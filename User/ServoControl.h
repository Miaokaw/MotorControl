#ifndef __SERVOCONTROL_H__
#define __SERVOCONTROL_H__

#include "stdint.h"
#include "usart.h"
#include "../../User/DMASerial.h"

#define FRAME_HEAD 0x55 /* 帧头 */

#define SERVO_NUM 5    /* 舵机数量 */
#define DT 50          /* 控制周期 */
#define ALL_SERVO 0xFF /* 表示全部舵机 */

#define CMD_SERVO_MOVE 0x03          /* 控制任意个舵机的转动 */
#define CMD_ACTION_GROUP_RUN 0x06    /* 控制动作组运行 */
#define CMD_ACTION_GROUP_STOP 0x07   /* 停止正在运行的动作组 */
#define CMD_ACTION_GROUP_SPEED 0x0B  /* 控制动作组的速度 */
#define CMD_GET_BATTERY_VOLTAGE 0x0F /* 获取控制板电池电压 */

#define GET_LOW_BYTE(DATA) ((uint8_t)(DATA))
#define GET_HIGH_BYTE(DATA) ((uint8_t)((DATA) >> 8))

typedef struct _Servo
{
    uint8_t servoID;      /* 舵机编号 */
    uint16_t targetAngel; /* 目标角度 */
} Servo;

extern Servo servo[SERVO_NUM];

void servoInit(void);
void runServosAction(void);
void runServosActionGroup(uint8_t actionGroupNum, uint8_t runTimes);
void stopServosActionGroup(void);
void changeServosActionGroupSpeed(uint8_t actionGroupNum, uint16_t runSpeed);
int16_t getBatteryVoltage(void);

#endif /*__SERVOCONTROL_H__*/
