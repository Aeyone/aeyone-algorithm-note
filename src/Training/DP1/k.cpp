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
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> b[i];
	}

	vector<vector<int>> dp(2, vector<int>(n + 1));
	for (int i = 1; i <= n; i ++) {
		int pre = 0;
		for (int j = 1; j <= n; j ++) {
			dp[i & 1][j] = dp[i - 1 & 1][j];
			if (a[i] == b[j]) {
				dp[i & 1][j] = pre + 1;
			}
			if (b[j] < a[i]) { // 满足递增条件
				pre = max(pre, dp[i - 1 & 1][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans = max(ans, dp[n & 1][i]);
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