#include "Pid.h"

PIDControl xPid = {0};
PIDControl yPid = {0};

void PIDInit(PIDControl *pid, float kp, float ki, float kd, float maxIntegral, float maxError, float loPassFactor)
{
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->integral = 0;
    pid->lastError = 0;
    pid->maxIntegral = maxIntegral;
    pid->maxError = maxError;
    pid->lowPassFactor = loPassFactor;
    pid->output = 0;
}

void PIDCalculate(PIDControl *pid, float targetPoint, float nowPoint)
{
    float error = targetPoint - nowPoint;

    /* 限制误差项 */
    if (error > pid->maxError)
        error = pid->maxError;
    else if (error < -pid->maxError)
        error = -pid->maxError;

    float Pout = pid->kp * error;
    pid->integral += error;

    /* 限制积分项 */
    if (pid->integral > pid->maxIntegral)
        pid->integral = pid->maxIntegral;
    else if (pid->integral < -pid->maxIntegral)
        pid->integral = -pid->maxIntegral;

    float Iout = pid->ki * pid->integral;
    float derivative = (error - pid->lastError);

    /* 低通滤波 */
    derivative *= pid->lowPassFactor;
    float Dout = pid->kd * derivative;

    pid->lastError = error;
    pid->output = Pout + Iout + Dout;
}
