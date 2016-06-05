#include <Stdio.h>
char pass_operand[10000][62];
int result[62];
int minus_1(void);
int minus_2(void);
int main()
{	
	
	
	pass_operand[0][50]='9';	
	pass_operand[0][49]='9';	
	pass_operand[0][48]='0';	
	pass_operand[1][50]='0';	
	pass_operand[1][49]='0';	
	pass_operand[1][48]='1';	

	for(int j=0;j<62;j++)
		result[j]='0';
	for(int j=0;j<62;j++)	
		{if(pass_operand[0][j]>pass_operand[1][j])
			{minus_1();
			 printf("1");	
			 break;
			}
	 	 else if(pass_operand[1][j]>pass_operand[0][j])
		 	{minus_2();
			 printf("2\n");	
		 	 break;
			}
		}
	for(int j=0;j<62;j++)
		printf("result[%d]=%c\n",j,result[j]);
	return 0;
	
}
int minus_1(void)													//부호가 다를 때 앞의 수가 뒤의 수보다 큰 경우 
{	for(int j=61;j>1;j--)
		{result[j]=result[j]+pass_operand[0][j]-pass_operand[1][j];
		 if(result[j]<'0')
			{result[j-1]=result[j-1]-1;
			 result[j]=result[j]+10;
		 	}	 
		}
		
	result[1]=0;
}
int minus_2(void)													//부호가 다를 때 앞의 수가 뒤의 수보다 작은 경우 
{	for(int j=61;j>1;j--)
		{result[j]=result[j]+pass_operand[1][j]-pass_operand[0][j];
		 if(result[j]<'0')
		 	{result[j-1]=result[j-1]-1;
		   	 result[j]=result[j]+10;
			}
		 }
	result[1]='-';
}	
