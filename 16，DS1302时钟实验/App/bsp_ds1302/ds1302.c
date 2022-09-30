#include  "ds1302.h"
#include "intrins.h"

//---DS1302д��Ͷ�ȡʱ����ĵ�ַ����---//
//---���ʱ�������� ���λ��дλ;-------//
uint_8 gREAD_RTC_ADDR[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d}; 
uint_8 gWRITE_RTC_ADDR[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};

//---DS1302ʱ�ӳ�ʼ��2022��9��30��������21��11��30�롣---//
//---�洢˳�������ʱ��������,�洢��ʽ����BCD��---//
uint_8 gDS1302_TIME[7] = {0x30, 0x11, 0x21, 0x30, 0x09, 0x05, 0x22};

/*
	��������DS1302_Write_Byte
	���ܣ�	DS1302д���ֽں���
*/
void DS1302_Write_Byte(uint_8 addr,uint_8 dat)
{
	uint_8 i = 0;
	
	DS1302_RST = 0;
	_nop_();	
	DS1302_CLK = 0;			//CLK�͵�ƽ
	_nop_();
	DS1302_RST = 1;			//RST�ɵ͵��߱仯
	_nop_();

	for(i=0;i<8;i++)		//��д��λ��д��λ
	{
		DS1302_IO = addr & 0x01;
		addr >>= 1;
		DS1302_CLK = 1;		//CLK�ɵ͵��߲��������أ��Ӷ�д������
		_nop_();
		DS1302_CLK = 0;
		_nop_();		
	}
	for(i=0;i<8;i++)		//��д��λ��д��λ
	{
		DS1302_IO = dat & 0x01;
		dat >>= 1;
		DS1302_CLK = 1;
		_nop_();
		DS1302_CLK = 0;
		_nop_();		
	}
	DS1302_RST = 0;			//RST����
	_nop_();	
}

/*
	��������DS1302_Read_Byte
	���ܣ�	DS1302�����ֽں���
*/
uint_8 DS1302_Read_Byte(uint_8 addr)
{
	uint_8 i = 0;
	uint_8 temp = 0;
	uint_8 value = 0;

	DS1302_RST = 0;
	_nop_();	
	DS1302_CLK = 0;			//CLK�͵�ƽ
	_nop_();
	DS1302_RST = 1;			//RST�ɵ͵��߱仯
	_nop_();
	
	for(i=0;i<8;i++)		//�ȶ���λ�ٶ���λ
	{
		DS1302_IO = addr & 0x01;
		addr >>= 1;	
		DS1302_CLK = 1;		 //CLK�ɵ͵��߲��������أ��Ӷ�д������
		_nop_();
		DS1302_CLK = 0;
		_nop_();		
	}
	for(i=0;i<8;i++)		//�ȶ���λ�ٶ���λ
	{
		temp = DS1302_IO;
		value = (temp<<7)|(value>>1);	//�Ƚ�value����1λ��Ȼ��temp����7λ����������
		DS1302_CLK = 1;
		_nop_();
		DS1302_CLK = 0;
		_nop_();		
	}
	DS1302_RST = 0;			//RST����
	_nop_();	
	DS1302_CLK = 1;		//����P3.4��û�������������ģ�����Ӵ˴��룬ʹ���ݿ�������������
	_nop_();
	DS1302_IO = 0;
	_nop_();
	DS1302_IO = 1;
	_nop_();	
	return value;		
}

/*
	��������DS1302_Init
	���ܣ�	DS1302��ʼ��ʱ�亯��
*/
void DS1302_Init(void)
{
	uint_8 i = 0;
	DS1302_Write_Byte(0x8E,0X00);
	for(i=0;i<7;i++)
	{
		DS1302_Write_Byte(gWRITE_RTC_ADDR[i],gDS1302_TIME[i]);	
	}
	DS1302_Write_Byte(0x8E,0X80);	
}

/*
	��������DS1302_Read_Time
	���ܣ�	DS1302��ȡʱ�亯��
*/
void DS1302_Read_Time(void)
{
	uint_8 i = 0;
	for(i=0;i<7;i++)
	{
		gDS1302_TIME[i] = DS1302_Read_Byte(gREAD_RTC_ADDR[i]);	
	}	
}










