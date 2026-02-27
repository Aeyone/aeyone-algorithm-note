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
	int n, m, k;
	cin >> n >> m >> k;
	using T = array<int, 3>;
	vector<vector<T>> g(n);
	for (int i = 0; i < m; i ++) {
		int u, v, c, l;
		cin >> u >> v >> c >> l;
		u --, v --;
		g[u].push_back({v, c, l});
		g[v].push_back({u, c, l});
	}
	vector<vector<array<int, 2>>> a(m + 1);
	vector<array<int, 2>> tot(k);
	for (int i = 0; i < k; i ++) {
		int c, l;
		cin >> c >> l;
		a[c].push_back({i, l});
		tot[i] = {c, l};
	}
	vector<vector<vector<int>>> st(m + 1);
	for (int i = 1; i <= m; i ++) {
		st[i].assign(a[i].size(), vector<int>(21));

		for (int j = 0; j < a[i].size(); j ++) {
			st[i][j][0] = a[i][j][1];
		}
		for (int p = 1; a[i].size() >> p > 0; p ++) {
			for (int j = 0; j + (1 << p) <= a[i].size(); j ++) {
				st[i][j][p] = max(st[i][j][p - 1], st[i][j + (1 << (p - 1))][p - 1]);
			}
		}
	}
	auto query = [&](int c, int l, int r)->int{
		int d = __lg(r - l + 1);
		return max(st[c][l][d], st[c][r - (1 << d) + 1][d]);
	};

	priority_queue<T, vector<T>, greater<T>> heap;
	vector<int> vis(n);

	heap.push({-1, 0, 0});

	while (heap.size()) {
		auto [t, d, u] = heap.top();
		heap.pop();

		if (vis[u]) {
			continue;
		}
		vis[u] = true;

		for (auto [v, c, len] : g[u]) {
			if (t != -1 && c == tot[t][0] && len <= tot[t][1] - d) {
				heap.push({t, d + len, v});
			} else {
				int l = lower_bound(a[c].begin(), a[c].end(), array<int, 2>{t, INF}) - a[c].begin();
				int r = a[c].size() - 1;
				int tar = -1;
				while (l <= r) {
					int mid = l + r >> 1;
					if (query(c, l, mid) >= len) {
						tar = mid, r = mid - 1;
					} else {
						l = mid + 1;
					}
				}
				if (tar != -1) {
					heap.push({a[c][tar][0], len, v});
				}
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		cout << vis[i];
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