#include<iostream>

using namespace std;
typedef pair<int, int> pi;

int main() {

	int n, m, sum = 0;
	scanf("%d %d", &m, &n);

	int** arr = new int*[m];
	int** tf = new int*[m];
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
		tf[i] = new int[n];
		memset(arr[i], 0, sizeof(int)*n);
		memset(tf[i], 0, sizeof(int)*n);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < m; i++)
	{
		int mx = -1;
		pi p;
		for (int j = 0; j < n; j++)
		{
			if (mx < arr[i][j])
			{
				mx = arr[i][j];
				p = { i,j };
			}
			tf[p.first][p.second] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int mx = -1;
		pi p;
		for (int j = 0; j < m; j++)
			if (mx < arr[j][i])
			{
				mx = arr[j][i];
				p = { j,i };
			}
		tf[p.first][p.second] = 1;
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!tf[i][j])
				sum += arr[i][j];


	printf("%d\n", sum);

	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
		delete[] tf[i];
	}
	delete[] tf;
	delete[] arr;

	tf = NULL;
	arr = NULL;

	return 0;
}
