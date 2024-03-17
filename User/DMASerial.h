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

/* 0x55 0x55 数据长度 命令 数据 功能*/
/* 0x55 0x55 0x     0x01      init*/
/* 0x55 0x55 0x     0x02      cal*/
/* 0x55 0x55 0x     0x03      setTarget*/
/* 0x55 0x55 0x     0x04      claw*/
/* 0x55 0x55 0x     0x05      setFineAdjustMode*/
#endif /*__DMASERIAL_H__*/
