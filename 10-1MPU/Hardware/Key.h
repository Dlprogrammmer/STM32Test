#include "stdint.h"
#ifndef _KEY_H
#define _KEY_H
void  LED_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED2_ON(void);
void LED2_OFF(void);
void Key_Init(void);
uint8_t Key_GetNum(void);
#endif