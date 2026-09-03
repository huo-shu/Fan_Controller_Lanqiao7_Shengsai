// @file    delay.c
// @brief   精准软件延时实现（@11.0592MHz 时序校准）
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "delay.h"

// @brief  约 10ms 软件延时（@11.0592MHz 时序校准），供按键消抖等待电平稳定
void Delay10ms()
{
	unsigned char i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}

// @brief  单总线协议粗延时
// @param[in] t 延时长度，每单位约 12 次空循环
void Delay_OneWire(unsigned int t)
{
	uchar i;
  while(t--)
  	for(i=0;i<12;i++)
		;
}
