#include  "lcd1602.h"



/*
	��������LCD1602_Write_Cmd
	���ܣ�	LCD1602д�����
	ע�⣺	Ĭ��ʹ��8λ���ݿ�LCD1602
*/
void LCD1602_Write_Cmd(uint_8 cmd)
{
	LCD1602_RS = 0;				//ѡ������
	LCD1602_RW = 0;				//ѡ��д
	LCD1602_E = 0;
	LCD1602_DATAPORT = cmd;		//׼������
	Delay_ms(1);
	LCD1602_E = 1;				//ʹ��E������д��
	Delay_ms(1);
	LCD1602_E = 0;				//ʹ��E���������д��	
}

/*
	��������LCD1602_Write_Data
	���ܣ�	LCD1602д�����
	ע�⣺	Ĭ��ʹ��8λ���ݿ�LCD1602
*/
void LCD1602_Write_Data(uint_8 dat) 
{
	LCD1602_RS = 1;				//ѡ������
	LCD1602_RW = 0;				//ѡ��д
	LCD1602_E = 0;
	LCD1602_DATAPORT = dat;		//׼������
	Delay_ms(1);
	LCD1602_E = 1;				//ʹ��E������д��
	Delay_ms(1);
	LCD1602_E = 0;				//ʹ��E���������д��		
}

/*
	��������LCD1602_Init
	���ܣ�	LCD1602��ʼ��
	ע�⣺	Ĭ��ʹ��8λ���ݿ�LCD1602
*/
void LCD1602_Init(void)
{
	LCD1602_Write_Cmd(0x38);		//��������8λ����ʾ2�У�5*7����/�ַ�
	LCD1602_Write_Cmd(0x0c);		//��ʾ���ܿ����޹�꣬�����˸
	LCD1602_Write_Cmd(0x06);		//д�������ݺ������ƣ���ʾ�����ƶ�
	LCD1602_Write_Cmd(0x01);		//����	
}

/*
	��������LCD1602_Clear
	���ܣ�	LCD1602����
	ע�⣺	Ĭ��ʹ��8λ���ݿ�LCD1602
*/
void LCD1602_Clear(void)
{
	LCD1602_Write_Cmd(0x01);	
}

/*
	��������LCD1602_Show_String
	���ܣ�	LCD1602��ʾ�ַ�
	ע�⣺	x,yΪ��ʾ���꣬x=0~15��y=0~1;
*/
void LCD1602_Show_String(uint_8 x,uint_8 y,uint_8 *str)
{
	uint_8 i = 0;

	if(y>1||x>15)
		return;			//���в���������ǿ���˳�

	if(y < 1)			//��1����ʾ
	{	
		while(*str != '\0')		//�ַ�������'\0'��β��ֻҪǰ�������ݾ���ʾ
		{
			if(i < 16-x)		//����ַ����ȳ�����һ����ʾ��Χ�����ڵڶ��м�����ʾ
			{
				LCD1602_Write_Cmd(0x80+i+x);	//��һ����ʾ��ַ����	
			}
			else
			{
				LCD1602_Write_Cmd(0x40+0x80+i+x-16);	//�ڶ�����ʾ��ַ����	
			}
			LCD1602_Write_Data(*str);		//��ʾ����
			str++;							//ָ�����
			i++;	
		}	
	}
	else				//��2����ʾ
	{
		while(*str != '\0')
		{
			if(i < 16-x) 		//����ַ����ȳ����ڶ�����ʾ��Χ�����ڵ�һ�м�����ʾ
			{
				LCD1602_Write_Cmd(0x80+0x40+i+x);	
			}
			else
			{
				LCD1602_Write_Cmd(0x80+i+x-16);	
			}
			LCD1602_Write_Data(*str);
			str++;
			i++;	
		}	
	}				
}









