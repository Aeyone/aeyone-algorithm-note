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
	vector<vector<array<int, 2>>> a(n);
	for (int i = 0; i < m; i ++) {
		int u, t;
		cin >> u >> t;
		u --;
		a[u].push_back({i, t});
	}

	vector<int> dep(n);
	vector<map<int, int>> mp(n);
	auto dfs = [&](auto &&self, int u, int fa = -1)-> void {
		set<int> st;
		for (auto [idx, t] : a[u]) {
			int T = t + dep[u];
			if (mp[u].find(T) != mp[u].end()) {
				st.insert(T);
				mp[u][T] = -1;
			} else {
				mp[u][T] = idx;
			}
		}
		for (auto v : g[u]) if (v != fa) {
			dep[v] = dep[u] + 1;
			self(self, v, u);
			if (mp[v].size() > mp[u].size()) {
				swap(mp[v], mp[u]);
			}
			for (auto [t, idx] : mp[v]) {
				if (mp[u].find(t) != mp[u].end()) {
					st.insert(t);
					mp[u][t] = -1;
				} else {
					mp[u][t] = idx;
				}
			}
		}
		for (auto e : st) {
			mp[u].erase(e);
		}
	};
	dfs(dfs, 0);
	vector<int> ans(m);
	for (auto [e, idx] : mp[0]) {
		ans[idx] = 1;
	}
	for (int i = 0; i < m; i ++) {
		cout << ans[i];
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}