#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;
	vector<vector<int>> g(n);
	for(int v = 1; v < n; v ++){
		int u;
		cin >> u;
		u --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = inf;
	for(auto e : g[0]){
		auto dfs = [&](auto &&self, int u, int fa)->int{
			int mn = inf;
			for(auto v : g[u]) if(v != fa)
				mn = min(mn, self(self, v, u));

			if(a[u] >= mn)
				return mn;
			else
				return ((mn == inf ? a[u] : mn) + a[u]) / 2;
		};
		ans = min(ans, dfs(dfs, e, 0));
	}
	cout << a[0] + ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}