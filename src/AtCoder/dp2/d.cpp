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
	int n; i64 d;
	cin >> n >> d;
	int c[6] {}, num[3] = {2, 3, 5};
	for (int i = 0; i < 3; i ++) {
		while (d % num[i] == 0) {
			d /= num[i];
			c[num[i]] ++;
		}
	}
	if (d > 1) {
		cout << 0 << '\n';
		return;
	}

	const int N = 210;
	vector dp(2, vector(N, vector(N / 2, vector<double>(N / 2))));

	dp[0][0][0][0] = 1;
	for (int cnt = 0; cnt < n; cnt ++) {
		dp[cnt + 1 & 1].assign(N, vector(N / 2, vector<double>(N / 2)));
		for (int i = 0; i <= 200; i ++) {
			for (int j = 0; j <= 100; j ++) {
				for (int k = 0; k <= 100; k ++) {
					dp[cnt + 1 & 1][i][j][k] += dp[cnt & 1][i][j][k] * 1 / 6;
					dp[cnt + 1 & 1][i + 1][j][k] += dp[cnt & 1][i][j][k] * 1 / 6;
					dp[cnt + 1 & 1][i][j + 1][k] += dp[cnt & 1][i][j][k] * 1 / 6;
					dp[cnt + 1 & 1][i + 2][j][k] += dp[cnt & 1][i][j][k] * 1 / 6;
					dp[cnt + 1 & 1][i][j][k + 1] += dp[cnt & 1][i][j][k] * 1 / 6;
					dp[cnt + 1 & 1][i + 1][j + 1][k] += dp[cnt & 1][i][j][k] * 1 / 6;
				}
			}
		}
	}
	double ans = 0;
	for (int i = c[2]; i <= 200; i ++) {
		for (int j = c[3]; j <= 100; j ++) {
			for (int k = c[5]; k <= 100; k ++) {
				ans += dp[n & 1][i][j][k];
			}
		}
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