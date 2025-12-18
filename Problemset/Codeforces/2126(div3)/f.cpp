#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<vector<array<int, 2>>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v, c;
		cin >> u >> v >> c;
		u --, v --;
		int x = min(u, v), y = max(u, v);
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	vector<map<int, i64>> cost(n);
	vector<int> fa(n), wfa(n);
	i64 res = 0;

	auto dfs = [&](auto &&self, int u)->void{
		for(auto [v, w] : g[u]) if(v != fa[u]){
			fa[v] = u, wfa[v] = w;
			cost[u][a[v]] += w;
			if(a[u] != a[v])
				res += w;
			self(self, v);
		}
	};
	dfs(dfs, 0);

	while(q --){
		int u, x;
		cin >> u >> x;
		u --;
		if(a[u] != x){
			if(x == a[fa[u]])
				res -= wfa[u];
			if(x != a[fa[u]] && a[fa[u]] == a[u])
				res += wfa[u];

			cost[fa[u]][a[u]] -= wfa[u];
			cost[fa[u]][x] += wfa[u];

			res += cost[u][a[u]];
			res -= cost[u][x];

			a[u] = x;
		}
		cout << res << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}