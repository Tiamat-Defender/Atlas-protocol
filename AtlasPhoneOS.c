#include <stdio.h>
#include "LORA/lora.h"
#include "pico/stdlib.h"

#define LORA_TX 0
#define LORA_RX 1
#define LORA_UART_NUMBER 0


int main()
{

    stdio_init_all();
    while (true) {
            printf("Hello, world!\n");
            sleep_ms(1000);
    }
}

    