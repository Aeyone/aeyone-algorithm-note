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
	int n, k, v;
	cin >> n >> k >> v;
	v --;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> mn(n, INF);
	auto dfs = [&](this auto &&self, int u, int fa = -1)->void {
		int cnt = 0;
		if (g[u].size() == 1) {
			mn[u] = 0;
			return;
		}
		multiset<int> st;
		st.insert(INF);
		for (auto v : g[u]) if(v != fa) {
			self(v, u);
			st.insert(mn[v]);
			mn[u] = min(mn[u], mn[v] + 1);
		}
		if (*st.begin() + *(++st.begin()) + 1 <= k) {
			mn[u] = 0;
		}
	};
	dfs(v);
	if (mn[v] == 0) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
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