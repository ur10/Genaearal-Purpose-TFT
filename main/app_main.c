#include"string.h"
#include"stdlib.h"

//#include"wav.h"
#include"device_config.h"
 #include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include "freertos/queue.h"
//esp_err_t device_tx(char *data);

typedef struct app_main
{
    /* data */
   int key;
   int modulo;
}a;

 char* buf="HERE GOES NOTHING\n";
 void app_main()
{
    a arr[10];
    
    esp_err_t res;
   res=device_init();
   if(res!=ESP_OK)
   printf("Error in initializing");
   else
   {
       printf("initialiization done");
   }
   
    // device_tx(&buf[0]);

    while(1)
   {
       for(int i=0;i<strlen(buf);i++)
       device_tx(&buf[i]);
   }      
}
 /* esp_err_t device_tx(char *data)
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
}*/