#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n = 4, q;
	vector<int> c(n + 1);
	cin >> c[1] >> c[2] >> c[3] >> c[4] >> q;

	vector<i64> dp(1e5 + 1);
	dp[0] = 1;

	for (int i = 1; i <= 4; i ++) {
		for (int j = c[i]; j <= 1e5; j ++) {
			dp[j] += dp[j - c[i]];
		}
	}

	// for (int i = 1; i <= 20; i ++) {
	// 	cout << dp[i] << '\n';
	// }

	while (q --) {
		vector<int> d(n + 1);
		int s;
		cin >> d[1] >> d[2] >> d[3] >> d[4] >> s;

		i64 ans = dp[s];

		for (int mask = 1; mask < 1 << n; mask ++) {
			i64 sum = 0;
			for (int i = 0; i < n; i ++) if (mask >> i & 1) {
				sum += 1ll * c[i + 1] * (d[i + 1] + 1);
			}
			if (sum <= s) {
				ans += (__builtin_popcount(mask) & 1) ? -dp[s - sum] : dp[s - sum]; 
			}
		}

		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}