#ifndef __SMG_H
#define __SMG_H

#include  "public.h"

//��������ܶ����
#define SMG_PORT	P0

//���������λѡ�źſ��ƿ�
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

//��������
extern uint_8 gSmg_init_code[17];
extern uint_8 gSmg_own_code[8];

//��������
void Smg_Display(void);

#endif /*__SMG_H*/