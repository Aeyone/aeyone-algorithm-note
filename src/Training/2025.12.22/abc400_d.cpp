#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++) {
		cin >> g[i];
	}
	int st[2] = {}, ed[2] = {};
	cin >> st[0] >> st[1] >> ed[0] >> ed[1];
	st[0] --, st[1] --, ed[0] --, ed[1] --;

	const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

	vector<vector<int>> dis(n, vector<int>(m, INF));
	deque<array<int, 5>> q;

	q.push_front({st[0], st[1], -1, -1, 0});
	dis[st[0]][st[1]] = 0;

	while(q.size()) {
		auto [x, y, bx, by, w] = q.front();
		q.pop_front();
		if(x == ed[0] && y == ed[1]) {
			cout << w << '\n';
			return;
		}
		for(int i = 0; i < 4; i ++) {
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a >= n || b < 0 || b >= m || (a == bx && b == by)){
				continue;
			}
			if(g[a][b] == '#') {
				int A = a + dx[i], B = b + dy[i];
				if(dis[a][b] > w + 1) {
					dis[a][b] = w + 1;
					q.push_back({a, b, A, B, w + 1});
				}
				if(A >= 0 && A < n && B >= 0 && B < m && dis[A][B] > w + 1) {
					dis[A][B] = w + 1;
					q.push_back({A, B, a, b, w + 1});
				}
			}else if(g[a][b] == '.' && dis[a][b] > w){
				dis[a][b] = w;
				q.push_front({a, b, -1, -1, w});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}