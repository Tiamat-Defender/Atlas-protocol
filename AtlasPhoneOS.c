#include "pico/stdlib.h"
#include "lcd.h"

#include "FreeRTOS.h"
#include "task.h"

#define PIN 0

void LCD_INIT_TASK() {
    // Initialize I2C and LCD
    lcdinit();
}

void vBlinkTask() {
    for (;;) {
        gpio_put(PIN, 1);
        vTaskDelay(250);
        gpio_put(PIN, 0);
        vTaskDelay(250);
    }
}

void main() {

    sleep_ms(1000);

    gpio_init(PIN);
    gpio_set_dir(PIN, GPIO_OUT);

    xTaskCreate(LCD_INIT_TASK, "LCD Init", 128, NULL, 1, NULL);

    xTaskCreate(vBlinkTask, "Blink Task", 128, NULL, 1, NULL);
    vTaskStartScheduler();

    return 0;
}
