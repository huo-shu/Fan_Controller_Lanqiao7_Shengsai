// @file    bsp_pwm.h
// @brief   风扇 PWM 输出接口（定时器1 时基，影子状态控制）
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef BSP_PWM_H
#define BSP_PWM_H

#include "type_def.h"

// @brief  初始化定时器1为 20us 中断时基，驱动风扇 PWM 占空比生成
void Timer1Init(void);

// @brief  推送 PWM 控制状态：由业务层在模式/运行状态变化时调用
// @param[in] mode   风扇模式 1~3（占空比档位）
// @param[in] enable 1 按档位输出占空比；0 输出低电平停转
void PWM_Control(uchar mode, bit enable);

#endif // BSP_PWM_H
