#include  "lcd1602.h"



/*
	函数名：LCD1602_Write_Cmd
	功能：	LCD1602写命令函数
	注意：	默认使用8位数据口LCD1602
*/
void LCD1602_Write_Cmd(uint_8 cmd)
{
	LCD1602_RS = 0;				//选择命令
	LCD1602_RW = 0;				//选择写
	LCD1602_E = 0;
	LCD1602_DATAPORT = cmd;		//准备命令
	Delay_ms(1);
	LCD1602_E = 1;				//使能E上升沿写入
	Delay_ms(1);
	LCD1602_E = 0;				//使能E负跳变完成写入	
}

/*
	函数名：LCD1602_Write_Data
	功能：	LCD1602写命令函数
	注意：	默认使用8位数据口LCD1602
*/
void LCD1602_Write_Data(uint_8 dat) 
{
	LCD1602_RS = 1;				//选择数据
	LCD1602_RW = 0;				//选择写
	LCD1602_E = 0;
	LCD1602_DATAPORT = dat;		//准备数据
	Delay_ms(1);
	LCD1602_E = 1;				//使能E上升沿写入
	Delay_ms(1);
	LCD1602_E = 0;				//使能E负跳变完成写入		
}

/*
	函数名：LCD1602_Init
	功能：	LCD1602初始化
	注意：	默认使用8位数据口LCD1602
*/
void LCD1602_Init(void)
{
	LCD1602_Write_Cmd(0x38);		//数据总线8位，显示2行，5*7点阵/字符
	LCD1602_Write_Cmd(0x0c);		//显示功能开，无光标，光标闪烁
	LCD1602_Write_Cmd(0x06);		//写入新数据后光标右移，显示屏不移动
	LCD1602_Write_Cmd(0x01);		//清屏	
}

/*
	函数名：LCD1602_Clear
	功能：	LCD1602清屏
	注意：	默认使用8位数据口LCD1602
*/
void LCD1602_Clear(void)
{
	LCD1602_Write_Cmd(0x01);	
}

/*
	函数名：LCD1602_Show_String
	功能：	LCD1602显示字符
	注意：	x,y为显示坐标，x=0~15，y=0~1;
*/
void LCD1602_Show_String(uint_8 x,uint_8 y,uint_8 *str)
{
	uint_8 i = 0;

	if(y>1||x>15)
		return;			//行列参数不对则强制退出

	if(y < 1)			//第1行显示
	{	
		while(*str != '\0')		//字符串是以'\0'结尾，只要前面有内容就显示
		{
			if(i < 16-x)		//如果字符长度超过第一行显示范围，则在第二行继续显示
			{
				LCD1602_Write_Cmd(0x80+i+x);	//第一行显示地址设置	
			}
			else
			{
				LCD1602_Write_Cmd(0x40+0x80+i+x-16);	//第二行显示地址设置	
			}
			LCD1602_Write_Data(*str);		//显示内容
			str++;							//指针递增
			i++;	
		}	
	}
	else				//第2行显示
	{
		while(*str != '\0')
		{
			if(i < 16-x) 		//如果字符长度超过第二行显示范围，则在第一行继续显示
			{
				LCD1602_Write_Cmd(0x80+0x40+i+x);	
			}
			else
			{
				LCD1602_Write_Cmd(0x80+i+x-16);	
			}
			LCD1602_Write_Data(*str);
			str++;
			i++;	
		}	
	}				
}









