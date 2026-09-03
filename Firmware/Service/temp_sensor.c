// @file    temp_sensor.c
// @brief   温度采集服务：驱动 DS18B20 完成温度转换与读取换算
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "type_def.h"
#include "bsp_onewire.h"
#include "delay.h"
#include "temp_sensor.h"

// @brief   启动一次温度转换并读取换算结果
// @return  摄氏温度值（含小数，分辨率 0.0625℃）
float Read_Tempe()
{
	uchar low, high;
	uint temp;
	float val;

	Init_DS18B20();
	Write_DS18B20(OW_SKIP_ROM);       // 跳过 ROM 匹配，寻址总线上唯一器件
	Write_DS18B20(DS18B20_CONVERT);   // 启动温度转换
	Delay_OneWire(400);               // 等待温度转换完成

	Init_DS18B20();
	Write_DS18B20(OW_SKIP_ROM);       // 跳过 ROM 匹配，寻址总线上唯一器件
	Write_DS18B20(DS18B20_READ);      // 读取暂存器

	low =  Read_DS18B20();            // 温度低字节
	high = Read_DS18B20();            // 温度高字节
	temp = high & 0x0f;               // 取高字节低 4 位整数部分
	temp = temp << 8 | low;           // 拼接为温度原始值
	val = temp * 0.0625;              // 原始值换算为摄氏温度，分辨率 0.0625℃

	return val;
}
