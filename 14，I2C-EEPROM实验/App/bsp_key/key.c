#include  "key.h"



/*
	��������Key_Scan
	���ܣ�	�����������Ƿ��£������ض�Ӧ��ֵ
	˵����	mode=0,����ɨ�裻mode=1������ɨ��
*/
uint_8 Key_Scan(uint_8 mode)
{
	static uint_8 key = 1;
	
	if(mode)	//mode=1,����ɨ��
	{
		key = 1;
	}	
		
	if(key==1 && (KEY1==0||KEY2==0||KEY3==0||KEY4==0))	//���ⰴ������
	{
		Delay_ms(10);	//����
		key = 0;		//����keyֵ
		if(KEY1==0)
			return	KEY1_PRESS;
		else if(KEY2==0)
			return	KEY2_PRESS;
		else if(KEY3==0)
			return	KEY3_PRESS;
		else if(KEY4==0)
			return	KEY4_PRESS;
	}
	else if(KEY1==1 && KEY2==1 && KEY3==1 && KEY4==1)	//�ް�������
	{
		key = 1;
	}
	return KEY_UNPRESS;
}
