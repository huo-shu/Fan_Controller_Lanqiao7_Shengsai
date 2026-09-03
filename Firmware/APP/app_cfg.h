// @file    app_cfg.h
// @brief   应用层参数配置：任务调度周期与 PWM 占空比阈值
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef APP_CFG_H
#define APP_CFG_H

#define APP_LED_REFRESH_PERIOD  200 // LED 刷新周期：软定时器 1ms 计数（200ms）
#define APP_TEMP_TRIGGER_PERIOD 537 // 温度采集触发周期：软定时器 1ms 计数（537ms）
#define APP_COUNTDOWN_PERIOD    999 // 倒计时节拍周期：软定时器 1ms 计数（999ms，约 1s）
#define APP_PWM_PERIOD          47  // PWM 周期：20us 基准计数上限（约 940us）
#define APP_PWM_DUTY_MODE1      9   // 模式1 占空比阈值：周期内高电平计数（低风速）
#define APP_PWM_DUTY_MODE2      14  // 模式2 占空比阈值：周期内高电平计数（中风速）
#define APP_PWM_DUTY_MODE3      33  // 模式3 占空比阈值：周期内高电平计数（高风速）

#define APP_TIMER_CH_LED      0 // 软定时器通道号：LED 刷新节拍
#define APP_TIMER_CH_TEMP     1 // 软定时器通道号：温度采集触发节拍
#define APP_TIMER_CH_CNTDOWN  2 // 软定时器通道号：倒计时节拍

#endif // APP_CFG_H
