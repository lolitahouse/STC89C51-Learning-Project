/**************************************************************************************
ʵ�����ƣ�	I2C-EEPROMʵ��
ʵ������	�������4λ��ʾ0����K1��������д�뵽EEPROM�ڱ��棬
		  	��K2����ȡEEPROM�ڱ�������ݣ���K3����ʾ���ݼ�1����K4����ʾ�������㣬
		  	�����д���������255��
ʵ�鵥Ƭ��������A2			
ע�����																		  
***************************************************************************************/

#include "public.h"
#include  "24c02.h"
#include  "key.h"
#include  "smg.h"



int main(void)
{
	uint_8 key_value = 0;
   	uint_8 save_value = 0;
	uint_8 save_buf[3];
					
	while(1)
	{
		key_value = Key_Scan(KEY_SCAN_MODE);  	//����ɨ��
		if(key_value == KEY1_PRESS)
		{
			AT24C02_Write_One_Byte(EEPROM_ADDRESS,save_value);	 //key1,д��
		}
		else if(key_value == KEY2_PRESS)
		{
			save_value = AT24C02_Read_One_Byte(EEPROM_ADDRESS);	 //key2����ȡ
		}
		else if(key_value == KEY3_PRESS)
		{
			save_value++;								//key3����1
			if(save_value == 255)
				save_value = 255;
		}
		else if(key_value == KEY4_PRESS)
		{
			save_value = 0;							 	//key4������
		}
		save_buf[0]=save_value/100;
		save_buf[1]=save_value%100/10;
		save_buf[2]=save_value%100%10;
		Smg_Display(save_buf,SHOW_POSITION);	     //�������ʾ
	}
}




