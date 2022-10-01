#ifndef __LCD12864_H
#define __LCD12864_H

#include  "public.h"

//LCD12864数据端口定义
#define LCD12864_DATAPORT		P0	

//管脚定义
sbit LCD12864_RS = P2^6;		//数据命令选择
sbit LCD12864_WR = P2^5;		//读写选择
sbit LCD12864_E = P2^7;			//使能信号
sbit LCD12864_PSB = P3^2;		//8位或4并口/串口选择


//函数声明
void LCD12864_Clear(void);
void LCD12864_Init(void);
void LCD12864_Show_String(uint_8 x,uint_8 y,uint_8 *str);
void LCD12864_Write_Cmd(uint_8 cmd);
void LCD12864_Write_Data(uint_8 dat);


#endif /*__LCD12864_H*/