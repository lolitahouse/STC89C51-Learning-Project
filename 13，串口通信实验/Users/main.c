/**************************************************************************************
实验名称：	串口通信实验
实验现象：	串口助手发送数据给单片机，单片机原封不动转发给串口助手显示
实验单片机：普中A2			
注意事项：	使用黄色跳线帽将CH340旁的P5端子的UTX和P30短接，URX和P31短接，出厂默认已短接好																	  
***************************************************************************************/

#include "public.h"

/*
	函数名： uart_Init
	功能：	 串口通信中断配置函数，通过设置TH和TL即可确定定时时间
*/
void uart_Init(uint_8 baud)
{
	TMOD |= 0X20;		//设置计数器工作方式2
	SCON = 0X50;		//设置为工作方式1
	PCON = 0X80;		//波特率加倍
	TH1 = baud;			//计数器初始值设置
	TL1 = baud;
	ES = 1;				//打开接收中断
	EA = 1;				//打开总中断
	TR1 = 1;			//打开计数器		
}



int main(void)
{
	uart_Init(0XFA);	//波特率为9600
					
	while(1)
	{
		
	}
}


/*
	////串口通信中断函数	
*/
void uart() interrupt 4 
{
	uint_8 rec_data;

	RI = 0;				//清除接收中断标志位
	rec_data = SBUF;	//存储接收到的数据
	SBUF = rec_data;	//将接收到的数据放入到发送寄存器
	while(!TI);			//等待发送数据完成
	TI = 0;				//清除发送完成标志位						
}



