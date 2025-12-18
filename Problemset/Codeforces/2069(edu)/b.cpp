#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	map<int, int> cnt;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> g[i][j], cnt[g[i][j]] = 1;

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			for(int k = 0; k < 4; k ++){
				int a = i + dx[k], b = j + dy[k];
				if(a < 0 || n <= a || b < 0 || m <= b || g[a][b] != g[i][j])
					continue;
				cnt[g[i][j]] = 2;
			}
		}
	}
	int mx = 0;
	for(auto [num , e] : cnt)
		if(cnt[mx] < e)
			mx = num;

	int ans = 0;
	for(auto [num , e] : cnt){
		if(num == mx)
			continue;
		ans += e;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}