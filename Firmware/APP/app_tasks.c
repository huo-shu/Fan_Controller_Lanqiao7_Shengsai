// @file    app_tasks.c
// @brief   应用任务实现：业务状态、节拍粘合与主循环调度
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "type_def.h"
#include "app_cfg.h"
#include "app_tasks.h"
#include "hal_timer.h"
#include "soft_timer.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_pwm.h"
#include "bsp_digitron.h"
#include "temp_sensor.h"
#include "display_mgr.h"

static uchar mode = 1;      // 风扇模式号 1~3
static int temper = 0;      // 温度整数部分，可负（-55~125℃，由温度采集刷新）
static uint last_time = 60; // 倒计时剩余秒数 0~65535，0 表示停止
static bit led_flag = 0;    // LED 刷新请求：软定时器回调置位，主循环处理后清零
static bit play_flag = 0;   // 显示页选择：0 倒计时页，1 温度页
static bit temp_flag = 0;   // 温度采集请求：软定时器回调置位，主循环处理后清零
static bit dirty = 0;       // 显示缓冲更新请求：状态变化处置位，节拍回调内渲染后清零

// @brief   倒计时秒节拍回调（中断上下文）：剩余秒数减 1，归零立即停转
static void Cb_Countdown(void)
{
	if(last_time != 0)
	{
		last_time--;
		if(last_time == 0)
		{
			PWM_Control(mode, 0); // 倒计时结束：风扇停转
		}
		dirty = 1; // 请求刷新倒计时显示
	}
}

// @brief   LED 刷新节拍回调（中断上下文）：请求 LED 状态刷新
static void Cb_LedRefresh(void)
{
	led_flag = 1;
}

// @brief   温度采集节拍回调（中断上下文）：请求温度采集
static void Cb_TempTrigger(void)
{
	temp_flag = 1;
}

// @brief   状态提交：推送 PWM 控制并请求刷新显示
static void App_Commit(void)
{
	PWM_Control(mode, last_time != 0);
	dirty = 1;
}

// @brief   1ms 节拍处理（中断上下文）：推进软定时器、渲染待刷新显示并执行扫描
static void App_TickHandler(void)
{
	SoftTimer_Tick();
	if(dirty == 1)
	{
		dirty = 0;
		DisplayMgr_Render(mode, temper, last_time, play_flag);
	}
	display();
}

// @brief   应用初始化：装配 1ms 节拍、启动软定时器并推送初始 PWM 状态
void App_Init(void)
{
	Timer2_SetTickCallback(App_TickHandler);
	SoftTimer_Start(APP_TIMER_CH_LED, APP_LED_REFRESH_PERIOD, Cb_LedRefresh);
	SoftTimer_Start(APP_TIMER_CH_TEMP, APP_TEMP_TRIGGER_PERIOD, Cb_TempTrigger);
	SoftTimer_Start(APP_TIMER_CH_CNTDOWN, APP_COUNTDOWN_PERIOD, Cb_Countdown);
	App_Commit();
}

// @brief   应用主循环任务：按键处理、LED 刷新与温度采集
void App_Process(void)
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
		App_Commit();
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
			App_Commit();
		}
	}
}
