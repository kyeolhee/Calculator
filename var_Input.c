#include <stdio.h>
#include <string.h>
int main ()
{
        char a[10000][61] = {0};
        char c = 'a';
        char var[10][61] = {'@'};
        char tmp[100] = {0};
        int i, j, k, m;
        char gap;
        scanf("%[^\n]", a[0]); // 개행 되기 전까지 scanf로 받음
        for(;c<='z'; c++)
        {
                strcpy(tmp,"? = ");
                tmp[0] = c; // tmp의 첫번째 배열이 a부터 z까지 바뀜
                if (strncasecmp(a[0], tmp, 3) == 0) // 배열 a와 tmp가 앞으ㅔ 3자리가 같으면 strncasecmp의 값음 0
                {
                        for (j = 0; j <= 9; j++)
                        {
                                if (var[j][0] == '@')
                                {
                                        // + 특수문자가 들어가면 오류뜨게
                                        var[j][0] = c;
                                        for (i = 1; i <= 61; i++)
                                                var[j][i] = a[0][i+3];
                                        break;
                                        //for문을 빠져나옴
                                }
                        }
                        // 변수에 저장
                        for (i = 4; i<=61; i++) // 이경우에 면수는 자릴수 57자리까지 받음 수정해야할듯
                        {
                                printf("%c", a[0][i]);
                        }
                        // 화면에 변수값 출력
                }
        }
	gap = 'A' - 'a';
        for (i = 0; i <= 61; i++)
                for (j = 0; j <= 61; j++)
                        if (a[i][j] <= 'z' && a[i][j] >= 'A')
                                for (k = 0; k <= 9; k++)
                                         if (a[i][j] == var[k][0] || a[i][j] + gap == var[k][0] || a[i][j] - gap == var[k][0])
                                                for (m = j; m <= 61; m++)
                                                        a[i][m] = var[k][m-j+1];
        // 입력된 배열이 알파벳이면 그 알파벳을 var 배열의 0번째와 비교해서 맞으면 var배열의 1번째 값부터 배열에 다시 넣는다
        return 0;
}
                         
