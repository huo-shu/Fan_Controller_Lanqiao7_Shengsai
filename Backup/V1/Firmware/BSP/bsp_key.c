// @file    bsp_key.c
// @brief   独立按键读取与消抖
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "bsp_key.h"
#include "delay.h"

// @brief  读取当前按下的独立按键并等待释放
// @return 按键编号 1~4；无有效按键返回 0xff
// @note   两次采样间隔 10ms 消抖，按住不放则阻塞等待释放，保证单次触发
uchar Read_Key()
{
	uchar temp, val = 0xff;
	temp = P3 & 0x0f; // P3 低 4 位接独立按键，未按下时为高电平
	if(temp != 0x0f)
	{
		Delay10ms();
		temp = P3 & 0x0f;
		if(temp != 0x0f)
		{
			switch(temp)
			{
				case 0x0e: val = 1; break;
				case 0x0d: val = 2; break;
				case 0x0b: val = 3; break;
				case 0x07: val = 4; break;

			}
		}
	}
	temp = P3 & 0x0f;
	while(temp != 0x0f)
	{
		Delay10ms();
		temp = P3 & 0x0f;
	}
	return val;
}
