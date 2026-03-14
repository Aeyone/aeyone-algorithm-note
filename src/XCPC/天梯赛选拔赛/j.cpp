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
	vector<int> a(n), stk;
	vector<vector<int>> g(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		while (stk.size() && a[stk.back()] > a[i]) {
			stk.pop_back();
		}
		if (stk.size()) {
			int u = stk.back();
			g[u].push_back(i);
			g[i].push_back(u);
		}
		stk.push_back(i);
	}

	int pow = __lg(n) + 1;
	vector st(n, vector<int>(pow + 1));
	vector<int> dep(n);

	auto dfs = [&](this auto &&self, int u, int fa = -1)-> void {
		if (fa != -1) {
			st[u][0] = fa;
		}
		for (int p = 1; p <= pow; p ++) {
			int la = st[u][p - 1];
			st[u][p] = st[la][p - 1];
		}
		for (int v : g[u]) if (v != fa) {
			dep[v] = dep[u] + 1;
			self(v, u);
		}
	};
	dfs(0);

	auto lca = [&](int x, int y)-> int {
		if (dep[x] < dep[y]) {
			swap(x, y);
		}
		for (int i = pow; i >= 0; i --) {
			if (dep[st[x][i]] >= dep[y]) {
				x = st[x][i];
			}
		}
		if (x == y) {
			return y;
		}
		for (int i = pow; i >= 0; i --) {
			if (st[x][i] != st[y][i]) {
				x = st[x][i];
				y = st[y][i];
			}
		}
		return st[x][0];
	};

	int q;
	cin >> q;
	while (q --) {
		int x, y, z;
		cin >> x >> y >> z;
		x --, y --, z --;
		int xy = lca(x, y);
		if (lca(z, xy) != xy) {
			cout << 0 << '\n';
			continue;
		}
		int inx = lca(z, x), iny = lca(z, y);
		int in = (inx == xy ? iny : inx);

		int tStart = dep[z] - dep[in];
		int len = dep[x] + dep[y] - 2 * dep[xy];
		int cnt = tStart / len, r = tStart % len;

		auto getpos = [&](int cur, int d)->int {
			while (d) {
				int x = d & -d;
				cur = st[cur][__lg(x)];
				d -= x;
			}
			return cur;
		};

		int lenx = dep[x] - dep[xy], leny = dep[y] - dep[xy];

		int pos;
		if (cnt & 1) {
			pos = r > leny ? getpos(x, leny + lenx - r) : getpos(y, r);
		} else {
			pos = r > lenx ? getpos(y, leny + lenx - r) : getpos(x, r);
		}

		cout << !((dep[pos] + dep[in] - 2 * dep[xy]) & 1) << '\n';
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