/**************************************************************************************
实验名称：	直流电机实验
实验现象：	直流电机旋转5S后停止
实验单片机：普中A2			
注意事项：	将直流电机两根线分别连接到“步进电机模块”输出端子J47的5V和O1上。																	  
***************************************************************************************/

#include "public.h"
#include  "dc_motor.h"

int main(void)
{
	DC_Motor_Run();				
	while(1)
	{
		
	}
}