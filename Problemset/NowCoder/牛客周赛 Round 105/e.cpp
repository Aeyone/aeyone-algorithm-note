#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), vis(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	i64 ans = 0;
	auto dfs = [&](auto &&self, int u)->void{
		for(auto v : g[u]) if(!vis[v]){
			vis[v] = true;
			self(self, v);
		}
		for(int i = 0; i <= 31; i ++){
			int x = (a[u] >> i) & 1;
			int pre[2] = {0, 0};
			for(auto v : g[u]){
				int y = (a[v] >> i) & 1;
				int tar = 1 ^ x ^ y;
				ans = (ans + (1ll << i) * pre[tar]) % mod;
				pre[y] ++;
			}
		}
	};
	vis[0] = true;
	dfs(dfs, 0);
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}