#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> c(n), k(n);
	for (int i = 0; i < n; i ++) cin >> c[i];
	for (int i = 0; i < n; i ++) cin >> k[i];

	vector<vector<array<int, 2>>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	vector<vector<int>> dis(n, vector<int>(n)), path(n, vector<int>(n));
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		path[i][i] = c[i];
		auto dfs = [&](auto &&self, int u, int fa)-> void {
			for (auto [v, w] : g[u]) if (v != fa) {
				dis[i][v] = dis[i][u] + w;
				path[i][v] = path[i][u] ^ c[v];
				self(self, v, u);
			}
		};
		dfs(dfs, i, -1);
		for (int j = i + 1; j < n; j ++) {
			int min = std::min(k[i], k[j]);
			if (min >= dis[i][j] && path[i][j] == 0) {
				ans ++;
			}
		}
	}
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