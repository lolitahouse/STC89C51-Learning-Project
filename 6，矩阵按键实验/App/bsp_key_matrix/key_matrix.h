#ifndef __KEY_MATRIX_H
#define __KEY_MATRIX_H

#include  "public.h"

//ʹ�ú궨����󰴼����ƿ�
#define KEY_MATRIX_PORT		P1	

//��������
uint_8 Key_Matrix_Ranks_Scan(void);
uint_8 Key_Matrix_Flip_Scan(void);

#endif /*__KEY_MATRIX_H*/