#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<vector<int>> g(n);
	vector<int> in(n);
	bool ok = true;
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		ok &= (v != u);
		g[u].push_back(v);
		in[v] ++;
	}
	for(int i = 0; i < n; i ++){
		sort(g[i].begin(), g[i].end());
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
	}
	vector<array<int, 26>> dp(n);
	vector<int> vis(n), now(n);

	auto dfs = [&](auto &&self, int u)->int{
		dp[u][s[u] - 'a'] ++;
		bool ok = true;
		for(auto v : g[u]){
			if(!now[v]){
				now[v] = true;
				if(!vis[v]){
					vis[v] = true;
					ok &= self(self, v);
				}
				for(int i = 0; i < 26; i ++){
					dp[u][i] = max(dp[u][i], dp[v][i] + (s[u] - 'a' == i));
				}
				now[v] = false;
			}else{
				return false;
			}
		}
		return ok;
	};

	int cnt = 0;
	for(int i = 0; i < n; i ++){
		if(!in[i]){
			cnt ++;
			now[i] = true;
		 	ok &= dfs(dfs, i);
			now[i] = false;
		}
	}
	if(!ok || cnt == 0){
		cout << -1 << '\n';
	}else{
		int ans = -INF;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < 26; j ++){
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}