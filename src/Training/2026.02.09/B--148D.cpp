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
	int w, b;
	cin >> w >> b;
	vector dp(w + 1, vector<double>(b + 1, 0));
	for (double i = 1; i <= w; i ++) {
		for (double j = 0; j <= b; j ++) {
			dp[i][j] = i / (i + j);
			if (j >= 2) { // 白色的逃走
				dp[i][j] += j / (i + j) * (j - 1) / (i + j - 1) * (i / (i + j - 2) * dp[i - 1][j - 2]);
			}
			if (j >= 3) { // 黑色的逃走
				dp[i][j] += j / (i + j) * (j - 1) / (i + j - 1) * ((j - 2) / (i + j - 2) * dp[i][j - 3]);
			}
		}
	}
	cout << dp[w][b] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}