#include  "key_matrix.h"


/*
	函数名：Key_Matrix_Ranks_Scan
	功能：	使用行列式扫描方法，检测矩阵按键是否按下，并返回对应键值
*/
uint_8 Key_Matrix_Ranks_Scan(void)
{
	uint_8 key_value=0;

	KEY_MATRIX_PORT = 0xf7; //第一列赋0
	if(KEY_MATRIX_PORT != 0xf7)
	{
		Delay_ms(10);	//消抖
		switch(KEY_MATRIX_PORT)//保存第一列按键按下后的键值	
		{
			case 0x77: key_value=1; break;
			case 0xb7: key_value=5; break;
			case 0xd7: key_value=9; break;
			case 0xe7: key_value=13; break;
		}
	}
	while(KEY_MATRIX_PORT != 0xf7);//等待按键松开	
	
	KEY_MATRIX_PORT=0xfb;	//第二列赋0
	if(KEY_MATRIX_PORT!=0xfb)//判断第二列按键是否按下
	{
		Delay_ms(10);	//消抖
		switch(KEY_MATRIX_PORT)//保存第二列按键按下后的键值	
		{
			case 0x7b: key_value=2;break;
			case 0xbb: key_value=6;break;
			case 0xdb: key_value=10;break;
			case 0xeb: key_value=14;break;
		}
	}
	while(KEY_MATRIX_PORT != 0xfb);//等待按键松开	
	
	KEY_MATRIX_PORT=0xfd;	//第三列赋0
	if(KEY_MATRIX_PORT!=0xfd)//判断第三列按键是否按下
	{
		Delay_ms(10);	//消抖
		switch(KEY_MATRIX_PORT)//保存第三列按键按下后的键值	
		{
			case 0x7d: key_value=3;break;
			case 0xbd: key_value=7;break;
			case 0xdd: key_value=11;break;
			case 0xed: key_value=15;break;
		}
	}
	while(KEY_MATRIX_PORT != 0xfd);//等待按键松开	
	
	KEY_MATRIX_PORT=0xfe;	//第四列赋0
	if(KEY_MATRIX_PORT!=0xfe)//判断第四列按键是否按下
	{
		Delay_ms(10);	//消抖
		switch(KEY_MATRIX_PORT)//保存第四列按键按下后的键值	
		{
			case 0x7e: key_value=4;break;
			case 0xbe: key_value=8;break;
			case 0xde: key_value=12;break;
			case 0xee: key_value=16;break;
		}
	}
	while(KEY_MATRIX_PORT != 0xfe);//等待按键松开
	
	return key_value;
}


/*
	函数名： Key_Matrix_Flip_Scan
	功能：	 使用线翻转法，检测矩阵按键是否按下，并返回对应键值
*/
uint_8 Key_Matrix_Flip_Scan(void)
{
	static uint_8 key_value = 0;

	KEY_MATRIX_PORT = 0x0f;		//给所有行赋
	if(KEY_MATRIX_PORT != 0x0f)//判断按键是否按下
	{
		Delay_ms(10);	//消抖
		if(KEY_MATRIX_PORT != 0x0f)
		{
			//测试列
			KEY_MATRIX_PORT = 0x0f;
			switch(KEY_MATRIX_PORT)//保存行为0，按键按下后的列值	
			{
				case 0x07: key_value=1; break;
				case 0x0b: key_value=2; break;
				case 0x0d: key_value=3; break;
				case 0x0e: key_value=4; break;
			}
			//测试行
			KEY_MATRIX_PORT = 0xf0;
			switch(KEY_MATRIX_PORT)//保存列为0，按键按下后的键值	
			{
				case 0x70: key_value=key_value; break;
				case 0xb0: key_value=key_value+4; break;
				case 0xd0: key_value=key_value+8; break;
				case 0xe0: key_value=key_value+12; break;
			}
			while(KEY_MATRIX_PORT != 0xf0);//等待按键松开	
		}
	}
	else
		key_value = 0;		
	
	return key_value;
}












