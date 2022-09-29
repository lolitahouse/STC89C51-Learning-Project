#ifndef __LED_H
#define __LED_H

#include  "public.h"

//宏定义P2端口
#define	LED_PORT	P2

//定义LED1管脚
sbit LED1 = P2^0;

//函数声明
void Led_Show(void);

#endif /*__LED_H*/