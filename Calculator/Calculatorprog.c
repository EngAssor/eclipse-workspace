#include<math.h>
#include"LIB\typ.h"
//#define F_CPU 8000000UL
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_prv.h"
#include "KPD_config.h"
#include "avr\delay.h"
s32 findop(s8 rr,s8 lr ,u8 op)
{
	s32 totalreult=0;
	switch (op){
		case '+':
		totalreult = rr+lr;
		break;
		case '-' :
		totalreult = rr-lr;
		break;
			case '*' :
		totalreult= rr*lr;
		break;
			case '/' :
		totalreult= rr/lr;
		break;
	}
return totalreult;
}
s32 findResult(u8 *r,u8 *l,u8 * in)
{
	u8 operation =0;
	u8 i =0;
	u8 j =0;

	s8 rcount=0 ,lcount=0;
	s8 rightfalg=0;
	while(in[i]!='=')
	{
		if(in[i]=='+' || in[i]=='-' || in[i]=='x' || in[i]=='/'){
			operation=in[i];
			rightfalg=1;
			i++;

		}
	else{}
	if(rightfalg==0)
	{r[i]=in[i];
		i++;
		rcount++;
	}
	else
	{
		l[j]=in[i];
		i++;
		j++;
		lcount++;
	}
	}
	//printf(" r count : (%d)\n",rcount);
	rcount--;
	lcount--;
	s8 right_result=0;
	u8 k;
	for(k=0;k<10;k++)
	{
		if(rcount!=0)
		{

			right_result=right_result+((r[k]-'0')*(pow(10,rcount--)));
		}
		else if(rcount==0)
		{
			right_result=right_result +((r[k]-'0'));
		break;
		}
	}
		s8 left_result=0;
	u8 w;
	for(w=0;w<10;w++)
	{
		if(lcount!=0)
		{
			left_result=left_result+((l[w]-'0')*(pow(10,lcount--)));
		}

		else if(lcount==0)
		{
			left_result=(left_result +(l[w]-'0'));
			break;
		}
	}

 s32 p =	findop(right_result,left_result,operation);
	return p;

}


void itos(s32 res,u8* result )
{
	s8 i =5;
for(i=5;i>=0;i--)
{
	result[i]=res%10 + '0' ;
	res=res/10;
}

}
