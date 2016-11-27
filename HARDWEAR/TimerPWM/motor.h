#ifndef __MOTOR_H
#define __MOTOR_H
#include <sys.h>	 

#define PWM_LEFT   TIM3->CCR3 //控制左边轮子pwm PB0

#define LEFT_1   PBout(12)//右边向前
#define RIGHT_2   PBout(13)
#define LEFT_2    PBout(14)//左边向前
#define RIGHT_1     PBout(15)

#define PWM_RIGHT  TIM3->CCR4 //控制右边轮子pwm PB1


void PWM_Init(u16 arr,u16 psc);
void Motor_Init(void);
void carStraight(u16 leftPWM, u16 rightPWM);
void carLeft(u16 leftPWM, u16 rightPWM);
void carRight(u16 leftPWM, u16 rightPWM);
void carBack(u16 leftPWM, u16 rightPWM);
void carStop(void);
void setPWM(u16 leftPWM, u16 rightPWM);
#endif
