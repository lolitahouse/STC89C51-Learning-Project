#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H

#include  "public.h"

//����ULN2003���Ʋ�������ܽ�
sbit IN1_A = P1^0;
sbit IN2_B = P1^1;
sbit IN3_C = P1^2;
sbit IN4_D = P1^3;

// ���岽������ٶȣ�ֵԽС���ٶ�Խ��
// ��С����С��1
#define STEPMOTOR_MAXSPEED        1  
#define STEPMOTOR_MINSPEED        5 

//��������
void Step_Motor_Send_Pulse(uint_8 step,uint_8 dir);	


#endif /*__STEP_MOTOR_H*/