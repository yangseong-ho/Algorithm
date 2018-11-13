#include<iostream>
#include<cmath>
#include<algorithm>

int main()
{
	int testcase;

	scanf("%d", &testcase);

	while (testcase--) {

		int arrN, Num_k, nearNumCase = 0, first = 0, last;

		scanf("%d %d", &arrN, &Num_k);
		last = arrN - 1;

		int* arr = new int[arrN] { 0, };

		for (int i = 0; i < arrN; i++)
			scanf("%d", &arr[i]);

		std::sort(arr, arr + arrN);
		
		if (arr[0] + arr[1] >= Num_k || arr[arrN - 2] + arr[arrN - 1] <= Num_k)
			nearNumCase++;
		
		else {
			
			int nearNum = abs(Num_k - (arr[first] + arr[last])), sum, d;
			
			while (first < last)
			{
				sum = arr[first] + arr[last];
				d = abs(Num_k - sum);
				if (Num_k > sum)
				{
					first++;
					if (nearNum > d)
					{
						nearNum = d;
						nearNumCase = 1;
					}
					else if (nearNum == d)
					{
						nearNumCase++;
					}
					else
						continue;
				}
				else // Num_k <= sum
				{
					if (nearNum > d)
					{
						nearNum = d;
						nearNumCase = 1;
					}
					else if (nearNum == d)
					{
						nearNumCase++;
					}
					last--;
				}
				//printf("%d %d\n", first, last);
			}

			
		}
		printf("%d\n", nearNumCase);

		delete[] arr;

		arr = NULL;

	}

	return 0;
}
