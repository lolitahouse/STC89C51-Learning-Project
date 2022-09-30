#ifndef __DS1302_H
#define __DS1302_H

#include  "public.h"

//�ܽŶ���
sbit DS1302_RST = P3^5;//��λ�ܽ�
sbit DS1302_CLK = P3^6;//ʱ�ӹܽ�
sbit DS1302_IO = P3^4;//���ݹܽ�

//��������
extern uint_8 gDS1302_TIME[7];

//��������
void DS1302_Init(void);
uint_8 DS1302_Read_Byte(uint_8 addr);
void DS1302_Read_Time(void);
void DS1302_Write_Byte(uint_8 addr,uint_8 dat);


#endif /*__DS1302_H*/