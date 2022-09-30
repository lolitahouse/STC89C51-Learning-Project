#ifndef __DS18B20_H
#define __DS18B20_H

#include  "public.h"

//����DS18B20���ݿ�
sbit DS18B20_PORT = P3^7;

//��������
uint_8 DS18B20_Check(void);
uint_8 DS18B20_Init(void);
uint_8 DS18B20_Read_Bit(void);
uint_8 DS18B20_Read_Byte(void);
float DS18B20_Read_Temperture(void);
void DS18B20_Reset(void);
void DS18B20_Start(void);
void DS18B20_Write_Byte(uint_8 dat);


#endif /*__DS18B20_H*/