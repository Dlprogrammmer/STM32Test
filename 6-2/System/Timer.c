#include "stm32f10x.h"                  // Device header
extern uint16_t Num;
void Timer_Init(void)
{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
		TIM_InternalClockConfig(TIM2);
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
		TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=10000-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	//清除标志位，防止重启时自动触发更新中断导致计数直接从1开始
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	//TIM_IT_Update 代表更新中断
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	//选择NVIC分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	//选择TIM2在NVIC里的通道
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	//响应优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
	//启动定时器
	TIM_Cmd(TIM2,ENABLE);
}
//重写定时器2的更新中断函数
void  TIM2_IRQHandler(void)
{
	//检查中断标志位
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
		Num++;
		//清除标志位
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}	