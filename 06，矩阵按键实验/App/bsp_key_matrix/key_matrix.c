#include  "key_matrix.h"


/*
	��������Key_Matrix_Ranks_Scan
	���ܣ�	ʹ������ʽɨ�跽���������󰴼��Ƿ��£������ض�Ӧ��ֵ
*/
uint_8 Key_Matrix_Ranks_Scan(void)
{
	uint_8 key_value=0;

	KEY_MATRIX_PORT = 0xf7; //��һ�и�0
	if(KEY_MATRIX_PORT != 0xf7)
	{
		Delay_ms(10);	//����
		switch(KEY_MATRIX_PORT)//�����һ�а������º�ļ�ֵ	
		{
			case 0x77: key_value=1; break;
			case 0xb7: key_value=5; break;
			case 0xd7: key_value=9; break;
			case 0xe7: key_value=13; break;
		}
	}
	while(KEY_MATRIX_PORT != 0xf7);//�ȴ������ɿ�	
	
	KEY_MATRIX_PORT=0xfb;	//�ڶ��и�0
	if(KEY_MATRIX_PORT!=0xfb)//�жϵڶ��а����Ƿ���
	{
		Delay_ms(10);	//����
		switch(KEY_MATRIX_PORT)//����ڶ��а������º�ļ�ֵ	
		{
			case 0x7b: key_value=2;break;
			case 0xbb: key_value=6;break;
			case 0xdb: key_value=10;break;
			case 0xeb: key_value=14;break;
		}
	}
	while(KEY_MATRIX_PORT != 0xfb);//�ȴ������ɿ�	
	
	KEY_MATRIX_PORT=0xfd;	//�����и�0
	if(KEY_MATRIX_PORT!=0xfd)//�жϵ����а����Ƿ���
	{
		Delay_ms(10);	//����
		switch(KEY_MATRIX_PORT)//��������а������º�ļ�ֵ	
		{
			case 0x7d: key_value=3;break;
			case 0xbd: key_value=7;break;
			case 0xdd: key_value=11;break;
			case 0xed: key_value=15;break;
		}
	}
	while(KEY_MATRIX_PORT != 0xfd);//�ȴ������ɿ�	
	
	KEY_MATRIX_PORT=0xfe;	//�����и�0
	if(KEY_MATRIX_PORT!=0xfe)//�жϵ����а����Ƿ���
	{
		Delay_ms(10);	//����
		switch(KEY_MATRIX_PORT)//��������а������º�ļ�ֵ	
		{
			case 0x7e: key_value=4;break;
			case 0xbe: key_value=8;break;
			case 0xde: key_value=12;break;
			case 0xee: key_value=16;break;
		}
	}
	while(KEY_MATRIX_PORT != 0xfe);//�ȴ������ɿ�
	
	return key_value;
}


/*
	�������� Key_Matrix_Flip_Scan
	���ܣ�	 ʹ���߷�ת���������󰴼��Ƿ��£������ض�Ӧ��ֵ
*/
uint_8 Key_Matrix_Flip_Scan(void)
{
	static uint_8 key_value = 0;

	KEY_MATRIX_PORT = 0x0f;		//�������и�
	if(KEY_MATRIX_PORT != 0x0f)//�жϰ����Ƿ���
	{
		Delay_ms(10);	//����
		if(KEY_MATRIX_PORT != 0x0f)
		{
			//������
			KEY_MATRIX_PORT = 0x0f;
			switch(KEY_MATRIX_PORT)//������Ϊ0���������º����ֵ	
			{
				case 0x07: key_value=1; break;
				case 0x0b: key_value=2; break;
				case 0x0d: key_value=3; break;
				case 0x0e: key_value=4; break;
			}
			//������
			KEY_MATRIX_PORT = 0xf0;
			switch(KEY_MATRIX_PORT)//������Ϊ0���������º�ļ�ֵ	
			{
				case 0x70: key_value=key_value; break;
				case 0xb0: key_value=key_value+4; break;
				case 0xd0: key_value=key_value+8; break;
				case 0xe0: key_value=key_value+12; break;
			}
			while(KEY_MATRIX_PORT != 0xf0);//�ȴ������ɿ�	
		}
	}
	else
		key_value = 0;		
	
	return key_value;
}












