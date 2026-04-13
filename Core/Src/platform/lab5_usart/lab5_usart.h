#ifndef SRC_PLATFORM_LAB5_USART_LAB5_USART_H_
#define SRC_PLATFORM_LAB5_USART_LAB5_USART_H_

#include <stdint.h>

void plt_uart_init(void);
void plt_uart_send(const char* data);
void plt_uart_print(const char* format, ...);

#endif
