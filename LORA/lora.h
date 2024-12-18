#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string.h>

#define DEFBAUD 115200

uint8_t index = 0;

uint8_t INIT_LORA(uint8_t TX, uint8_t RX, uint8_t UART_TYPE)
{
    char buff[3];

    gpio_set_function(TX, GPIO_FUNC_UART);
    gpio_set_function(RX, GPIO_FUNC_UART);

    if (UART_TYPE == 0)
    {
        uart_init(uart0, DEFBAUD);
        uart_puts(uart0, "AT");

        while (true)
        {

            if (uart_is_readable(uart0))
            { 
                    buff[index] = uart_getc(uart0);
                    index ++;
                    
                    if(index >= 4)
                    {

                        if(strcmp(buff, "+ok"))return 0;
                        else return 1;
                    }
                
            }
        }
    }else return 1;
    

}

uint8_t LORA_SEND()
{
    uart_puts(uart0, "AT+SEND=%i,%i,%i,%i");
}

uint8_t LORA_READ()
{
    uart_puts(uart0, "AT+SEND=%i,%i,%i,%i");


}

uint8_t LORA_GET_UID()
{
    uart_puts(uart0, "AT+SEND=%i,%i,%i,%i");
}

uint8_t LORA_SET_MODE()
{
    uart_puts(uart0, "AT+SEND=%i,%i,%i,%i");

}

uint8_t LORA_SET_PARAMS()
{
    uart_puts(uart0, "AT+SEND=%i,%i,%i,%i");

}

uint8_t LORA_SETA_ADDR()
{
    uart_puts(uart0, "AT+SEND=%i,%i,%i,%i");

}

uint8_t LORA_SET_NET_ID()
{
    uart_puts(uart0, "AT+SEND=%i,%i,%i,%i");

}

uint8_t LORA_FACTORY_RESET()
{
    uart_puts(uart0, "AT+SEND=%i,%i,%i,%i");

}


