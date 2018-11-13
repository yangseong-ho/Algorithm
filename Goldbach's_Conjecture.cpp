#include<iostream>
#include<cmath>

int isPrime(int n, int i );

int main()
{
	int testcase;

	scanf("%d", &testcase);

	while (testcase--) {

		int num, p1, p2, differ=0, n_p1, n_p2, first=0; // p1, p2 소수 differ 소수차이

		scanf("%d", &num);

		for (int i = 2; i < num; i++)
		{
			if (isPrime(i, 2) && isPrime(num - i, 2))
			{
				if (first==0) {
					p1 = i;
					p2 = num - i;
					differ = abs(p2 - p1);
					first++;
				}

				n_p1 = i;
				n_p2 = num - i;

				if (differ > abs(n_p2 - n_p1)) {

					p1 = i;
					p2 = num - i;
					differ = abs(n_p2 - n_p1);
				}
					
			}
		}
		printf("%d %d\n", p1, p2);

	}


	return 0;
}

int isPrime(int n, int i ) {
	
	if (n <= 2)
		return 1;

	if (n % i == 0)
		return 0;

	if (i * i > n)
		return 1;

	return isPrime(n, i + 1);
}
