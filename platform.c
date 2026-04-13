#include "platform.h"
#include "main.h"
#include "lab5_usart.h"
#include <stdio.h>

int plt_init(void)
{
    plt_uart_init();
    return 0;
}

void plt_process(void)
{
    static uint32_t counter = 0;
    counter++;
    plt_uart_print("Tick: %lu\r\n", counter);
    plt_uart_print("Value: %lu\r\n", counter * 10);
    plt_uart_print("Square: %lu\r\n", counter * counter);
    HAL_Delay(1000);
}
