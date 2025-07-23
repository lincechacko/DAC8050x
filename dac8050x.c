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
/*change this function according to your controller function*/
void enable_chipSelect(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
}

/**
  * @brief  function to disable the chip select
  * @param  None
  * @retval None
  */
/*change this function according to your controller function*/
void disable_chipSelect(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
}

/**
  * @brief  function to transmit data using SPI
  * @param  data : data to be transmitted
  * @retval return the transmission is success or not
  */
/*change this function according to your controller function*/
bool dac8050x_transmitData(uint8_t * data)
{
	  HAL_SPI_Transmit(&hspi1, data, 3, 1000);
	  return true;

}

/**
  * @brief  function to receive data using SPI
  * @param  data : data to be transmitted
  * @retval return the transmission is success or not
  */
/*change this function according to your controller function*/
bool dac8050x_receiveData(uint8_t * data)
{
	  HAL_SPI_Receive(&hspi1, data, 3, 1000);
	  return true;
}

/**
  * @brief  function to read device ID
  * @param  None
  * @retval return the 16 bit data from the corresponding register
  */
/*function will return both device ID and version ID first two bit is version ID (LSB)*/
uint16_t readDeviceID(void)
{
	bool status = false;
	uint8_t tempBufferTransmit[NUM_THREE] = {INIT_ZERO};
	uint8_t tempBufferReceive[NUM_THREE] = {INIT_ZERO};
	tempBufferTransmit[NUM_ZERO] = READ_REGISTER_COMMAND | REGISTER_DAC_DEVICE_ID;
	dac8050x_config.enable_chipSelect();
	status = dac8050x_config.spi_transferData(tempBufferTransmit);
	if(!status)
	{
		return(NUM_ZERO);
	}
	status = dac8050x_config.spi_ReceiveData(tempBufferReceive);
	dac8050x_config.disable_chipSelect();
	if(!status)
	{
		return(NUM_ZERO);
	}
	return ((tempBufferReceive[NUM_TWO] << 8) | tempBufferReceive[NUM_THREE] ); /*device ID + version id*/
}
