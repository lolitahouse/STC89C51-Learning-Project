#ifndef __XPT2046_H
#define __XPT2046_H

#include  "public.h"

//�ܽŶ���
sbit DOUT = P3^7;	  //���
sbit CLK  = P3^6;	  //ʱ��
sbit DIN  = P3^4;	  //����
sbit CS   = P3^5;	  //Ƭѡ


//��������
uint_16 XPT2046_Read_ADC_Value(uint_8 cmd);
uint_16	XPT2046_Read_Data(void);
void XPT2046_Wirte_Data(uint_8 dat);

void Electricity_Measure(void);
void Light_Measure(void);
void Heat_Measure(void);
void Voltage_Collect(void);


#endif /*__XPT2046_H*/