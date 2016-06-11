#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[1000][62], pass_operand[1000][62], dot[1000], result[62];
char var[50][62]={'0'};

int input_f(void);
void pos_digit(int k);
void variable(void);
void judg(void);
int operator(int);
int plus_equal(int);
void savef(void);
void loadf(void);

//// MAIN ////
int main()
{
	int i, k, end;
	char c;

    end = input_f(); //입력함수 호출 및 end 리턴값 저장
    
    //명령판단함수
	judg();
	
    //각 배열(0~end) 자리배정함수 호출
    for(k = 0; k <= end; k++)
        pos_digit(k);

    //변수 판단, 지정
	if((input[0][0] >= 'A' && input[0][0] <= 'Z') || (input[0][0] >= 'a' && input[0][0] <= 'z'))
		if(input[1][0] == '=')
			variable();

    //연산자 판단, 계산
    for(int i = 1; i <= end; i++)
    {
        operator(i);
        i++;
    }
    
    
    
    for(int i = 0; i <= end; i++)   //(확인작업)
        for(int j = 0; j < 62; j++)
            printf("pass_operand[%d][%d] = %c\n", i, j, pass_operand[i][j]);


	main();
    return 0;
}


//// 입 력 함 수 ////
int input_f(void)
{
	int i, end;
	char c;
	printf("(input) ");
	
	for(i = 0; i <= 1000; i++)
	{
    	scanf("%s", input[i]);
    	if((c = getchar()) == '\n')
        {
            end = i;
            break;
        }
	}

	//pass_operand 초기화
	for(int i = 0; i <= end; i++)
		for(int j = 0; j <= 62; j++)
			pass_operand[i][j] = 0;

	return end;
}

//// 자 리 배 정 함 수 ////
void pos_digit(int k)
{
    int l, n, r, s, o, u;
    for(l = 0; l <= 62; l++)
    {
        if(input[k][l] == '.')
        {
            dot[k] = l;
            pass_operand[k][52] = input[k][dot[k]];
        }
    }
    if(pass_operand[k][52]=='.')						//입력된 값이 정수가 아닌 실수인 경우의 정수부 위치 배정
    {
        for(n = dot[k] - 1, o = 51; o >= 0; n--, o--)
        {
            if(n>=0 && input[k][n] != '-')
                pass_operand[k][o] = input[k][n];
            else if (n==0 && input[k][n] == '-')
                pass_operand[k][1] = input[k][n];
            else if (n < 0 && o > 1)
                pass_operand[k][o] = '0';
        }
        for(r = dot[k] + 1, s = 53; s <= 61; r++, s++)
        {
            if(input[k][r] >= '0' && input[k][r] <= '9')
                pass_operand[k][s] = input[k][r];
            else
                pass_operand[k][s] = '0';
        }
    }
    else if(pass_operand[k][52] != '.')					//입력된 값이 정수인 경우의 정수부 위치 배정
    {
        for(n = strlen(input[k]) - 1, o = 51;o >= 0; n--, o--)
        {
            if(input[k][n] == '+'||input[k][n] == '-'||input[k][n] == '*'||input[k][n] == '/'||input[k][n] == '%')
            {
                if(strlen(input[k]) > 1)					// 단항 연산자 - 저장
                {
                    pass_operand[k][1] = input[k][n];
                    pass_operand[k][51] = '0';
                }
                else if(strlen(input[k])==1)			// 이항 연산자 저장(+,-,*,/,%)
                    pass_operand[k][0] = input[k][n];
            }
            else
            {
                if(n >= 0 && o > 1)
                    pass_operand[k][o] = input[k][n];
                if(n < 0 && o > 1)
                    pass_operand[k][o] = '0';
            }
        }
        for(u = 53; u <= 61; u++)
            pass_operand[k][u] = '0';
    }
    pass_operand[k][52] = '.';
    
    return ;
}

//변수(임시)
void variable(void)
{
	printf("variable call success\n");
	if(input[0][0] >= 'a' && input[0][0] <= 'z')
		for(int i = 0; i <= 61; i++)
			var[input[0][0] - 'a'][i] = pass_operand[2][i];
	if(input[0][0] >= 'A' && input[0][0] <= 'Z')
		for(int i = 0; i <= 61; i++)
			var[input[0][0] - 'A'][i] = pass_operand[2][i];
	return ;
}

//// 명 령 판 단 ////
void judg(void)
{
	if(strcmp(input[0], "clear") == 0)	system("clear");
	if(strcmp(input[0], "end") == 0)	system("exit");
    if(strcmp(input[0], "VAR") == 0)	printf("var call\n");
	if(strcmp(input[0], "save") == 0)	savef();
	if(strcmp(input[0], "load") == 0)	loadf();

	return ;
}

//// 변 수 저 장 함 수 ////
void savef(void)
{
	printf("savef call\n");
    FILE *save;
    save = fopen("var_save.txt", "w");
    for(int i = 0; i <= 10; i++)
        fprintf(save, "%s", pass_operand[i]);	//테스트. 변수배열로 수정 필요
    fclose(save);
}

//// 변 수 로 드 함 수 ////
void loadf(void)
{
	printf("loadf call\n");
    FILE *save;
    save = fopen("var_save.txt", "r");
    for(int i = 0; i <= 10; i++)
        fscanf(save, "%s", var[i]);
    fclose(save);
}

//// 사 칙 연 산 판 단 함 수 ////
int operator(int i)
{
	printf("operator call\n");
	switch(pass_operand[i][0])
	{
		case '+':
            if (pass_operand[i-1][1]==pass_operand[i+1][1])
                    plus_equal(i);
//            else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
//                    plus_dif();
            break;
        case '-':
//            if (pass_operand[i-1][1]==pass_operand[i+1][1])
//                    minus_equal();
//            else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
//                    minus_dif();
            break;
        case '*':
//            if (pass_operand[i-1][1]==pass_operand[i+1][1])
//                    multi_equal();
//            else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
//                   multi_dif();
            break;
        case '/':
//            if (pass_operand[i-1][1]==pass_operand[i+1][1])
//            		divi_equal();
//            else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
//            		divi_dif();
            break;
        case '%':
//            if (pass_operand[i-1][1]==pass_operand[i+1][1])
//            		rest_equal();
//			else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
//    				rest_dif();
    		break;
        default :
			break;
	}
}

//// 덧 셈 함 수 ////
int plus_equal(int i)   //부호같을때
{
	printf("plus call\n");
    for(int j = 0; j < 62; j++)
    {
        pass_operand[i-1][j] = '0';
        pass_operand[i+1][j] = '0';
    }

    for(int j = 0; j < 62; j++)
        result[j] = '0';
    
    for(int j = 61; j > 1; j--)
    {
        result[j] = result[j] + pass_operand[i-1][j] + pass_operand[i+1][j] - '0'*2;
        if(j!=53)											//소수점 아래 첫째 자리의 합이 10보다 큰 경우
            if(result[j] > '9')											//덧셈 결과 자릿수가 9보다 큰 경우
            {
                result[j-1]++;
                result[j] = result[j] - 10;
            }
        else if(result[j] > '9')												//덧셈 결과 자릿수가 9보다 큰 경우
        {
            result[j-2]++;
            result[j] = result[j] - 10;
        }
    }
    
    result[52] = '.';
    if(pass_operand[i-1][1] == '-' && pass_operand[i+1][1] == '-')
        result[1] = '-';
    //오류 코드 보내기 코딩 필요 
    //중간 결과 값 저장 코딩 필요 
	return 0;
}
