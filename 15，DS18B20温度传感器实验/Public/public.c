#include  "public.h"

/*
	��������Delay_10us
	���ܣ�	������ʱ10us
*/
void Delay_10us(uint_16 time_us)
{
	while(time_us--);
}

/*
	��������Delay_ms
	���ܣ�	������ʱ1ms
*/
void Delay_ms(uint_16 time_ms)
{
	uint_16 i=0,j=0;
	for(i=time_ms;i>0;i--)
		for(j=110;j>0;j--);
}