/*
 * Acc.h
 *
 *  Created on: Dec 17, 2023
 *      Author: rafae
 */

#ifndef INC_ACC_H_
#define INC_ACC_H_
#include "main.h"



//Macros
#define DEVICE_ADDRESS 0x68

#define FS_GYRO_250 	0
#define FS_GYRO_500		8
#define FS_GYRO_1000	9
#define FS_GYRO_2000	10

#define FS_ACC_2G 		0
#define FS_ACC_4G 		8
#define FS_ACC_8G 		9
#define FS_ACC_16G 		10

#define REG_CONFIG_GYRO 27
#define REG_CONFIG_ACC  28
#define REG_USR_CTRL	107

#define REG_DATA_X		59
#define REG_DATA_Y		61
#define REG_DATA_Z		63


#define REG_GY_X		67
#define REG_GY_Y		69
#define REG_GY_Z		71








void acc_init();

int16_t acc_xread();
int16_t acc_yread();
int16_t acc_zread();

int16_t gy_xread();
int16_t gy_yread();
int16_t gy_zread();




#endif /* INC_ACC_H_ */
