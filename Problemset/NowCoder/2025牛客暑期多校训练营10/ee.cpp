#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;

	if(__gcd(n, m) != 1){
		cout << "NO" << '\n';
		return;
	}
	vector<vector<int>> g(n, vector<int>(m));
	int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
	auto dfs = [&](auto &&self, pair<int, int> pos, int d, int cnt)->void{
		auto [x, y] = pos;
		if(d % n == 0){
			cnt ++;
			if(cnt == m)
				return;
			
			int tmp = d / n, b;
			if(tmp & 1)
				y = (y + d) % m;
			else
				y = (y - d + 2 * n * m) % m;
		}else{
			if(d & 1)
				x = (x + d) % n;
			else
				x = (x - d + 2 * n * m) % n;
		}
		g[x][y] = ++ d;
		self(self, {x, y}, d, cnt);
	};
	g[0][0] = 1;
	dfs(dfs, {0, 0}, 1, 0);
	cout << "YES" << '\n';
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++)
			cout << g[i][j] << ' ';
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}