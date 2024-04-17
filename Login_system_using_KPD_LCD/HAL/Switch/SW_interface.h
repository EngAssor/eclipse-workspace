#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H

typedef struct 
{
    /* data */
    u8 Port       ;
    u8 Pin        ;
    u8 Pull_State ;
}SW_Type;

#define SW_PULL_UP    1
#define FLOATING   0


void SW_voidInit(SW_Type SW_Config);
u8 SW_u8GetPressed(SW_Type SW_Config);




#endif