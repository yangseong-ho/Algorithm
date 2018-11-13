#include<iostream>

int Eureka(int n);

int main() {

	int testcase;

	scanf("%d", &testcase);

	while (testcase--) {

		int num_K, t1, t2, t3, check=0;

		scanf("%d", &num_K);

		for (int i = 1; Eureka(i) < num_K; i++) {
			
			t1 = Eureka(i);

			//printf("%d\n", t1);
			
			for (int j = 1; Eureka(j) < num_K; j++) {
				
				t2 = Eureka(j);

				//printf("%d\n", t2);
				
				for (int k = 1; Eureka(k) < num_K; k++)
				{
					t3 = Eureka(k);

					//printf("%d\n", t3);
					
					if (t1 + t2 + t3 == num_K) {
						check++;
						break;
					}
					
				}
				if (check)
					break;
			}
			if (check)
				break;
		}

		printf("%d\n", check);
	}

	return 0;
}

int Eureka(int n) {

	return n * (n + 1) * 1 / 2;
}
