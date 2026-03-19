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
	vector<vector<array<int, 2>>> g(n);
	for (int v = 1; v < n; v ++) {
		int u, w;
		cin >> u >> w;
		u --;
		g[v].push_back({u, w});
		g[u].push_back({v, w});
	}
	vector<int> dep(n), d(n);
	vector up(n, vector<int>(21));
	vector sum(n, vector<i64>(21));
	auto dfs = [&](this auto &&self, int u, int fa = -1)-> void {
		up[u][0] = fa;
		for (int p = 1; p < 21; p ++) {
			int la = up[u][p - 1];
			if (la != -1) {
				up[u][p] = up[la][p - 1];
				sum[u][p] = sum[u][p - 1] + sum[la][p - 1];
			}
		}
		for (auto [v, w] : g[u]) if (v != fa) {
			sum[v][0] = w;
			dep[v] = dep[u] + 1;
			self(v, u);
			d[u] += d[v];
		}
		
		auto jump = [&](int x, int dis)-> pair<i64, int> {
			i64 res = 0;
			while (dis > 0) {
				int low = dis & -dis;
				res += sum[x][__lg(low)];
				x = up[x][__lg(low)];
				dis -= low;
			}
			return {res, x};
		};

		int l = 0, r = dep[u], ans = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (jump(u, mid).first <= a[u]) {
				ans = mid, l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if (fa != -1) {
			d[fa] ++;
		}
		ans = jump(u, ans + 1).second;
		if (ans != -1) {
			d[ans] --;
		}
	};
	dfs(0);
	for (int i = 0; i < n; i ++) {
		cout << d[i] << ' ';
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