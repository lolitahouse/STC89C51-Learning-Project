#ifndef __PWM_H
#define __PWM_H

#include  "public.h"

//�ܽŶ���
sbit PWM = P2^1;

//��������
extern uint_8 gtim_scale;


//��������
void PWM_Init(uint_8 tim_h,uint_8 tim_l,uint_16 tim_scale,uint_8 duty);
void PWM_Set_Duty_Cycle(uint_8 duty);


#endif /*__PWM_H*/