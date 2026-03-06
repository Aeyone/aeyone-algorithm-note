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
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<i64> ans(n), sum(n), son(n);
	vector<int> dep(n), depm(n), exc(n);

	auto dfs = [&](this auto &&self, int u, int fa = -1)->void {
		int cur = dep[u];
		son[u] = a[u];
		if (fa != -1) {
			dep[u] = dep[fa] + 1;
			depm[u] = dep[u];
		}
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			son[u] += son[v];
			sum[u] += sum[v] + son[v];
			depm[u] = max(depm[u], depm[v]);
			exc[v] = cur;
			cur = max(cur, depm[v]);
		}
		cur = dep[u];
		ans[u] = max(ans[u], sum[u]);
		for (int i = g[u].size() - 1; i >= 0; i --) {
			int v = g[u][i];
			if (v == fa) {
				continue;
			}
			exc[v] = max(exc[v], cur);
			cur = max(cur, depm[v]);
			ans[u] = max(ans[u], sum[u] - sum[v] + ans[v]);
			ans[u] = max(ans[u], sum[u] + son[v] * (exc[v] - dep[u]));
		}
	};
	dfs(0);
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
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