#ifndef __BEEP_H
#define __BEEP_H

#include  "public.h"

//����P2�˿�
sbit BEEP = P1^5;

//��������
void Beep_Show(uint_16 count);

//����ѭ������
#define CYCLE_NUM	2000

#endif /*__BEEP_H*/