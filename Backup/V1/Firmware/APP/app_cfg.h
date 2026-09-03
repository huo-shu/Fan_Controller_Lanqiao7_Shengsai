// @file    app_cfg.h
// @brief   应用层参数配置：任务调度周期与 PWM 占空比阈值
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef APP_CFG_H
#define APP_CFG_H

#define APP_LED_REFRESH_PERIOD  200 // LED 刷新周期：1ms 计数阈值（200ms）
#define APP_TEMP_TRIGGER_PERIOD 537 // 温度采集触发周期：1ms 计数阈值（537ms）
#define APP_COUNTDOWN_PERIOD    999 // 倒计时步长：1ms 计数 0~999，即每 1s 减 1
#define APP_PWM_PERIOD          47  // PWM 周期：20us 基准计数上限（约 940us）
#define APP_PWM_DUTY_MODE1      9   // 模式1 占空比阈值：周期内高电平计数（低风速）
#define APP_PWM_DUTY_MODE2      14  // 模式2 占空比阈值：周期内高电平计数（中风速）
#define APP_PWM_DUTY_MODE3      33  // 模式3 占空比阈值：周期内高电平计数（高风速）

#endif // APP_CFG_H
