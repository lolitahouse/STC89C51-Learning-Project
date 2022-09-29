#ifndef __KEY_H
#define __KEY_H

#include  "public.h"

//定义独立按键控制脚
sbit KEY1 = P3^1;
sbit KEY2 = P3^0;
sbit KEY3 = P3^2;
sbit KEY4 = P3^3;

//宏定义独立按键按下的键值
#define KEY1_PRESS		1
#define KEY2_PRESS		2
#define KEY3_PRESS		3
#define KEY4_PRESS		4
#define KEY_UNPRESS		0

//定义扫描模式
#define KEY_SCAN_MODE	0

//函数声明
uint_8 Key_Scan(uint_8 mode);

#endif /*__KEY_H*/