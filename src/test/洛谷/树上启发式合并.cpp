// https://www.luogu.com.cn/problem/U41492
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
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	vector<int> dfn(n), seg(n), siz(n), son(n, -1);
	int T = 0;
	auto init = [&](this auto &&self, int u, int fa = -1)-> void {
		dfn[u] = T, seg[T ++] = u;
		siz[u] = 1;
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			siz[u] += siz[v];
			if (son[u] == -1 || siz[v] > siz[son[u]]) {
				son[u] = v;
			}
		}
	};
	init(0);

	vector<int> col(n + 1); // 记录每种颜色的数量
	int cnt = 0; // 颜色种类数

	auto add = [&](int c)-> void {
		cnt += (col[c] == 0);
		col[c] ++;
	};

	auto del = [&](int c)-> void {
		cnt -= (col[c] == 1);
		col[c] --;
	};

	vector<int> ans(n); // 记录以1为根的树，以v为根的子树的颜色种类数

	auto dfs = [&](this auto &&self, int u, int keep, int fa = -1)-> void {
		for (auto v : g[u]) if (v != fa && v != son[u]) {
			self(v, 0, u);
		}
		if (son[u] != -1) {
			self(son[u], 1, u);
		}
		add(a[u]);
		for (auto v : g[u]) if (v != fa && v != son[u]) {
			for (int i = dfn[v]; i < dfn[v] + siz[v]; i ++) {
				add(a[seg[i]]);
			}
		}
		ans[u] = cnt;
		if (!keep) {
			for (int i = dfn[u]; i < dfn[u] + siz[u]; i ++) {
				del(a[seg[i]]);
			}
		}
	};
	dfs(0, 0);

	int q;
	cin >> q;
	while (q --) {
		int u;
		cin >> u;
		u --;
		cout << ans[u] << '\n';
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