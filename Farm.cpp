#include<iostream>

int main()
{
	int testcase;

	scanf("%d", &testcase);
	while (testcase--) {
						 //n전체 개체수, w 하루동안 소비한 사료
		int a, b, n, w;  //a 양이먹는 사료, b 염소가 먹는 사료
		scanf("%d %d %d %d", &a, &b, &n, &w);
		int check = 0, sheep, goat;
		for (int i = 1; i < n; i++) {
				if (check > 1)
				break;
				if (a*i + b * (n - i) == w )
				{
					check++;
					sheep = i;
					goat = n - i;
				}
		}
		if (check == 1)
			printf("%d %d\n", sheep, goat);
		else
			printf("-1\n");

	}

	return 0;
}
