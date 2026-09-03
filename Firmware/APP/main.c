// @file    main.c
// @brief   程序入口：系统初始化并调度应用主任务
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "type_def.h"
#include "bsp_led.h"
#include "hal_timer.h"
#include "bsp_pwm.h"
#include "app_tasks.h"

void main()
{
	led_on(~0x00);   // 上电熄灭全部 LED
	module_off();    // 上电关闭继电器与蜂鸣器
	Timer2Init();    // 1ms 系统节拍
	App_Init();      // 装配节拍回调与软定时器，推送初始 PWM 状态
	Timer1Init();    // 20us PWM 时基
	EA = 1;          // 开启总中断
	while(1)
	{
		App_Process();
	}
}
