#include  "ds1302.h"
#include "intrins.h"

//---DS1302写入和读取时分秒的地址命令---//
//---秒分时日月周年 最低位读写位;-------//
uint_8 gREAD_RTC_ADDR[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d}; 
uint_8 gWRITE_RTC_ADDR[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};

//---DS1302时钟初始化2022年9月30日星期五21点11分30秒。---//
//---存储顺序是秒分时日月周年,存储格式是用BCD码---//
uint_8 gDS1302_TIME[7] = {0x30, 0x11, 0x21, 0x30, 0x09, 0x05, 0x22};

/*
	函数名：DS1302_Write_Byte
	功能：	DS1302写单字节函数
*/
void DS1302_Write_Byte(uint_8 addr,uint_8 dat)
{
	uint_8 i = 0;
	
	DS1302_RST = 0;
	_nop_();	
	DS1302_CLK = 0;			//CLK低电平
	_nop_();
	DS1302_RST = 1;			//RST由低到高变化
	_nop_();

	for(i=0;i<8;i++)		//先写低位再写高位
	{
		DS1302_IO = addr & 0x01;
		addr >>= 1;
		DS1302_CLK = 1;		//CLK由低到高产生上升沿，从而写入数据
		_nop_();
		DS1302_CLK = 0;
		_nop_();		
	}
	for(i=0;i<8;i++)		//先写低位再写高位
	{
		DS1302_IO = dat & 0x01;
		dat >>= 1;
		DS1302_CLK = 1;
		_nop_();
		DS1302_CLK = 0;
		_nop_();		
	}
	DS1302_RST = 0;			//RST拉低
	_nop_();	
}

/*
	函数名：DS1302_Read_Byte
	功能：	DS1302读单字节函数
*/
uint_8 DS1302_Read_Byte(uint_8 addr)
{
	uint_8 i = 0;
	uint_8 temp = 0;
	uint_8 value = 0;

	DS1302_RST = 0;
	_nop_();	
	DS1302_CLK = 0;			//CLK低电平
	_nop_();
	DS1302_RST = 1;			//RST由低到高变化
	_nop_();
	
	for(i=0;i<8;i++)		//先读低位再读高位
	{
		DS1302_IO = addr & 0x01;
		addr >>= 1;	
		DS1302_CLK = 1;		 //CLK由低到高产生上升沿，从而写入数据
		_nop_();
		DS1302_CLK = 0;
		_nop_();		
	}
	for(i=0;i<8;i++)		//先读低位再读高位
	{
		temp = DS1302_IO;
		value = (temp<<7)|(value>>1);	//先将value右移1位，然后temp左移7位，最后或运算
		DS1302_CLK = 1;
		_nop_();
		DS1302_CLK = 0;
		_nop_();		
	}
	DS1302_RST = 0;			//RST拉低
	_nop_();	
	DS1302_CLK = 1;		//对于P3.4口没有外接上拉电阻的，需添加此代码，使数据口有上升沿脉冲
	_nop_();
	DS1302_IO = 0;
	_nop_();
	DS1302_IO = 1;
	_nop_();	
	return value;		
}

/*
	函数名：DS1302_Init
	功能：	DS1302初始化时间函数
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
	函数名：DS1302_Read_Time
	功能：	DS1302读取时间函数
*/
void DS1302_Read_Time(void)
{
	uint_8 i = 0;
	for(i=0;i<7;i++)
	{
		gDS1302_TIME[i] = DS1302_Read_Byte(gREAD_RTC_ADDR[i]);	
	}	
}










