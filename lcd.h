#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "i2s.h"
#include "soc/gpio_periph.h"
#include "gpio.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_intr_alloc.h"
#include "main/device_config.h"

#define LCD_ID          0x9328   
#define LCD_H            320
#define LCD_W            280
/*values of various color to be displayed */
#define WHITE           0xFFFF
#define BLACK      	    0x0000	  
#define BLUE         	0x001F  
#define BRED            0XF81F
#define GRED 			0XFFE0
#define GBLUE	      	0X07FF
#define RED             0xF800
#define MAGENTA         0xF81F
#define GREEN           0x07E0
#define CYAN            0x7FFF
#define YELLOW          0xFFE0
#define BROWN 			0XBC40 
#define BRRED 			0XFC07 
#define GRAY  			0X8430
#define DARKBLUE      	0X01CF	
#define LIGHTBLUE      	0X7D7C	 
#define GRAYBLUE       	0X5458 
#define LIGHTGREEN     	0X841F 
#define LIGHTGRAY       0XEF5B 
#define LGRAY 			0XC618 
#define LGRAYBLUE      	0XA651 
#define LBBLUE          0X2B12 


typedef struct 
{
   uint16_t width;
   uint16_t height;
   uint8_t dir;
   uint16_t wramcmd;
   uint16_t rramcmd;
   uint16_t setxcmd;
   uint16_t setycmd;

}lcd_para_t;


/* */
void send_parallel_data(uint8_t data);

void lcd_init(void);

void lcd_WR_data(uint8_t data);

void lcd_WR_data_16bit(uint16_t data);

void lcd_WR_reg(uint16_t data);

void lcd_WR_reg_data(uint16_t reg, uint16_t reg_value);

void lcd_direction(uint8_t direction);

void lcd_Write_RAM_init(void);

void lcd_set_windows(uint16_t xStart, uint16_t yStart , uint16_t xEnd,uint16_t yEnd);

void lcd_set_cursor(uint16_t xPos,uint16_t yPos);

void lcd_clear(uint16_t color);
