#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool ok = false;
	int cnt = 0;
	for(int i = 0; i < n; i ++){
		ok |= (g[i].size() == n - 1);
		cnt += (g[i].size() == 1);
	}
	int mx = 0;
	for(int i = 0; i < n; i ++){
		int c = 0;
		for(auto v : g[i])
			c += (g[v].size() == 1);
		mx = max(mx, c);
	}
	if(!ok)
		cout << cnt - mx << '\n';
	else
		cout << 0 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}