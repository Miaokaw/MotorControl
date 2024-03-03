#include "Led.h"

void ledLed(COLOR color, uint8_t num)
{
    while (num > 0)
    {
        LED(color, 0);
        HAL_Delay(500);
        LED(color, 1);
        HAL_Delay(500);
        num--;
    }
}
