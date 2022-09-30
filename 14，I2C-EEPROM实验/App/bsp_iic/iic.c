#include  "iic.h"

/*
	函数名： IIC_Start
	功能：	 产生IIC起始信号
*/
void IIC_Start(void)
{
	IIC_SCL = 1;
	IIC_SDA = 1;
	Delay_10us(1);
	IIC_SDA = 0;	//当SCL为高电平时，SDA由高变为低
	Delay_10us(1);
	IIC_SCL = 0;	//钳住I2C总线，准备发送或接收数据
}


/*
	函数名： IIC_Stop
	功能：	 产生IIC停止信号	
*/
void IIC_Stop(void)
{
	IIC_SCL = 1;
	IIC_SDA = 0;
	Delay_10us(1);
	IIC_SDA = 1;	//当SCL为高电平时，SDA由低变为高
	Delay_10us(1);			
}

/*
	函数名： IIC_Ack
	功能：	 产生ACK应答信号
*/
void IIC_Ack(void)
{
	IIC_SCL = 0;
	IIC_SDA = 0;	//SDA为低电平
	Delay_10us(1);
   	IIC_SCL = 1;
	Delay_10us(1);
	IIC_SCL = 0;
}

/*
	函数名： IIC_Nack
	功能：	 产生NACK非应答信号
*/
void IIC_Nack(void)
{
	IIC_SCL = 0;
	IIC_SDA = 1;	//SDA为高电平
	Delay_10us(1);
   	IIC_SCL = 1;
	Delay_10us(1);
	IIC_SCL = 0;	
}

/*
	函数名： IIC_Wait_Ack
	功能：	 等待应答信号到来
	注意：	 返回1，则接收应答失败；返回0，则接收应答成功
*/
uint_8 IIC_Wait_Ack(void)
{
	uint_8 time_temp = 0;
	
	IIC_SCL = 1;
	Delay_10us(1);
	while(IIC_SDA)	//等待SDA为低电平
	{
		time_temp++;
		if(time_temp > 100)	
		{	
			IIC_Stop();	 	//超时则强制结束IIC通信
			return 1;	
		}			
	}
	IIC_SCL = 0;
	return 0;	
}

/*
	函数名： IIC_Nack
	功能：	 IIC发送一个字节
*/
void IIC_Write_Byte(uint_8 dat)
{                        
    uint_8 i = 0; 
	   	    
    IIC_SCL = 0;
    for(i=0;i<8;i++)	//循环8次将一个字节传出，先传高再传低位
    {              
        if( (dat&0x80) > 0) 
			IIC_SDA = 1;
		else
			IIC_SDA = 0;
        dat <<= 1; 	  
		Delay_10us(1);  
		IIC_SCL = 1;
		Delay_10us(1); 
		IIC_SCL = 0;	
		Delay_10us(1);
    }	 
}

/*
	函数名： IIC_Nack
	功能：	 IIC读一个字节
	注意：	 ack=1时，发送ACK，ack=0，发送nACK
*/
uint_8 IIC_Read_Byte(uint_8 ack)
{
	uint_8 i = 0,rec_dat = 0;

    for(i=0;i<8;i++)	//循环8次将一个字节读出，先读高再读低位
	{
        IIC_SCL = 0; 
        Delay_10us(1);
		IIC_SCL = 1;
        rec_dat <<= 1;
        if(IIC_SDA)	
			rec_dat++;   
		Delay_10us(1); 
    }					 
    if (!ack)
        IIC_Nack();
    else
        IIC_Ack();  
		  
    return rec_dat;
}
















