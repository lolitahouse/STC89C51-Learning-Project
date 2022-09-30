#include  "hc595.h"


// LEDDZ������ʾ����
uint_8 gHC595_buf[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};



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

void HC595_Display(void)
{
	static uint_8 i = 0;

	for(i=0;i<8;i++)
	{
		HC595_Write_Data(0x00);	//����ǰ��Ĵ�����������
		HC595_Write_Data(gHC595_buf[i]);	//д���µ�����
		Delay_ms(500);			//��ʱ500ms
	}
	for(i=6;i>0;i--)
	{
		HC595_Write_Data(0x00);	//����ǰ��Ĵ�����������
		HC595_Write_Data(gHC595_buf[i]);	//д���µ�����
		Delay_ms(500);			//��ʱ500ms	
	}
}








