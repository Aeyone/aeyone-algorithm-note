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
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) cin >> a[i];

	vector<i64> pre(n + 1);

	for (int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];

	vector dp(n + 1, vector<i64>(2 * n + 1));
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= 2 * n; j ++) {
			dp[i][j] = max(pre[min(n, i + j)] - pre[i - 1], pre[i] - pre[max(1, i - j) - 1]);
		}
	}

	for (int j = 1; j < 2 * n; j ++) {
		for (int i = 1; i <= n; i ++) {
			if (i + 1 <= n) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			if (i - 1 >= 1) dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j]);
		}
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i ++) {
		i64 res = 0;
		for (int j = 1; j <= 2 * n; j ++) {
			res ^= dp[i][j] * j;
		}
		ans ^= (res + i);
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