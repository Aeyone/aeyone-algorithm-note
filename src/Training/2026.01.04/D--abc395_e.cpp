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
	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<array<int, 2>>> g(n);
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back({v, 0});
		g[v].push_back({u, 1});
	}
	vector<vector<i64>> dis(2, vector<i64>(n, {INFLL}));
	vector<vector<int>> vis(2, vector<int>(n));
	using T = array<i64, 3>;
	priority_queue<T, vector<T>, greater<T>> q;

	dis[0][0] = 0;
	q.push({dis[0][0], 0, 0});

	while (q.size()) {
		auto [w, u, st] = q.top();
		q.pop();
		if (vis[st][u]) {
			continue;
		}
		vis[st][u] = true;
		for (auto [v, c] : g[u]) {
			if (dis[c][v] > w + 1ll * (c != st) * x + 1) {
				dis[c][v] = w + 1ll * (c != st) * x + 1;
				q.push({dis[c][v], v, c});
			}
		} 
	}
	cout << min(dis[0][n - 1], dis[1][n - 1]) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}