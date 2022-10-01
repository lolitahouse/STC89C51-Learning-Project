#include  "xpt2046.h"
#include "intrins.h"
#include  "smg.h"


/*
	函数名： XPT2046_Wirte_Data
	功能：	 XPT2046写数据
*/
void XPT2046_Wirte_Data(uint_8 dat)
{
	uint_8 i = 0;

	CLK = 0;
	_nop_();
	for(i=0;i<8;i++)		//传输一个字节
	{
		DIN = dat >> 7;		//先传高位再传低位
		dat <<= 1;			//将低位移到高位
		CLK = 1;			//CLK由低到高产生上升沿，从而写入数据
		_nop_();	
		CLK = 0;
		_nop_();
	}
}


/*
	函数名： XPT2046_Read_Data
	功能：	 XPT2046读数据
*/
uint_16	XPT2046_Read_Data(void)
{
	uint_8 i = 0;
	uint_16 dat = 0;

	CLK = 0;
	_nop_();
	for(i=0;i<12;i++)	//大于一个字节数，所以返回值类型是uint_16
	{
		dat <<= 1;
		CLK = 1;
		_nop_();
		CLK = 0; 		//CLK由高到低产生一个下降沿，从而读取数据
		_nop_();
		dat |= DOUT;	//读输出的数据，先读高位再读低位	
	}
	return dat;	
}

/*
	函数名： XPT2046_Read_ADC_Value
	功能：	 XPT2046读AD数据
*/
uint_16 XPT2046_Read_ADC_Value(uint_8 cmd)
{
	uint_8 i = 0;
	uint_16 adc_value = 0;

	CLK = 0;					//先拉低时钟
	CS  = 0;					//使能XPT2046
	XPT2046_Wirte_Data(cmd);	//发送命令字
	for(i=6; i>0; i--);			//延时等待转换结果
	CLK = 0;
	_nop_();
	CLK = 1;					//发送一个时钟，清除BUSY
	_nop_();
	adc_value = XPT2046_Read_Data();
	CS = 1;						//关闭XPT2046
	return adc_value;
}

/*
	函数名：Electricity_Measure
	功能：	测量电位器电压
*/
void Electricity_Measure(void)
{
	static uint_16 adc_value = 0;
	static float adc_vol = 0.0;			//ADC电压值
	static uint_8 adc_buf[3] = 0;
				
	adc_value = XPT2046_Read_ADC_Value(0x94);		//测量电位器
	adc_vol = 5.0*adc_value/4096;					//将读取的AD值转换为电压
	adc_value = adc_vol*10;						//放大10倍，即保留小数点后一位
	adc_buf[0] = gSmg_init_code[adc_value/10]|0x80;
	adc_buf[1] = gSmg_init_code[adc_value%10];
	adc_buf[2] = 0x3e;							//显示单位V

	Smg_Display(adc_buf,SHOW_POSITION);		
}


/*
	函数名：Light_Measure
	功能：	测量光敏电阻
*/
void Light_Measure(void)
{	
	static uint_16 adc_value = 0;
	static uint_8 adc_buf[4] = 0;

	while(1)
	{				
		adc_value = XPT2046_Read_ADC_Value(0xA4);		//测量光敏电阻
		adc_buf[0] = gSmg_init_code[adc_value/1000];
		adc_buf[1] = gSmg_init_code[adc_value%1000/100];
		adc_buf[2] = gSmg_init_code[adc_value%1000%100/10];
		adc_buf[3] = gSmg_init_code[adc_value%1000%100%10];

		Smg_Display(adc_buf,5);		
	}		
}

/*
	函数名：Light_Measure
	功能：	测量热敏电阻
*/
void Heat_Measure(void)
{	
	static uint_16 adc_value = 0;
	static uint_8 adc_buf[4] = 0;

	while(1)
	{				
		adc_value = XPT2046_Read_ADC_Value(0xD4);			//测量热敏电阻
		adc_buf[0] = gSmg_init_code[adc_value/1000];
		adc_buf[1] = gSmg_init_code[adc_value%1000/100];
		adc_buf[2] = gSmg_init_code[adc_value%1000%100/10];
		adc_buf[3] = gSmg_init_code[adc_value%1000%100%10];

		Smg_Display(adc_buf,5);		
	}		
}
	 

/*
	函数名：Voltage_Collect
	功能：	外部通道电压采集
*/
void Voltage_Collect(void)
{	
	static uint_16 adc_value = 0;
	static float adc_vol = 0.0;			//ADC电压值
	static uint_8 adc_buf[3] = 0;

	while(1)
	{				
		adc_value = XPT2046_Read_ADC_Value(0xE4);		//测量外部输入通道AIN3
		adc_vol = 5.0*adc_value/4096;					//将读取的AD值转换为电压
		adc_value = adc_vol*10;							//放大10倍，即保留小数点后一位
		adc_buf[0] = gSmg_init_code[adc_value/10]|0x80;
		adc_buf[1] = gSmg_init_code[adc_value%10];
		adc_buf[2] = 0x3e;							//显示单位V

		Smg_Display(adc_buf,SHOW_POSITION);		
	}		
}


