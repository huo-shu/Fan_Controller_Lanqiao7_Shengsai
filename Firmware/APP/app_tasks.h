// @file    app_tasks.h
// @brief   应用任务接口与全局业务状态声明
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef APP_TASKS_H
#define APP_TASKS_H

#include "type_def.h"

extern uchar mode;      // 当前风扇模式：1/2/3
extern uchar temper;    // 当前温度值：整数℃，0~99
extern uint last_time;  // 倒计时剩余秒数：0~65535，0 表示停止
extern bit led_flag;    // LED 刷新请求标志：Timer2_ISR 周期置位，主循环处理后清零
extern bit play_flag;   // 运行状态标志：0 显示倒计时，1 显示温度
extern bit temp_flag;   // 温度采集请求标志：Timer2_ISR 周期置位，主循环处理后清零

// @brief   应用主循环任务：按键处理、LED 刷新与温度采集
void App_Process();

#endif // APP_TASKS_H
