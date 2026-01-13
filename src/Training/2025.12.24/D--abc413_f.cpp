#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n, vector<int>(m)), dis(n, vector<int>(m, INF)), vis(n, vector<int>(m));
	queue<array<int, 3>> q;

	for(int i = 0; i < k; i ++) {
		int x, y;
		cin >> x >> y;
		x --, y --;
		g[x][y] = -1;
		dis[x][y] = 0;
		q.push({0, x, y});
	}

	while(q.size()) {
		auto [d, x, y] = q.front();
		q.pop();

		if(vis[x][y]) {
			continue;
		}
		vis[x][y] = true;

		for(int i = 0; i < 4; i ++) {
			int a = x + dx[i], b = y + dy[i];
			if(a >= n || a < 0 || b >= m || b < 0 || g[a][b] == -1) {
				continue;
			}
			g[a][b] ++;
			if(g[a][b] < 2) {
				continue;
			}
			if(dis[a][b] > d + 1) {
				dis[a][b] = d + 1;
				q.push({d + 1, a, b});
			}
		}
	}
	i64 ans = 0;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			ans += (dis[i][j] == INF ? 0 : dis[i][j]);
		}
	}
	cout << ans << '\n';
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