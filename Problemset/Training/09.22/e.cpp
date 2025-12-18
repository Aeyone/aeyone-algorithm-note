#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 infll = 0x3f3f3f3f3f3f3f3f;

void solve() {//很有趣的dp题
	int n, k;
	cin >> n >> k;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	vector<vector<i64>> dp(n, vector<i64>(32, -infll));
	dp[0][0] = a[0] - k;
	dp[0][1] = a[0] / 2;
	i64 ans = -infll;
	for(int i = 0; i < n - 1; i ++){
		for(int j = 0; j <= min(30, i + 1); j ++){	
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (a[i + 1] >> j) - k);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (a[i + 1] >> (j + 1)));
		}
		ans = max(ans, dp[i + 1][31]);
	}
	for(int i = 0; i <= 31; i ++){
		ans = max(ans, dp[n - 1][i]);
	}
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