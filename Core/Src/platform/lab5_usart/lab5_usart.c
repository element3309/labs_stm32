#include "lab5_usart.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

extern UART_HandleTypeDef huart1;
char uart_buffer[256];

void plt_uart_init(void)
{
    plt_uart_send("USART Ready!\r\n");
}

void plt_uart_send(const char* data)
{
    HAL_UART_Transmit(&huart1, (uint8_t*)data, strlen(data), HAL_MAX_DELAY);
}

void plt_uart_print(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vsnprintf(uart_buffer, sizeof(uart_buffer), format, args);
    va_end(args);
    plt_uart_send(uart_buffer);
}
