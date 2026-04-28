/* Директива препроцессора для подключения заголовочного файла */
#include "platform.h"
//#include "lab1_gpio/lab1_gpio.h"
#include "lab3_stepper/lab3_stepper.h"
//#include "lab1_gpio.h"
//#include "lab2_timer/lab2_timer.h"
//#include "lab3_stepper/lab3_stepper.h"


/* Однократный вызов */
int plt_init(void)
{

	return 0;
}

int stp = 0;
/* Повторяющийся вызов */
void plt_process(void)
{
	//if (stp > 4) stp = 1;
	//plt_stepper_dir;
	//plt_stepper_full(stp);
	//stp++;
	/* Устанавливаем задержку */
	//plt_delay(10);
	plt_stepper(-1);
	plt_delay(15);
}


