#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 2e5 + 10;

void solve() {
	int n, m;
	char c;
	cin >> n >> m >> c;
	vector<string> g(n);
	for(int i = 0; i < n; i ++)
		cin >> g[i];

	vector<array<int, 2>> q;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(g[i][j] == c)
				q.push_back({i, j});

	vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
	map<char, bool> mp;
	mp['.'] = mp[c] = true;
	int ans = 0;
	for(auto &[x, y] : q){
		for(int i = 0; i < 4; i ++){
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a >= n || b < 0 || b >= m || mp[g[a][b]])
				continue;
			mp[g[a][b]] = true;
			ans ++;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}