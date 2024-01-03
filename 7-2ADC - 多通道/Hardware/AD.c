#include "stm32f10x.h"                  // Device header
void AD_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	GPIO_InitTypeDef GPIO_InitStructure;
	//配置模式为模拟输入
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//选择规则组输入通道
	
	ADC_InitTypeDef ADC_InitStructure;
	//工作模式
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;
	//数据对齐方式
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;
	//外部触发源选择
	ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	//连续转换还是单次转换
	ADC_InitStructure.ADC_ContinuousConvMode=DISABLE;
	//是否为扫描模式
	ADC_InitStructure.ADC_ScanConvMode=DISABLE;
	//扫描模式下通道数目
	ADC_InitStructure.ADC_NbrOfChannel=1;
	ADC_Init(ADC1,&ADC_InitStructure);
	//开启电源
	ADC_Cmd(ADC1,ENABLE);
	//校准
	//复位校准
ADC_ResetCalibration(ADC1);
//获取复位校准状态
while(ADC_GetResetCalibrationStatus(ADC1));
//开始校准
ADC_StartCalibration(ADC1);
//获取开始校准状态
while(ADC_GetCalibrationStatus(ADC1));

}
uint16_t AD_GetValue(uint8_t ADC_Channel)
{
	ADC_RegularChannelConfig(ADC1,ADC_Channel,1,ADC_SampleTime_55Cycles5);
	//软件触发转换
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	//获取规则组转换标志位
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)==RESET);
	//获取结果
	return ADC_GetConversionValue(ADC1);
}