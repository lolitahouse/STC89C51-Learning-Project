#ifndef __BEEP_H
#define __BEEP_H

#include  "public.h"

//定义P2端口
sbit BEEP = P1^5;

//函数声明
void Beep_Show(uint_16 count);

//定义循环次数
#define CYCLE_NUM	2000

#endif /*__BEEP_H*/