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
*	区间DP，将一整个区间拆成若干个子区间问题
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	vector<i64> s(n + 1);
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i - 1] + a[i];
	}

	vector dp(n + 1, vector<i64>(n + 1, INFLL));
	for (int i = 1; i <= n; i ++) {
		dp[i][i] = 0;
	}
	for (int len = 2; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n; l ++) {
			int r = l + len - 1;
			for (int i = l; i < r; i ++) {
				dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + s[r] - s[l - 1]);
			}
		}
	}
	cout << dp[1][n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}