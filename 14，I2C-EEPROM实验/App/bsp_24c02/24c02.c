#include  "24c02.h"
#include  "iic.h"

/*
	�������� AT24C02_Write_One_Byte
	���ܣ�	 ��AT24C02ָ����ַд��һ������	
*/
void AT24C02_Write_One_Byte(uint_8 addr,uint_8 dat)
{				   	  	    																 
    IIC_Start();  
	IIC_Write_Byte(0XA0);	//����д����	    	  
	IIC_Wait_Ack();	   
    IIC_Write_Byte(addr);	//����д��ַ   
	IIC_Wait_Ack(); 	 										  		   
	IIC_Write_Byte(dat);	//�����ֽ�    							   
	IIC_Wait_Ack();  		    	   
    IIC_Stop();				//����һ��ֹͣ����
	Delay_ms(10);	 
}


/*
	�������� AT24C02_Read_One_Byte
	���ܣ�	 ��AT24C02ָ����ַ����һ������	
*/
uint_8 AT24C02_Read_One_Byte(uint_8 addr)
{				  
	uint_8 read_dat = 0;
			  	    																 
    IIC_Start();  
	IIC_Write_Byte(0XA0);	//����д����	   
	IIC_Wait_Ack(); 
    IIC_Write_Byte(addr); 	//����д��ַ  
	IIC_Wait_Ack();	   
	 
	IIC_Start();  	 	   
	IIC_Write_Byte(0XA1); 			//�������ģʽ         			   
	IIC_Wait_Ack();	 
    read_dat = IIC_Read_Byte(0);	//��ȡ�ֽ�		   
    IIC_Stop();						//����һ��ֹͣ���� 
	   
	return read_dat;			//���ض�ȡ������
}











