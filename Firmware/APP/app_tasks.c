// @file    app_tasks.c
// @brief   应用任务实现：全局业务状态定义与主循环任务调度
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "app_tasks.h"
#include "bsp_key.h"
#include "bsp_led.h"
#include "temp_sensor.h"

uchar mode = 1, temper = 0;                 // 风扇模式 1~3；温度值整数℃

uint last_time = 60;                        // 倒计时剩余秒数，初值 60s

bit led_flag = 0, play_flag = 0, temp_flag = 0;  // 任务触发与运行状态标志

// @brief   应用主循环任务：扫描按键切换模式/倒计时，周期刷新 LED 与温度
void App_Process()
{
	uchar key;
	key = Read_Key();
	if(key != 0xff)
	{
		switch(key)
		{
			case 4: // 模式键：模式号在 1~3 间循环递增
				mode ++;
				if(mode >= 4)
					mode = 1;
			break;
			case 3: // 加时键：倒计时延长 60s
				last_time += 60;
			break;
			case 2: // 停止键：倒计时清零
				last_time = 0;
			break;
			case 1: // 启停键：运行/停止状态取反
				play_flag = ~play_flag;
		}
	}
	if(led_flag == 1)
	{
		led_flag = 0;
		if(last_time != 0)
		{
			if(mode == 1)       // 模式1 点亮最低位 LED
				led_on(~0x01);
			else if(mode == 2)  // 模式2 点亮次低位 LED
				led_on(~0x02);
			else if(mode == 3)  // 模式3 点亮第三位 LED
				led_on(~0x04);
		}
		else
			led_on(~0x00);      // 倒计时结束熄灭全部 LED
	}

	if(temp_flag == 1)
	{
		temp_flag = 0;
		if(play_flag == 1)
		{
			temper = Read_Tempe();  // 运行状态下周期采集温度
		}
	}
}
