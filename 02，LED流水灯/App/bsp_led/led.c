#include  "led.h"

/*
	函数名：Led_Show
	功能：	实现双向流水灯
*/
void Led_Show(void)
{
	uint_8 i=0;
	
   	//实现流水灯
	for(i=0;i<8;i++)
	{
		LED_PORT = ~(0x01<<i);
		Delay_ms(500);
	}
	for(i=0;i<6;i++)
	{
		LED_PORT = ~(0x40>>i);
		Delay_ms(500);
	}
}