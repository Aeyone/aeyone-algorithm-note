#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/*
*	dp[i][j]为考虑以第i个积木中，物品的价值和为j，的最大价值
*/

void solve() {
	int n;
	cin >> n;
	vector<int> w(n), s(n), v(n);
	for (int i = 0; i < n; i ++) {
		cin >> w[i] >> s[i] >> v[i];
	}
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](const int &i, const int &j)->bool{
		return w[i] + s[i] < w[j] + s[j];
	});

	int ans = 0;
	vector dp(2, vector<int>(10001));
	for (int _i = 0; _i < n; _i ++) {
		int i = idx[_i];
		dp[_i & 1] = dp[~_i & 1];
		for (int j = 0; j <= s[i]; j ++) {
			if (j + w[i] <= 10000) {
				dp[_i & 1][j + w[i]] = max(dp[_i & 1][j + w[i]], dp[~_i & 1][j] + v[i]);
			} else {
				ans = max(ans, dp[~_i & 1][j] + v[i]);
			}
		}
	}
	for (int i = 0; i <= 10000; i ++) {
		ans = max(ans, dp[n - 1 & 1][i]);
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