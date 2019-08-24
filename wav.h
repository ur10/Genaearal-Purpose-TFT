#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "i2s.h"
#include "soc/gpio_periph.h"
#include "gpio.h"
#include "device_config.h"
#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "driver/sdspi_host.h"
#include "sdmmc_cmd.h"

typedef struct wav
{  //wav header
   char chunkId[4];
   int  chunkSize;
   char sriffType[4];
//sub chunk header
   char sGroupId[4];
   int  sChunkSize;
   short int sFormat;
   short int sChannels;
   int   samplePerSec;
   int   avgBytesPerSec;
   short int   wBlockAlign;
   int   BitsPerSample;

// sub data chunk
   char dataChunkId[4];
   int dataChunkSize; 
};
