// @file    hal_timer.c
// @brief   定时器0/2驱动：1ms 中断服务提供倒计时递减、任务触发标志与数码管刷新
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "type_def.h"
#include "config.h"
#include "app_cfg.h"
#include "app_tasks.h"
#include "bsp_digitron.h"
#include "display_mgr.h"
#include "hal_timer.h"

// @brief   初始化定时器0：1T 模式，16 位自动重装，1ms 溢出中断
void Timer0Init(void)
{
	AUXR |= 0x80;              // 定时器0时钟 1T 模式
	TMOD &= 0xF0;              // 定时器0工作于模式0（16 位自动重装）
	TL0 = T1MS_RELOAD_L;       // 1ms 定时重装值低字节
	TH0 = T1MS_RELOAD_H;       // 1ms 定时重装值高字节
	TF0 = 0;                   // 清除定时器0溢出标志
	TR0 = 1;                   // 启动定时器0
	ET0 = 1;                   // 允许定时器0中断
}

// @brief   初始化定时器2：1T 模式，16 位自动重装，1ms 溢出中断
void Timer2Init(void)
{
	AUXR |= 0x04;              // 定时器2时钟 1T 模式
	T2L = T1MS_RELOAD_L;       // 1ms 定时重装值低字节
	T2H = T1MS_RELOAD_H;       // 1ms 定时重装值高字节
	AUXR |= 0x10;              // 启动定时器2
	IE2 |= 0x04;               // 允许定时器2中断
}

// @brief   定时器0中断服务（1ms）：倒计时秒递减
void Timer0_ISR() interrupt 1
{
	static uint t_1ms = 0;     // 1ms 计数器，取值 0~APP_COUNTDOWN_PERIOD
	t_1ms++;
	if(t_1ms >= APP_COUNTDOWN_PERIOD)
	{
		t_1ms = 0;
		if(last_time != 0)
		{
			last_time--;
		}
	}
}

// @brief   定时器2中断服务（1ms）：周期置位任务触发标志并刷新数码管
void Timer2_ISR() interrupt 12
{
	static uint i = 0, j = 0;  // i: LED 刷新计数 0~APP_LED_REFRESH_PERIOD；j: 温度采集计数 0~APP_TEMP_TRIGGER_PERIOD
	i++;
	j++;
	if(i >= APP_LED_REFRESH_PERIOD)
	{
		i = 0;
		led_flag = 1;
	}
	if(j >= APP_TEMP_TRIGGER_PERIOD)
	{
		j = 0;
		temp_flag = 1;
	}
	set();
	display();
}
