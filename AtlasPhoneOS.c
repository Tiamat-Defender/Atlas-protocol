#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

void fun1()
{
    gpio_init(0);
    gpio_set_dir(0, GPIO_OUT);


    while (true)
    {
        gpio_put(0, 1);
        sleep_ms(100);
        gpio_put(0, 0);
        sleep_ms(100);          
    }
    

}

int main()
{
    stdio_init_all();

    TaskHandle_t task1 = NULL;

    uint32_t status = xTaskCreate(
                        fun1,
                        "task1",
                        1024,
                        NULL,
                        tskIDLE_PRIORITY,
                        &task1
    );

    vTaskStartScheduler();

    return 0;
}