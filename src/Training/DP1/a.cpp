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
	int n, w;
	cin >> n >> w;
	vector<int> a(n), v(n);

	int sum = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i] >> v[i];
		sum += v[i];
	}
	vector<i64> dp(sum + 1, INFLL); // dp[i][j]为考虑前i个物品，价值和为j时，重量的最小值
	dp[0] = 0;

	for (int i = 0; i < n; i ++) {
		for (int j = sum; j >= v[i]; j --) {
			dp[j] = min(dp[j], dp[j - v[i]] + a[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i <= sum; i ++) {
		if (dp[i] <= w) ans = i;
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