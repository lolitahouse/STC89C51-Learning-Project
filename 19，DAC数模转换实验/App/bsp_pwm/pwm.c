#include  "pwm.h"


//����ȫ�ֱ���
uint_8 gtim_h = 0;		//���涨ʱ����ֵ��8λ
uint_8 gtim_l = 0;		//���涨ʱ����ֵ��8λ
uint_8 gduty = 0;		//����PWMռ�ձ�
uint_8 gtim_scale = 0;	//����PWM����=��ʱ����ֵ*tim_scale


/*
	��������PWM_Init
	���ܣ�	PWM��ʼ������
*/
void PWM_Init(uint_8 tim_h,uint_8 tim_l,uint_16 tim_scale,uint_8 duty)
{
	gtim_h = tim_h;			//������ĳ�ֵ������ȫ�ֱ����У������жϺ�����������
	gtim_l = tim_l;
	gduty = duty;
	gtim_scale = tim_scale;

	TMOD|=0X01;				//ѡ��Ϊ��ʱ��0ģʽ��������ʽ1
	TH0 = gtim_h;			//��ʱ��ֵ���� 
	TL0 = gtim_l;		
	ET0 = 1;				//�򿪶�ʱ��0�ж�����
	EA = 1;					//�����ж�
	TR0 = 1;				//�򿪶�ʱ��
}

/*
	��������PWM_Set_Duty_Cycle
	���ܣ�	PWM����ռ�ձȺ���
*/
void PWM_Set_Duty_Cycle(uint_8 duty)
{
	gduty = duty;	
}


/*
	  ��ʱ��0�жϺ���
*/
void pwm(void) interrupt 1
{
	static uint_16 time = 0;

	TH0 = gtim_h;	//��ʱ��ֵ���� 
	TL0 = gtim_l;
	
	time++;
	if(time >= gtim_scale)		//PWM����=��ʱ����ֵ*gtim_scale�����¿�ʼ����
		time = 0;
	if(time <= gduty)			//ռ�ձ�	
		PWM = 1;
	else
		PWM = 0;		
}










