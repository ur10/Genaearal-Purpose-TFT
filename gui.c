#include "gui.h"
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
#include "lcd.h"

void gui_draw_point(uint16_t xStart,uint16_t yStart,uint16_t color)
{
  lcd_set_cursor(xStart,yStart) ;
  lcd_WR_data_16bit(color);
}

void gui_draw_line(uint16_t xStart,uint16_t yStart,uint16_t xEnd,uint16_t yEnd)
{
    lcd_set_cursor(xStart,yStart);
    uint16_t x_delta=xEnd-xStart;
    uint16_t y_delta=yEnd-yStart;
      if(y_delta>0&&x_delta>0)
      {
        /*first quadrant */
      }   
      else if(y_delta<0&&x_delta>0)
      {
        /*Second quadrant */
      }
      else if(y_delta<0&&x_delta<0)
      {
        /*Third qaudrant */
      }
      else if(y_delta>0&& x_delta<0)
      {
        /*Fourth quadrant */
      }
}




