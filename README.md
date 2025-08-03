# DAC80508 SPI Driver (Texas Instruments)

A lightweight and portable C driver for the **Texas Instruments DAC80508** (DAC8050x series) 16-bit SPI digital-to-analog converter.

This driver is written to be **platform-agnostic**, with minimal dependencies, so it can be easily adapted to **any microcontroller platform** (e.g., STM32, ESP32, NXP, etc.) by modifying only a few low-level SPI and GPIO functions.

---

## ✅ Features

- SPI communication with DAC80508
- Set DAC output voltage
- Clean register definitions
- Designed for portability
- Easy to integrate into embedded projects

---

## 📁 File Structure
├── dac8050x.c # Driver implementation

├── dac8050x.h # Driver header

└── README.md # This file
---

## 🚀 Getting Started

### 1. Clone this repo
```bash
git clone https://github.com/lincechacko/DAC8050x.git

2. Add files to your firmware project
dac8050x.c

dac8050x.h

3. Modify platform-specific functions
Edit the following functions in dac8050x.c to suit your MCU's GPIO and SPI APIs.

🔧 Platform-Specific Functions
These are the only parts that need to be modified to port this driver to a different microcontroller:

/**
  * @brief  Function to enable Chip Select (CS)
  * @note   Modify this function to match your microcontroller's GPIO control
  */
#warning change this function according to your controller function
void enable_chipSelect(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET); // Example: STM32 HAL
}

/**
  * @brief  Function to disable Chip Select (CS)
  */
#warning change this function according to your controller function
void disable_chipSelect(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET); // Example: STM32 HAL
}

/**
  * @brief  Transmit data over SPI
  */
#warning change this function according to your controller function
bool dac8050x_transmitData(uint8_t * data, uint8_t size)
{
   	HAL_StatusTypeDef status = HAL_OK;
   	HAL_SPI_Transmit(&hspi1, data, size, 1000);
   	if(status == HAL_OK) return (true);
   	else return (false);
}

/**
  * @brief  Receive data over SPI
  */
#warning change this function according to your controller function
bool dac8050x_receiveData(uint8_t * data, uint8_t size)
{
   	HAL_StatusTypeDef status = HAL_OK;
   	status = HAL_SPI_Receive(&hspi1, data, size, 1000);
   	if(status == HAL_OK) return (true);
   	else return (false);
}


📘 Datasheet
TI DAC8050x Product Page
