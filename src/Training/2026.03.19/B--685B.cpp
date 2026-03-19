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
	int n, q;
	cin >> n >> q;
	vector<vector<int>> g(n);
	for (int v = 1; v < n; v ++) {
		int u;
		cin >> u;
		u --;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> dep(n), siz(n), son(n, -1), f(n), w(n); // w[u]为在不确定根的情况下，去掉u节点之后连通块的最大节点数

	auto dfs1 = [&](this auto &&self, int u)-> void {
		siz[u] = 1;
		for (auto v : g[u]) if (v != f[u]) {
			dep[v] = dep[u] + 1;
			f[v] = u;
			self(v);
			siz[u] += siz[v];
			w[u] = max(w[u], siz[v]);
		}
		for (auto v : g[u]) if (v != f[u]) {
			if (son[u] == -1 || siz[son[u]] < siz[v]) {
				son[u] = v;
			}
		}
	};

	vector<int> tail(n), dfn(n), seg(n);
	int T = 0;
	auto dfs2 = [&](this auto &&self, int u)-> void {
		tail[u] = u, dfn[u] = T, seg[T ++] = u;
		if (son[u] != -1) {
			self(son[u]);
			tail[u] = tail[son[u]];
		}
		for (auto v : g[u]) if (v != f[u] && v != son[u]) {
			self(v);
		}
	};

	vector<int> ans(n);
	auto dfs3 = [&](this auto &&self, int u)-> void {
		for (auto v : g[u]) if (v != f[u]) {
			self(v);
		}
		int cur = (son[u] == -1 ? u : ans[son[u]]);
		while (max(siz[u] - siz[cur], w[cur]) > siz[u] / 2) {
			cur = seg[dfn[cur] - 1];
		}
		ans[u] = cur;
	};
	dfs1(0);
	dfs2(0);
	dfs3(0);

	while (q --) {
		int u;
		cin >> u;
		u --;
		cout << ans[u] + 1<< '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}