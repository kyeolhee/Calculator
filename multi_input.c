#include <stdio.h>
int main()
{
	int i, j, k, dot[1000]={0}, end;
	char input[1000][60]={0}, operand[1000][60]={0};
	
	//input
	printf("Start . . .\n(input) ");
	for(i = 0; i <= 1000; i++)
	{
		scanf("%s", input[i]);
		if(getchar() == '\n')
		{
			end = i;
			break;
		}
	}

	//input 확인
	for(j = 0; j <= end; j++)
		printf("input[%d] : %s\n", j, input[j]);

	//dot 위치
	for(j = 0; j <= end; j++)
	{
		for(i = 0; i <= 59; i++)
			if(input[j][i] == '.') 
			{
				dot[j] = i;
				break;
			}
		operand[j][50] = '.';
		j++;
	}
	for(j = 0; j <= end; j++)
	{
		printf("dot[%d] : %d\n", j, dot[j]);
		j++;
	}

	//정수 위치 배정
	for(j = 0; j <= end; j++)
	{
		for(i = dot[j] - 1, k = 49; k >= 0; i--, k--)
		{
			operand[j][k] = input[j][i];
			if(input[j][i] >= 48 && input[j][i] <= 57);
			else operand[j][k] = '0';
			if(i < 0) operand[j][k] = '0';		//쓰레기값 제거
		}
		j++;
	}
	//소수 위치 배정
	for(j = 0; j <= end; j++)
	{
		for(i = dot[j] + 1, k = 51; k <= 59; i++, k++)
		{
			operand[j][k] = input[j][i];
			if(input[j][i] >= 48 && input[j][i] <= 57);
			else operand[j][k] = '0';
		}
		j++;
	}

	//배열 하나하나 출력
	for(j = 0; j <= end; j++)
		printf("operand[%2d] = %s\n", j, operand[j]);
	
	return 0;
}
