#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int P = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i < n; i ++) {
		if (g[i].size() == 1 && a[i] == 0) {
			cout << 0 << '\n';
			return;
		}
	}
	vector<vector<int>> dp(n, vector<int>(n + 1));
	vector<int> siz(n);

	auto dfs = [&](this auto &&self, int u, int fa = -1)-> void {
		dp[u][0] = 1;
		if (u != 0 && g[u].size() == 1 && a[u] == 1) {
			dp[u][1] = 1;
		}

		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			vector<int> c(n + 1);
			for (int i = 0; i <= siz[u]; i ++) {
				for (int j = 0; j <= siz[v]; j ++) {
					if (i + j <= n) {
						c[i + j] = (c[i + j] + 1ll * dp[u][i] * dp[v][j] % P) % P;
					}
				}
			}
			siz[u] += siz[v];
			dp[u] = c;
		}
		siz[u] ++;

		if (a[u] > 0) {
			dp[u][a[u]] = dp[u][a[u] - 1];
		} else {
			dp[u][a[u]] = 0;
		}
	};
	dfs(0);

	i64 ans = 0;
	for (auto e : dp[0]) {
		ans = (ans + e + P) % P;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}