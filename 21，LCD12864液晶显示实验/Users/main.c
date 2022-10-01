/**************************************************************************************
实验名称：	LCD12864液晶显示实验
实验现象：	LCD12864上显示字符信息
实验单片机：普中A2			
注意事项：																		  
***************************************************************************************/

#include "public.h"
#include  "lcd12864.h"


int main(void)
{	
	LCD12864_Init();								//LCD12864初始化

	LCD12864_Show_String(0,0,"This is a test!");	//第1行字符串显示
	LCD12864_Show_String(0,1,"Made by LOlita");		//第2行字符串显示
	LCD12864_Show_String(0,2,"使用普中A2开发");		//第3行字符串显示
	LCD12864_Show_String(0,3,"字符数据显示成功");	//第4行字符串显示

	while(1)
	{
				
	}
}



