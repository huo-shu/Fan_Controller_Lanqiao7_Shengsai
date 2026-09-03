// @file    temp_sensor.h
// @brief   温度采集服务接口
// @author  Huo-shu
// @date    2026-09-03
//
// @version V1.0 (2026-09-03) 初版发布

#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

// @brief   启动一次 DS18B20 温度转换并读取结果
// @return  摄氏温度值（含小数，分辨率 0.0625℃）
float Read_Tempe();

#endif // TEMP_SENSOR_H
