// @file    bsp_pwm.h
// @brief   风扇 PWM 输出接口（定时器1 时基）
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef BSP_PWM_H
#define BSP_PWM_H

// @brief  初始化定时器1为 20us 中断时基，驱动风扇 PWM 占空比生成
void Timer1Init(void);

#endif // BSP_PWM_H
