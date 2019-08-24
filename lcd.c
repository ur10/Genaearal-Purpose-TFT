#include <stdlib.h>
#include <string.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "i2s.h"
#include "soc/gpio_periph.h"
#include "gpio.h"
#include "lcd.h"

lcd_para_t lcd_para;


/* helper functions for difernet lcd operations*/
 //clearing various lcd pins 
void write_data(uint16_t data)
{
   /* TODO */
}

void lcd_cs_clr(void)
{
   gpio_set_direction(LCD_CS_PIN,GPIO_MODE_OUTPUT_OD);
   gpio_set_level(LCD_CS_PIN,0);
}

void lcd_rst_clr(void)
{
   gpio_set_direction(LCD_RST_PIN,GPIO_MODE_OUTPUT_OD);
   gpio_set_level(LCD_RST_PIN,0);
}

void lcd_rd_clr(void)
{
   gpio_set_direction(LCD_RD_PIN,GPIO_MODE_OUTPUT_OD);
   gpio_set_level(LCD_RD_PIN,0);
}

void lcd_rs_clr(void)
{
   gpio_set_direction(LCD_RS_PIN,GPIO_MODE_OUTPUT_OD);
   gpio_set_level(LCD_RS_PIN,0);
}

 //setting the bits

 void lcd_cs_set(void)
{
   gpio_set_direction(LCD_CS_PIN,GPIO_MODE_OUTPUT_OD);
   gpio_set_level(LCD_CS_PIN,1);
}

 void lcd_rst_set(void)
{
   gpio_set_direction(LCD_RST_PIN,GPIO_MODE_OUTPUT_OD);
   gpio_set_level(LCD_RST_PIN,1);
}
 void lcd_rd_set(void)
{
   gpio_set_direction(LCD_RD_PIN,GPIO_MODE_OUTPUT_OD);
   gpio_set_level(LCD_RD_PIN,1);
}

 void lcd_rs_set(void)
{
   gpio_set_direction(LCD_RS_PIN,GPIO_MODE_OUTPUT_OD);
   gpio_set_level(LCD_RS_PIN,1);
}

void lcd_reset(void)
{
   lcd_rs_clr();
   vTaskDelay(pdMS_TO_TICKS(100));
   lcd_rs_set();
   vTaskDelay(pdMS_TO_TICKS(50));
}
/* WRITING DATA AND SENDING COMMAND APIs */
//helper function
void lcd_write_data_helper(uint16_t data)
{
   lcd_cs_clr();
   write_data(data);
   lcd_cs_set();
   
}
 
 // Write to a register
void lcd_WR_reg(uint16_t data)
{
	lcd_cs_clr();
   lcd_rs_clr();
   lcd_write_data_helper(data<<8);
   
}

// Write an 8-bit data
void lcd_WR_data(uint16_t data)
{
   lcd_rs_set();
   lcd_write_data_helper(data<<8);
}

void lcd_WR_data_16bit(uint16_t data)
{
   lcd_rs_set();
   lcd_cs_clr();
   write_data(data<<8);
   write_data(data);
   lcd_cs_clr();
   lcd_rs_clr();
}

//Write data to a reg

void lcd_WR_reg_data(uint16_t reg,uint16_t reg_val)
{
   lcd_WR_data(reg);
   lcd_WR_data(reg_val);
}

// init for writing data to the RAM

void lcd_Write_RAM_init(void)
{
   lcd_WR_reg(lcd_para.wramcmd);    
}

//setting up lcd orientation
void lcd_direction(uint8_t direction)
{
   lcd_para.setxcmd = 0x2A;
   lcd_para.setycmd = 0x2B;
   lcd_para.wramcmd = 0x2C;
   lcd_para.rramcmd = 0x2D;
   lcd_para.width =   LCD_W;
   lcd_para.height=   LCD_H;
}

             /*LCD  INITIALIZATION */
