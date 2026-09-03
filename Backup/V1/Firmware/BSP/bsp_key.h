// @file    bsp_key.h
// @brief   独立按键读取接口（P3 低 4 位，低电平有效）
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef BSP_KEY_H
#define BSP_KEY_H

#include "type_def.h"

// @brief  读取当前按下的独立按键并等待释放
// @return 按键编号 1~4；无有效按键返回 0xff
// @note   内部含消抖与释放等待，阻塞期间持续软件延时
uchar Read_Key();

#endif // BSP_KEY_H
