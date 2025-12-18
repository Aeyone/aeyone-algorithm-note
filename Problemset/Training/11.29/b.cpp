#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

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
	vector<int> siz(n, 1), son(n), root;
	auto dfs = [&](auto &&self, int u, int fa)->void{
		int mx = 0;
		son[u] = u;
		for(auto v : g[u]) if(v != fa){
			self(self, v, u);
			siz[u] += siz[v];
			son[u] = son[v];
			mx = max(mx, siz[v]);
		}
		mx = max(mx, n - siz[u]);
		if(mx <= n / 2){
			root.push_back(u);
		}
	};
	dfs(dfs, 0, -1);
	if(root.size() == 1){
		cout << 1 << ' ' << g[0][0] + 1 << '\n';
		cout << 1 << ' ' << g[0][0] + 1 << '\n';
	}else{
		int e = son[root[0]];
		cout << e + 1 << ' ' << g[e][0] + 1 << '\n';
		cout << e + 1 << ' ' << root[1] + 1 << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}