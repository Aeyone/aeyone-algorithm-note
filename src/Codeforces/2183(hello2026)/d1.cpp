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
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> fa(n), d(n);
	auto dfs = [&](auto &&self, int u, int f)->void{
		for (auto v : g[u]) {
			if (v == f) {
				continue;
			}
			fa[v] = u;
			d[v] = d[u] + 1;
			self(self, v, u);
		}
	};
	dfs(dfs, 0, -1);
	// for (auto e : fa) {
	// 	cout << e << ' ';
	// }
	// cout << '\n';

	vector<int> cnt(n);
	for (int i = 0; i < n; i ++) {
		cnt[d[i]] ++;
	}
	int mx = *max_element(cnt.begin(), cnt.end());
	vector<set<int>> vv(n);
	bool ok = true;
	for (int i = 0; i < n; i ++) {
		if (cnt[d[i]] != mx) {
			continue;
		}
		vv[d[i]].insert(fa[i]);
	}
	for (int i = 0; i < n; i ++) {
		ok &= (vv[d[i]].size() >= 2 || vv[d[i]].size() == 0);
	}
	cout << mx + (!ok) << '\n';
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