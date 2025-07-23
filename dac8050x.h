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

#define CRC_CHECK_DISABLE

#define NUM_THREE                                          3
#define INIT_ZERO                                          0
#define NUM_ZERO                                           0
#define NUM_ONE                                            1
#define NUM_TWO                                            2
#define NUM_FOUR                                           4
#define NUM_EIGHT                                          8

#define REGISTER_DAC_NOP                                   0x00 /*register to get the DAC device id*/
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

/*--------------------------------------SYNCHRONOUS ENABLE / DISABLE---------------------------------------------------*/
#define DAC7_SYNC_ENABLE                                   1<<7 /*bit to enable the SYNC for the DAC channel 7*/
#define DAC7_SYNC_DISABLE                                  0<<7 /*bit to disable the SYNC for the DAC channel 7*/

#define DAC6_SYNC_ENABLE                                   1<<6 /*bit to enable the SYNC for the DAC channel 6*/
#define DAC6_SYNC_DISABLE                                  0<<6 /*bit to disable the SYNC for the DAC channel 6*/

#define DAC5_SYNC_ENABLE                                   1<<5 /*bit to enable the SYNC for the DAC channel 5*/
#define DAC5_SYNC_DISABLE                                  0<<5 /*bit to disable the SYNC for the DAC channel 5 */

#define DAC4_SYNC_ENABLE                                   1<<4 /*bit to enable the SYNC for the DAC channel 4*/
#define DAC4_SYNC_DISABLE                                  0<<4 /*bit to disable the SYNC for the DAC channel 4 */

#define DAC3_SYNC_ENABLE                                   1<<3 /*bit to enable the SYNC for the DAC channel 3*/
#define DAC3_SYNC_DISABLE                                  0<<3 /*bit to disable the SYNC for the DAC channel 3*/

#define DAC2_SYNC_ENABLE                                   1<<2 /*bit to enable the SYNC for the DAC channel 2*/
#define DAC2_SYNC_DISABLE                                  0<<2 /*bit to disable the SYNC for the DAC channel 2*/

#define DAC1_SYNC_ENABLE                                   1<<1 /*bit to enable the SYNC for the DAC channel 1*/
#define DAC1_SYNC_DISABLE                                  0<<1 /*bit to disable the SYNC for the DAC channel 1 */

#define DAC0_SYNC_ENABLE                                   1<<0 /*bit to enable the SYNC for the DAC channel 0*/
#define DAC0_SYNC_DISABLE                                  0<<0 /*bit to disable the SYNC for the DAC channel 0 */

/*--------------------------------------BROADCAST ENABLE AND DISABLE----------------------------------------------*/
#define DAC7_BROADCAST_ENABLE                              1<<15 /*bit to enable the broadcast for the DAC channel 7*/
#define DAC7_BROADCAST_DISABLE                             0<<15 /*bit to disable the broadcast for the DAC channel 7*/

#define DAC6_BROADCAST_ENABLE                              1<<14 /*bit to enable the broadcast for the DAC channel 6*/
#define DAC6_BROADCAST_DISABLE                             0<<14 /*bit to disable the broadcast for the DAC channel 6*/

#define DAC5_BROADCAST_ENABLE                              1<<13 /*bit to enable the broadcast for the DAC channel 5*/
#define DAC5_BROADCAST_DISABLE                             0<<13 /*bit to disable the broadcast for the DAC channel 5 */

#define DAC4_BROADCAST_ENABLE                              1<<12 /*bit to enable the broadcast for the DAC channel 4*/
#define DAC4_BROADCAST_DISABLE                             0<<12 /*bit to disable the broadcast for the DAC channel 4 */

#define DAC3_BROADCAST_ENABLE                              1<<11 /*bit to enable the broadcast for the DAC channel 3*/
#define DAC3_BROADCAST_DISABLE                             0<<11 /*bit to disable the broadcast for the DAC channel 3*/

#define DAC2_BROADCAST_ENABLE                              1<<10 /*bit to enable the broadcast for the DAC channel 2*/
#define DAC2_BROADCAST_DISABLE                             0<<10 /*bit to disable the broadcast for the DAC channel 2*/

#define DAC1_BROADCAST_ENABLE                              1<<9 /*bit to enable the broadcast for the DAC channel 1*/
#define DAC1_BROADCAST_DISABLE                             0<<9 /*bit to disable the broadcast for the DAC channel 1 */

