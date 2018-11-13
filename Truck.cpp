#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <cassert>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, int> > vli;
typedef vector<pair<ll, ll> > vll;
typedef vector<pair<db, db> > vdd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define mp make_pair
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const db PI = acos(-1);

int main() {

	std::ios::sync_with_stdio(false);

	int n, w, l, t, cnt = 0, sum = 0;
	scanf("%d %d %d", &n, &l, &w);

	queue<int> q;

	while (n--) {
		scanf("%d", &t);

		while (1) {
			if (q.empty()) {
				q.push(t);
				sum += t;
				cnt++;
				break;
			}
			else if (q.size() == l) {
				sum -= q.front(); q.pop();
			}
			else {
				if (sum + t > w) {
					q.push(0);
					cnt++;
				}
				else {
					sum += t;
					q.push(t);
					cnt++;
					break;
				}
			}
		}
	}
	sum -= t;

	printf("%d", cnt + l);

	return 0;
}
