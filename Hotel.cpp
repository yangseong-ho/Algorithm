#include<iostream>

int main()
{
	int T;
	
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int H, W, N;
		
		scanf("%d %d %d", &H, &W, &N);

		
		/*int **arr = new int*[H];
		for (int j = 0; j < H; j++)
		{
			arr[j] = new int[W];
			memset(arr[j], 0, sizeof(int)*W);

		}*/
		
		if (H > N)
			N = N * 100 + 1;
		
		else if (H == N)
			N = H * 100 + 1;
		else
		{
			if (N % H == 0)
				N = H * 100 + N / H ;
			else
				N = (N % H) * 100 + N / H + 1;
		}
		
		printf("%d \n", N);
		
		/*
		for (int k = 0; k < H; k++)
			delete[] arr[k];
		delete[] arr;
		*/
	}
}
