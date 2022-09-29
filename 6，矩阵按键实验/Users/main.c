/**************************************************************************************
实验名称：	矩阵按键实验
实验现象：	按下矩阵按键S1-S16键，对应数码管最左边显示0-F
实验单片机：普中A2																				  
***************************************************************************************/

#include "public.h"
#include  "key_matrix.h"
#include  "smg.h"

int main(void)
{
	uint_8 key_value = 0;
			
	while(1)
	{
		key_value = Key_Matrix_Flip_Scan();
		if(key_value != 0)
			SMG_PORT = gSmg_init_code[key_value - 1];
	}
}