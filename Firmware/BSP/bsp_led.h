// @file    bsp_led.h
// @brief   LED 与继电器/蜂鸣器锁存器控制接口
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef BSP_LED_H
#define BSP_LED_H

#include "type_def.h"

// @brief  设置 LED 组亮灭状态（低电平点亮）
// @param[in] led LED 位模式，位为 0 对应灯亮（如 ~0x01 仅点亮 L1）
void led_on(uchar led);

// @brief  关闭继电器并静音蜂鸣器
void module_off();

#endif // BSP_LED_H
