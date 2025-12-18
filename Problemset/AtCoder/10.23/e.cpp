#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	vector<vector<int>> swp(n, vector<int>(n));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			int cnt = 0;
			for(int k = 0; k < m; k ++){
				cnt += (g[i][k] != g[j][k]);
			}
			swp[i][j] = (cnt == 1);
		}
	}
	bool ok = false;
	for(int i = 0; i < n; i ++){
		vector<bool> vis(n);
		auto dfs = [&](auto &&self, int u, int cnt)->bool{
			if(cnt == n){
				return true;
			}
			bool ok = false;
			for(int i = 0; i < n; i ++){
				if(vis[i] || !swp[u][i]){
					continue;
				}
				vis[i] = true;
				ok |= self(self, i, cnt + 1);
				vis[i] = false;
			}
			return ok;
		};
		vis[i] = true;
		ok |= dfs(dfs, i, 1);
	}
	if(ok){
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
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