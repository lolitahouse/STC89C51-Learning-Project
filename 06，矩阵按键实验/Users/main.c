/**************************************************************************************
ʵ�����ƣ�	���󰴼�ʵ��
ʵ������	���¾��󰴼�S1-S16������Ӧ������������ʾ0-F
ʵ�鵥Ƭ��������A2																				  
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