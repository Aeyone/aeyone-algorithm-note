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
	vector<int> a(n), b(n);
	for (auto &e : a) {
		cin >> e;
	}
	for (auto &e : b) {
		cin >> e;
	}
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> dfn(n), seg(n), siz(n), son(n, -1), zero(n);
	int T = 0;
	auto init = [&](this auto &&self, int u, int fa = -1)-> void {
		dfn[u] = T, seg[T ++] = u;
		siz[u] = 1;
		zero[u] = (a[u] == 0);
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			siz[u] += siz[v];
			zero[u] += zero[v];
			if (son[u] == -1 || siz[v] > siz[son[u]]) {
				son[u] = v;
			}
		}
	};
	init(0);

	vector<int> cnt(n + 1);
	int neg = 0; // 负数的总和

	auto add = [&](int num)-> void {
		if (num != 0) {
			neg -= (cnt[num] < 0);
			cnt[num] ++;
		}
	};

	auto del = [&](int num)-> void {
		if (num != 0) {
			neg += (cnt[num] <= 0);
			cnt[num] --;
		}
	};

	vector<int> ans(n);
	auto dfs = [&](this auto &&self, int u, int fa = -1, int keep = 0)-> void {
		for (auto v : g[u]) if (v != fa && v != son[u]) {
			self(v, u, 0);
		}
		if (son[u] != -1) {
			self(son[u], u, 1);
		}
		add(a[u]);
		del(b[u]);
		for (auto v : g[u]) if (v != fa && v != son[u]) {
			for (int i = dfn[v]; i < dfn[v] + siz[v]; i ++) {
				add(a[seg[i]]);
				del(b[seg[i]]);
			}
		}
		ans[u] = (zero[u] >= neg);
		if (!keep) {
			for (int i = dfn[u]; i < dfn[u] + siz[u]; i ++) {
				del(a[seg[i]]);
				add(b[seg[i]]);
			}
		}

	};
	dfs(0);
	for (int i = 0; i < n; i ++) {
		cout << ans[i];
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