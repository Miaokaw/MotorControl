#include "Key.h"

uint8_t key_scan(uint8_t mode)
{
    static uint8_t keyUp = 1;
    uint8_t keyVal = 0;

    if (keyUp && (KEY0 == 1 || KEY1 == 0 || KEY2 == 0 || KEY3 == 0 || KEY_UP == 1))
    {
        HAL_Delay(9);
        keyUp = 0;

        if (KEY0 == 1)
            keyVal = KEY0_PRES;

        if (KEY1 == 0)
            keyVal = KEY1_PRES;

        if (KEY2 == 0)
            keyVal = KEY2_PRES;

        if (KEY3 == 0)
            keyVal = KEY3_PRES;

        if (KEY_UP == 1)
            keyVal = KEY_UP_PRES;
    }
    else if (KEY0 == 0 && KEY1 == 1 && KEY2 == 1 && KEY3 == 1 && KEY_UP == 0) /* 没有任何按键按下, 标记按键松开 */
    {
        keyUp = 1;
    }

    return keyVal; /* 返回键值 */
}

/*     if (mode) keyUp = 1;

        if (keyUp && (KEY0 ==1 || KEY_UP == 1))
    {
        HAL_Delay(9);
        keyUp = 0;

        if (KEY0 == 1)  keyVal = KEY0_PRES;

        if (KEY_UP == 1) keyVal = KEY_UP_PRES;
    }
    else if (KEY0 == 0 && KEY_UP == 0)
    {
        keyUp = 1;
    }
*/
