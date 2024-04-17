/*
 * main.c

 *
 *  Created on: Apr 10, 2021
 *      Author: pc1
 */
#include "LIB/typ.h"
#include "DIO_interface.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
void Blink_200ms(void *pvParameters)
{
	DIO_VidSetPinDir(DIO_PIN0,DIO_PORTD,DIO_OUTPUT);
	while(1)
	{
	TogelpinVal(DIO_PORTD,DIO_PIN0);
	vTaskDelay(200);
	}
}

void Blink_1000ms(void *pvParameters)
{
DIO_VidSetPinDir(DIO_PIN1,DIO_PORTD,DIO_OUTPUT);
while(1)
{
TogelpinVal(DIO_PORTD,DIO_PIN1);
vTaskDelay(1000);
}
}

int main ()
{
xTaskCreate(Blink_200ms,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
xTaskCreate(Blink_1000ms,NULL,configMINIMAL_STACK_SIZE,NULL,2,NULL);

vTaskStartScheduler();
}
