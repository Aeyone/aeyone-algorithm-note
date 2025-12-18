#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	queue<array<int, 3>> q;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(g[i][j] >= '1' && g[i][j] <= '9'){
				q.push({g[i][j] - '0', i, j});
				g[i][j] = '.';
			}
		}
	}
	int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
	while(q.size()){
		auto [cnt, x, y] = q.front();
		q.pop();
		if(cnt == 0){
			continue;
		}
		for(int i = 0; i < 4; i ++){
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a >= n || b < 0 || b >= m){
				continue;
			}
			q.push({cnt - 1, a, b});
			g[a][b] = '.';
		}
	}
	for(int i = 0; i < n; i ++){
		cout << g[i] << '\n';
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