// @file    bsp_pwm.c
// @brief   风扇 PWM 输出：定时器1 中断按影子状态生成占空比
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "type_def.h"
#include "config.h"
#include "app_cfg.h"
#include "bsp_pwm.h"

sbit PWM = P3^4; // 风扇驱动引脚

static uchar pwm_mode = 1; // 占空比档位 1~3，由 PWM_Control 更新
static bit pwm_run = 0;    // 输出使能：1 按档位输出，0 停转

// @brief  初始化定时器1为 20us 中断时基，驱动风扇 PWM 占空比生成
void Timer1Init(void)
{
	AUXR |= 0x40; // 定时器1时钟选择 1T 模式
	TMOD &= 0x0F; // 定时器1为模式0（16位自动重装）
	TL1 = T20US_RELOAD_L;
	TH1 = T20US_RELOAD_H;
	TF1 = 0; // 清除溢出标志
	TR1 = 1; // 启动定时器1
	ET1 = 1; // 允许定时器1中断
}

// @brief  推送 PWM 控制状态：先更新档位再更新使能，避免过渡态错档
void PWM_Control(uchar mode, bit enable)
{
	pwm_mode = mode;
	pwm_run = enable;
}

// @brief  定时器1中断：每 20us 推进周期计数，按当前档位输出占空比；
//         输出关闭时保持低电平并复位周期计数
void Timer1_ISR() interrupt 3
{
	static uint k = 0; // PWM 周期计数器，0~APP_PWM_PERIOD 循环
	if(pwm_run)
	{
		k++;
		if(pwm_mode == 1)
		{
			if(k < APP_PWM_DUTY_MODE1)
			{
				PWM = 1;
			}
			else if(k < APP_PWM_PERIOD)
			{
				PWM = 0;
			}
			else
			{
				k = 0;
				PWM = 1;
			}
		}
		else if(pwm_mode == 2)
		{
			if(k < APP_PWM_DUTY_MODE2)
			{
				PWM = 1;
			}
			else if(k < APP_PWM_PERIOD)
			{
				PWM = 0;
			}
			else
			{
				k = 0;
				PWM = 1;
			}
		}
		else
		{
			if(k < APP_PWM_DUTY_MODE3)
			{
				PWM = 1;
			}
			else if(k < APP_PWM_PERIOD)
			{
				PWM = 0;
			}
			else
			{
				k = 0;
				PWM = 1;
			}
		}
	}
	else
	{
		k = 0;
		PWM = 0;
	}
}
