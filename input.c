#include <stdio.h>
int main()
{
	int i, j, dot;
	char input[60]={0}, operand[60]={0};
	scanf("%s", input);

	//input
	for(i = 0; i <= 59; i++)
		printf("input[%2d] = %c\n", i, input[i]);
	

	//dot 위치
	for(i = 0; i <= 59; i++)
		if(input[i] == '.') dot = i;


	operand[50] = input[dot];
	//정수 위치 배정
	for(i = dot - 1, j = 49; j >= 0; i--, j--)
	{
		operand[j] = input[i];
		if(input[i] >= 48 && input[i] <= 57);
		else operand[j] = '0';
		if(i < 0) operand[j] = '0';		//쓰레기값 제거
	}
	//소수 위치 배정
	for(i = dot + 1, j = 51; j <= 59; i++, j++)
	{
		operand[j] = input[i];
		if(input[i] >= 48 && input[i] <= 57);
		else operand[j] = '0';
	}


	//배열 하나하나 출력
	for(i = 0; i <= 59; i++)
		printf("operand[%2d] = %c\n", i, operand[i]);

		
	//배정한 숫자 출력(자리수 고려)
	printf("operand : ");
	for(i = 0; i <= 59; i++)
		printf("%c", operand[i]);
	printf("\n");

	return 0;

}
