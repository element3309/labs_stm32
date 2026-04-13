/* Директива препроцессора для подключения заголовочного файла */
#include "lab4_adc.h"

/* Подключение заголовочного файла с определениями, перечислениями и макросами */
#include "../platform_def.h"

/* Подключение заголовочного файла main.h
 * main.h в свою очередь подключает _hal.h" - файл
 * необходимый для работы с периферией МК stm32 */
#include "main.h"

/* объявление внешней переменной */
extern ADC_HandleTypeDef hadc3;

#include <stdio.h>

#define tV_25   0.76f      // Напряжение (в вольтах) на датчике при температуре 25 °C.
#define tSlope  0.0025f    // Изменение напряжения (в вольтах) при изменении температуры на градус.
#define Vref    3.3f       // Образцовое напряжение АЦП (в вольтах).

void plt_adc_start(void)
{
    HAL_ADC_Start(&hadc3);
}

void plt_adc_stop(void)
{
    HAL_ADC_Stop(&hadc3);
}

int plt_adc_conversion_poll(void)
{
    if(HAL_ADC_PollForConversion(&hadc3, 100) == HAL_OK)
        return PLT_OK;
    else
        return PLT_ERROR;
}

uint32_t plt_adc_get_value(void)
{
    return HAL_ADC_GetValue(&hadc3);
}

float plt_adc_get_voltage(void)
{
    uint32_t adc_value = plt_adc_get_value();
    float voltage = (adc_value * Vref) / 4095.0f;
    return voltage;
}

float plt_adc_get_temperature(void)
{
    float voltage = plt_adc_get_voltage();
    float temperature = (voltage - tV_25) / tSlope + 25.0f;
    return temperature;
}
