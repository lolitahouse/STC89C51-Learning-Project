#include  "public.h"

/*
	函数名：Delay_10us
	功能：	粗略延时10us
*/
void Delay_10us(uint_16 time_us)
{
	while(time_us--);
}

/*
	函数名：Delay_ms
	功能：	粗略延时1ms
*/
void Delay_ms(uint_16 time_ms)
{
	uint_16 i=0,j=0;
	for(i=time_ms;i>0;i--)
		for(j=110;j>0;j--);
}