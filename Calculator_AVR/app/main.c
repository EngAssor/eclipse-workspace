

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>
#include <string.h>
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/CLCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"

struct Array
{
    /* data */
    u8 data[16];
    u8 len;
    u8 size;
};
struct Array input={{'f','f','f','f','f','f','f','f','f','f','f','f','f','f','f','f'},0,16};
struct Array op={{0},0,16}; // this hold operations during the pursing
struct Array expr={{0},0,16}; // this to save the expression after been converted
struct Array op1={{0},0,16}; // this hold operand
/*
S_push stand for stack push
this function doesn't retern anything and takes pointer to the struct that has the stack array
and the value
*/
void S_push(struct Array * A,u8 value)
{
    // make suer thta's the array isn't full
    if(A->len>=A->size)
    {

    }
    else
    {
        A->data[A->len++]=value;
    }
}

/*
S_pop stand for stack pop
this function  return the value that the array hold and takes pointer to the struct that has the stack array
*/
u8 S_pop(struct Array * A)
{
    u8 temp;
    // make sure that the array isn't empty
    if(A->len<=0)
    {
        temp= -1;
    }
    else
    {
        temp= A->data[--A->len];
    }
    return temp;
}

/*
-getpriority is a function that takes the opretion and retrun it's priority
*/
u8 getpriority(u8 opretion)
{
    u8 res ;
    switch (opretion)
    {
    case '*':
         res=0;
         break;
    case '/':
         res=0;
         break;
    case '+':
         res=1;
         break;
    case '-':
         res=1;
         break;
    default:
        res=-1;
        break;
    }
return res;
}
void infixtopostfix(struct Array * input,struct Array * op,struct Array *  expr )
{

        u8 priority;
    u8 operation,temp;
    for(u8 i=0;i<input->len;i++)
    {

        if((input->data[i] >=48 && input->data[i] <= 57) || input->data[i] == ';' )
        {

            S_push(expr,input->data[i]);
        }
        else
        {

           operation=input->data[i];
            priority=getpriority(operation);
            if(priority != -1)
            {

                if(op->len==0)
                {

                    S_push(op,input->data[i]);
                }
                else
                {
                    if(priority<(getpriority(op->data[op->len-1])))
                    {
                        S_push(op,input->data[i]);
                    }
                    else
                    {
                        while (op->len !=0)
                        {
                            temp=S_pop(op);
                            S_push(expr,temp);
                        }
                        S_push(op,operation);
                    }
                }
            }
        }
    }
      while (op->len !=0)
                        {
                            temp=S_pop(op);
                            S_push(expr,temp);
                        }

    S_push(expr,'=');

}
int stoi(char a[], int len) {
    int res = 0;
    int i = 0;
    int factor = 1; // Positional weight

    // Start from the least significant digit
    for (i = len - 1; i >= 0; i--) {
        // Check if the character is a digit
        if (a[i] >= '0' && a[i] <= '9') {
            // Convert the character to its integer value and add it to the result
            res += (a[i] - '0') * factor;
            // Update the positional weight for the next digit
            factor *= 10;
        }

    }
    return res;
}

struct Array get_operand(struct Array  * expression )
{
    struct Array oprand ={{0},0,16}; // this hold operand
    int i=0;


        while (expression->data[i]!= ';' && expression->data[i] >= '0' && expression->data[i]<='9')
    {
        /* code */
        oprand.data[i]=expression->data[i];
        oprand.len++;
        i++;
    }

    // shift the exprssion array left
    for(;i>=0;i--)
    {
        for(int j=i;j<expression->len;j++)
        {
            expression->data[j]=expression->data[j+1];
        }
        expression->len--;
    }
    return oprand;
}
char get_opration(struct Array  * expression)
{
    char opreation ='?';
    if(expression->data[0] == '*' || expression->data[0] == '-' || expression->data[0] == '+' || expression->data[0] == '/' )
        opreation = expression->data[0];

        return opreation;
}



int main (void)
{
	int num1,num2;
	char opre;


	s8 CLCD_COL_POS=1;
	CLCD_voidInit();
	KPD_voidInit();
	CLCD_voidSendCommand(CLCD_DISPON_CURSON);
	CLCD_voidSendString("welcome ..!");
	_delay_ms(3000);
	CLCD_voidSendCommand(CLCD_CLR);
	CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);

	while(1)
	{
		u8 LOC_input=0;
		LOC_input=KPD_u8GetPressed();
		if(LOC_input !=0 )
		{
			switch (LOC_input) {
				case '=':
					// get the answer
				    infixtopostfix(&input,&op,&expr);
					CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);

			    	CLCD_voidSendString(expr.data);

				    op1=get_operand(&expr);
				    num1=stoi(op1.data,op1.len);
				    while (expr.data[0]!='=')
				    {
				        /* code */
				        op1=get_operand(&expr);
				        num2=stoi(op1.data,op1.len);
				        opre=get_opration(&expr);
				        switch (opre)
				        {
				        case '*':
				            num1=num1*num2;
				            /* code */
				            break;
				        case '/':
				            num1=num1/num2;
				            /* code */
				            break;
				        case '+':
				            num1=num1+num2;
				            /* code */
				            break;
				         case '-':
				            num1=num1-num2;
				            /* code */
				            break;
				        default:
				            break;
				        }

				    }
				//	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);

					CLCD_voidSendNumber(num1);

					break;
				case 'C':
					// delete the last input only

					if(CLCD_COL_POS >= 0)
					{
						CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_POS-1);
						CLCD_voidSendChar(' ');
					    CLCD_voidSetPosition(CLCD_ROW_1,--CLCD_COL_POS);

						if(input.data[input.len] >= 48 && input.data[input.len] <= 57)
						{
							input.data[input.len--]='f';
						}
						else
						{
							input.data[input.len--]='f';
							input.data[input.len--]='f';

						}


					}
					else
					{
						CLCD_voidSendCommand(CLCD_CLR);
						CLCD_voidSetPosition(CLCD_ROW_1,CLCD_COL_1);
						CLCD_COL_POS=0;

					}

					break;

				default:
					// put the LOC on input array
					if(LOC_input >= 48 && LOC_input <= 57)
					{
						// insert the input to input array and increment the position pointer

					input.data[input.len++]=LOC_input;
					CLCD_voidSendChar(LOC_input);
					CLCD_COL_POS++;
					}
					else
					{
						input.data[input.len++]=';';
						input.data[input.len++]=LOC_input;
						CLCD_voidSendChar(LOC_input);
						CLCD_COL_POS++;

					}
					break;
			}

		}
	}

	return 0;
}

	/*
	 *
	 *
	 * */
