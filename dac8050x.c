/*******************************************************************************
* Title                 :   DAC driver for DAC8050x series
* Filename              :   dac8050x.c
* Author                :   LINCE
* Origin Date           :   21/07/25
* Version               :   1.0.0
* Compiler              :   gcc
* Target                :   Generic
* Notes                 :   None
*
*
*******************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version      Author          Description
*  21/07/25   1.0.0       LINCE           Initial Release.
*
*******************************************************************************/
/**
  ******************************************************************************
  * @file    dac8050x.c
  * @author  LINCE
  * @date    10/07/25
  * @brief   This file contains template for c file including the doxygen style
  * 			documentations.
  *
  * <br><b> - HISTORY OF CHANGES - </b>
  *
  * <table align="left" style="width:800px">
  * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
  * <tr><td> 14/01/2024 </td><td> 1.0.0            </td><td> SKP      </td><td> Module Created </td></tr>
  * </table><br><br>
  * <hr>
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright(c)  @TachlogPvtLtd.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */
#include "dac8050x.h"

extern SPI_HandleTypeDef hspi1;

/*configured the Clock polarity as LOW and clock phase as 2nd edge.*/
DAC8050x_CONFIG dac8050x_config =
{
		dac8050x_transmitData,
		dac8050x_receiveData,
		enable_chipSelect,
		disable_chipSelect
};


/**
  * @brief  function to Enable the chip select
  * @param  None
  * @retval None
  */
#warning change this function according to your controller function
void enable_chipSelect(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
}

/**
  * @brief  function to disable the chip select
  * @param  None
  * @retval None
  */
#warning change this function according to your controller function
void disable_chipSelect(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
}

/**
  * @brief  function to transmit data using SPI
  * @param  data : data to be transmitted
  * @retval return the transmission is success or not
  */
#warning change this function according to your controller function
bool dac8050x_transmitData(uint8_t * data)
{
	HAL_StatusTypeDef status = HAL_OK;
	HAL_SPI_Transmit(&hspi1, data, NUM_THREE, 1000);
	if(status == HAL_OK) return (true);
	else return (false);

}

/**
  * @brief  function to receive data using SPI
  * @param  data : data to be transmitted
  * @retval return the transmission is success or not
  */
#warning change this function according to your controller function
bool dac8050x_receiveData(uint8_t * data)
{
	HAL_StatusTypeDef status = HAL_OK;
	status = HAL_SPI_Receive(&hspi1, data, NUM_THREE, 1000);
	if(status == HAL_OK) return (true);
	else return (false);

}


/**
  * @brief  function to write to the config register
  * @param  None
  * @retval return the transmission is success or not
  */
bool writeSyncRegister(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = WRITE_REGISTER_COMMAND | REGISTER_DAC_SYNC;
	tempBufferTransmit[NUM_ONE] =  ((uint16_t)CONFIG_SYNC_REGISTER_VALUE >> 8);
	tempBufferTransmit[NUM_TWO] =  ((uint8_t)CONFIG_SYNC_REGISTER_VALUE);
	return (dac8050x_writeRegister(tempBufferTransmit));
}

/**
  * @brief  function to write to the config register
  * @param  None
  * @retval return the transmission is success or not
  */
bool writeConfigRegister(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = WRITE_REGISTER_COMMAND | REGISTER_DAC_CONFIG;
	tempBufferTransmit[NUM_ONE] =  ((uint16_t)CONFIG_CONFIG_REGISTER_VALUE >> 8);
	tempBufferTransmit[NUM_TWO] =  ((uint8_t)CONFIG_CONFIG_REGISTER_VALUE);
	return (dac8050x_writeRegister(tempBufferTransmit));
}

/**
  * @brief  function to write to the gain register
  * @param  None
  * @retval return the transmission is success or not
  */
bool writeGainRegister(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = WRITE_REGISTER_COMMAND | REGISTER_DAC_GAIN;
	tempBufferTransmit[NUM_ONE] =  ((uint16_t)CONFIG_GAIN_REGISTER_VALUE >> 8);
	tempBufferTransmit[NUM_TWO] =  ((uint8_t)CONFIG_GAIN_REGISTER_VALUE);
	return (dac8050x_writeRegister(tempBufferTransmit));
}

