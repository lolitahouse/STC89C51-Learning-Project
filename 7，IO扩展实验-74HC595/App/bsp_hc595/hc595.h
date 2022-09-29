#ifndef __HC595_H
#define __HC595_H

#include  "public.h"

//定义74HC595控制管脚
sbit SRCLK = P3^6;		//移位寄存器时钟输入
sbit RCLk = P3^5;		//存储寄存器时钟输入
sbit SER = P3^4; 		//串行数据输入

//定义LED点阵的列控制端口
#define LEDDZ_COL_PORT	  P0

extern uint_8 gHC595_buf[8];

//函数声明
void HC595_Write_Data(uint_8 dat);	
void HC595_Display(void);

#endif /*__HC595_H*/