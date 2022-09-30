#ifndef __IIC_H
#define __IIC_H

#include  "public.h"

//定义EEPROM控制脚
sbit IIC_SCL = P2^1;//SCL时钟线
sbit IIC_SDA = P2^0;//SDA数据线


//函数声明
void IIC_Ack(void);
void IIC_Nack(void);
uint_8 IIC_Read_Byte(uint_8 ack);
void IIC_Start(void);
void IIC_Stop(void);
uint_8 IIC_Wait_Ack(void);
void IIC_Write_Byte(uint_8 dat);


#endif /*__IIC_H*/