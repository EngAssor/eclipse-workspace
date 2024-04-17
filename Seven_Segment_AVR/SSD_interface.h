#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_COMMON_CATHODE 0
#define SSD_COMMON_ANOD    1

// 7 segment values
#define ZERO  0x3f
#define ONE   0x06
#define TWO   0x5b
#define THREE 0x4f
#define FOUR  0x66
#define FIVE  0x6d
#define SIX   0x7d
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE  0x67

typedef struct 
{
    /* data */
    u8 Type         ;
    u8 Data_Port    ;
    u8 Enable_Port  ;
    u8 Enable_Pin   ;
}SSD_Type;


void SSD_voidInit(SSD_Type Copy_structSSD_Config);
void SSD_voidSendNumber(SSD_Type Copy_structSSD_Config,u8 Copy_u8Number);
void SSD_voidEnable    (SSD_Type Copy_structSSD_Config);
void SSD_voidDisable   (SSD_Type Copy_structSSD_Config);


#endif
