#include  "lcd12864.h"



/*
	函数名：LCD12864_Write_Cmd
	功能：	LCD12864写命令函数
	注意：
*/
void LCD12864_Write_Cmd(uint_8 cmd)
{
	LCD12864_RS = 0;			//选择命令
	LCD12864_WR = 0;			//选择写
	LCD12864_E = 0;
	LCD12864_DATAPORT = cmd;	//准备命令
	Delay_ms(1);
	LCD12864_E = 1;				//使能E上升沿写入
	Delay_ms(1);
	LCD12864_E = 0;				//使能E负跳变完成写入
}

/*
	函数名：LCD12864_Write_Data
	功能：	LCD12864写数据函数
	注意：
*/
void LCD12864_Write_Data(uint_8 dat)
{
	LCD12864_RS = 1;			//选择数据
	LCD12864_WR = 0;			//选择写
	LCD12864_E = 0;
	LCD12864_DATAPORT = dat;	//准备数据
	Delay_ms(1);
	LCD12864_E = 1;				//使能E上升沿写入
	Delay_ms(1);
	LCD12864_E = 0;				//使能E负跳变完成写入
}

/*
	函数名：LCD12864_Init
	功能：	LCD12864初始化函数
	注意：
*/
void LCD12864_Init(void)
{
	LCD12864_PSB = 1;			//选择8位或4位并口方式
	LCD12864_Write_Cmd(0x30);	//数据总线8位，基本指令操作
	LCD12864_Write_Cmd(0x0c);	//整体显示关，游标显示关，游标正常显示
	LCD12864_Write_Cmd(0x06);	//写入新数据后光标右移，显示屏不移动
	LCD12864_Write_Cmd(0x01);	//清屏	
}

/*
	函数名：LCD12864_Clear
	功能：	LCD12864清屏函数
	注意：
*/
void LCD12864_Clear(void)
{
	LCD12864_Write_Cmd(0x01);	
}

/*
	函数名：LCD12864_Show_String
	功能：	LCD12864显示字符串函数
	注意：	x,y为显示坐标，x=0~7，y=0~3;
*/
void LCD12864_Show_String(uint_8 x,uint_8 y,uint_8 *str)
{
	if(y <= 0)
		y = 0;
	if(y > 3)
		y=3;
	x &= 0x0f;			//限制x,y不能大于显示范围

	switch(y)
	{
		case 0: x|=0x80; break;		//第1行地址+x的偏移
		case 1: x|=0x90; break;		//第2行地址+x的偏移
		case 2: x|=0x88; break;		//第3行地址+x的偏移
		case 3: x|=0x98; break;		//第4行地址+x的偏移
	}
	LCD12864_Write_Cmd(x);
	while(*str != '\0')
	{
		LCD12864_Write_Data(*str);
		str++;		
	}		
}









