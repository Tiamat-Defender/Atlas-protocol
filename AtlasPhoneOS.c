#include "pico/stdlib.h"
#include "lcd.h"

#include "FreeRTOS.h"
#include "task.h"


#define PIN 0

void LCD_STARTUP() {
    // Initialize I2C and LCD
    lcd_init();
    //animation for startup will say atlas os then switch to code for a better future
    lcd_set_cursor(0, 4);
    lcd_string("ATLAS OS");
    sleep_ms(2000);
    lcd_clear();
    lcd_set_cursor(0, 3);
    lcd_string("Code for a");
    lcd_set_cursor(1, 1);
    lcd_string("Better future.");
}


void vMainMenu() {
    lcd_clear();
    lcd_set_cursor(0, 0);
    lcd_string("NO NEW MESSAGES.");
    lcd_set_cursor(1 ,0);
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

    LCD_STARTUP();

    vMainMenu();

    xTaskCreate(vBlinkTask, "Blink Task", 128, NULL, 1, NULL);
    vTaskStartScheduler();

}
