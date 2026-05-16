#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	vector<vector<array<int, 2>>> g(n);
	for (int v = 1; v < n; v ++) {
		int u, w;
		cin >> u >> w;
		g[v].push_back({u, w});
		g[u].push_back({v, w});
	}
	vector<int> path(n, INF);

	auto dfs = [&](auto &&self, int u, int fa = -1) -> void {
		for (auto [v, w] : g[u]) if (v != fa) {
			path[v] = min(path[u], w);
			self(self, v, u);
		}
	};
	dfs(dfs, 0);

	int mx = 0;
	for (int i = 0; i < n; i ++) {
		if (g[i].size() == 1 && path[i] != INF) {
			mx = max(mx, path[i]);
		}
	}

	vector<int> v;
	for (int i = 0; i < n; i ++) {
		if (g[i].size() == 1 && path[i] == mx) {
			v.push_back(i);
		}
	}

	cout << mx << '\n';
	for (int i = 0; i < v.size() - 1; i ++) {
		cout << v[i] << ' ';
	}
	cout << v.back() << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}