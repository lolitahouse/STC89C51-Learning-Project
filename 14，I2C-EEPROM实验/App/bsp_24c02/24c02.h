#ifndef __24C02_H
#define __24C02_H

#include  "public.h"

//�������ݴ���EEPROM����ʼ��ַ
#define EEPROM_ADDRESS	0	

//��������
uint_8 AT24C02_Read_One_Byte(uint_8 addr);
void AT24C02_Write_One_Byte(uint_8 addr,uint_8 dat);

#endif /*__24C02_H*/