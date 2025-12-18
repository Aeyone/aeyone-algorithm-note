#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
	int cnt = 1;
	auto dfs = [&](auto &&self, pair<int, int> pos, int d)->bool{
		auto [x, y] = pos;
		if(cnt == n * m){
			// for(int i = 0; i < n; i ++){
			// 	for(int j = 0; j < m; j ++)
			// 		cout << g[i][j] << ' ';
			// 	cout << '\n';
			// }
			// cout << '\n';
			return true;
		}
		bool ok = false;
		for(int i = 0; i < 4; i ++){
			int a = (x + d * dx[i] + n * m) % n, b = (y + d * dy[i] + n * m) % m;
			if(a < 0 || b < 0 || a >= n || b >= m || g[a][b] != 0)
				continue;
			g[a][b] = d + 1;
			cnt ++;
			ok |= self(self, {a, b}, d + 1);
			if(ok)
				return ok;
			cnt --;
			g[a][b] = 0;
		}
		return ok;
	};
	g[0][0] = 1;
	bool ok = dfs(dfs, {0, 0}, 1);
	// for(int i = 0; i < n; i ++){
	// 	for(int j = 0; j < m; j ++)
	// 		cout << g[i][j] << ' ';
	// 	cout << '\n';
	// }
	if(ok){
		cout << "YES" << '\n';
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++)
				cout << g[i][j] << ' ';
			cout << '\n';
		}
	}else{
		cout << "NO" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}