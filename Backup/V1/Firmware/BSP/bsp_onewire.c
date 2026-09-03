// @file    bsp_onewire.c
// @brief   DS18B20 单总线底层时序实现
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "bsp_onewire.h"
#include "delay.h"

sbit DQ = P1^4; // 单总线数据引脚

// @brief  复位单总线并检测 DS18B20 是否应答
// @return 1：总线上无器件应答；0：检测到器件存在
bit Init_DS18B20(void)
{
	bit initflag = 0;
	DQ = 1;
	Delay_OneWire(12);
	DQ = 0;
	Delay_OneWire(80);
	DQ = 1;
	Delay_OneWire(10);
	initflag = DQ;
	Delay_OneWire(5);

	return initflag;
}

// @brief  向 DS18B20 写入一个字节（低位在前）
// @param[in] dat 待写入的命令或数据字节
void Write_DS18B20(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		DQ = 0;
		DQ = dat&0x01;
		Delay_OneWire(5);
		DQ = 1;
		dat >>= 1;
	}
	Delay_OneWire(5);
}

// @brief  从 DS18B20 读取一个字节（低位在前）
// @return 读回的数据字节
unsigned char Read_DS18B20(void)
{
	unsigned char i;
	unsigned char dat;

	for(i=0;i<8;i++)
	{
		DQ = 0;
		dat >>= 1;
		DQ = 1;
		if(DQ)
		{
			dat |= 0x80;
		}
		Delay_OneWire(5);
	}
	return dat;
}
