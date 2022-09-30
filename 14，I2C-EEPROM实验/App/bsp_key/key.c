#include  "key.h"



/*
	函数名：Key_Scan
	功能：	检测独立按键是否按下，并返回对应键值
	说明：	mode=0,单次扫描；mode=1，连续扫描
*/
uint_8 Key_Scan(uint_8 mode)
{
	static uint_8 key = 1;
	
	if(mode)	//mode=1,连续扫描
	{
		key = 1;
	}	
		
	if(key==1 && (KEY1==0||KEY2==0||KEY3==0||KEY4==0))	//任意按键按下
	{
		Delay_ms(10);	//消抖
		key = 0;		//清零key值
		if(KEY1==0)
			return	KEY1_PRESS;
		else if(KEY2==0)
			return	KEY2_PRESS;
		else if(KEY3==0)
			return	KEY3_PRESS;
		else if(KEY4==0)
			return	KEY4_PRESS;
	}
	else if(KEY1==1 && KEY2==1 && KEY3==1 && KEY4==1)	//无按键按下
	{
		key = 1;
	}
	return KEY_UNPRESS;
}
