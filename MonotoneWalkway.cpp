#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Point {
	int x;
	int y;
};

bool comp(const Point& l, const Point& r) {
	if (l.x < r.x) return true;
	if (l.x > r.x) return false;
	if (l.y < r.y) return true;
	if (l.y > r.y) return false;
}

int main() {

	int testcase;

	scanf("%d", &testcase);

	while (testcase--)
	{
		int n;

		scanf("%d", &n);
		vector<Point> points;
		points.push_back({ -1, 0 }); // 1부터 시작.
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			points.push_back({ x, y });
		}
		sort(points.begin(), points.end(), comp);

		/*for (int i = 0; i < points.size(); i++)
			printf("{%d, %d}\n", points[i].x, points[i].y);
*/
		for (int i = 1; i <= n; i++) 
		{
			if (points[i - 1].x != points[i].x) 
			{
				int s = i;
				int e = i;

				for (; e <= n; e++) 
				{
					if (points[s].x != points[e].x) break;
				}
				if (points[i - 1].y != points[s].y) 
				{
					reverse(points.begin() + s, points.begin() + e);
				}
			}
		}

		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int p;
			scanf("%d", &p);
			printf("%d %d\n", points[p].x, points[p].y);
		}

	}


	return 0;
}
