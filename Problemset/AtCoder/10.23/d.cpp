#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(m, vector<int>(n)), vis(n + 1, vector<int>(n + 1));
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			cin >> g[i][j];
		}
	}
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			if(j - 1 >= 0){
				vis[g[i][j]][g[i][j - 1]] = true; 
			}
			if(j + 1 < n){
				vis[g[i][j]][g[i][j + 1]] = true;
			}
		}
	}
	vector<array<int, 2>> ans;
	for(int i = 1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
			if(!vis[i][j]){
				ans.push_back({i, j});
			}
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}