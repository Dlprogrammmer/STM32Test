#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
	OLED_ShowString(1,3,"HelloWorld!");
	while(1)
	{
	
	
	}
}
