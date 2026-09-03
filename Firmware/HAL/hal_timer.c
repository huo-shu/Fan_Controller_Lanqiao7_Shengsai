// @file    hal_timer.c
// @brief   定时器2驱动：1ms 系统节拍，中断内直连节拍处理
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布
//
// @note    H1 假设变体：节拍处理由中断直连调用，去除函数指针间接层

#include "type_def.h"
#include "config.h"
#include "app_tasks.h"
#include "hal_timer.h"

// @brief   初始化定时器2：1T 模式，16 位自动重装，1ms 溢出中断
void Timer2Init(void)
{
	AUXR |= 0x04;              // 定时器2时钟 1T 模式
	T2L = T1MS_RELOAD_L;       // 1ms 定时重装值低字节
	T2H = T1MS_RELOAD_H;       // 1ms 定时重装值高字节
	AUXR |= 0x10;              // 启动定时器2
	IE2 |= 0x04;               // 允许定时器2中断
}

// @brief   定时器2中断服务（1ms）：推进节拍处理
void Timer2_ISR() interrupt 12
{
	App_TickHandler();
}
