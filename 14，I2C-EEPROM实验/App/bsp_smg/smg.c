#include  "smg.h"


//�������������ʾ0~F�Ķ�������
uint_8 gSmg_init_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

//�������������ʾ520-1314�Ķ�������
uint_8 gSmg_own_code[8]={0x6d,0x5b,0x3f,0x40,0x06,0x4f,0x06,0x66};


/*
	��������Smg_Display
	���ܣ�	ʵ�ֶ�̬�������ʾ
	ע�⣺	pos:��ʼ��ʾ��λ�ã���Χ1~8
*/
void Smg_Display(uint_8 dat[],uint_8 pos)
{
	uint_8 i = 0;
	uint_8 pos_temp = pos-1;

	for(i=pos_temp;i<8;i++)
	{
	   	switch(i)//λѡ
		{
			case 0: LSC=1;LSB=1;LSA=1; break;
			case 1: LSC=1;LSB=1;LSA=0; break;
			case 2: LSC=1;LSB=0;LSA=1; break;
			case 3: LSC=1;LSB=0;LSA=0; break;
			case 4: LSC=0;LSB=1;LSA=1; break;
			case 5: LSC=0;LSB=1;LSA=0; break;
			case 6: LSC=0;LSB=0;LSA=1; break;
			case 7: LSC=0;LSB=0;LSA=0; break;
		}
		SMG_PORT = gSmg_init_code[ dat[i-pos_temp] ];	//���Ͷ�ѡ����
		Delay_10us(100);				//��ʱһ��ʱ�䣬�ȴ���ʾ�ȶ�
		SMG_PORT = 0x00;				//��Ӱ
	}	
}