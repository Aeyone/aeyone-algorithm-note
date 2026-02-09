#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/*
*	区间dp + 回文，关键在于状态转移
*	设dp[l][r]为区间[l，r]的最少操作次数
*	对于求dp[l][r]
*	1) 一般的情况(套路)：枚举i(l <= i < r)，dp[l][r] = min(dp[l][i] + dp[i + 1][r]);
*	2) a[l] == a[r]：dp[l][r] = dp[l + 1][r - 1]
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector dp(n, vector<int>(n, INF));
	for (int i = 0; i < n; i ++) {
		dp[i][i] = 1;
		if (i > 0) {
			dp[i - 1][i] = 1 + (a[i - 1] != a[i]);
		}
	}
	for (int len = 3; len <= n; len ++) {
		for (int l = 0; l + len - 1 < n; l ++) {
			int r = l + len - 1;
			if (a[l] == a[r]) {
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
			}
			for (int i = l; i < r; i ++) {
				dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
			}
		}
	}
	cout << dp[0][n - 1] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}