#ifndef __PID_H__
#define __PID_H__

// 定义 PID 控制器结构体
typedef struct _PIDControl
{
    float kp;            // 比例系数
    float ki;            // 积分系数
    float kd;            // 微分系数
    float integral;      // 积分项
    float lastError;     // 上次误差
    float maxIntegral;   // 积分项最大值
    float maxError;      // 最大误差
    float lowPassFactor; // 低通滤波器系数
    float output;
} PIDControl;

void PIDInit(PIDControl *pid, float kp, float ki, float kd, float maxIntegral, float maxError, float lowPassFactor);
void PIDCalculate(PIDControl *pid, float targetPoint, float nowPoint);

#endif /*__PID_H__*/
