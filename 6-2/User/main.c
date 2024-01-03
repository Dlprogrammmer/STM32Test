#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
uint16_t Num;
int main(void)
{
	OLED_Init();
	Timer_Init();
	OLED_ShowString(1,1,"Num:");
	while(1)
	{
	OLED_ShowNum(1,5,Num,5);
		//展示自动重装值
	OLED_ShowNum(2,5,TIM_GetCounter(TIM2),5);
	}
}