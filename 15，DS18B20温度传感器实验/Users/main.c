/**************************************************************************************
ʵ�����ƣ�	DS18B20�¶ȴ�����ʵ��
ʵ������	����DS18B20�¶ȴ��������������ʾ�����¶�ֵ
ʵ�鵥Ƭ��������A2			
ע�����																		  
***************************************************************************************/

#include "public.h"
#include  "ds18b20.h"
#include  "smg.h"



int main(void)
{
	uint_8 i = 0;
   	int temper_value = 0;
	uint_8 temper_buf[5] = 0;

	DS18B20_Init();		//��ʼ��DS18B20

	while(1)
	{				
		i++;
		if(i%50 == 0)		//���һ��ʱ���ȡ�¶�ֵ�����ʱ��Ҫ�����¶ȴ�����ת���¶�ʱ��
			temper_value = DS18B20_Read_Temperture()*10;	//�����¶�ֵС����һλ
		if(temper_value < 0)	//���¶�
		{
			temper_value = -temper_value;
			temper_buf[0] = 0x40;	//��ʾ����	
		}
		else
			temper_buf[0] = 0x00;	//����ʾ����
		temper_buf[1] = gSmg_init_code[temper_value/1000];				//��λ
		temper_buf[2] = gSmg_init_code[temper_value%1000/100];			//ʮλ
		temper_buf[3] = gSmg_init_code[temper_value%1000%100/10]|0x80;	//��λ+С����
		temper_buf[4] = gSmg_init_code[temper_value%1000%100%10];			//С�����һλ
		Smg_Display(temper_buf,SHOW_POSITION);
	}
}




