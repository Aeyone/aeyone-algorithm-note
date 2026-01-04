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
	vector<vector<pair<int, i64>>> g(n);
	for (int i = 0; i < m; i ++) {
		int u, v;
		i64 w;
		cin >> u >> v >> w;
		u --, v --;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	i64 ans = INFLL, cur = 0;
	vector<int> vis(n);
	auto dfs = [&](auto &&self, int u)->void{
		if (u == n - 1) {
			ans = min(ans, cur);
			return;
		}
		for (auto [v, w] : g[u]) {
			if (vis[v]) {
				continue;
			}
			vis[v] = true;
			cur ^= w;
			self(self, v);
			cur ^= w;
			vis[v] = false;
		}
	};
	vis[0] = true;
	dfs(dfs, 0);
	cout << ans << '\n';
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