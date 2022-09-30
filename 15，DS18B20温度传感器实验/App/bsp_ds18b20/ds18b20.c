#include  "ds18b20.h"
#include "intrins.h"

/*
	�������� DS18B20_Reset
	���ܣ�	 ��λDS18B20
*/
void DS18B20_Reset(void)
{
	DS18B20_PORT = 0;	//����DQ
	Delay_10us(75);	   //����750us
	DS18B20_PORT = 1;	//DQ=1
	Delay_10us(2);		//20uS
}

/*
	�������� DS18B20_Check
	���ܣ�	 ���DS18B20�Ƿ����
	ע�⣺	 ����1����ʾ�����ڣ�0��ʾ����
*/
uint_8 DS18B20_Check(void)
{
	uint_8 time_temp = 0;

	while(DS18B20_PORT && time_temp < 20)	//�ȴ�DQΪ�͵�ƽ
	{
		time_temp++;
		Delay_10us(1);	
	}
	if(time_temp >= 20)
		return 1;			//�����ʱ��ǿ�Ʒ���1
	else 
		time_temp = 0;
	while((!DS18B20_PORT) && time_temp < 20)	//�ȴ�DQΪ�ߵ�ƽ
	{
		time_temp++;
		Delay_10us(1);
	}
	if(time_temp >= 20)
		return 1;		//�����ʱ��ǿ�Ʒ���1
	return 0;
}

/*
	�������� DS18B20_Read_Bit
	���ܣ�	 ��DS18B20��ȡһ��λ
*/
uint_8 DS18B20_Read_Bit(void)
{
	uint_8 dat = 0;
	
	DS18B20_PORT = 0;
	_nop_();
	_nop_();
	DS18B20_PORT = 1;	
	_nop_();
	_nop_(); 			//�ö�ʱ�䲻�ܹ�����������15us�ڶ�ȡ����
	if(DS18B20_PORT)
		dat = 1;		//���������Ϊ1������datΪ1������Ϊ0
	else 
		dat = 0;
	Delay_10us(5);
	return dat;
}

/*
	�������� DS18B20_Read_Byte
	���ܣ�	 ��DS18B20��ȡһ���ֽ�
*/
uint_8 DS18B20_Read_Byte(void)
{
	uint_8 i = 0;
	uint_8 dat = 0;
	uint_8 temp = 0;

	for(i=0;i<8;i++)	//�ȶ���λ�ٶ���λ
	{
		temp = DS18B20_Read_Bit();
		dat = (temp<<7) | (dat>>1);
	}
	return dat;	
}

/*
	�������� DS18B20_Write_Byte
	���ܣ�	 дһ���ֽڵ�DS18B20
*/
void DS18B20_Write_Byte(uint_8 dat)
{
	uint_8 i = 0;
	uint_8 temp = 0;

	for(i=0;i<8;i++)	//��д��λ��д��λ
	{
		temp = dat&0x01;	//ѡ���λ׼��д��
		dat >>= 1;			//���θ�λ�Ƶ���λ
		if(temp)
		{
			DS18B20_PORT = 0;
			_nop_();
			_nop_();
			DS18B20_PORT = 1;	
			Delay_10us(6);
		}
		else
		{
			DS18B20_PORT=0;
			Delay_10us(6);
			DS18B20_PORT=1;
			_nop_();
			_nop_();	
		}	
	}	
}

/*
	�������� DS18B20_Start
	���ܣ�	 ��ʼ�¶�ת��
*/
void DS18B20_Start(void)
{
	DS18B20_Reset();			//��λ
	DS18B20_Check();			//���DS18B20
	DS18B20_Write_Byte(0xcc);	//SKIP ROM
    DS18B20_Write_Byte(0x44);	//ת������	
}

/*
	�������� DS18B20_Init
	���ܣ�	 ��ʼ��DS18B20��IO��, ͬʱ���DS�Ĵ���
*/
uint_8 DS18B20_Init(void)
{
	DS18B20_Reset();
	return DS18B20_Check();	
}

/*
	�������� DS18B20_Read_Temperture
	���ܣ�	 ��DS18B20�õ��¶�ֵ
*/
float DS18B20_Read_Temperture(void)
{
	float temper = 0.0;
	uint_8 dath = 0; 	//�߰�λ
	uint_8 datl = 0;	//�Ͱ�λ
	uint_16 value = 0;

	DS18B20_Start();	//��ʼת��
	DS18B20_Reset();	//��λ
	DS18B20_Check();
	DS18B20_Write_Byte(0xcc);	//SKIP ROM
    DS18B20_Write_Byte(0xbe);	//���洢��

	datl = DS18B20_Read_Byte();	//���ֽ�
	dath = DS18B20_Read_Byte();	//���ֽ�
	value = (dath<<8) + datl;	//�ϲ�Ϊ16λ����

	if((value & 0xf800) == 0xf800)		//�жϷ���λ�����¶�
	{
		value = (~value)+1; 			//����ȡ���ټ�1
		temper = value*(-0.0625);		//���Ծ���	
	}
	else 		//���¶�
	{
		temper = value*0.0625;	
	}
	return temper;
}