#define DAC0_BROADCAST_ENABLE                              1<<8 /*bit to enable the broadcast for the DAC channel 0*/
#define DAC0_BROADCAST_DISABLE                             0<<8 /*bit to disable the broadcast for the DAC channel 0 */

/*-------------------------------------------CONFIG REGISTER-------------------------------------------------------*/
#define ALARM_PIN_CRC_ERROR                                0<<13  /*set alarm pin as crc error*/
#define ALARM_PIN_REF_ALARM                                1<<13  /*set alarm pin as ref alarm*/

#define CONFIG_ALARM_ENABLE                                1<<12 /*to enable the alarm*/
#define CONFIG_ALARM_DISABLE                               0<<12 /*to disable the alarm*/

#define CONFIG_CRC_ENABLE                                  1<<11 /*enable the crc*/
#define CONFIG_CRC_DISABLE                                 0<<11 /*disable the crc*/

#define CONFIG_UPDATE_RISING_EDGE                          0<<10 /*update data on the rising edge*/
#define CONFIG_UPDATE_FALLING_EDGE                         1<<10 /*update data on the falling edge*/

#define CONFIG_DISABLE_SERIAL_OUT                          1<<9  /*disable serial output*/
#define CONFIG_ENABLE_SERIAL_OUT                           0<<9  /*enable serial output*/

#define CONFIG_DISABLE_INTERNAL_REF                        1<<8 /*to disable the internal reference*/
#define CONFIG_ENABLE_INTERNAL_REF                         0<<8 /*to enable internal reference*/

#define CONFIG_ENABLE_MODE_POWERDOWN_DAC7                  1<<7 /*to enable power down mode for DAC channel 7*/
#define CONFIG_DISABLE_MODE_POWERDOWN_DAC7                 0<<7 /*to disable power down mode for DAC channel 7*/

#define CONFIG_ENABLE_MODE_POWERDOWN_DAC6                  1<<6 /*to enable power down mode for DAC channel 6*/
#define CONFIG_DISABLE_MODE_POWERDOWN_DAC6                 0<<6 /*to disable power down mode for DAC channel 6*/

#define CONFIG_ENABLE_MODE_POWERDOWN_DAC5                  1<<5 /*to enable power down mode for DAC channel 5*/
#define CONFIG_DISABLE_MODE_POWERDOWN_DAC5                 0<<5 /*to disable power down mode for DAC channel 5*/

#define CONFIG_ENABLE_MODE_POWERDOWN_DAC4                  1<<4 /*to enable power down mode for DAC channel 4*/
#define CONFIG_DISABLE_MODE_POWERDOWN_DAC4                 0<<4 /*to disable power down mode for DAC channel 4*/

#define CONFIG_ENABLE_MODE_POWERDOWN_DAC3                  1<<3 /*to enable power down mode for DAC channel 3*/
#define CONFIG_DISABLE_MODE_POWERDOWN_DAC3                 0<<3 /*to disable power down mode for DAC channel 3*/

#define CONFIG_ENABLE_MODE_POWERDOWN_DAC2                  1<<2 /*to enable power down mode for DAC channel 2*/
#define CONFIG_DISABLE_MODE_POWERDOWN_DAC2                 0<<2 /*to disable power down mode for DAC channel 2*/

#define CONFIG_ENABLE_MODE_POWERDOWN_DAC1                  1<<1 /*to enable power down mode for DAC channel 1*/
#define CONFIG_DISABLE_MODE_POWERDOWN_DAC1                 0<<1 /*to disable power down mode for DAC channel 1*/

#define CONFIG_ENABLE_MODE_POWERDOWN_DAC0                  1<<0 /*to enable power down mode for DAC channel 0*/
#define CONFIG_DISABLE_MODE_POWERDOWN_DAC0                 0<<0 /*to disable power down mode for DAC channel 0*/

/*---------------------------------------------GAIN REGISTER-------------------------------------------------*/
#define GAIN_REG_DIV_INT_REF_0                             0<<8 /*no division for internal reference*/
#define GAIN_REG_DIV_INT_REF_2                             1<<8 /*division of internal refernce with a factor of 2*/

#define GAIN_DAC_CHANNEL_7_VALUE_2                         1<<7 /*DAC channel 7 gain value as 2*/
#define GAIN_DAC_CHANNEL_7_VALUE_1                         0<<7 /*DAC channel 7 gain value as 1*/

#define GAIN_DAC_CHANNEL_6_VALUE_2                         1<<6 /*DAC channel 6 gain value as 2*/
#define GAIN_DAC_CHANNEL_6_VALUE_1                         0<<6 /*DAC channel 6 gain value as 1*/

