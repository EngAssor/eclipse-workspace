/*
author : Asser Tantwy 

date : 30/10/2023

*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidInit(LED_Type LED_Config )
{
      DIO_enumSetPINDirection(LED_Config.Port,LED_Config.Pin,DIO_OUTPUT);


}
void LED_voidOn  (LED_Type LED_Config )
{
    if(LED_Config.Active_State == ACTIVE_HIGH)
    {
      
      DIO_enumSetPINValue    (LED_Config.Port,LED_Config.Pin, DIO_HIGH);

    }
    else if(LED_Config.Active_State == ACTIVE_LOW)
    {

           DIO_enumSetPINValue    (LED_Config.Port,LED_Config.Pin, DIO_LOW);

    }
}
void LED_voidOff (LED_Type LED_Config )
{
     if(LED_Config.Active_State == ACTIVE_HIGH)
    {
      
      DIO_enumSetPINValue    (LED_Config.Port,LED_Config.Pin, DIO_LOW);

    }
     else if(LED_Config.Active_State == ACTIVE_LOW)
    {

           DIO_enumSetPINValue    (LED_Config.Port,LED_Config.Pin, DIO_HIGH);

    }

}
