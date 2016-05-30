#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[10000][61]={0};
	char b[10000][100]={0}, c[10000][10]={0};
	int x, idx, j, k, i, d;
	printf("문자열을 입력하세요:");
	for(i=0;;i++)
	{scanf("%s",a[i]);
		//소수점 아래 9자리보다 많을 때 오류 메세지 출력
		//소수점 윗자리가 50자리 보다 많을 때 오류 메세지 출력 
	 if((d=getchar())=='\n')
		break;
	}
	for(x=0;x<=i;x++)
		{idx=strlen(a[x])-1; 
		 printf("%d\n",idx);	
		 for(j=0;j<=idx;j++)  
			if(a[x][j]!='.')
				{  b[x][j]=a[x][j];
				}
			else if(a[x][j]=='.')		 
					{j++;
					 for(int k=0;j<=idx;j++)
					  {c[x][k]=a[x][j];
					   k++;	
					  }
					}
		 if(strlen(b[x])>50||strlen(c[x])>9)
		 	{printf("=error\n");			 
		 	 break;
			}
				 
		}
	for(x=0;x<=i;x++)
		{printf("(%d)입력된 정수:%s\n",x+1,b[x]);			 
		 printf("(%d)입력된 정수의 자릿수:%d\n",x+1,strlen(b[x]));	
 		 printf("(%d)입력된 소수점 아래 수:%s\n",x+1,c[x]);
		 printf("(%d)입력된 소수점 아래 자릿수:%d\n",x+1,strlen(c[x]));		 
		}

		
	return 0;
}

