 #include "main/device_config.h"
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

void gui_draw_point(uint16_t x,uint16_t y,uint16_t color);

void gui_draw_line(uint16_t xStart,uint16_t yStart,uint16_t xEnd,uint16_t yEnd,uint16_t color);
    