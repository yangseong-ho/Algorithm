#include<iostream>
#include<algorithm>

void FindRoomCount(char **room, int x, int y, int *RoomSize, int m, int n, char rc);
bool greater(int a, int b);

int main()
{
	int testcase;

	scanf("%d", &testcase);

	while (testcase--)
	{
		int m, n, RoomCount = 0;
		int RS[101] = { 0, };

		scanf("%d %d", &n, &m); // n이 열로 m행

		char** room = new char*[m];

		for (int i = 0; i < m; i++)
		{
			room[i] = new char[n + 1];

			for (int j = 0; j < n + 1; j++)
			{
				scanf("%c", &room[i][j]); //엔터도 입력받는거 체킹
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				if (room[i][j] == '.')
				{
					int RoomSize = 0;    //방크기 초기화
					FindRoomCount(room, i, j, &RoomSize, m, n, 'a'+RoomCount); //방크기 찾고, 방을 구별
					RS[RoomCount] = RoomSize;    //방번호에 방크기 저장
					RoomCount++;				// 방번호 증가
				}
			}
		}

		printf("%d\n", RoomCount);

		std::sort(RS, RS + 101, greater);

		for (int i = 0; i < RoomCount; i++)
			printf("%d ", RS[i]);
		printf("\n");
			
/*
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n + 1; j++)
			{
				printf("%c", room[i][j]);
			}*/

		for (int i = 0; i < m; i++)
			delete[] room[i];
		delete[] room;

		room = NULL;
	}


	return 0;
}

void FindRoomCount(char **room, int x, int y, int *RS, int m, int n, char rc) // 룸 갯수
{	

	if (room[x][y] == rc)
		return;

	if (room[x][y] == '.')
	{
		room[x][y] = rc;
		(*RS)++;
	}
	if (x > 0 && room[x-1][y] == '.') 
	{
		FindRoomCount(room, x - 1, y, RS, m, n, rc);
	}
	if (x < m - 1 && room[x+1][y] == '.')
	{
		FindRoomCount(room, x + 1, y, RS, m, n, rc);
	}
	if (y > 0 && room[x][y-1] == '.')
	{
		FindRoomCount(room, x, y - 1, RS, m, n, rc);
	}
	if (y < n && room[x][y+1] == '.')
	{
		FindRoomCount(room, x, y + 1, RS, m, n, rc);
	}


}

bool greater(int a, int b)  //오름차순
{
	return a > b;
}
