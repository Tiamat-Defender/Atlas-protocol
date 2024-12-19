#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

void vBlinkTask() {
    for (;;) {
        gpio_put(25, 1);
        vTaskDelay(250);
        gpio_put(25, 0);
        vTaskDelay(250);
    }
}

void main() {
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
    xTaskCreate(vBlinkTask, "Blink Task", 128, NULL, 1, NULL);
    vTaskStartScheduler();
}