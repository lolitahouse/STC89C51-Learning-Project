#include  "24c02.h"
#include  "iic.h"

/*
	函数名： AT24C02_Write_One_Byte
	功能：	 在AT24C02指定地址写入一个数据	
*/
void AT24C02_Write_One_Byte(uint_8 addr,uint_8 dat)
{				   	  	    																 
    IIC_Start();  
	IIC_Write_Byte(0XA0);	//发送写命令	    	  
	IIC_Wait_Ack();	   
    IIC_Write_Byte(addr);	//发送写地址   
	IIC_Wait_Ack(); 	 										  		   
	IIC_Write_Byte(dat);	//发送字节    							   
	IIC_Wait_Ack();  		    	   
    IIC_Stop();				//产生一个停止命令
	Delay_ms(10);	 
}


/*
	函数名： AT24C02_Read_One_Byte
	功能：	 在AT24C02指定地址读出一个数据	
*/
uint_8 AT24C02_Read_One_Byte(uint_8 addr)
{				  
	uint_8 read_dat = 0;
			  	    																 
    IIC_Start();  
	IIC_Write_Byte(0XA0);	//发送写命令	   
	IIC_Wait_Ack(); 
    IIC_Write_Byte(addr); 	//发送写地址  
	IIC_Wait_Ack();	   
	 
	IIC_Start();  	 	   
	IIC_Write_Byte(0XA1); 			//进入接收模式         			   
	IIC_Wait_Ack();	 
    read_dat = IIC_Read_Byte(0);	//读取字节		   
    IIC_Stop();						//产生一个停止条件 
	   
	return read_dat;			//返回读取的数据
}











