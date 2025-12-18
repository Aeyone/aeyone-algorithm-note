#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m, x;
	cin >> n >> m >> x;
	bitset<200000> bomb, vis;
	for(int i = 0; i < x; i ++){
		int e; cin >> e, bomb[e - 1] = true;
	}
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> res = {0};
	auto dfs = [&](auto &&self, int u)->void{
		for(auto v : g[u]) if(!vis[v] && !bomb[v]){
			res.push_back(v);
			vis[v] = true;
			self(self, v);
		}
	};
	vis[0] = true;
	dfs(dfs, 0);
	sort(res.begin(), res.end());
	for(auto e : res)
		cout << e + 1 << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}