#ifndef __LED_H
#define __LED_H

#include  "public.h"

//�궨��P2�˿�
#define	LED_PORT	P2

//����LED1�ܽ�
sbit LED1 = P2^0;

//��������
void Led_Show(void);

#endif /*__LED_H*/