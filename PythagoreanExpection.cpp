#include<iostream>
#include<cmath>

int main() {
	int testcase;

	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int n, m; // n 팀 개수, m 전체 경기수, m개의 줄에는 각 경기에대한 정보
		double max=0 , min=0;

		scanf("%d %d", &n, &m);

		int* t_s = new int[n + 1]{ 0, };  // 팀별 총득점
		int* t_a = new int[n + 1]{ 0, };  //  "     실점
			
		for (int j = 0; j < m; j++)  // 전체 경기 정보
		{
			int a, b, p, q; // a,b팀 // p a팀 득점// q b팀 득점

			scanf("%d %d %d %d", &a, &b, &p, &q);

			t_s[a] += p;  //a팀 득
			t_a[b] += p;  //b팀 실
			
			t_a[a] += q;  //a팀 실
			t_s[b] += q;  //b팀 실
			
		}
		//printf("%lf \n", pow((double)t_s[1], 2.0));
		for (int k = 1; k < n+1; k++)
		{
			double t_w ;

			if (t_s[k] == 0 && t_a[k] == 0) {
				t_w = 0;
			}
			else {
				t_w = pow((double)t_s[k], 2.0) / (pow((double)t_s[k], 2.0) + pow((double)t_a[k], 2.0));
			}
			

			if (k == 1) {
				max = t_w;
				min = t_w;
			}

			if (t_w > max)
				max = t_w;
			if (t_w < min)
				min = t_w;
		}

		printf("%d \n%d\n", (int)(max * 1000.0), (int)(min * 1000.0));
		
		delete[] t_s;
		delete[] t_a;
		
		t_s = NULL;
		t_a = NULL;
	}

	return 0;
}
