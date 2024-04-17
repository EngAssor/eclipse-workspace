#include<math.h>
#include"LIB\typ.h"
#include "avr\delay.h"
s32 findop(s8 rr, s8 lr , u8 op)
{
	switch (op){
		case '+':
		return rr+lr;
		break;
		case '-' :
		return rr-lr;
		break;
			case '*' :
		return rr*lr;
		break;
			case '/' :
		return rr/lr;
		break;
	}
	return -1;

}
s32 findResult(u8* r,u8* l,u8* in)
{
	u8 op =0;
	u8 i =0;
	u8 j =0;

	s8 rcount=0 ,lcount=0;
	s8 rightfalg=0;
	while(in[i]!='=')
	{
		if(in[i]=='+' || in[i]=='-' || in[i]=='x' || in[i]=='/'){
			op=in[i];
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

	rcount--;
	lcount--;
	s8 rr=0;
	u8 k;

	for(k=0;k<10;k++)
	{
		if(rcount!=0)
		{

		rr=rr+((r[k]-'0')*(pow(10,rcount--)));
		}
		else if(rcount==0)
		{
		rr=rr +((r[k]-'0'));
		break;
		}
	}
		s8 lr=0;
	u8 w;
	for(w=0;w<10;w++)
	{
		if(lcount!=0)
		{

		lr=lr+((l[w]-'0')*(pow(10,lcount--)));
		}
		else if(lcount==0)
		{
		lr=lr +((l[w]-'0'));
		break;
		}
	}


	//return findop(rr,lr,op);
	 s32 re = findop(rr,lr,op);
	 return re;
}
/*void itos(s32 res,u8* result )
{
	s8 i =5;
for(i=5;i>=0;i--)
{
	result[i]=res%10 + '0' ;
	res=res/10;
}

}
*/
