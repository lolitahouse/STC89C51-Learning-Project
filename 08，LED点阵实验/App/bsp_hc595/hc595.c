#include  "hc595.h"


uint_8 gled_row[8] = {0x00,0x7C,0x82,0x82,0x82,0x7C,0x00,0x00};//LED点阵显示数字0的行数据
uint_8 gled_row_heart[8] = {0x38,0x7C,0x7E,0x3F,0x3F,0x7E,0x7C,0x38};//LED点阵显示心形的行数据
uint_8 gled_col[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};//LED点阵显示列数据



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


/*
	函数名：HC595_Display
	功能：	显示数字0 或 心形的图像
*/
void HC595_Display(void)
{
	static uint_8 i = 0;

	for(i=0;i<8;i++)//循环8次扫描8行、列
	{
		LEDDZ_COL_PORT = gled_col[i];	 //传送列选数据
		HC595_Write_Data(gled_row_heart[i]);   //传送行选数据
		Delay_10us(100);				 //延时一段时间，等待显示稳定
		HC595_Write_Data(0x00);		     //消影	
	}
}








