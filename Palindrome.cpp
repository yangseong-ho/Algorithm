#include<iostream>
#include<cmath>

int checkPalindrome(int str[], int first, int last);

int main() {

	int testcase;

	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int num, check=0;

		scanf("%d", &num);  // 10진수 정수

		for (int j = 2; j < 65; j++)  // base 
		{
			int l = 0;
			int m = num;
			for (int k = 2; k < num; k++) // 배열 크기 지정
			{
				if ( pow((double)j, (double)k) <= num   && pow( (double)j, (double)(k+1)) > num  )
				{
					l = k + 1;
					break;
				}
			}

		int* str = new int [l] { 0, };
		
		for (int n = 0; n < l; n++) // 배열에 진수값 저장 
		{
			str[n] = m % j;  //정수를 base를 나눈 나머지
			m /= j;
		}

		if (checkPalindrome(str, 0, l - 1) ) // 1나오면 break후 출력
		{
			check++;
			break;
		}
		
		}
		printf("%d\n", check);
		
	}

	return 0;
}

int checkPalindrome(int str[], int first, int last)
{
	if (last <= first)
		return 1;
	else if (str[first] != str[last])
		return 0;
	else
		return checkPalindrome(str, first + 1, last - 1);
}
