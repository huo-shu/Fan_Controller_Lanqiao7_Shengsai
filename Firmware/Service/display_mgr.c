// @file    display_mgr.c
// @brief   数码管显示内容管理：按运行模式与倒计时/温度状态填充显示缓冲区
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "app_tasks.h"
#include "bsp_digitron.h"
#include "display_mgr.h"

// @brief   按当前业务状态刷新显示缓冲区
// @note    停止状态显示模式号与四位倒计时；运行状态显示 "-4--温度C"
void set()
{
	if(play_flag == 0)
	{
		dis_code[0] =  0xbf;                      // 段码 '-'（分隔横杠）
		dis_code[1] =  DIG_CODE[mode];            // 当前模式号
		dis_code[2] =  0xbf;                      // 段码 '-'（分隔横杠）
		dis_code[3] =  0xff;                      // 段码 0xff：熄灭
		dis_code[4] =  DIG_CODE[last_time / 1000];        // 倒计时千位
		dis_code[5] =  DIG_CODE[last_time % 1000 / 100];  // 倒计时百位
		dis_code[6] =  DIG_CODE[last_time % 100 / 10];    // 倒计时十位
		dis_code[7] =  DIG_CODE[last_time % 10];          // 倒计时个位
	}
	else
	{
		dis_code[0] =  0xbf;                      // 段码 '-'（分隔横杠）
		dis_code[1] =  DIG_CODE[4];               // 温度显示页页号 '4'
		dis_code[2] =  0xbf;                      // 段码 '-'（分隔横杠）
		dis_code[3] =  0xff;                      // 段码 0xff：熄灭
		dis_code[4] =  0xff;                      // 段码 0xff：熄灭
		dis_code[5] =  DIG_CODE[temper / 10];     // 温度十位
		dis_code[6] =  DIG_CODE[temper % 10];     // 温度个位
		dis_code[7] =  0xc6;                      // 段码 'C'（摄氏度标识）
	}
}
