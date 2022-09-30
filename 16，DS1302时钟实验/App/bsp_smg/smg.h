#ifndef __SMG_H
#define __SMG_H

#include  "public.h"

//定义数码管段码口
#define SMG_PORT	P0

//定义显示位置
#define SHOW_POSITION	1

//定义数码管位选信号控制口
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

//数组声明
extern uint_8 gSmg_init_code[17];
extern uint_8 gSmg_own_code[8];

//函数声明
void Smg_Display(uint_8 dat[],uint_8 pos);

#endif /*__SMG_H*/