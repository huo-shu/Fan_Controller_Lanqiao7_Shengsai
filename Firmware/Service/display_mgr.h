// @file    display_mgr.h
// @brief   数码管显示内容管理接口：按业务状态组装显示缓冲区
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef DISPLAY_MGR_H
#define DISPLAY_MGR_H

#include "type_def.h"

// @brief   按业务状态刷新数码管显示缓冲区 dis_code
// @param[in] mode      风扇模式 1~3
// @param[in] temper    温度整数部分，可负
// @param[in] last_time 倒计时剩余秒数
// @param[in] play      显示页：0 倒计时页，1 温度页
void DisplayMgr_Render(uchar mode, int temper, uint last_time, uchar play);

#endif // DISPLAY_MGR_H
