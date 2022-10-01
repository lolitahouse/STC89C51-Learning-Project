#ifndef __LCD1602_H
#define __LCD1602_H

#include  "public.h"



//�ܽŶ���
sbit LCD1602_RS = P2^6;			//��������ѡ��
sbit LCD1602_RW = P2^5;			//��дѡ��
sbit LCD1602_E = P2^7; 			//ʹ���ź�
#define LCD1602_DATAPORT 	P0	//�궨��LCD1602���ݶ˿�


//��������
void LCD1602_Clear(void);
void LCD1602_Init(void);
void LCD1602_Show_String(uint_8 x,uint_8 y,uint_8 *str);
void LCD1602_Write_Cmd(uint_8 cmd);
void LCD1602_Write_Data(uint_8 dat);


#endif /*__LCD1602_H*/