#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<i64>> g(n, vector<i64>(m));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cin >> g[i][j];
		}
	}
	auto idx = [&](int x, int y)->int{
		return m * x + y;
	};
	int cur = 0;
	vector<bool> vis(1 << 20);
	auto dfs = [&](auto &&self, int u)->void{
		int x = u / m, y = u % m;
		if(x == n - 1 && y == m - 1){
			vis[cur] = true;
			return;
		}
		self(self, u + 1);
		if(!(cur >> idx(x, y) & 1)){
			cur ^= (1 << idx(x, y));
			if(y + 1 < m && !(cur >> idx(x, y + 1) & 1)){
				cur ^= (1 << idx(x, y + 1));
				self(self, u + 1);
				cur ^= (1 << idx(x, y + 1));
			}
			if(x + 1 < n && !(cur >> idx(x + 1, y) & 1)){
				cur ^= (1 << idx(x + 1, y));
				self(self, u + 1);
				cur ^= (1 << idx(x + 1, y));
			}
			cur ^= (1 << idx(x, y));
		}
	};
	dfs(dfs, 0);
	i64 ans = -INFLL;
	for(int mask = 0; mask < 1 << n * m; mask ++){
		if(!vis[mask]){
			continue;
		}
		i64 tot = 0;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				if(!(mask >> idx(i, j) & 1)){
					tot ^= g[i][j];
				}
			}
		}
		ans = max(ans, tot);
	}
	cout << ans << '\n';
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