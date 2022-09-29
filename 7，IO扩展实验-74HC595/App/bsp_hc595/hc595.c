#include  "hc595.h"


// LEDDZ的行显示数据
uint_8 gHC595_buf[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};



/*
	函数名：HC595_Write_Data
	功能：	向74HC595写入一个字节的数据
*/
void HC595_Write_Data(uint_8 dat)
{
	uint_8 i = 0;

	for(i=0;i<8;i++) 	//循环8次即可将一个字节写入寄存器中
	{
		SER = dat >>7;	//优先传输高位,故先将高位移到最低位
		dat <<= 1;		//将次高位移到高位
		SRCLK = 0;
		Delay_10us(1);
		SRCLK = 1;
		Delay_10us(1);	//移位寄存器时钟上升沿将端口数据送入寄存器中
	}
	RCLk = 0;
	Delay_10us(1);
	RCLk = 1;			//存储寄存器时钟上升沿将前面写入到寄存器的数据输出
}

void HC595_Display(void)
{
	static uint_8 i = 0;

	for(i=0;i<8;i++)
	{
		HC595_Write_Data(0x00);	//消除前面寄存器缓存数据
		HC595_Write_Data(gHC595_buf[i]);	//写入新的数据
		Delay_ms(500);			//延时500ms
	}
	for(i=6;i>0;i--)
	{
		HC595_Write_Data(0x00);	//消除前面寄存器缓存数据
		HC595_Write_Data(gHC595_buf[i]);	//写入新的数据
		Delay_ms(500);			//延时500ms	
	}
}








