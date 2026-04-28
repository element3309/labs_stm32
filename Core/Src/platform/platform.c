/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"

//#include "lab1_gpio/lab1_gpio.h"
//#include "lab2_timer/lab2_timer.h"
#include "lab3_stepper/lab3_stepper.h"


/* Однократный вызов */
int plt_init(void)
{

	return 0;
}

int step = 0;

/* Повторяющийся вызов */
void plt_process(void)
{
		plt_stepper(-1);
		plt_delay(15);

//		 plt_stepper_full(step);
//		 step = (step + 1) % 5;
//		 plt_delay(15);

	//plt_stepper_half(step);
	//step = (step + 1) % 8;
	//HAL_Delay(10);

//plt_stepper_full(step);
	/* Устанавливаем задержку */
	//plt_delay(500);
}

/* Перенести в main.c в user code (перенесено)*/
//void plt_delay(uint32_t delay_ms)
//{
//	HAL_Delay(delay_ms);
//}


