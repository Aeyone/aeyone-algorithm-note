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
*	区间DP + 二维前缀和的计数问题，用于解决某区间内所有子区间问题。
*/

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	vector dp(n + 1, vector<int>(n + 1)), pre(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i ++) { // 预处理len为1和2的情况
		dp[i][i] = 1;
		if (s[i] == s[i - 1]) {
			dp[i - 1][i] = 1;
		}
	}
	for (int len = 3; len <= n; len ++) {
		for (int i = 1; i + len - 1 <= n; i ++) {
			int j = i + len - 1;
			dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			pre[i][j] = dp[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
		}
	}

	int q;
	cin >> q;
	while (q --) {
		int l, r;
		cin >> l >> r;
		cout << pre[r][r] - pre[r][l - 1] - pre[l - 1][r] + pre[l - 1][l - 1] << '\n';
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