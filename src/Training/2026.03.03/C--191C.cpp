#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/*
*	树上倍增求lca模板，树上差分
*/

void solve() {
	int n;
	cin >> n;
	vector<vector<array<int, 2>>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	vector up(n, vector<int>(21));
	vector<int> dep(n);

	auto init = [&](this auto &&self, int u, int fa)->void {
		up[u][0] = fa;
		for (int p = 1; dep[u] >> p > 0; p ++) {
			int la = up[u][p - 1];
			up[u][p] = up[la][p - 1];
		}
		for (auto [v, _] : g[u]) if (v != fa) {
			dep[v] = dep[u] + 1;
			self(v, u);
		}
	};
	init(0, -1);

	auto lca = [&](int x, int y)->int {
		if (dep[x] < dep[y]) {
			swap(x, y);
		}
		for (int p = 20; p >= 0; p --) {
			if (dep[x] - (1 << p) >= dep[y]) {
				x = up[x][p];
			}
		}
		if (x == y) {
			return x;
		}
		for (int p = 20; p >= 0; p --) {
			if (up[x][p] != up[y][p]) {
				x = up[x][p];
				y = up[y][p];
			}
		}
		return up[x][0];
	};

	vector<int> d(n), res(n);

	int q;
	cin >> q;
	while (q --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		d[u] ++, d[v] ++;
		d[lca(u, v)] -= 2;
	}

	auto dfs = [&](this auto &&self, int u, int fa)->void {
		for (auto [v, id] : g[u]) if (v != fa) {
			self(v, u);
			d[u] += d[v];
			res[id] = d[v];
		}
	};
	dfs(0, -1);

	for (int i = 1; i < n; i ++) {
		cout << res[i] << ' ';
	}
	cout << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}