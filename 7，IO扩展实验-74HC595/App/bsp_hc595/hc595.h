#ifndef __HC595_H
#define __HC595_H

#include  "public.h"

//����74HC595���ƹܽ�
sbit SRCLK = P3^6;		//��λ�Ĵ���ʱ������
sbit RCLk = P3^5;		//�洢�Ĵ���ʱ������
sbit SER = P3^4; 		//������������

//����LED������п��ƶ˿�
#define LEDDZ_COL_PORT	  P0

extern uint_8 gHC595_buf[8];

//��������
void HC595_Write_Data(uint_8 dat);	
void HC595_Display(void);

#endif /*__HC595_H*/