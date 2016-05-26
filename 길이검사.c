#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[10000][61]={0}, b[100]={0}, c[10]={0};
	int x, idx, j, k, i, d;
	printf("문자열을 입력하세요:");
	scanf("%s",&a[0]);	
	for(x=0;x<=0;x++)
		{idx=strlen(a[x])-1; //입력된 숫자의 자릿수 구하기 
		 printf("%d\n",idx);	
		 for(j=0;j<=idx;j++) //제대로 실행이 안됨 
			if(a[x][j]=='.')
				{for(int k=0;k<j;k++)  //입력된 숫자의 정수 자릿수 구하기
					{b[k]=a[x][k];
				 	 if(strlen(b)>50)	 //b[k]의 길이 검사 (입력된 수의 정수 자릿수 검사)
						 printf("error\n");
					}
				 for(int l=j+1, k=0;l<=idx;l++)		//입력된 숫자의 소수점 아래 자릿수 구하기 
				 	{c[k]=a[x][l];
					 k++;	
				 	 if(strlen(b)>9)	//c[k]의 길이 검사(입력된 수의 소수점 아래 자릿수 검사 )
						  printf("error");
					}
				 
				}
					}

		}
	return 0;
}
// 배열값 초기화 과정 필요
