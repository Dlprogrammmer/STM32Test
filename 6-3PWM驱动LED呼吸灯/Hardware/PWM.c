#include "stm32f10x.h"                  // Device header
void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	TIM_InternalClockConfig(TIM2);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=100-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler=720-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	TIM_OCInitTypeDef TIM_OCInitStructure;
	//给结构体赋初始值
	TIM_OCStructInit(&TIM_OCInitStructure);
	//输出比较的模式
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	//输出比较的极性
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High; 
	//输出比较的使能
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	//设置CCR(输出比较寄存器的值)
	TIM_OCInitStructure.TIM_Pulse=90;
	TIM_OC1Init(TIM2,&TIM_OCInitStructure); 
	//启动定时器
	TIM_Cmd(TIM2,ENABLE);

}
void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2,Compare);
}