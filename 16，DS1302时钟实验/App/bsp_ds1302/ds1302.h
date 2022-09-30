#ifndef __DS1302_H
#define __DS1302_H

#include  "public.h"

//管脚定义
sbit DS1302_RST = P3^5;//复位管脚
sbit DS1302_CLK = P3^6;//时钟管脚
sbit DS1302_IO = P3^4;//数据管脚

//变量声明
extern uint_8 gDS1302_TIME[7];

//函数声明
void DS1302_Init(void);
uint_8 DS1302_Read_Byte(uint_8 addr);
void DS1302_Read_Time(void);
void DS1302_Write_Byte(uint_8 addr,uint_8 dat);


#endif /*__DS1302_H*/