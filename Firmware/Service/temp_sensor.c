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
// @return  摄氏温度值（含小数，分辨率 0.0625℃，负温返回负值）
float Read_Tempe()
{
	uchar low, high;
	uint raw;
	int temp_s;
	float val;

	Init_DS18B20();
	Write_DS18B20(OW_SKIP_ROM);       // 跳过 ROM 匹配，寻址总线上唯一器件
	Write_DS18B20(DS18B20_CONVERT);   // 启动温度转换
	Delay_OneWire(400);               // 等待温度转换完成

	Init_DS18B20();
	Write_DS18B20(OW_SKIP_ROM);       // 跳过 ROM 匹配，寻址总线上唯一器件
	Write_DS18B20(DS18B20_READ);      // 读取暂存器

	low =  Read_DS18B20();            // 温度原始值低字节
	high = Read_DS18B20();            // 温度原始值高字节（bit15 为符号位）
	raw = (uint)high << 8 | low;      // 16 位原始值：低 12 位有效，LSB = 0.0625℃
	if((raw & 0x8000) != 0)           // 符号位为 1（负温补码）：还原为负数
		temp_s = (int)raw - 65536;
	else
		temp_s = (int)raw;
	val = temp_s * 0.0625;            // 换算摄氏温度：分辨率 0.0625℃

	return val;
}
