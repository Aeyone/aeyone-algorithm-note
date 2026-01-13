#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;
/*
	对于所有的j：枚举所有可能操作的长度k
	dp[i][j] = dp[i - k - 1][j - k] + min(a[i - k : i])
*/
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, INFLL));//前i个数中使用恰好j次操作的最小值
	dp[0][0] = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= m; j ++){
			int mn = a[i];
			for(int k = 0; k <= min(j, i - 1); k ++){
				mn = min(mn, a[i - k]);
				dp[i][j] = min(dp[i][j], dp[i - k - 1][j - k] + mn * (k + 1));
			}
		}
	}
	int ans = INFLL;
	for(int i = 0; i <= m; i ++){
		ans = min(ans, dp[n][i]);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}