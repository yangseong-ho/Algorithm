#include<iostream>

int R_Fibonacci(int num);

int main() {

	int testcase;

	scanf("%d", &testcase);

	while (testcase--) {
	
		int num;
		
		scanf("%d", &num);

		printf("%d\n", R_Fibonacci(num));

	}

	return 0;
}

int R_Fibonacci(int num) {

	if (num <= 1)
		return num;
	else
		return R_Fibonacci(num - 1) + R_Fibonacci(num - 2);

}
