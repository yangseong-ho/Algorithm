#include<iostream>

int h_gcd(int num_a, int num_b);

int main() 
{

	int testcase;

	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int num_a, num_b, next_b=0, num_gcd=0;

		scanf("%d %d", &num_a, &num_b); //// a 분자 b분모 

		
		while(num_a != 1)
		{
			next_b = (num_b / num_a) + 1; // 가장 큰 기약분수 분모

			num_a = (num_a * next_b) - num_b; //다음 분자
					
			num_b *= next_b;

			num_gcd = h_gcd(num_a, num_b);

			num_a /= num_gcd;
			num_b /= num_gcd;
		}

		printf("%d\n", num_b);

	}

	return 0;
}

int h_gcd(int num_a, int num_b)
{
	if (num_b == 0)
		return num_a;
	else
		return h_gcd(num_b, num_a % num_b);
}
