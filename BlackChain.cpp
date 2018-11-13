#include<iostream>

int main()
{
	int testcase;

	scanf("%d", &testcase);

	while (testcase--) {

		long long num; //%lli
		scanf("%lli", &num);
		int j = 1;

		while (1) {

			long long sum = j;
			long long tmp = j + 1;
			for (int i = 0; i < j + 1; i++) {
				sum += tmp;
				tmp *= 2;
			}
			if (sum >= num)
				break;
			j++;
		}
		printf("%d\n", j);
	}


	return 0;
}
