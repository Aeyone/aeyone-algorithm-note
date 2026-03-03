#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;



void solve() {
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;

	vector<int> to(n + 1), stk;
	for (int i = 1; i <= n; i ++) {
		if (s[i] == '(') {
			stk.push_back(i);
		} else {
			to[stk.back()] = i;
			stk.pop_back();
		}
	}

	// dp[l][r][i][j]代表区间[l，r]，且l为颜色i，r颜色为j的方案数
	vector dp(n + 1, vector(n + 1, vector(3, vector<i64>(3))));
	
	auto dfs = [&](this auto &&self, int l, int r)->void { // 保证l~r为一个合法括号序列
		if (l + 1 == r) {
			dp[l][r][0][1] = dp[l][r][1][0] = dp[l][r][0][2] = dp[l][r][2][0] = 1;
		} else if (r == to[l]) {
			self(l + 1, r - 1);
			for (int i = 0; i < 3; i ++) {
				for (int j = 0; j < 3; j ++) {
					if (j != 1) {
						dp[l][r][0][1] = (dp[l][r][0][1] + dp[l + 1][r - 1][i][j]) % MOD;
					}
					if (i != 1) {
						dp[l][r][1][0] = (dp[l][r][1][0] + dp[l + 1][r - 1][i][j]) % MOD;
					}
					if (j != 2) {
						dp[l][r][0][2] = (dp[l][r][0][2] + dp[l + 1][r - 1][i][j]) % MOD;
					}
					if (i != 2) {
						dp[l][r][2][0] = (dp[l][r][2][0] + dp[l + 1][r - 1][i][j]) % MOD;
					}
				}
			}
		} else {
			self(l, to[l]), self(to[l] + 1, r);
			for (int i = 0; i < 3; i ++) {
				for (int j = 0; j < 3; j ++) {
					for (int p = 0; p < 3; p ++) {
						for (int q = 0; q < 3; q ++) {
							if (j == p && j != 0 && p != 0) {
								continue;
							}
							dp[l][r][i][q] = (dp[l][r][i][q] + dp[l][to[l]][i][j] * dp[to[l] + 1][r][p][q] % MOD) % MOD;
						}
					}
				}
			}
		}
	};

	dfs(1, n);
	i64 ans = 0;
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++) {
			ans = (ans + dp[1][n][i][j]) % MOD;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}