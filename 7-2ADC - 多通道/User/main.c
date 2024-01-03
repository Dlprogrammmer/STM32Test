#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
uint16_t AD0,AD1,AD2,AD3;
uint16_t ADValue;
float Voltage;
//通过多次单次转换实现多通道
int main(void)
{
	OLED_Init();
	AD_Init();
	OLED_ShowString(1,1,"AD0:");
	OLED_ShowString(2,1,"AD1:");
	OLED_ShowString(3,1,"AD2:");
	OLED_ShowString(4,1,"AD3:");
	OLED_ShowString(2,1,"Voltage");
	while(1)
	{
		ADValue=AD_GetValue(ADC_Channel_0);
		ADValue=AD_GetValue(ADC_Channel_1);
		ADValue=AD_GetValue(ADC_Channel_2);
		ADValue=AD_GetValue(ADC_Channel_3);
		OLED_ShowNum(1,5,AD0,4);
		OLED_ShowNum(2,5,AD1,4);
		OLED_ShowNum(3,5,AD2,4);
		OLED_ShowNum(4,5,AD3,4);
		
		Delay_ms(100);
	}
}
