#include<iostream>
#include<algorithm>

int main() {

	int testcase;

	scanf("%d", &testcase);

	while (testcase--) {

		int arrN, result;

		scanf("%d", &arrN);

		int* arr = new int[arrN] { 0, };

		for (int i = 0; i < arrN; i++)
			scanf("%d", &arr[i]);

		std::sort(arr, arr + arrN);

		for (int j = 0; j <= arrN; j++)                 // j 타겟넘버
		{
			int a = std::lower_bound(arr, arr + arrN, j) - arr; //배열의 이름을 빼면 몇번째 인자인지 찾음
			int b = std::upper_bound(arr, arr + arrN, j) - arr; //lower는 key값을 찾음. 없으면 key보단 크고 그중작은 정수
			
			for (int k = a; k <= b; k++)						 // upper는	key값을 초과하는 가장첫번째 원소위치(같은값x)
			{
				if (j == arrN - k)
					result = j;
			}
		}

		printf("%d\n", result);

		delete[] arr;

		arr = NULL;
	}

	return 0;
}
