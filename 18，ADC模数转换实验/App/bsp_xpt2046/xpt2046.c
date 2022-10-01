#include  "xpt2046.h"
#include "intrins.h"
#include  "smg.h"


/*
	�������� XPT2046_Wirte_Data
	���ܣ�	 XPT2046д����
*/
void XPT2046_Wirte_Data(uint_8 dat)
{
	uint_8 i = 0;

	CLK = 0;
	_nop_();
	for(i=0;i<8;i++)		//����һ���ֽ�
	{
		DIN = dat >> 7;		//�ȴ���λ�ٴ���λ
		dat <<= 1;			//����λ�Ƶ���λ
		CLK = 1;			//CLK�ɵ͵��߲��������أ��Ӷ�д������
		_nop_();	
		CLK = 0;
		_nop_();
	}
}


/*
	�������� XPT2046_Read_Data
	���ܣ�	 XPT2046������
*/
uint_16	XPT2046_Read_Data(void)
{
	uint_8 i = 0;
	uint_16 dat = 0;

	CLK = 0;
	_nop_();
	for(i=0;i<12;i++)	//����һ���ֽ��������Է���ֵ������uint_16
	{
		dat <<= 1;
		CLK = 1;
		_nop_();
		CLK = 0; 		//CLK�ɸߵ��Ͳ���һ���½��أ��Ӷ���ȡ����
		_nop_();
		dat |= DOUT;	//����������ݣ��ȶ���λ�ٶ���λ	
	}
	return dat;	
}

/*
	�������� XPT2046_Read_ADC_Value
	���ܣ�	 XPT2046��AD����
*/
uint_16 XPT2046_Read_ADC_Value(uint_8 cmd)
{
	uint_8 i = 0;
	uint_16 adc_value = 0;

	CLK = 0;					//������ʱ��
	CS  = 0;					//ʹ��XPT2046
	XPT2046_Wirte_Data(cmd);	//����������
	for(i=6; i>0; i--);			//��ʱ�ȴ�ת�����
	CLK = 0;
	_nop_();
	CLK = 1;					//����һ��ʱ�ӣ����BUSY
	_nop_();
	adc_value = XPT2046_Read_Data();
	CS = 1;						//�ر�XPT2046
	return adc_value;
}

/*
	��������Electricity_Measure
	���ܣ�	������λ����ѹ
*/
void Electricity_Measure(void)
{
	static uint_16 adc_value = 0;
	static float adc_vol = 0.0;			//ADC��ѹֵ
	static uint_8 adc_buf[3] = 0;
				
	adc_value = XPT2046_Read_ADC_Value(0x94);		//������λ��
	adc_vol = 5.0*adc_value/4096;					//����ȡ��ADֵת��Ϊ��ѹ
	adc_value = adc_vol*10;						//�Ŵ�10����������С�����һλ
	adc_buf[0] = gSmg_init_code[adc_value/10]|0x80;
	adc_buf[1] = gSmg_init_code[adc_value%10];
	adc_buf[2] = 0x3e;							//��ʾ��λV

	Smg_Display(adc_buf,SHOW_POSITION);		
}


/*
	��������Light_Measure
	���ܣ�	������������
*/
void Light_Measure(void)
{	
	static uint_16 adc_value = 0;
	static uint_8 adc_buf[4] = 0;

	while(1)
	{				
		adc_value = XPT2046_Read_ADC_Value(0xA4);		//������������
		adc_buf[0] = gSmg_init_code[adc_value/1000];
		adc_buf[1] = gSmg_init_code[adc_value%1000/100];
		adc_buf[2] = gSmg_init_code[adc_value%1000%100/10];
		adc_buf[3] = gSmg_init_code[adc_value%1000%100%10];

		Smg_Display(adc_buf,5);		
	}		
}

/*
	��������Light_Measure
	���ܣ�	������������
*/
void Heat_Measure(void)
{	
	static uint_16 adc_value = 0;
	static uint_8 adc_buf[4] = 0;

	while(1)
	{				
		adc_value = XPT2046_Read_ADC_Value(0xD4);			//������������
		adc_buf[0] = gSmg_init_code[adc_value/1000];
		adc_buf[1] = gSmg_init_code[adc_value%1000/100];
		adc_buf[2] = gSmg_init_code[adc_value%1000%100/10];
		adc_buf[3] = gSmg_init_code[adc_value%1000%100%10];

		Smg_Display(adc_buf,5);		
	}		
}
	 

/*
	��������Voltage_Collect
	���ܣ�	�ⲿͨ����ѹ�ɼ�
*/
void Voltage_Collect(void)
{	
	static uint_16 adc_value = 0;
	static float adc_vol = 0.0;			//ADC��ѹֵ
	static uint_8 adc_buf[3] = 0;

	while(1)
	{				
		adc_value = XPT2046_Read_ADC_Value(0xE4);		//�����ⲿ����ͨ��AIN3
		adc_vol = 5.0*adc_value/4096;					//����ȡ��ADֵת��Ϊ��ѹ
		adc_value = adc_vol*10;							//�Ŵ�10����������С�����һλ
		adc_buf[0] = gSmg_init_code[adc_value/10]|0x80;
		adc_buf[1] = gSmg_init_code[adc_value%10];
		adc_buf[2] = 0x3e;							//��ʾ��λV

		Smg_Display(adc_buf,SHOW_POSITION);		
	}		
}


