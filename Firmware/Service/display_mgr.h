// @file    display_mgr.h
// @brief   数码管显示内容管理接口，组装显示缓冲区
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef DISPLAY_MGR_H
#define DISPLAY_MGR_H

// @brief   按当前业务状态刷新数码管显示缓冲区 dis_code
// @note    play_flag==0 时显示模式号与倒计时，否则显示温度
void set();

#endif // DISPLAY_MGR_H
