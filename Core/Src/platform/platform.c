/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"
#include "main.h"
//#include "lab1_gpio/lab1_gpio.h"
//#include "lab2_timer/lab2_timer.h"
//#include "lab3_stepper/lab3_stepper.h"
#include "lab4_adc/lab4_adc.h"
extern UART_HandleTypeDef huart1;
/* Однократный вызов */
int plt_init(void)
{

	return 0;
}


/* Повторяющийся вызов */
void plt_process(void)
{
	float voltage;

    plt_adc_start();

    if (plt_adc_conversion_poll() == PLT_OK)
    {
        voltage = plt_adc_get_voltage();

        if (voltage > 3.0f)
        {
            HAL_GPIO_WritePin(
                USER_LED_GPIO_Port,
                USER_LED_Pin,
                GPIO_PIN_SET);
        }
        else
        {
            HAL_GPIO_WritePin(
                USER_LED_GPIO_Port,
                USER_LED_Pin,
                GPIO_PIN_RESET);
        }
    }

    plt_adc_stop();

    plt_delay(100);
}

/* Перенести в main.c в user code */
//void plt_delay(uint32_t delay_ms)
//{
//	HAL_Delay(delay_ms);
//}
