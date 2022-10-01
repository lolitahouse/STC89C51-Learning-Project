#ifndef __PWM_H
#define __PWM_H

#include  "public.h"

//管脚定义
sbit PWM = P2^1;

//变量声明
extern uint_8 gtim_scale;


//函数声明
void PWM_Init(uint_8 tim_h,uint_8 tim_l,uint_16 tim_scale,uint_8 duty);
void PWM_Set_Duty_Cycle(uint_8 duty);


#endif /*__PWM_H*/