#include  "led.h"

/*
	��������Led_Show
	���ܣ�	ʵ��˫����ˮ��
*/
void Led_Show(void)
{
	uint_8 i=0;
	
   	//ʵ����ˮ��
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