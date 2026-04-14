#include "platform.h"
#include "lab5_usart.h"

int plt_init(void)
{
    plt_uart_init();
    return 0;
}

void plt_process(void)
{
    // nothing is here
}
