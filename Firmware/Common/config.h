// @file    config.h
// @brief   系统级配置：晶振频率与定时器重装值
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef CONFIG_H
#define CONFIG_H

#define CONFIG_FOSC    11059200UL // 系统晶振频率，单位 Hz（@11.0592MHz）
#define T1MS_RELOAD_H  0xD4       // 1ms 定时重装值高字节，1T 模式（定时器0/2 共用）
#define T1MS_RELOAD_L  0xCD       // 1ms 定时重装值低字节，1T 模式（定时器0/2 共用）
#define T20US_RELOAD_H 0xFF       // 20us 定时重装值高字节，1T 模式（定时器1，PWM 时基）
#define T20US_RELOAD_L 0x23       // 20us 定时重装值低字节，1T 模式（定时器1，PWM 时基）

#endif // CONFIG_H
