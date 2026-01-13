#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n; 
	cin >> n;
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> len(n, inf);
	auto dfs = [&](auto &&self, int u, int fa)->void{
		int siz = 0;
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
			len[u] = min(len[u], len[v] + 1);
			siz ++;
		}
		if(siz == 0)
			len[u] = 1;
		if(siz == 1)
			len[u] = 2;
		if(siz == 2)
			len[u] ++;
	};
	dfs(dfs, 0, -1);
	cout << n - len[0] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}