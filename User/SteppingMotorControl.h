#ifndef __STEPPINGMOTORCONTROL_H__
#define __STEPPINGMOTORCONTROL_H__

#include "main.h"
#include "tim.h"
#include "math.h"
#include "malloc.h"
#include "Beep.h"

#define MIN_PWM HCLK / ((PSC + 1) * (ARR + 1))

#define MOTOR1DIRCHANGE(x)                                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        x ? HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET) : HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET); \
    } while (0)
#define MOTOR2DIRCHANGE(x)                                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        x ? HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET) : HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET); \
    } while (0)
#define MOTOR3DIRCHANGE(x) 1
#define MOTOR4DIRCHANGE(x) 2

/* 电机状态 */
typedef enum
{
    IDLE = 0,     /* 电机空闲状态 */
    ACCEL = 1,    /* 电机加速状态 */
    AVESPEED = 2, /* 电机匀速状态 */
    DECEL = 3,    /* 电机减速状态 */
    STOP = 4,     /* 电机停止状态 */
} State;

/* 电机编号 */
typedef enum
{
    MOTOR1 = 1,
    MOTOR2 = 2,
    MOTOR3 = 3,
    MOTOR4 = 4,
} MOTOR;

/* 电机方向 */
typedef enum
{
    FORWARD = 0,  /* 正向 */
    BACKWARD = 1, /* 反向 */
} DIR;

/* 电机主要控制参数 */
typedef struct _MotorControl
{
    // int32_t v0;          /* 初速度 单位 step/s */
    int32_t v1;          /* 末速度 单位 step/s */
    int32_t accStep;     /* 加速段的步数单位 step */
    int32_t decStep;     /* 加速段的步数单位 step */
    float *accTab;       /* 速度表格 单位 step/s 步进电机的脉冲频率 */
    float *decTab;       /* 速度表格 单位 step/s 步进电机的脉冲频率 */
    float *ptr;          /* 速度指针 */
    int32_t changePoint; /* 匀速到减速 */
    int32_t step;        /* 总步数 */
    int32_t pos;         /* 加减速中位置 */
    int32_t actPos;      /* 实际位置 */
    int32_t maxPos;      /* 最大限制位置 */
    uint16_t pulse;      /* pulse */
    uint8_t i;           /* 两次中断输出一次脉冲 */
    State state;         /* 电机状态 */
    MOTOR motor;         /* 电机编号 */
    DIR dir;             /* 电机方向 */
} MotorControl;

extern MotorControl motor1;
extern MotorControl motor2;
extern MotorControl motor3;
extern MotorControl motor4;

extern uint8_t errorBeep;

void motorInit(void);
uint8_t motorMove(MotorControl *motorControl, int32_t v0, int32_t v1, float AccTime, float DecTime, int32_t step);

#endif /*__STEPPINGMOTORCONTROL_H__*/
