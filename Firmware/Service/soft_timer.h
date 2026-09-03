// @file    soft_timer.h
// @brief   软件定时器接口：周期事件定时，由 1ms 节拍驱动
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef SOFT_TIMER_H
#define SOFT_TIMER_H

#include "type_def.h"

#define SOFT_TIMER_CH_NUM 3  // 软件定时器通道数：LED 刷新 / 温度采集 / 倒计时

// @brief   软件定时器节拍推进：每 1ms 调用一次，通道到期时触发注册的回调
void SoftTimer_Tick(void);

// @brief   启动（或重载）一个周期软件定时器
// @param[in] ch         通道号：0 ~ (SOFT_TIMER_CH_NUM-1)
// @param[in] period     触发周期：1ms 节拍计数次数
// @param[in] on_expire  到期回调函数指针
void SoftTimer_Start(uchar ch, uint period, void (*on_expire)(void));

#endif // SOFT_TIMER_H
