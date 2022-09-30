#ifndef __KEY_MATRIX_H
#define __KEY_MATRIX_H

#include  "public.h"

//使用宏定义矩阵按键控制口
#define KEY_MATRIX_PORT		P1	

//函数声明
uint_8 Key_Matrix_Ranks_Scan(void);
uint_8 Key_Matrix_Flip_Scan(void);

#endif /*__KEY_MATRIX_H*/