#include "detector.h"

void detectorInit(){
	//初始化红外接口 PA12 PA13
	RCC->APB2ENR |= 1<<2;
	
	GPIOA->CRH &= 0xFF00FFFF;
	GPIOA->CRH |= 0x00880000;
	//GPIOA->CRH |= 0x00330000;
	GPIOA->ODR |= 1<<12;
	GPIOA->ODR |= 1<<13;
}
