#include  "beep.h"

/*
	函数名：Beep_Show
	功能：	实现蜂鸣器鸣响
*/
void Beep_Show(uint_16 count)
{
	for(;count>0;count--)
	{
		BEEP = !BEEP;    //产生一定频率的脉冲信号
		Delay_10us(100);
	}
	count = 0;		//计数清零
	BEEP = 0;	    //关闭蜂鸣器
}