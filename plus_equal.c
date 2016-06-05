plus_equal(int i)																//부호가 같은 경우 덧셈
{
	int j;	
	for(j=61;j>1;j--)
		{result[j]=result[j]+pass_operand[i-1][j]+pass_operand[i+1][j]-'0';		//같은 자릿수 덧셈
		 if(result[j]>'9')														//덧셈 결과 자릿수가 9보다 큰 경우
		 	{result[j-1]++;			
			 result[j]=result[j]-10;	
			} 
		}
	//오류 코드 보내기 코딩 필요 
	//중간 결과 값 저장 코딩 필요 
}

