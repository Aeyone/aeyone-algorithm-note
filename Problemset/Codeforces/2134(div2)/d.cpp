#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<int> deep(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto dfs = [&](auto &&self, int u, int fa)->void{
		if(g[u].size() == 1)
			return;

		int mn = inf;
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
			mn = min(mn, deep[v]);
		}
		deep[u] += mn + 1;
	};
	for(int i = 0; i < n; i ++){
		if(g[i].size() > 2){
			dfs(dfs, i, -1);
			int a, b, c;
			b = i;
			a = g[i][0];
			c = g[i][1];
			for(auto e : g[i]){
				if(deep[e] > deep[a])
					a = e;
				if(deep[e] < deep[c])
					c = e;
			}
			cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}