#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for(int i = 1; i <= n; i ++){
		int x, y;
		cin >> x >> y;
		g[i].push_back(x);
		g[i].push_back(y);
	}
	vector<vector<int>> dp(n + 1, vector<int>(30, 2e9));
	dp[0][1] = 1;
	for(int i = 0; i <= n; i ++)
		dp[i][0] = 0;

	for(int i = 2; i < 30; i ++)
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2] + 1;

	auto dfs = [&](auto &&self, int u)->int{
		for(auto v : g[u]) if(v != 0){
			dp[u][0] += self(self, v);
		}
		dp[u][0] ++;
		dp[u][1] = dp[g[u][0]][0] + dp[g[u][1]][0];
		for(int h = 2; h < 30; h ++){
			dp[u][h] = min(dp[u][h], dp[g[u][0]][h - 1] + dp[g[u][1]][h - 1]);
			dp[u][h] = min(dp[u][h], dp[g[u][0]][h - 1] + dp[g[u][1]][h - 2]);
			dp[u][h] = min(dp[u][h], dp[g[u][0]][h - 2] + dp[g[u][1]][h - 1]);
		}
		return dp[u][0];
	};
	dfs(dfs, 1);
	int ans = 2e9;
	for(int i = 0; i < 30; i ++)
		ans = min(ans, dp[1][i]);

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}