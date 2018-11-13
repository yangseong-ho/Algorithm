#include<iostream>

void Hanoi(int n, int a, int b, int c, int *cnt)
{
	if (n > 0)
	{
		(*cnt)++;
		Hanoi(n - 1, a, c, b, cnt);
		printf("%d Move disk from %d to %d.\n", *cnt, a, c);
		Hanoi(n - 1, b, a, c, cnt);
	}
}
int main(void)
{
	int numDisks = 4, cnt = 0;
	printf("Number of disks to move: %d\n", numDisks);
	Hanoi(numDisks, 1, 2, 3, &cnt);

	return 0;
}