#define GAIN_DAC_CHANNEL_5_VALUE_2                         1<<5 /*DAC channel 5 gain value as 2*/
#define GAIN_DAC_CHANNEL_5_VALUE_1                         0<<5 /*DAC channel 5 gain value as 1*/

#define GAIN_DAC_CHANNEL_4_VALUE_2                         1<<4 /*DAC channel 4 gain value as 2*/
#define GAIN_DAC_CHANNEL_4_VALUE_1                         0<<4 /*DAC channel 4 gain value as 1*/

#define GAIN_DAC_CHANNEL_3_VALUE_2                         1<<3 /*DAC channel 3 gain value as 2*/
#define GAIN_DAC_CHANNEL_3_VALUE_1                         0<<3 /*DAC channel 3 gain value as 1*/

#define GAIN_DAC_CHANNEL_2_VALUE_2                         1<<2 /*DAC channel 2 gain value as 2*/
#define GAIN_DAC_CHANNEL_2_VALUE_1                         0<<2 /*DAC channel 2 gain value as 1*/

#define GAIN_DAC_CHANNEL_1_VALUE_2                         1<<1 /*DAC channel 1 gain value as 2*/
#define GAIN_DAC_CHANNEL_1_VALUE_1                         0<<1 /*DAC channel 1 gain value as 1*/

#define GAIN_DAC_CHANNEL_0_VALUE_2                         1<<0 /*DAC channel 0 gain value as 2*/
#define GAIN_DAC_CHANNEL_0_VALUE_1                         0<<0 /*DAC channel 0 gain value as 1*/

/*------------------------------------------TRIGGER REGISTER-------------------------------------------------*/
#define TRIGGER_LOAD_SYNCHRONOUS_VALUE_ON                  1<<4 /*enable trigger for the synchronous mode*/
#define TRIGGER_LOAD_SYNCHRONOUS_VALUE_OFF                 0<<4 /*disable trigger for the  asynchronous mode*/
#define SOFT_RESET_DAC_ON                                  0x0A /*do a soft reset*/
#define SOFT_RESET_DAC_OFF                                 0x00 /*turn off soft reset*/


/*------------------------------------------DAC CONFIGURATIONS---------------------------------------------------------*/
#define CONFIG_SYNC_REGISTER_VALUE \
	                (DAC7_BROADCAST_ENABLE | DAC6_BROADCAST_ENABLE| DAC5_BROADCAST_ENABLE | DAC4_BROADCAST_ENABLE \
                     |DAC3_BROADCAST_ENABLE | DAC2_BROADCAST_ENABLE | DAC1_BROADCAST_ENABLE| DAC0_BROADCAST_ENABLE \
                     |DAC7_SYNC_DISABLE | DAC6_SYNC_DISABLE | DAC5_SYNC_DISABLE | DAC4_SYNC_DISABLE| DAC3_SYNC_DISABLE \
					 | DAC2_SYNC_DISABLE |DAC1_SYNC_DISABLE | DAC0_SYNC_DISABLE)


#ifdef CRC_CHECK_DISABLE
#define CONFIG_CONFIG_REGISTER_VALUE \
	                (ALARM_PIN_REF_ALARM | CONFIG_ALARM_DISABLE | CONFIG_CRC_DISABLE | CONFIG_UPDATE_RISING_EDGE |CONFIG_ENABLE_SERIAL_OUT \
	                 |CONFIG_ENABLE_INTERNAL_REF	|CONFIG_DISABLE_MODE_POWERDOWN_DAC7 | CONFIG_DISABLE_MODE_POWERDOWN_DAC6\
					  |CONFIG_DISABLE_MODE_POWERDOWN_DAC5 | CONFIG_DISABLE_MODE_POWERDOWN_DAC4 | CONFIG_DISABLE_MODE_POWERDOWN_DAC3\
					  |CONFIG_DISABLE_MODE_POWERDOWN_DAC2 | CONFIG_DISABLE_MODE_POWERDOWN_DAC1 | CONFIG_DISABLE_MODE_POWERDOWN_DAC0)
