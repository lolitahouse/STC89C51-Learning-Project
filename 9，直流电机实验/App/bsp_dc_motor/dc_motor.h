#ifndef __DC_MOTOR_H
#define __DC_MOTOR_H

#include  "public.h"

//����ֱ��������ƹܽ�
sbit DC_Motor = P1^0;

//����ֱ���������ʱ��Ϊ3000ms
#define DC_MOTOR_RUN_TIME	3000

//��������
void DC_Motor_Run(void);	


#endif /*__DC_MOTOR_H*/