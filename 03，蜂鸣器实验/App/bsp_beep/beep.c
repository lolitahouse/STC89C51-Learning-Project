#include  "beep.h"

/*
	��������Beep_Show
	���ܣ�	ʵ�ַ���������
*/
void Beep_Show(uint_16 count)
{
	for(;count>0;count--)
	{
		BEEP = !BEEP;    //����һ��Ƶ�ʵ������ź�
		Delay_10us(100);
	}
	count = 0;		//��������
	BEEP = 0;	    //�رշ�����
}