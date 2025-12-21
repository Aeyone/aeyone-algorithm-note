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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n);
	for(int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> vis(n), cnt(n);
	int root = 0;
	for(int i = 0; i < k; i ++) {
		cin >> root;
		root --;
		vis[root] = true;
	}
	auto dfs = [&](auto &&self, int u, int fa)->void{
		for(int v : g[u]) if(v != fa) {
			self(self, v, u);
			cnt[u] += cnt[v];
		}
		if(vis[u] || cnt[u] != 0) {
			cnt[u] ++;
		}
	};
	dfs(dfs, root, -1);
	cout << cnt[root] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}