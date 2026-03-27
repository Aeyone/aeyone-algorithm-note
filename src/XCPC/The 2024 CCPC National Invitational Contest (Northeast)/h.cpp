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
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<array<int, 4>> a(m);
	for (auto &[x, y, _, __] : a) {
		cin >> x >> y;
	}

	vector<int> dep(n), siz(n), son(n, -1), f(n);
	auto init = [&](this auto &&self, int u, int fa = -1)-> void {
		siz[u] = 1;
		for (auto v : g[u]) if (v != fa) {
			dep[v] = dep[u] + 1;
			f[v] = u;
			self(v, u);
			siz[u] += siz[v];
			if (son[u] == -1 || siz[v] > siz[son[u]]) {
				son[u] = v;
			}
		}
	};
	init(0);

	vector<int> in(n + 1), out(n + 1), top(n);
	int t = 1;
	auto dfs = [&](this auto &&self, int u, int fa, int ftop)-> void {
		in[u] = t ++;
		top[u] = ftop;
		if (son[u] != -1) {
			self(son[u], u, ftop);
		}
		for (auto v : g[u]) if (v != fa && v != son[u]) {
			self(v, u, v);
		}
		out[u] = t;
	};
	dfs(0, -1, 0);


	auto lca = [&](int x, int y)-> int {
		int len = 0;
		while (top[x] != top[y]) {
			if (dep[top[x]] < dep[top[y]]) {
				swap(x, y);
			}
			len += (dfn[top[x]] - dfn[x]);
			x = f[top[x]];
		}
		len += abs(dfn[y] - dfn[x]);
		return (dfn[x] < dfn[y] ? x : y);
	};

	auto jump = [&](int u, int k)-> int {
		if (dep[u] < k) {
			return -1;
		}
		int d = dep[u] - k;
		while (dep[top[u]] > d) {
			u = f[top[u]];
		}
		return seg[dfn[u] - (dep[u] - d)];
	};




	for (auto &[x, y, d, lca] : a) {
		auto [a, b] = getInfo(x, y);
		d = a, lca = b;
	}

	auto check = [&](int D)-> bool {
		bool ok = true;
		for (auto [x, y, d, lca] : a) {
			ok &= (d <= 2 * D);
		}
		if (!ok) {
			return false;
		}
		vector<int> dif(n);
		for (auto [x, y, d, lca] : a) {
			if (d > D) {
				int dx = dep[x] - dep[lca], dy = dep[y] - dep[lca];
				int l, r;
				if (dy >= D) {
					l = jump(y, D);
				} else {
					l = jump(x, dx + dy - D);
				}
				if (dx >= D) {
					r = jump(x, D);
				} else {
					r = jump(y, dx + dy - D);
				}
				if (getInfo(l, r).second == l) {
					dif[jump(y, dx + dy - D - 1)];
				}
			}
		}
		for (int i = 1; i <= n; i ++) {
			dif[i] += dif[i - 1];
		}

		auto dfs = [&](this auto &&self, int u)-> void {

		}

	};

	int l = 0, r = n, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
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