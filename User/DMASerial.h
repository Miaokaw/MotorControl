#ifndef __DMASERIAL_H__
#define __DMASERIAL_H__

#include "stdint.h"
#include "string.h"
#include "usart.h"
#include "stdio.h"

#define SERVO_RXBUFFER_LEN 10

typedef struct _ServoData
{
    uint8_t rxFlag;
    uint8_t rxLen;
    uint8_t rxBuffer[SERVO_RXBUFFER_LEN];
} ServoData;

void ServoDataInit(ServoData *Data);

extern ServoData servoData;

#endif /*__DMASERIAL_H__*/
