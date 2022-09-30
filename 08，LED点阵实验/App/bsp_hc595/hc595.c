#include  "hc595.h"


uint_8 gled_row[8] = {0x00,0x7C,0x82,0x82,0x82,0x7C,0x00,0x00};//LED������ʾ����0��������
uint_8 gled_row_heart[8] = {0x38,0x7C,0x7E,0x3F,0x3F,0x7E,0x7C,0x38};//LED������ʾ���ε�������
uint_8 gled_col[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};//LED������ʾ������



/*
	��������HC595_Write_Data
	���ܣ�	��74HC595д��һ���ֽڵ�����
*/
void HC595_Write_Data(uint_8 dat)
{
	uint_8 i = 0;

	for(i=0;i<8;i++) 	//ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
	{
		SER = dat >>7;	//���ȴ����λ,���Ƚ���λ�Ƶ����λ
		dat <<= 1;		//���θ�λ�Ƶ���λ
		SRCLK = 0;
		Delay_10us(1);
		SRCLK = 1;
		Delay_10us(1);	//��λ�Ĵ���ʱ�������ؽ��˿���������Ĵ�����
	}
	RCLk = 0;
	Delay_10us(1);
	RCLk = 1;			//�洢�Ĵ���ʱ�������ؽ�ǰ��д�뵽�Ĵ������������
}


/*
	��������HC595_Display
	���ܣ�	��ʾ����0 �� ���ε�ͼ��
*/
void HC595_Display(void)
{
	static uint_8 i = 0;

	for(i=0;i<8;i++)//ѭ��8��ɨ��8�С���
	{
		LEDDZ_COL_PORT = gled_col[i];	 //������ѡ����
		HC595_Write_Data(gled_row_heart[i]);   //������ѡ����
		Delay_10us(100);				 //��ʱһ��ʱ�䣬�ȴ���ʾ�ȶ�
		HC595_Write_Data(0x00);		     //��Ӱ	
	}
}








