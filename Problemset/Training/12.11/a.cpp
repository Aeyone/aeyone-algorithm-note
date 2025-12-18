#include <bits/stdc++.h>

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> c(n + 1), h(n + 1);
	int sum = 0;
	for(int i = 1; i <= n; i ++) {
		std::cin >> c[i] >> h[i];
		sum += h[i];
	}
	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(sum + 1, -INFLL));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= sum; j ++){
			dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + x);
			if(j >= h[i] && dp[i - 1][j - h[i]] >= c[i]){
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j - h[i]] - c[i] + x);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= sum; i ++){
		ans = (dp[n][i] >= 0 ? i : ans);
	}
	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cout << std::fixed << std::setprecision(10);
	int _ = 1;
	std::cin >> _;
	while (_ --){
		solve();
	}
}