// @file    delay.h
// @brief   精准软件延时接口，供各 BSP 模块调用
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef DELAY_H
#define DELAY_H

#include "type_def.h"

// @brief  约 10ms 软件延时（@11.0592MHz 时序校准）
void Delay10ms();

// @brief  单总线协议粗延时
// @param[in] t 延时长度，每单位约 12 次空循环
void Delay_OneWire(unsigned int t);

#endif // DELAY_H
