#include  "ds18b20.h"
#include "intrins.h"

/*
	函数名： DS18B20_Reset
	功能：	 复位DS18B20
*/
void DS18B20_Reset(void)
{
	DS18B20_PORT = 0;	//拉低DQ
	Delay_10us(75);	   //拉低750us
	DS18B20_PORT = 1;	//DQ=1
	Delay_10us(2);		//20uS
}

/*
	函数名： DS18B20_Check
	功能：	 检测DS18B20是否存在
	注意：	 返回1，表示不存在，0表示存在
*/
uint_8 DS18B20_Check(void)
{
	uint_8 time_temp = 0;

	while(DS18B20_PORT && time_temp < 20)	//等待DQ为低电平
	{
		time_temp++;
		Delay_10us(1);	
	}
	if(time_temp >= 20)
		return 1;			//如果超时则强制返回1
	else 
		time_temp = 0;
	while((!DS18B20_PORT) && time_temp < 20)	//等待DQ为高电平
	{
		time_temp++;
		Delay_10us(1);
	}
	if(time_temp >= 20)
		return 1;		//如果超时则强制返回1
	return 0;
}

/*
	函数名： DS18B20_Read_Bit
	功能：	 从DS18B20读取一个位
*/
uint_8 DS18B20_Read_Bit(void)
{
	uint_8 dat = 0;
	
	DS18B20_PORT = 0;
	_nop_();
	_nop_();
	DS18B20_PORT = 1;	
	_nop_();
	_nop_(); 			//该段时间不能过长，必须在15us内读取数据
	if(DS18B20_PORT)
		dat = 1;		//如果总线上为1则数据dat为1，否则为0
	else 
		dat = 0;
	Delay_10us(5);
	return dat;
}

/*
	函数名： DS18B20_Read_Byte
	功能：	 从DS18B20读取一个字节
*/
uint_8 DS18B20_Read_Byte(void)
{
	uint_8 i = 0;
	uint_8 dat = 0;
	uint_8 temp = 0;

	for(i=0;i<8;i++)	//先读低位再读高位
	{
		temp = DS18B20_Read_Bit();
		dat = (temp<<7) | (dat>>1);
	}
	return dat;	
}

/*
	函数名： DS18B20_Write_Byte
	功能：	 写一个字节到DS18B20
*/
void DS18B20_Write_Byte(uint_8 dat)
{
	uint_8 i = 0;
	uint_8 temp = 0;

	for(i=0;i<8;i++)	//先写低位再写高位
	{
		temp = dat&0x01;	//选择低位准备写入
		dat >>= 1;			//将次高位移到低位
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
	函数名： DS18B20_Start
	功能：	 开始温度转换
*/
void DS18B20_Start(void)
{
	DS18B20_Reset();			//复位
	DS18B20_Check();			//检查DS18B20
	DS18B20_Write_Byte(0xcc);	//SKIP ROM
    DS18B20_Write_Byte(0x44);	//转换命令	
}

/*
	函数名： DS18B20_Init
	功能：	 初始化DS18B20的IO口, 同时检测DS的存在
*/
uint_8 DS18B20_Init(void)
{
	DS18B20_Reset();
	return DS18B20_Check();	
}

/*
	函数名： DS18B20_Read_Temperture
	功能：	 从DS18B20得到温度值
*/
float DS18B20_Read_Temperture(void)
{
	float temper = 0.0;
	uint_8 dath = 0; 	//高八位
	uint_8 datl = 0;	//低八位
	uint_16 value = 0;

	DS18B20_Start();	//开始转换
	DS18B20_Reset();	//复位
	DS18B20_Check();
	DS18B20_Write_Byte(0xcc);	//SKIP ROM
    DS18B20_Write_Byte(0xbe);	//读存储器

	datl = DS18B20_Read_Byte();	//低字节
	dath = DS18B20_Read_Byte();	//高字节
	value = (dath<<8) + datl;	//合并为16位数据

	if((value & 0xf800) == 0xf800)		//判断符号位，负温度
	{
		value = (~value)+1; 			//数据取反再加1
		temper = value*(-0.0625);		//乘以精度	
	}
	else 		//正温度
	{
		temper = value*0.0625;	
	}
	return temper;
}





