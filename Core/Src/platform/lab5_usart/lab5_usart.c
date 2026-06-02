#include "lab5_usart.h"
#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

extern UART_HandleTypeDef huart1;

static char tx_buf[256];
static char rx_byte = 0;

volatile int uart_rx_flag = 0;

static void send_response(uint8_t code, const char *msg)
{
    plt_uart_print("\r\n[CODE: %u] %s\r\nWaiting input: ", code, msg);
}

void plt_uart_init(void)
{
    plt_uart_send("\r\n=== LED CONTROL ===\r\n");
    plt_uart_send("Enter 1 -> LED ON\r\n");
    plt_uart_send("Enter 0 -> LED OFF\r\n");
    plt_uart_send("==================\r\n");
    plt_uart_send("Waiting input: ");

    HAL_UART_Receive_IT(&huart1, (uint8_t*)&rx_byte, 1); /* перезапуск приема след байта*/
}

/* send строки по UART */
void plt_uart_send(const char *data)
{
    HAL_UART_Transmit(&huart1, (uint8_t*)data, strlen(data), HAL_MAX_DELAY);
}

/* отформатированный вывод */
void plt_uart_print(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vsnprintf(tx_buf, sizeof(tx_buf), format, args);
    va_end(args);
    plt_uart_send(tx_buf);
}

int plt_uart_is_available(void)
{
	return uart_rx_flag;
}

void plt_uart_proccess(void)
{
    if (!plt_uart_is_available())
    {
        return;
    }

    uart_rx_flag = 0;

    if (rx_byte != '\r' && rx_byte != '\n')
    {
        char echo[2] = { (char)rx_byte, '\0' };
        plt_uart_send(echo);
    }

    if (rx_byte == '1')
    {
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
        send_response(0U, "LED ON");
    }
    else if (rx_byte == '0')
    {
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
        send_response(0U, "LED OFF");
    }
    else if (rx_byte != '\r' && rx_byte != '\n')
    {
        send_response(1U, "Use only 1 or 0");
    }

    HAL_UART_Receive_IT(&huart1, &rx_byte, 1U);
}

/* колбэк при получении байта */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        uart_rx_flag = 1;
    }
}
