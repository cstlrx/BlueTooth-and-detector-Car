#include "motor.h"
void Motor_Init(void)
{
	RCC->APB2ENR|=1<<3;       //PORTB时钟使能   
	GPIOB->CRH&=0X0000FFFF;   //PORTB12 13 14 15推挽输出
	GPIOB->CRH|=0X22220000;   //PORTB12 13 14 15推挽输出
}
void PWM_Init(u16 arr,u16 psc)
{		 					 
	Motor_Init(); //初始化电机控制所需IO
	RCC->APB1ENR|=1<<1;       //TIM3时钟使能   
	
	RCC->APB2ENR|=1<<3;       //PORTB时钟使能     PB0和TIM3 三通道相连
	GPIOB->CRL&=0XFFFFFF00;   //PORTB0 1复用输出	  PB1和TIM34通道相连
	GPIOB->CRL|=0X000000BB;   //PORTB0 1复用输出
	
	TIM3->ARR=arr;//设定计数器自动重装值 
	TIM3->PSC=psc;//预分频器不分频
	
	TIM3->CCMR2|=6<<12;//CH4 PWM1模式	6 110 pwm模式
	TIM3->CCMR2|=6<<4; //CH3 PWM1模式	
	TIM3->CCMR2|=1<<11;//CH4预装载使能	 
	TIM3->CCMR2|=1<<3; //CH3预装载使能	 
	
	TIM3->CCER|=1<<12; //CH4输出使能	   
	TIM3->CCER|=1<<8;  //CH3输出使能	
	
	TIM3->CR1=0x8000;  //ARPE使能 整个TIM总开关
	TIM3->CR1|=0x01;   //使能定时器3 										  
} 
void carStraight(u16 leftPWM, u16 rightPWM){
	
	setPWM(leftPWM,rightPWM);
	
	LEFT_1 = 1;
	RIGHT_1 = 1;
	
	LEFT_2 = 0;
	RIGHT_2 = 0;
}
void carLeft(u16 leftPWM, u16 rightPWM){
	setPWM(leftPWM,rightPWM);
	LEFT_1 = 1;
	RIGHT_1 = 1;
	
	LEFT_2 = 0;
	RIGHT_2 = 0;
}
void carRight(u16 leftPWM, u16 rightPWM){
	setPWM(leftPWM,rightPWM);
	LEFT_1 = 1;
	RIGHT_1 = 1;
	
	LEFT_2 = 0;
	RIGHT_2 = 0;
}
void carBack(u16 leftPWM, u16 rightPWM){
	setPWM(leftPWM,rightPWM);
	LEFT_2 = 1;
	RIGHT_2 = 1;
	
	LEFT_1 = 0;
	RIGHT_1 = 0;
}
void carStop(){
	setPWM(0,0);
	LEFT_1 = 0;
	RIGHT_1 = 0;
}

void setPWM(u16 leftPWM, u16 rightPWM){
	PWM_LEFT = leftPWM;
	PWM_RIGHT = rightPWM;
}
