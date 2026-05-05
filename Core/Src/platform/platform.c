/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"
#include "main.h"
//#include "lab1_gpio/lab1_gpio.h"
//#include "lab2_timer/lab2_timer.h"
#include "lab3_stepper/lab3_stepper.h"
//#include "lab4_adc/lab4_adc.h"

// extern UART_HandleTypeDef huart1;

/* Глобальные переменные */
int direction = 1;
int step_counter = 0;
int steps_per_rotation = 8;

/* Однократный вызов */
int plt_init(void)
{
    return 0;
}

/* Повторяющийся вызов */
void plt_process(void)
{
    plt_stepper(direction);

    /* Устанавливаем задержку */
    plt_delay(500);

    step_counter++;

    if (step_counter >= steps_per_rotation) {
        direction = -direction;
        step_counter = 0;
    }
}

/* Функция задержки - перенести в main.c в user code или раскомментировать здесь */
//void plt_delay(uint32_t delay_ms)
//{
 //   HAL_Delay(delay_ms);
//}
