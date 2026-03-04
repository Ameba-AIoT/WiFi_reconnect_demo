#include "WiFi_reconnect_demo.h"

void app_example(void)
{
    RTK_LOGI(TAG, "Customize wifi reconnect demo start!\r\n");    
    gpio_led_init();
    if (rtos_task_create( NULL, "WiFi_reconnect_demo", (rtos_task_t)WiFi_connect_demo_task, NULL, 2048, tskIDLE_PRIORITY) != RTK_SUCCESS )
    {
        RTK_LOGE(TAG, "WiFi_reconnect_demo failed!\r\n");        
    }   
}
    