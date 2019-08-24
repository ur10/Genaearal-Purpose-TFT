#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "soc/gpio_periph.h"
#include "driver/gpio.h"
#include "device_config.h"

static const char* TAG ="SPI";

esp_err_t device_init()
{
    esp_err_t res;
     //spi bus configuration
    spi_bus_config_t bus_config;
    bus_config.flags =SPICOMMON_BUSFLAG_MISO|SPICOMMON_BUSFLAG_MOSI|SPICOMMON_BUSFLAG_SCLK;
    bus_config.max_transfer_sz=0;
    bus_config.miso_io_num=MISO;
    bus_config.mosi_io_num=MOSI;
    bus_config.sclk_io_num=CLK;
    bus_config.max_transfer_sz=0;
    bus_config.quadhd_io_num=-1;
    bus_config.quadwp_io_num=-1;
  
    ESP_LOGI(TAG,"Initializing SPI bus ...\n");
        
    res=spi_bus_initialize(HSPI_HOST,&bus_config,1)   ;
 
    if (res==ESP_OK)
          ESP_LOGI(TAG,"Bus initialized successfullly!!\n");
    else
    {       ESP_LOGI(TAG,"Error in intialization of bus with error =%d\n",res);
           return ESP_ERR_INVALID_ARG;
    }
    
      //device configurations
      spi_device_interface_config_t spi_config;
      spi_config.address_bits=0;
      spi_config.clock_speed_hz=SPI_MASTER_FREQ_10M;
      spi_config.command_bits=0;
      spi_config.cs_ena_posttrans=0;
      spi_config.cs_ena_pretrans=0;
      spi_config.dummy_bits=0;
      spi_config.duty_cycle_pos=0;
      spi_config.flags=SPI_DEVICE_NO_DUMMY;
      spi_config.input_delay_ns=0;
      spi_config.mode=0;
      spi_config.post_cb=NULL;
      spi_config.pre_cb=NULL;
      spi_config.queue_size=1;
      spi_config.spics_io_num=-1;
 //spi_bus_add_device(sp SPI, const spi_device_interface_config_t *dev_config, spi_device_handle_t *handle);
   spi_bus_add_device(SPI,&spi_config,NULL);
   return ESP_OK;
}


 esp_err_t device_tx(char *data)
{
      esp_err_t res;
      //tranasaction details

      spi_transaction_t trans_desc_t;      
      
      trans_desc_t.length= 8; //single byte data transfer
      trans_desc_t.tx_buffer=data;
      trans_desc_t.rxlength=0;
      trans_desc_t.rx_buffer=data;
      trans_desc_t.flags=0;
      
      res=spi_device_transmit(NULL,&trans_desc_t);

      if(res!=ESP_OK)
      {
            ESP_LOGI(TAG,"error transmitting data\n");
             return ESP_ERR_INVALID_ARG;
      }
     return ESP_OK;
}