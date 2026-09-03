// @file    app_tasks.h
// @brief   应用任务接口：系统装配与主循环任务
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef APP_TASKS_H
#define APP_TASKS_H

// @brief   应用初始化：装配 1ms 节拍回调、启动软定时器并推送初始状态
void App_Init(void);

// @brief   应用主循环任务：按键处理、LED 刷新与温度采集
void App_Process(void);

#endif // APP_TASKS_H
