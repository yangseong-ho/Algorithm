#include<iostream>

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0
typedef struct Point { int x, y; } point;
point direction[8] = { {1, -2}, {2, -1}, {2, 1}, {1, 2},
{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2} };
int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];
int knightTour(int m, int n, point pos, int counter)
{
	int i;
	point next;
	if (counter == m * n)
		return 1;
	for (i = 0; i < 8; i++)
	{
		next.x = pos.x + direction[i].x;
		next.y = pos.y + direction[i].y;
		if (next.x > 0 && next.x <= n &&
			next.y > 0 && next.y <= m &&
			board[next.y][next.x] != MARK)
		{
			board[next.y][next.x] = MARK;
			path[next.y][next.x] = counter + 1;
			if (knightTour(m, n, next, counter + 1))
				return 1;
			board[next.y][next.x] = UNMARK;
		}
	}
	return 0;
}
void main(void)
{
	int i, j, m, n;
	point start;
	m = 6; n = 8;
	start.y = 3; start.x = 4;
	for (i = 1; i <= m; i++)
		for (j = 1; j < n; j++)
			board[i][j] = UNMARK;
	board[start.y][start.x] = MARK;
	path[start.y][start.x] = 1;
	if (knightTour(m, n, start, 1))
		printTour(m, n);
}
