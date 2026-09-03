// @file    display_mgr.c
// @brief   数码管显示内容管理：按业务状态填充显示缓冲区
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "type_def.h"
#include "bsp_digitron.h"
#include "display_mgr.h"

// @brief   按业务状态刷新显示缓冲区
// @note    布局：停止页 "- 模式 - 空 倒计时四位"；温度页 "- 4 - 空 [负号] 十位 个位 C"
void DisplayMgr_Render(uchar mode, int temper, uint last_time, uchar play)
{
	if(play == 0)
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
		if(temper < 0)                            // 负温：负号位显示 '-'，数值取绝对值
		{
			dis_code[4] =  0xbf;                  // 段码 '-'（负号）
			temper = -temper;
		}
		else
		{
			dis_code[4] =  0xff;                  // 段码 0xff：熄灭
		}
		dis_code[5] =  DIG_CODE[temper / 10];     // 温度十位
		dis_code[6] =  DIG_CODE[temper % 10];     // 温度个位
		dis_code[7] =  0xc6;                      // 段码 'C'（摄氏度标识）
	}
}
