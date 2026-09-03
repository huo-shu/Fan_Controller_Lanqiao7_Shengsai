// @file    bsp_digitron.c
// @brief   数码管段码表与动态扫描输出
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#include "bsp_digitron.h"

// 共阳数码管段码表：下标 0~9 对应数字 0~9，段线低电平有效
uchar code DIG_CODE[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

uchar dis_code[8];  // 显示缓冲区：8 个数码位的段码，由显示管理模块刷新
uchar dis_flag = 0; // 当前扫描位序号，范围 0~7，循环推进

// @brief  数码管动态扫描：消隐、选中 dis_flag 位并输出其段码，随后推进位序号
void display()
{
	P2 = P2 & 0x0f | 0xe0; // 选通 Y7 段码锁存器
	P0 = 0xff;             // 全段熄灭，消除切换残影
	P2 &= 0x0f;
	P2 = P2 & 0x0f | 0xc0; // 选通 Y6 位选锁存器
	P0 = 0x01<<dis_flag;   // 选中当前扫描位
	P2 &= 0x0f;
	P2 = P2 & 0x0f | 0xe0; // 再选通段码锁存器
	P0 = dis_code[dis_flag]; // 输出当前位段码
	P2 &= 0x0f;

	if(++dis_flag == 8)
		dis_flag = 0;

}