#endif
#ifndef CRC_CHECK_DISABLE
#define CONFIG_CONFIG_REGISTER_VALUE \
	                (ALARM_PIN_REF_ALARM | CONFIG_ALARM_DISABLE |CONFIG_CRC_ENABLE | CONFIG_UPDATE_RISING_EDGE |CONFIG_ENABLE_SERIAL_OUT \
	                 |CONFIG_ENABLE_INTERNAL_REF	|CONFIG_DISABLE_MODE_POWERDOWN_DAC7 | CONFIG_DISABLE_MODE_POWERDOWN_DAC6\
					  |CONFIG_DISABLE_MODE_POWERDOWN_DAC5 | CONFIG_DISABLE_MODE_POWERDOWN_DAC4 | CONFIG_DISABLE_MODE_POWERDOWN_DAC3\
					  |CONFIG_DISABLE_MODE_POWERDOWN_DAC2 | CONFIG_DISABLE_MODE_POWERDOWN_DAC1 | CONFIG_DISABLE_MODE_POWERDOWN_DAC0)
#endif

#define CONFIG_GAIN_REGISTER_VALUE \
	                (GAIN_REG_DIV_INT_REF_0 | GAIN_DAC_CHANNEL_7_VALUE_2 | GAIN_DAC_CHANNEL_6_VALUE_2 | GAIN_DAC_CHANNEL_5_VALUE_2\
	                |GAIN_DAC_CHANNEL_4_VALUE_2 | GAIN_DAC_CHANNEL_3_VALUE_2	| GAIN_DAC_CHANNEL_2_VALUE_2 |GAIN_DAC_CHANNEL_1_VALUE_2\
				   | GAIN_DAC_CHANNEL_0_VALUE_2)

#define CONFIG_TRIGGER_REGISTER_VALUE \
	                (TRIGGER_LOAD_SYNCHRONOUS_VALUE_OFF | SOFT_RESET_DAC_OFF )


/*STRUCTURE FOR THE SPI CONFIG FOR THE DAC*/
typedef struct
{
	bool (* spi_transferData) (uint8_t *data , uint8_t size);
	bool (* spi_ReceiveData)  (uint8_t *data , uint8_t size);
	void (* enable_chipSelect) (void);
	void (* disable_chipSelect) (void);
}DAC8050x_CONFIG;

/**
  * @brief  function to Enable the chip select
  * @param  None
  * @retval None
  */
void enable_chipSelect(void);

/**
  * @brief  function to disable the chip select
  * @param  None
  * @retval None
  */
void disable_chipSelect(void);

/**
  * @brief  function to transmit data using SPI
  * @param  data : data to be transmitted
  * @retval return the transmission is success or not
  */
bool dac8050x_transmitData(uint8_t * data, uint8_t size);

/**
  * @brief  function to receive data using SPI
  * @param  data : data to be transmitted
  * @retval return the transmission is success or not
  */
bool dac8050x_receiveData(uint8_t * data, uint8_t size);

/**
  * @brief  function to write to the config register
  * @param  None
  * @retval return the transmission is success or not
  */
bool writeSyncRegister(void);

/**
  * @brief  function to write to the config register
  * @param  None
  * @retval return the transmission is success or not
  */
bool writeConfigRegister(void);

/**
  * @brief  function to write to the gain register
  * @param  None
  * @retval return the transmission is success or not
  */
bool writeGainRegister(void);

/**
  * @brief  function to read device ID
  * @param  None
  * @retval return the 16 bit device ID.
  */
/*function will return both device ID and version ID first two bit is version ID (LSB)*/
uint16_t dac8050x_readDeviceID(void);

/**
  * @brief  function to read sync register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readSyncRegister(void);

/**
  * @brief  function to read configuration register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readConfigRegister(void);

/**
  * @brief  function to read Gain register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readGainRegister(void);

/**
  * @brief  function to read broadcast register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readBroadcastRegister(void);

/**
  * @brief  function to read status register
  * @param  None
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readStatusRegister(void);

/**
  * @brief  function to read DAC channel value
  * @param  channelNo : DAC channel number to get the value
  * @retval return the 16 bit register value
  */
uint16_t dac8050x_readDacRegValue(uint8_t channelNo);

/**
  * @brief  function to read the register
  * @param  None
  * @retval return the 16 bit data from the corresponding register
  */
uint16_t dac8050x_readRegister(uint8_t * data);

/**
  * @brief  function to write the register
  * @param  None
  * @retval return the 16 bit data from the corresponding register
  */
/*the input parameter should contain the write command + address of the register + the data need to be written to the register*/
bool dac8050x_writeRegister(uint8_t * data);

/**
  * @brief  function to get the CRC value
  * @param  data : data to calculate the CRC
  * @param  len  : length of the data
  * @retval return the 8 bit CRC value
  */
uint8_t crc8_atm(uint8_t *data, size_t len);




#endif /* BSP_DAC8050X_DAC8050X_H_ */
