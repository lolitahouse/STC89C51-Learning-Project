#ifndef __Ired_H
#define __Ired_H

#include  "public.h"


//管脚定义
sbit IRED = P3^2;

//声明变量
extern uint_8 gired_data[4];

//函数声明
void Ired_Init(void);


#endif /*__Ired_H*/