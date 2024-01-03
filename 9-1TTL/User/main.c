#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
uint8_t RxData;
int main(void)
{
	OLED_Init();
	Serial_Init();
	Serial_SendByte(0x41);
	while(1)
	{
	if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==SET)
	{
		
	RxData=USART_ReceiveData(USART1);
	OLED_ShowNum(1,1,RxData,2);
	}
}
}
