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

void gui_draw_line(uint16_t xStart,uint16_t yStart,uint16_t xEnd,uint16_t yEnd,uint16_t color)
{
    lcd_set_cursor(xStart,yStart);
    uint16_t xDelta=xEnd-xStart;
    uint16_t yDelta=yEnd-yStart;
      if(yDelta>0&&xDelta>0)
      {
         uint16_t xPos=xStart;
         uint16_t yPos=yStart;
         while(xPos!=xEnd && yPos!=yEnd)
         {
           xPos += xDelta;
           yPos -= yDelta;
            
           gui_draw_point(xPos,yPos,color);
         }       
      }   
      else if(yDelta<0&&xDelta>0)
      {
        /*Second quadrant */
         uint16_t xPos=xStart;
         uint16_t yPos=yStart;
         while(xPos!=xEnd && yPos!=yEnd)
         {
           xPos -= xDelta;
           yPos -= yDelta;
            
           gui_draw_point(xPos,yPos,color);
         }
      }
      else if(yDelta<0&&xDelta<0)
      {
        /*Third qaudrant */
      uint16_t xPos=xStart;
         uint16_t yPos=yStart;
         while(xPos!=xEnd && yPos!=yEnd)
         {
           xPos -= xDelta;
           yPos += yDelta;
            
           gui_draw_point(xPos,yPos,color);
         }
      }
      else if(yDelta>0&& xDelta<0)
      {
        /*Fourth quadrant */
        uint16_t xPos=xStart;
         uint16_t yPos=yStart;
         while(xPos!=xEnd && yPos!=yEnd)
         {
           xPos += xDelta;
           yPos += yDelta;
            
           gui_draw_point(xPos,yPos,color);
         }
      }
}




