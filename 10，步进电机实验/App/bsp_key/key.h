#ifndef __KEY_H
#define __KEY_H

#include  "public.h"

//��������������ƽ�
sbit KEY1 = P3^1;
sbit KEY2 = P3^0;
sbit KEY3 = P3^2;
sbit KEY4 = P3^3;

//�궨������������µļ�ֵ
#define KEY1_PRESS		1
#define KEY2_PRESS		2
#define KEY3_PRESS		3
#define KEY4_PRESS		4
#define KEY_UNPRESS		0

//����ɨ��ģʽ
#define KEY_SCAN_MODE	0

//��������
uint_8 Key_Scan(uint_8 mode);

#endif /*__KEY_H*/