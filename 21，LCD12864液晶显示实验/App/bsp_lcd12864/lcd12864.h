#ifndef __LCD12864_H
#define __LCD12864_H

#include  "public.h"

//LCD12864���ݶ˿ڶ���
#define LCD12864_DATAPORT		P0	

//�ܽŶ���
sbit LCD12864_RS = P2^6;		//��������ѡ��
sbit LCD12864_WR = P2^5;		//��дѡ��
sbit LCD12864_E = P2^7;			//ʹ���ź�
sbit LCD12864_PSB = P3^2;		//8λ��4����/����ѡ��


//��������
void LCD12864_Clear(void);
void LCD12864_Init(void);
void LCD12864_Show_String(uint_8 x,uint_8 y,uint_8 *str);
void LCD12864_Write_Cmd(uint_8 cmd);
void LCD12864_Write_Data(uint_8 dat);


#endif /*__LCD12864_H*/