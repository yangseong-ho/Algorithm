#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream fs("input.txt");
	int testcase;

	fs >> testcase;

	while (testcase--) {

		int n, k, check = 0, fail = 0; // n승객의 수, k 창구 수 2<= n,k <= 1000

		fs >> n >> k;

		if (fs.peek() == EOF)break;

		int* arrN = new int[n] {0, }; // 승객 배열
		int* arrK = new int[k] {0, }; // 창구 배열

		for (int i = 0; i < n; i++)
			fs >> arrN[i];
		for (int i = 0; i < n; i++) { // 승객
			for (int j = 0; j < k; j++) { // 창구
				if (arrK[j] < arrN[i]) { // 들어가면 break 후 다음 승객
					arrK[j] = arrN[i];
					if (arrK[j] == arrN[n - 1]) //마지막 승객 창구에 들어갔는지 check 
						check++;
					break;
				}
				if (j == k - 1) {  //마지막 창구에도 들어가지 못한 경우
					fail++;
				}
			}
			if (check || fail)
				break;
		}
		/*	for (int i = 0; i < k; i++)
				printf("%d\n", arrK[i]);
		*/

		if (check == 0)
			printf("NO\n");
		else
			printf("YES\n");

		delete[] arrN;
		delete[] arrK;
		arrN = NULL;
		arrK = NULL;
	}
	fs.close();
	return 0;
}
