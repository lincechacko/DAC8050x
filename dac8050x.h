/*******************************************************************************
* Title                 :   DAC driver for DAC8050x series
* Filename              :   dac8050x.h
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
  * @file    dac8050x.h
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

/*Please refer Data sheet and configure the SPI*/
/*SDI data are clocked on SCLK falling edges*/


#ifndef BSP_DAC8050X_DAC8050X_H_
#define BSP_DAC8050X_DAC8050X_H_


#include "main.h"
#include <stdbool.h>

#define NUM_THREE                                          3
#define INIT_ZERO                                          0
#define NUM_ZERO                                           0
#define NUM_ONE                                            1
#define NUM_TWO                                            2

#define REGISTER_DAC_DEVICE_ID                             0x01 /*register to get the DAC device id*/
#define REGISTER_DAC_SYNC                                  0x02 /*register address to the sync register*/
#define REGISTER_DAC_CONFIG                                0x03 /*register address for the configuration register*/
#define REGISTER_DAC_GAIN                                  0x04 /*register address for the gain register*/
#define REGISTER_DAC_TRIGGGER                              0x05 /*register address for the trigger register*/
#define REGISTER_DAC_BROADCAST                             0x06 /*register address for the broadcast register*/
#define REGISTER_DAC_STATUS                                0x07 /*register address for the status register*/
#define REGISTER_DAC_CHANNEL_0 	                           0x08 /*register address for the DAC channel 0 - DAC80501*/
#define REGISTER_DAC_CHANNEL_1 	                           0x09 /*register address for the DAC channel 1 - DAC80502*/
#define REGISTER_DAC_CHANNEL_2 	                           0x0A /*register address for the DAC channel 2 - DAC80502*/
#define REGISTER_DAC_CHANNEL_3 	                           0x0B /*register address for the DAC channel 3 - DAC80502*/
#define REGISTER_DAC_CHANNEL_4 	                           0x0C /*register address for the DAC channel 4 - DAC80502*/
#define REGISTER_DAC_CHANNEL_5 	                           0x0D /*register address for the DAC channel 5 - DAC80502*/
#define REGISTER_DAC_CHANNEL_6 	                           0x0E /*register address for the DAC channel 6 - DAC80502*/
#define REGISTER_DAC_CHANNEL_7 	                           0x0F /*register address for the DAC channel 7 - DAC80502*/


#define READ_REGISTER_COMMAND                              0x80  /*command for reading register*/
#define WRITE_REGISTER_COMMAND                             0x00  /*command for writing register*/




typedef struct
{
	bool (* spi_transferData) (uint8_t *data);
	bool (* spi_ReceiveData)  (uint8_t *data);
}DAC8050x_CONFIG;

/**
  * @brief  function to transmit data using SPI
  * @param  data : data to be transmitted
  * @retval return the transmission is success or not
  */
bool dac8050x_transmitData(uint8_t * data);

/**
  * @brief  function to receive data using SPI
  * @param  data : data to be transmitted
  * @retval return the transmission is success or not
  */
bool dac8050x_receiveData(uint8_t * data);










#endif /* BSP_DAC8050X_DAC8050X_H_ */
