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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &e : a) {
		cin >> e;
	}
	vector dp(2, vector<int>(10001));
	dp[1][0] = 1;
	for (int i = 0; i < n; i ++) {
		dp[i & 1] = dp[~i & 1];
		for (int j = a[i]; j <= 10001; j ++) {
			dp[i & 1][j] |= dp[~i & 1][j - a[i]];
		}
	}
	int ans = 0;
	for (int i = 0; i <= 10000; i ++) {
		ans += dp[~n & 1][i];
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