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
	vector<vector<int>> g(n);
	int cnt = 0;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		int siz;
		cin >> siz;
		while (siz --) {
			int x;
			cin >> x;
			x --;
			a[i] |= (1 << x);
		}
	}

	int tot = 0;
	vector dp(n, vector<int>(1 << m));
	auto dfs1 = [&](this auto &&self, int u, int fa) -> void {
		if (g[u].size() == 1) {
			cnt ++;
			if (fa != -1) dp[u][a[u]] = 1;
		} else {
			tot |= a[u];
		}
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			for (int i = 0; i < 1 << m; i ++) {
				dp[u][i | a[u]] += dp[v][i];
			}
		}
	};
	dfs1(0, -1);

	vector ans(n, vector<int>(1 << m));
	ans[0] = dp[0];
	auto dfs2 = [&](this auto &&self, int u, int fa)-> void {
		if (fa != -1) {
			auto up = ans[fa];
			ans[u] = dp[u];
			if (g[u].size() == 1) ans[u][a[u]] --;
			if (g[fa].size() == 1) up[a[fa]] ++;
			for (int i = 0; i < 1 << m; i ++) {
				up[i | a[fa]] -= dp[u][i];
			}
			for (int i = 0; i < 1 << m; i ++) {
				ans[u][i | a[u]] += up[i];
			}
		}
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
		}
	};
	dfs2(0, -1);

	for (int i = 0; i < n; i ++) {
		int res = cnt, tmp = tot;
		if (g[i].size() == 1) {
			tmp |= a[i];
			res --;
		}
		int mx = 0;
		for (int j = 0; j < 1 << m; j ++) {
			mx = max(mx, ans[i][tmp | j]);
		}	
		cout << res - mx << ' ';
	}
	cout << '\n';
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