#ifndef __Ired_H
#define __Ired_H

#include  "public.h"


//�ܽŶ���
sbit IRED = P3^2;

//��������
extern uint_8 gired_data[4];

//��������
void Ired_Init(void);


#endif /*__Ired_H*/