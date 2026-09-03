// @file    soft_timer.c
// @brief   软件定时器实现：多通道周期计数，到期触发回调
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "type_def.h"
#include "soft_timer.h"

typedef struct
{
	uint period;              // 触发周期：1ms 节拍计数次数
	uint cnt;                 // 当前计数：递增至 period 后清零并触发
	void (*on_expire)(void);  // 到期回调函数指针
} SoftTimer_Ch;

static SoftTimer_Ch st_timer[SOFT_TIMER_CH_NUM]; // 各通道的周期/计数/回调

// @brief   推进全部通道计数：每 1ms 节拍调用一次
void SoftTimer_Tick(void)
{
	uchar i;
	for(i = 0; i < SOFT_TIMER_CH_NUM; i++)
	{
		st_timer[i].cnt++;
		if(st_timer[i].cnt >= st_timer[i].period)
		{
			st_timer[i].cnt = 0;
			if(st_timer[i].on_expire != 0)
				st_timer[i].on_expire();
		}
	}
}

// @brief   启动/重载通道定时器：清零计数并记录周期与到期回调
void SoftTimer_Start(uchar ch, uint period, void (*on_expire)(void))
{
	st_timer[ch].period = period;
	st_timer[ch].cnt = 0;
	st_timer[ch].on_expire = on_expire;
}
