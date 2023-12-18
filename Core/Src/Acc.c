/*
 * Acc.c
 *
 *  Created on: Dec 17, 2023
 *      Author: rafae
 */
#include <Acc.h>
#include <main.h>

extern I2C_HandleTypeDef hi2c1;

void acc_init()
{
	HAL_StatusTypeDef ret;
	uint8_t pdata;

	ret=HAL_I2C_IsDeviceReady(&hi2c1,(DEVICE_ADDRESS<<1)+0 , 1, 100);
	if(ret==HAL_OK)
	{
		printf("The device is ready\n");
	}
	else{printf("The device is not ready\n");}

	pdata=FS_GYRO_500;
	ret =HAL_I2C_Mem_Write(&hi2c1, (DEVICE_ADDRESS<<1)+0, REG_CONFIG_GYRO, 1, &pdata, 1,100);

	if(ret==HAL_OK)
	{
	  printf("Configuring the Gyroscope\n");
	}
	else{printf("The device is not ready\n");}


	pdata=FS_ACC_4G;
	ret =HAL_I2C_Mem_Write(&hi2c1, (DEVICE_ADDRESS<<1)+0, REG_CONFIG_ACC, 1,&pdata, 1,100);

		if(ret==HAL_OK)
		{
			printf("Configuring the Accelerometer\n");
		}
		else{printf("The device is not ready\n");}




	pdata=0;
	ret =HAL_I2C_Mem_Write(&hi2c1, (DEVICE_ADDRESS<<1)+0, REG_USR_CTRL, 1,&pdata, 1,100);

		if(ret==HAL_OK)
		{
		  printf("Existing the sleep mode\n");
		}
		else{printf("The device is not ready\n");}



}




int16_t acc_xread()
{
	uint8_t data[2];
	int16_t x_acc;
	HAL_I2C_Mem_Read(&hi2c1, (DEVICE_ADDRESS<<1)+1, REG_DATA_X, 1, data, 2,100);
	x_acc= ((int16_t)data[0]<<8)+data[1];
	return x_acc;
}

int16_t acc_yread()
{
	uint8_t data[2];
	int16_t y_acc;
	HAL_I2C_Mem_Read(&hi2c1, (DEVICE_ADDRESS<<1)+1, REG_DATA_Y, 1, data, 2,100);
	y_acc= ((int16_t)data[0]<<8)+data[1];
	return y_acc;
}

int16_t acc_zread()
{
	uint8_t data[2];
	int16_t z_acc;
	HAL_I2C_Mem_Read(&hi2c1, (DEVICE_ADDRESS<<1)+1, REG_DATA_Z, 1, data, 2,100);
	z_acc= ((int16_t)data[0]<<8)+data[1];
	return z_acc;
}




int16_t gy_xread()
{
	uint8_t data[2];
	int16_t x_gy;
	HAL_I2C_Mem_Read(&hi2c1, (DEVICE_ADDRESS<<1)+1, REG_GY_X, 1, data, 2,100);
	x_gy= ((int16_t)data[0]<<8)+data[1];
	return x_gy;
}

int16_t gy_yread()
{
	uint8_t data[2];
	int16_t y_gy;
	HAL_I2C_Mem_Read(&hi2c1, (DEVICE_ADDRESS<<1)+1, REG_GY_Y, 1, data, 2,100);
	y_gy= ((int16_t)data[0]<<8)+data[1];
	return y_gy;
}

int16_t gy_zread()
{
	uint8_t data[2];
	int16_t z_gy;
	HAL_I2C_Mem_Read(&hi2c1, (DEVICE_ADDRESS<<1)+1, REG_GY_Z, 1, data, 2,100);
	z_gy= ((int16_t)data[0]<<8)+data[1];
	return z_gy;
}
