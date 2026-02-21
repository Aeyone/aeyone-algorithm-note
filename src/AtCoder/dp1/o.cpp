#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

/*
*	状压DP，按照二进制数中1的个数层层枚举
*/

void solve() {
	int n;
	cin >> n;
	vector g(n, vector<int> (n));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> g[i][j];
		}
	}
	vector<vector<int>> bucket(n + 1);
	for (int mask = 0; mask < 1 << n; mask ++) {
		bucket[__builtin_popcount(mask)].push_back(mask);
	}

	vector<i64> dp(1 << n, -1);
	dp[0] = 1;
	for (int i = 1; i <= n; i ++) {
		for (auto mask : bucket[i]) {
			for (int j = 0; j < n; j ++) {
				if ((mask >> j & 1) && dp[mask ^ (1 << j)] != -1 && g[i - 1][j]) {
					if (dp[mask] == -1) {
						dp[mask] = 0;
					}
					dp[mask] = (dp[mask] + dp[mask ^ (1 << j)]) % MOD;
				}
			}
		}
	}
	cout << (dp[(1 << n) - 1] == -1 ? 0 : dp[(1 << n) - 1]) << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}