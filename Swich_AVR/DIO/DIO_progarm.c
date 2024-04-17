#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_interface.h"


 DIO_ErroStatus DIO_enumSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
 {
	 DIO_ErroStatus LOC_enumState=DIO_OK;
    switch(Copy_u8Port)
    {

        case DIO_PORTA : 
                        if(Copy_u8Direction == DIO_OUTPUT)
                           {
                                DDRA_REG =0xff; 
                           } 
                        else if(Copy_u8Direction == DIO_INPUT)
                          {  
                                DDRA_REG=0x00;
                          }
                          else
                          {
                            /**/
                        	  LOC_enumState=DIO_NOK;
                          }
                    break;
        case DIO_PORTB :
                        if(Copy_u8Direction == DIO_OUTPUT)
                            {
                                DDRB_REG =0xff; 
                            }
                        else if(Copy_u8Direction == DIO_INPUT)
                            {
                                DDRB_REG=0x00;
                            }
                            else
                            {
                                /**/
                          	  LOC_enumState=DIO_NOK;
                            }
                    break;
        case DIO_PORTC : 
                        if(Copy_u8Direction == DIO_OUTPUT)
                            {
                                DDRC_REG =0xff; 
                            }
                        else if (Copy_u8Direction == DIO_INPUT)
                            {
                                DDRC_REG=0x00;
                            }
                            else
                            {
                                /**/
                          	  LOC_enumState=DIO_NOK;
                            }
                    break;
        case DIO_PORTD : 
                        if(Copy_u8Direction == DIO_OUTPUT)
                            {
                                DDRD_REG =0xff; 
                            }
                        else if (Copy_u8Direction==DIO_INPUT)
                            {
                                DDRD_REG=0x00;
                            }
                            else
                            {
                                /**/
                          	  LOC_enumState=DIO_NOK;
                            }
                    break;

        default:
      	  LOC_enumState=DIO_NOK;

    }
return    LOC_enumState;
 }
 DIO_ErroStatus DIO_enumSetPortValue    (u8 Copy_u8Port, u8 Copy_u8Value    )
 {
	 DIO_ErroStatus LOC_enumState=DIO_OK;

     switch(Copy_u8Port)
    {
        case DIO_PORTA : 
                        if( Copy_u8Value >=0 && Copy_u8Value <= 0xff)
                           {
                                PORTA_REG =Copy_u8Value;
                           }

                          else
                          {
                            /**/
                         	  LOC_enumState=DIO_NOK;
                          }
                    break;
        case DIO_PORTB :
        	  if( Copy_u8Value >=0 && Copy_u8Value <= 0xff)
        	                           {
        	                                PORTB_REG =Copy_u8Value;
        	                           }

        	                          else
        	                          {
        	                            /**/
        	                         	  LOC_enumState=DIO_NOK;
        	                          }
        	                    break;
        case DIO_PORTC : 
        	  if( Copy_u8Value >=0 && Copy_u8Value <= 0xff)
        	                           {
        	                                PORTC_REG =Copy_u8Value;
        	                           }

        	                          else
        	                          {
        	                            /**/
        	                         	  LOC_enumState=DIO_NOK;
        	                          }
        	                    break;
        case DIO_PORTD : 
        	  if( Copy_u8Value >=0 && Copy_u8Value <= 0xff)
        	                           {
        	                                PORTD_REG =Copy_u8Value;
        	                           }

        	                          else
        	                          {
        	                            /**/
        	                         	  LOC_enumState=DIO_NOK;
        	                          }
        	                    break;
        default:
       	  LOC_enumState=DIO_NOK;

     }
 return    LOC_enumState;
 }

 DIO_ErroStatus DIO_enumSetPINDirection(u8 Copy_u8Port,u8 Copy_u8PINNumber, u8 Copy_u8Direction)
 {
	DIO_ErroStatus LOC_enumState = DIO_OK;
	if((Copy_u8PINNumber>=DIO_PIN0)&& (Copy_u8PINNumber<=DIO_PIN7))
	{
		 switch(Copy_u8Port)
		    {

		        case DIO_PORTA :
		                        if(Copy_u8Direction == DIO_OUTPUT)
		                           {
		                                SET_BIT(DDRA_REG,Copy_u8PINNumber);
		                           }
		                        else if(Copy_u8Direction == DIO_INPUT)
		                          {
		                                CLR_BIT(DDRA_REG,Copy_u8PINNumber);
		                          }
		                          else
		                          {
		                            /**/
		                        	  LOC_enumState=DIO_NOK;
		                          }
		                    break;
		        case DIO_PORTB :
		                        if(Copy_u8Direction == DIO_OUTPUT)
		                            {
		                                SET_BIT(DDRB_REG,Copy_u8PINNumber);
		                            }
		                        else if(Copy_u8Direction == DIO_INPUT)
		                            {
	                                    CLR_BIT(DDRB_REG,Copy_u8PINNumber);
		                            }
		                            else
		                            {
		                                /**/
		                          	  LOC_enumState=DIO_NOK;
		                            }
		                    break;
		        case DIO_PORTC :
		                        if(Copy_u8Direction == DIO_OUTPUT)
		                            {
	                                SET_BIT(DDRC_REG,Copy_u8PINNumber);
		                            }
		                        else if (Copy_u8Direction == DIO_INPUT)
		                            {
	                                CLR_BIT(DDRC_REG,Copy_u8PINNumber);
		                            }
		                            else
		                            {
		                                /**/
		                          	  LOC_enumState=DIO_NOK;
		                            }
		                    break;
		        case DIO_PORTD :
		                        if(Copy_u8Direction == DIO_OUTPUT)
		                            {
	                                SET_BIT(DDRD_REG,Copy_u8PINNumber);
		                            }
		                        else if (Copy_u8Direction==DIO_INPUT)
		                            {
	                                CLR_BIT(DDRD_REG,Copy_u8PINNumber);
		                            }
		                            else
		                            {
		                                /**/
		                          	  LOC_enumState=DIO_NOK;
		                            }
		                    break;

		        default:
		      	  LOC_enumState=DIO_NOK;

	}
	}
	else
	{
		LOC_enumState=DIO_NOK;
	}



	return LOC_enumState;
 }
 DIO_ErroStatus DIO_enumSetPINValue    (u8 Copy_u8Port,u8 Copy_u8PINNumber, u8 Copy_u8Value    )
 {
	 DIO_ErroStatus LOC_enumState = DIO_OK;
	 	if((Copy_u8PINNumber>=DIO_PIN0)&& (Copy_u8PINNumber<=DIO_PIN7))
	 	{
	 		 switch(Copy_u8Port)
	 		    {

	 		        case DIO_PORTA :
	 		                        if(Copy_u8Value == DIO_HIGH)
	 		                           {
	 		                                SET_BIT(PORTA_REG,Copy_u8PINNumber);
	 		                           }
	 		                        else if(Copy_u8Value == DIO_LOW)
	 		                          {
	 		                                CLR_BIT(PORTA_REG,Copy_u8PINNumber);
	 		                          }
	 		                          else
	 		                          {
	 		                            /**/
	 		                        	  LOC_enumState=DIO_NOK;
	 		                          }
	 		                    break;
	 		        case DIO_PORTB :
	 		                        if(Copy_u8Value == DIO_HIGH)
	 		                            {
	 		                                SET_BIT(PORTB_REG,Copy_u8PINNumber);
	 		                            }
	 		                        else if(Copy_u8Value == DIO_LOW)
	 		                            {
	 	                                    CLR_BIT(PORTB_REG,Copy_u8PINNumber);
	 		                            }
	 		                            else
	 		                            {
	 		                                /**/
	 		                          	  LOC_enumState=DIO_NOK;
	 		                            }
	 		                    break;
	 		        case DIO_PORTC :
	 		                        if(Copy_u8Value == DIO_HIGH)
	 		                            {
	 	                                SET_BIT(PORTC_REG,Copy_u8PINNumber);
	 		                            }
	 		                        else if (Copy_u8Value==DIO_LOW)
	 		                            {
	 	                                CLR_BIT(PORTC_REG,Copy_u8PINNumber);
	 		                            }
	 		                            else
	 		                            {
	 		                                /**/
	 		                          	  LOC_enumState=DIO_NOK;
	 		                            }
	 		                    break;
	 		        case DIO_PORTD :
	 		                        if(Copy_u8Value == DIO_HIGH)
	 		                            {
	 	                                SET_BIT(PORTD_REG,Copy_u8PINNumber);
	 		                            }
	 		                        else if (Copy_u8Value==DIO_LOW)
	 		                            {
	 	                                CLR_BIT(PORTD_REG,Copy_u8PINNumber);

	 		                            }
	 		                            else
	 		                            {
	 		                                /**/
	 		                          	  LOC_enumState=DIO_NOK;
	 		                            }
	 		                    break;

	 		        default:
	 		      	  LOC_enumState=DIO_NOK;

	 	}
	 	}
	 	else
	 	{
	 		LOC_enumState=DIO_NOK;
	 	}



	 	return LOC_enumState;
	  }

 DIO_ErroStatus DIO_enumGetPortValue    (u8 Copy_u8Port, u8 *Copy_ptrData   )
 {
	 DIO_ErroStatus LOC_enumState=DIO_OK;
	 switch (Copy_u8Port) {
		case DIO_PORTA: *Copy_ptrData = PINA_REG;
			break;
		case DIO_PORTB: *Copy_ptrData = PINB_REG;
					break;
		case DIO_PORTC: *Copy_ptrData = PINC_REG;
					break;
		case DIO_PORTD: *Copy_ptrData = PIND_REG;
					break;
		default:
			LOC_enumState =DIO_NOK;
			break;
	}
	 return LOC_enumState;


 }

 DIO_ErroStatus DIO_enumGetPINValue     (u8 Copy_u8Port,u8 Copy_u8PINNumber, u8 *Copy_ptrData   )
 {
	 DIO_ErroStatus LOC_enumState = DIO_OK;
		if((Copy_u8PINNumber>=DIO_PIN0)&& (Copy_u8PINNumber<=DIO_PIN7))
		 	{
		 		 switch(Copy_u8Port)
		 		    {
		 		case DIO_PORTA: *Copy_ptrData = GET_BIT(PINA_REG,Copy_u8PINNumber);
		 			break;
		 		case DIO_PORTB: *Copy_ptrData = GET_BIT(PINB_REG,Copy_u8PINNumber);
		 					break;
		 		case DIO_PORTC: *Copy_ptrData = GET_BIT(PINC_REG,Copy_u8PINNumber);
		 					break;
		 		case DIO_PORTD: *Copy_ptrData = GET_BIT(PIND_REG,Copy_u8PINNumber);
		 					break;
		 		default:
		 			LOC_enumState =DIO_NOK;
		 			break;

		 		    }
		 	}
	 else {
		 LOC_enumState = DIO_NOK;
	}

	 return LOC_enumState;
 }




