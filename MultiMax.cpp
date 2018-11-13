#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int testcase;

	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
	{
		int n, max=0;
		scanf("%d", &n);
		int* arr = new int[n]{ 0, };

		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[j]);
		}

		sort(arr, arr + n);

		max = arr[n - 1] * arr[n - 2];

		if (max < arr[n - 3] * arr[n - 1] * arr[n - 2])
			max = arr[n - 3] * arr[n - 1] * arr[n - 2];
		
		if (max < arr[0] * arr[1])
			max = arr[0] * arr[1];

		if (max < arr[0] * arr[1] * arr[n - 1])
			max = arr[0] * arr[1] * arr[n - 1];
				
		
		printf("%d\n", max);

	}

	return 0;
}
