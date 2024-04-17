
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"
void SW_voidInit(SW_Type SW_Config)
{
    DIO_enumSetPINDirection(SW_Config.Port, SW_Config.Pin, DIO_INPUT);
    if (SW_Config.Pull_State == SW_PULL_UP)
    {
        DIO_enumSetPINValue(SW_Config.Port, SW_Config.Pin, DIO_HIGH);
    }
    else 
    {
        DIO_enumSetPINValue(SW_Config.Port, SW_Config.Pin, DIO_LOW);
    }
}
u8 SW_u8GetPressed(SW_Type SW_Config)
{
    u8 LOC_u8Result = 0;
    DIO_enumGetPINValue     (SW_Config.Port,SW_Config.Pin, &LOC_u8Result  );

    return LOC_u8Result;
}
