#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int> (m)), dp(n, vector<int> (m));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> g[i][j];

	if((n + m - 1) & 1){
		cout << "NO" << '\n';
		return;
	}
	dp[0][0] = g[0][0];
	for(int i = 1; i < n; i ++)
		dp[i][0] = dp[i - 1][0] + g[i][0];
	for(int i = 1; i < m ; i ++)
		dp[0][i] = dp[0][i - 1] + g[0][i];

	for(int i = 1; i < n; i ++)
		for(int j = 1; j < m; j ++)
			dp[i][j] = max(dp[i - 1][j] + g[i][j], dp[i][j - 1] + g[i][j]);

	int mx = dp[n - 1][m - 1];

	for(int i = 1; i < n; i ++)
		for(int j = 1; j < m; j ++)
			dp[i][j] = min(dp[i - 1][j] + g[i][j], dp[i][j - 1] + g[i][j]);

	int mn = dp[n - 1][m - 1];

	if(mx >= 0 && mn <= 0)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}