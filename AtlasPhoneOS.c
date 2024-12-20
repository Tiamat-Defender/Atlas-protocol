#include "pico/stdlib.h"
#include "lcd.h"

#include "FreeRTOS.h"
#include "task.h"

#define PIN 0

void vBlinkTask() {
    for (;;) {
        gpio_put(PIN, 1);
        vTaskDelay(250);
        gpio_put(PIN, 0);
        vTaskDelay(250);
    }
}

void main() {

    LCD_INIT();

    gpio_init(PIN);
    gpio_set_dir(PIN, GPIO_OUT);
    xTaskCreate(vBlinkTask, "Blink Task", 128, NULL, 1, NULL);
    vTaskStartScheduler();
}