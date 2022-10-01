#include  "lcd12864.h"



/*
	��������LCD12864_Write_Cmd
	���ܣ�	LCD12864д�����
	ע�⣺
*/
void LCD12864_Write_Cmd(uint_8 cmd)
{
	LCD12864_RS = 0;			//ѡ������
	LCD12864_WR = 0;			//ѡ��д
	LCD12864_E = 0;
	LCD12864_DATAPORT = cmd;	//׼������
	Delay_ms(1);
	LCD12864_E = 1;				//ʹ��E������д��
	Delay_ms(1);
	LCD12864_E = 0;				//ʹ��E���������д��
}

/*
	��������LCD12864_Write_Data
	���ܣ�	LCD12864д���ݺ���
	ע�⣺
*/
void LCD12864_Write_Data(uint_8 dat)
{
	LCD12864_RS = 1;			//ѡ������
	LCD12864_WR = 0;			//ѡ��д
	LCD12864_E = 0;
	LCD12864_DATAPORT = dat;	//׼������
	Delay_ms(1);
	LCD12864_E = 1;				//ʹ��E������д��
	Delay_ms(1);
	LCD12864_E = 0;				//ʹ��E���������д��
}

/*
	��������LCD12864_Init
	���ܣ�	LCD12864��ʼ������
	ע�⣺
*/
void LCD12864_Init(void)
{
	LCD12864_PSB = 1;			//ѡ��8λ��4λ���ڷ�ʽ
	LCD12864_Write_Cmd(0x30);	//��������8λ������ָ�����
	LCD12864_Write_Cmd(0x0c);	//������ʾ�أ��α���ʾ�أ��α�������ʾ
	LCD12864_Write_Cmd(0x06);	//д�������ݺ������ƣ���ʾ�����ƶ�
	LCD12864_Write_Cmd(0x01);	//����	
}

/*
	��������LCD12864_Clear
	���ܣ�	LCD12864��������
	ע�⣺
*/
void LCD12864_Clear(void)
{
	LCD12864_Write_Cmd(0x01);	
}

/*
	��������LCD12864_Show_String
	���ܣ�	LCD12864��ʾ�ַ�������
	ע�⣺	x,yΪ��ʾ���꣬x=0~7��y=0~3;
*/
void LCD12864_Show_String(uint_8 x,uint_8 y,uint_8 *str)
{
	if(y <= 0)
		y = 0;
	if(y > 3)
		y=3;
	x &= 0x0f;			//����x,y���ܴ�����ʾ��Χ

	switch(y)
	{
		case 0: x|=0x80; break;		//��1�е�ַ+x��ƫ��
		case 1: x|=0x90; break;		//��2�е�ַ+x��ƫ��
		case 2: x|=0x88; break;		//��3�е�ַ+x��ƫ��
		case 3: x|=0x98; break;		//��4�е�ַ+x��ƫ��
	}
	LCD12864_Write_Cmd(x);
	while(*str != '\0')
	{
		LCD12864_Write_Data(*str);
		str++;		
	}		
}









