// @file    hal_timer.h
// @brief   定时器2底层接口：1ms 系统节拍与节拍回调注册
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef HAL_TIMER_H
#define HAL_TIMER_H

// @brief   初始化定时器2：1T 模式 1ms 溢出中断，作为系统节拍
void Timer2Init(void);

// @brief   注册 1ms 节拍回调（回调在定时器2中断内执行）
// @param[in] callback 节拍处理函数指针
void Timer2_SetTickCallback(void (*callback)(void));

#endif // HAL_TIMER_H
