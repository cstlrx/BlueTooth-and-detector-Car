#include"led.h"
void LED_Init(void)
{
	//PA8 PD2
	RCC->APB2ENR |=1<<2;//GPIOA
	RCC->APB2ENR |=1<<5;//GPIOD
	
	GPIOA->CRH   &=0XFFFFFFF0;
	GPIOA->CRH   |=0X00000003;
	
	
	GPIOD->CRL   &=0XFFFFF0FF;
	GPIOD->CRL   |=0X00000300;
	
}

