// @file    bsp_onewire.h
// @brief   DS18B20 单总线底层时序接口
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef BSP_ONEWIRE_H
#define BSP_ONEWIRE_H

#include "type_def.h"

#define OW_SKIP_ROM     0xcc // 跳过 ROM 匹配命令：单点总线上直接寻址
#define DS18B20_CONVERT 0x44 // 温度转换命令：启动一次温度测量
#define DS18B20_READ    0xbe // 读暂存器命令：读回温度转换结果

// @brief  复位单总线并检测 DS18B20 是否应答
// @return 1：总线上无器件应答；0：检测到器件存在
bit Init_DS18B20(void);

// @brief  向 DS18B20 写入一个字节（低位在前）
// @param[in] dat 待写入的命令或数据字节
void Write_DS18B20(unsigned char dat);

// @brief  从 DS18B20 读取一个字节（低位在前）
// @return 读回的数据字节
unsigned char Read_DS18B20(void);

#endif // BSP_ONEWIRE_H
