#include "key.h"
#include "delay.h"

void KEY_Init(void)
{
	//PA0 PA15 PC5
	RCC->APB2ENR |= 1<<2;//GPIOA
	RCC->APB2ENR |= 1<<4;//GPIOC
	JTAG_Set(SWD_ENABLE);
	GPIOA->CRL &= 0XFFFFFFF0;
	GPIOA->CRL |= 0X00000008;
	
	GPIOA->CRH &= 0X0FFFFFFF;
	GPIOA->CRH |= 0X80000000;
	GPIOA->ODR |= 1<<15;
	
	GPIOC->CRL &= 0XFF0FFFFF;
	GPIOC->CRL |= 0XFF8FFFFF;
	GPIOC->ODR |= 1<<5;
}

u8 KEY_Scan(u8 mode)
{
	static u8 key_up=1;
	if(mode)key_up=1;
	
	if(key_up && (KEY0==0||KEY1==0||WK_UP==1))
	{
		delay_ms(10);
		key_up=0;
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		else if(WK_UP==1)return WKUP_PRES;
	}
	else if(KEY0==1 && KEY1==1 && WK_UP==0)key_up=1;
	return 0;
}