void lcd_init(void)
{
   lcd_reset();
   /*for ili9386 */
   lcd_WR_reg(0XF1);
	lcd_WR_data(0x36);
	lcd_WR_data(0x04);
	lcd_WR_data(0x00);
	lcd_WR_data(0x3C);
	lcd_WR_data(0X0F);
	lcd_WR_data(0x8F);
	lcd_WR_reg(0XF2);
	lcd_WR_data(0x18);
	lcd_WR_data(0xA3);
	lcd_WR_data(0x12);
	lcd_WR_data(0x02);
	lcd_WR_data(0XB2);
	lcd_WR_data(0x12);
	lcd_WR_data(0xFF);
	lcd_WR_data(0x10);
	lcd_WR_data(0x00);
	lcd_WR_reg(0XF8);
	lcd_WR_data(0x21);
	lcd_WR_data(0x04);
	lcd_WR_reg(0XF9);
	lcd_WR_data(0x00);
	lcd_WR_data(0x08);
	lcd_WR_reg(0x36);
	lcd_WR_data(0x08);
	lcd_WR_reg(0xB4);
	lcd_WR_data(0x00);
	lcd_WR_reg(0xC1);
	lcd_WR_data(0x41);
	lcd_WR_reg(0xC5);
	lcd_WR_data(0x00);
	lcd_WR_data(0x91);
	lcd_WR_data(0x80);
	lcd_WR_data(0x00);
	lcd_WR_reg(0xE0);
	lcd_WR_data(0x0F);
	lcd_WR_data(0x1F);
	lcd_WR_data(0x1C);
	lcd_WR_data(0x0C);
	lcd_WR_data(0x0F);
	lcd_WR_data(0x08);
	lcd_WR_data(0x48);
	lcd_WR_data(0x98);
	lcd_WR_data(0x37);
	lcd_WR_data(0x0A);
	lcd_WR_data(0x13);
	lcd_WR_data(0x04);
	lcd_WR_data(0x11);
	lcd_WR_data(0x0D);
	lcd_WR_data(0x00);
	lcd_WR_reg(0xE1);
	lcd_WR_data(0x0F);
	lcd_WR_data(0x32);
	lcd_WR_data(0x2E);
	lcd_WR_data(0x0B);
	lcd_WR_data(0x0D);
	lcd_WR_data(0x05);
	lcd_WR_data(0x47);
	lcd_WR_data(0x75);
	lcd_WR_data(0x37);
	lcd_WR_data(0x06);
	lcd_WR_data(0x10);
	lcd_WR_data(0x03);
	lcd_WR_data(0x24);
	lcd_WR_data(0x20);
	lcd_WR_data(0x00);
	lcd_WR_reg(0x3A);
	lcd_WR_data(0x55);
	lcd_WR_reg(0x11);
	lcd_WR_reg(0x36);
	lcd_WR_data(0x28);
	vTaskDelay(pdMS_TO_TICKS(100));
	lcd_WR_reg(0x29);

   lcd_direction(1);
}


// Setting up the area to be written

void lcd_set_windows(uint16_t xStart, uint16_t yStart , uint16_t xEnd,uint16_t yEnd)
{
   lcd_WR_reg(lcd_para.setxcmd);
   
   lcd_WR_data(xStart>>8);
   lcd_WR_data(xStart &0x00FF);
    
   lcd__WR_data(xEnd>>8);
   lcd_WR_data(xEnd);
   
   lcd_WR_data(yStart>>8);
   lcd_WR_data(yStart &0x00FF);
    
   lcd__WR_data(yEnd>>8);
   lcd_WR_data(yEnd&0x00FF);
   
   lcd_Write_RAM_init();
}

//clear the lcd 
void lcd_clear(uint16_t color)
{
 lcd_set_windows(0 , 0 , lcd_para.width-1 , lcd_para.height-1);

 for(int i=0;i<lcd_para.width*lcd_para.height-1;i++)
 {
    lcd_WR_data_16bit(color);
 }

}

//Positioning the cursor 
void lcd_set_cursor(uint16_t xPos,uint16_t yPos)
{
   lcd_set_windows(xPos,yPos,xPos,yPos);
}

// Drawing a point
void lcd_draw_point(uint16_t xpos,uint16_t ypos,uint16_t color)
{
   lcd_set_cursor(xpos,ypos);
    lcd_WR_data_16bit(color);
}

