#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

struct DSU {
	vector<int> f, siz;

	DSU() {}
	DSU(int n) {
		init(n);
	}

	void init(int n) {
		f.resize(n);
		iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}

	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}

	bool cmp(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {//将y合并至x中
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}

	int size(int x) {
		return siz[find(x)];
	}
};

vector<int> minp, p;

void sieve(int n) {
	minp.assign(n + 1, 0);
	p.clear();
	for (int i = 2; i <= n; i ++) {
		if (minp[i] == 0) {
			minp[i] = i;
			p.push_back(i);
		}
		for (auto e : p) {
			if (1ll * i * e > n) {
				break;
			}
			minp[i * e] = e;
			if (e == minp[i]) {
				break;
			}
		}
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto &e : a) cin >> e;

	vector<vector<pair<int, int>>> tot(n);
	vector<vector<int>> mp(1e6 + 1);

	for (int i = 0; i < n; i ++) {
		int cur = a[i];
		while (cur > 1) {
			int cnt = 0, x = minp[cur];
			while (cur % x == 0) {
				cnt ++;
				cur /= x;
			}
			tot[i].push_back({x, cnt});
		}
	}

	auto dfs = [&](auto &&self, int idx, int num, int u)-> void {
		if (idx == tot[u].size()) {
			if (num != 1) mp[num].push_back(u);
			return;
		}
		self(self, idx + 1, num, u);
		for (int i = 1; i <= tot[u][idx].second; i ++) {
			num *= tot[u][idx].first;
			self(self, idx + 1, num, u);
		}
	};
	for (int i = 0; i < n; i ++) {
		dfs(dfs, 0, 1, i);
	}

	DSU dsu(n);
	vector<vector<int>> g(n);

	for (int i = 1e6; i >= 2; i --) {
		auto &v = mp[i];
		for (int j = 1; j < v.size(); j ++) {
			if (dsu.merge(v[j], v[j - 1])) {
				g[v[j - 1]].push_back(v[j]);
				g[v[j]].push_back(v[j - 1]);
			}
		}
	}

	const int pow = 20;
	vector<array<int, pow + 1>> up(n), mn(n);
	vector<int> dep(n), vis(n);

	auto init = [&](this auto && self, int u, int fa)->void {
		up[u][0] = fa;
		vis[u] = true;
		if (fa != -1) mn[u][0] = __gcd(a[u], a[fa]);
		for (int p = 1; dep[u] >> p > 0; p ++) {
			int la = up[u][p - 1];
			up[u][p] = up[la][p - 1];
			mn[u][p] = min(mn[u][p - 1], mn[la][p - 1]);
		}
		for (auto v : g[u]) if (v != fa) {
			dep[v] = dep[u] + 1;
			self(v, u);
		}
	};

	auto lca = [&](int x, int y)->int {
		int res = INF;
		if (dep[x] < dep[y]) {
			swap(x, y);
		}
		for (int p = pow; p >= 0; p --) { // 使x, y跳到同一树高
			if (dep[x] - (1 << p) >= dep[y]) {
				res = min(res, mn[x][p]);
				x = up[x][p];
			}
		}
		if (x == y) { // 已经相等说明y就是x的祖先
			return res;
		}
		for (int p = pow; p >= 0; p --) { // 一起上跳至差一格到lca
			if (up[x][p] != up[y][p]) {
				res = min({res, mn[x][p], mn[y][p]});
				x = up[x][p];
				y = up[y][p];
			}
		}
		return min({res, mn[x][0], mn[y][0]}); // 最后不要忘记再跳一次
	};

	for (int i = 0; i < n; i ++) if (!vis[i]) {
		init(i, -1);
	}

	while (q --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		if (u == v) {
			cout << a[u] << '\n';
			continue;
		}
		if (!dsu.cmp(u, v)) {
			cout << 1 << '\n';
			continue;
		}
		cout << lca(u, v) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	sieve(1e6);
	// cin >> _;
	while (_ --) {
		solve();
	}
}