/**
  * @brief  function to write to the trigger register
  * @param  None
  * @retval return the transmission is success or not
  */
bool writeTriggerRegister(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = WRITE_REGISTER_COMMAND | REGISTER_DAC_TRIGGGER;
	tempBufferTransmit[NUM_ONE] =  ((uint16_t)CONFIG_TRIGGER_REGISTER_VALUE >> 8);
	tempBufferTransmit[NUM_TWO] =  ((uint8_t)CONFIG_TRIGGER_REGISTER_VALUE);
	return (dac8050x_writeRegister(tempBufferTransmit));
}

/**
  * @brief  function to read device ID
  * @param  None
  * @retval return the 16 bit device ID.
  */
/*function will return both device ID and version ID first two bit is version ID (LSB)*/
uint16_t dac8050x_readDeviceID(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = READ_REGISTER_COMMAND | REGISTER_DAC_DEVICE_ID;
	return (dac8050x_readRegister(tempBufferTransmit));
}

/**
  * @brief  function to read sync register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readSyncRegister(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = READ_REGISTER_COMMAND | REGISTER_DAC_SYNC;
	return (dac8050x_readRegister(tempBufferTransmit));
}

/**
  * @brief  function to read configuration register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readConfigRegister(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = READ_REGISTER_COMMAND | REGISTER_DAC_CONFIG;
	return (dac8050x_readRegister(tempBufferTransmit));
}

/**
  * @brief  function to read Gain register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readGainRegister(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = READ_REGISTER_COMMAND | REGISTER_DAC_GAIN;
	return (dac8050x_readRegister(tempBufferTransmit));
}

/**
  * @brief  function to read broadcast register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readBroadcastRegister(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = READ_REGISTER_COMMAND | REGISTER_DAC_BROADCAST;
	return (dac8050x_readRegister(tempBufferTransmit));
}

/**
  * @brief  function to read status register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readStatusRegister(void)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = READ_REGISTER_COMMAND | REGISTER_DAC_STATUS;
	return (dac8050x_readRegister(tempBufferTransmit));
}

/**
  * @brief  function to read DAC channel value
  * @param  channelNo : DAC channel number to get the value
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readDacRegValue(uint8_t channelNo)
{
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = READ_REGISTER_COMMAND | (REGISTER_DAC_CHANNEL_0 + channelNo);
	return (dac8050x_readRegister(tempBufferTransmit));
}

/**
  * @brief  function to read the register
  * @param  None
  * @retval return the 16 bit data from the corresponding register
  */
/*the input parameter should contain the read command + address of the register*/
uint16_t dac8050x_readRegister(uint8_t * data)
{
	bool status = false;
	uint8_t tempBufferReceive[NUM_THREE] = {INIT_ZERO};
	dac8050x_config.enable_chipSelect();
	HAL_Delay(1);
	status = dac8050x_config.spi_transferData(data);
	if(!status)
	{
		return(NUM_ZERO);
	}
	status = dac8050x_config.spi_ReceiveData(tempBufferReceive);
	HAL_Delay(1);
	dac8050x_config.disable_chipSelect();
	if(!status)
	{
		return(NUM_ZERO);
	}
	return ((tempBufferReceive[NUM_ONE] << 8) | tempBufferReceive[NUM_TWO] ); /*device ID + version id*/
}

/**
  * @brief  function to write the register
  * @param  None
  * @retval return the 16 bit data from the corresponding register
  */
/*the input parameter should contain the write command + address of the register + the data need to be written to the register*/
bool dac8050x_writeRegister(uint8_t * data)
{
	bool status = false;
	dac8050x_config.enable_chipSelect();
	HAL_Delay(1);
	status = dac8050x_config.spi_transferData(data);
	HAL_Delay(1);
	dac8050x_config.disable_chipSelect();
	if(!status)
	{
		return(NUM_ZERO);
	}
	return true;
}
