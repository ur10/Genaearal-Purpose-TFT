
#include <string.h>
#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "freertos/queue.h"
//#include "i2s.h"

#include "soc/gpio_periph.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_intr_alloc.h"
#include"driver/spi_master.h"
#include "driver/spi_common.h"


#define SPI                  HSPI_HOST
#define SPI1                 VSPI_HOST
#define MISO                 GPIO_NUM_12    
#define MOSI                 GPIO_NUM_13
#define CLK                  GPIO_NUM_14
#define CS                   GPIO_NUM_15

//#define LCD_RST_PIN          GPIO_NUM_13 //  RESET PIN
//#define LCD_CS_PIN           GPIO_NUM_14 //  CHIP SELECT PIN (ACTIVE LOW)
//#define LCD_RS_PIN           GPIO_NUM_15 //  REGISTER SELECT PIN (COMMAND OR DATA MODE)
//#define LCD_RD_PIN           GPIO_NUM_16 

esp_err_t pin_init();

esp_err_t device_init();

esp_err_t device_tx(char *data);
