#include  "pwm.h"


//定义全局变量
uint_8 gtim_h = 0;		//保存定时器初值高8位
uint_8 gtim_l = 0;		//保存定时器初值低8位
uint_8 gduty = 0;		//保存PWM占空比
uint_8 gtim_scale = 0;	//保存PWM周期=定时器初值*tim_scale


/*
	函数名：PWM_Init
	功能：	PWM初始化函数
*/
void PWM_Init(uint_8 tim_h,uint_8 tim_l,uint_16 tim_scale,uint_8 duty)
{
	gtim_h = tim_h;			//将传入的初值保存在全局变量中，方便中断函数继续调用
	gtim_l = tim_l;
	gduty = duty;
	gtim_scale = tim_scale;

	TMOD|=0X01;				//选择为定时器0模式，工作方式1
	TH0 = gtim_h;			//定时初值设置 
	TL0 = gtim_l;		
	ET0 = 1;				//打开定时器0中断允许
	EA = 1;					//打开总中断
	TR0 = 1;				//打开定时器
}

/*
	函数名：PWM_Set_Duty_Cycle
	功能：	PWM设置占空比函数
*/
void PWM_Set_Duty_Cycle(uint_8 duty)
{
	gduty = duty;	
}


/*
	  定时器0中断函数
*/
void pwm(void) interrupt 1
{
	static uint_16 time = 0;

	TH0 = gtim_h;	//定时初值设置 
	TL0 = gtim_l;
	
	time++;
	if(time >= gtim_scale)		//PWM周期=定时器初值*gtim_scale，重新开始计数
		time = 0;
	if(time <= gduty)			//占空比	
		PWM = 1;
	else
		PWM = 0;		
}










