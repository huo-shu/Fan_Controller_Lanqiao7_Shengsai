// @file    bsp_led.c
// @brief   LED 与继电器/蜂鸣器锁存器控制
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "bsp_led.h"

// @brief  设置 LED 组亮灭状态（低电平点亮）
// @param[in] led LED 位模式，位为 0 对应灯亮（如 ~0x01 仅点亮 L1）
void led_on(uchar led)
{
	P2 = P2 & 0x0f | 0x80; // 选通 Y4 LED 锁存器，保留低 4 位控制线状态
	P0 = led;              // 输出 LED 位模式，低电平灯亮
	P2 &= 0x0f;            // 撤销选通，锁存输出
}

// @brief  关闭继电器并静音蜂鸣器
void module_off()
{
	P2 = P2 & 0x0f | 0xa0; // 选通 Y5 继电器/蜂鸣器锁存器
	P0 = 0x00;             // 继电器断开，蜂鸣器静音
	P2 &= 0x0f;            // 撤销选通，锁存输出
}
