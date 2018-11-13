#include<iostream>

int main() {

	int testcase;

	scanf("%d", &testcase);

	while (testcase--)
	{
		int k, node_cnt, left, right;

		scanf("%d", &k);
		
		node_cnt = 1 << (k + 1);  // 노드갯수+1
		
		int* node_arr = new int[node_cnt] {0, }; // 노드 선언
		int* distance_arr = new int[node_cnt] {0, }; // 루트까지 길이
		int* sum_arr = new int[node_cnt] {0, }; // 해당노드까지 합
		
		
		for (int i = 2; i < node_cnt; i++)  // 1은 루트
			scanf("%d", &node_arr[i]);     // 거리 입력

		for (int i = (1 << k) -1; i > 0; i--)
		{
			left = i << 1;
			right = left + 1;
			
			if (distance_arr[left] + node_arr[left] >= distance_arr[right] + node_arr[right])
				distance_arr[i] = distance_arr[left] + node_arr[left];
			else
				distance_arr[i] = distance_arr[right] + node_arr[right];

			sum_arr[i] = sum_arr[left] + sum_arr[right] + (distance_arr[i] - distance_arr[left])
				+ (distance_arr[i] - distance_arr[right]);
			
		}

		printf("%d\n", sum_arr[1]);

		delete[] node_arr;
		delete[] distance_arr;
		delete[] sum_arr;

		node_arr = NULL;
		distance_arr = NULL;
		sum_arr = NULL;
	}

	return 0;
}
