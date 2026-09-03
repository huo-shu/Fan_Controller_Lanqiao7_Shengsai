// @file    bsp_digitron.h
// @brief   数码管段码表、显示缓冲区与动态扫描接口
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef BSP_DIGITRON_H
#define BSP_DIGITRON_H

#include "type_def.h"

extern uchar code DIG_CODE[]; // 共阳数码管段码表，下标 0~9 对应数字 0~9 的段码
extern uchar dis_code[8];     // 显示缓冲区，8 个数码位的段码，0xff 为熄灭

// @brief  数码管动态扫描：输出当前位（dis_flag）的段码并推进位选
void display();

#endif // BSP_DIGITRON_H
