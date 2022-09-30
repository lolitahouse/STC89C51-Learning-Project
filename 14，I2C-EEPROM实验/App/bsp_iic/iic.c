#include  "iic.h"

/*
	�������� IIC_Start
	���ܣ�	 ����IIC��ʼ�ź�
*/
void IIC_Start(void)
{
	IIC_SCL = 1;
	IIC_SDA = 1;
	Delay_10us(1);
	IIC_SDA = 0;	//��SCLΪ�ߵ�ƽʱ��SDA�ɸ߱�Ϊ��
	Delay_10us(1);
	IIC_SCL = 0;	//ǯסI2C���ߣ�׼�����ͻ��������
}


/*
	�������� IIC_Stop
	���ܣ�	 ����IICֹͣ�ź�	
*/
void IIC_Stop(void)
{
	IIC_SCL = 1;
	IIC_SDA = 0;
	Delay_10us(1);
	IIC_SDA = 1;	//��SCLΪ�ߵ�ƽʱ��SDA�ɵͱ�Ϊ��
	Delay_10us(1);			
}

/*
	�������� IIC_Ack
	���ܣ�	 ����ACKӦ���ź�
*/
void IIC_Ack(void)
{
	IIC_SCL = 0;
	IIC_SDA = 0;	//SDAΪ�͵�ƽ
	Delay_10us(1);
   	IIC_SCL = 1;
	Delay_10us(1);
	IIC_SCL = 0;
}

/*
	�������� IIC_Nack
	���ܣ�	 ����NACK��Ӧ���ź�
*/
void IIC_Nack(void)
{
	IIC_SCL = 0;
	IIC_SDA = 1;	//SDAΪ�ߵ�ƽ
	Delay_10us(1);
   	IIC_SCL = 1;
	Delay_10us(1);
	IIC_SCL = 0;	
}

/*
	�������� IIC_Wait_Ack
	���ܣ�	 �ȴ�Ӧ���źŵ���
	ע�⣺	 ����1�������Ӧ��ʧ�ܣ�����0�������Ӧ��ɹ�
*/
uint_8 IIC_Wait_Ack(void)
{
	uint_8 time_temp = 0;
	
	IIC_SCL = 1;
	Delay_10us(1);
	while(IIC_SDA)	//�ȴ�SDAΪ�͵�ƽ
	{
		time_temp++;
		if(time_temp > 100)	
		{	
			IIC_Stop();	 	//��ʱ��ǿ�ƽ���IICͨ��
			return 1;	
		}			
	}
	IIC_SCL = 0;
	return 0;	
}

/*
	�������� IIC_Nack
	���ܣ�	 IIC����һ���ֽ�
*/
void IIC_Write_Byte(uint_8 dat)
{                        
    uint_8 i = 0; 
	   	    
    IIC_SCL = 0;
    for(i=0;i<8;i++)	//ѭ��8�ν�һ���ֽڴ������ȴ����ٴ���λ
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
	�������� IIC_Nack
	���ܣ�	 IIC��һ���ֽ�
	ע�⣺	 ack=1ʱ������ACK��ack=0������nACK
*/
uint_8 IIC_Read_Byte(uint_8 ack)
{
	uint_8 i = 0,rec_dat = 0;

    for(i=0;i<8;i++)	//ѭ��8�ν�һ���ֽڶ������ȶ����ٶ���λ
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
















