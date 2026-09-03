// @file    hal_timer.h
// @brief   定时器0/2初始化接口，提供 1ms 系统节拍
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef HAL_TIMER_H
#define HAL_TIMER_H

// @brief   初始化定时器0：1T 模式 1ms 中断，用于倒计时秒递减
void Timer0Init(void);

// @brief   初始化定时器2：1T 模式 1ms 中断，用于任务标志置位与数码管扫描
void Timer2Init(void);

#endif // HAL_TIMER_H
