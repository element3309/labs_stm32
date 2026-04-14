#ifndef LAB5_USART_H
#define LAB5_USART_H

void plt_uart_init(void);
void plt_uart_send(const char *data);
void plt_uart_print(const char *format, ...);

#endif
