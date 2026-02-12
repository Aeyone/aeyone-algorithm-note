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
	int n, m, b, mod;
	cin >> n >> m >> b >> mod;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector dp(2, vector(m + 1, vector<int>(b + 1))); // dp[i][j][k]: 代表前i个程序员，一共编写j行代码，总bug数量为k的方案数
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		dp[i & 1].assign(m + 1, vector<int>(b + 1, 0));
		for (int j = 0; j <= m; j ++) {
			for (int k = 0; k <= b; k ++) {
				dp[i & 1][j][k] = (dp[i & 1][j][k] + dp[~i & 1][j][k]) % mod;
				if (j - 1 >= 0 && k - a[i] >= 0) {
					dp[i & 1][j][k] = (dp[i & 1][j][k] + dp[i & 1][j - 1][k - a[i]]) % mod;
				}
			}
		}
	}
	i64 ans = 0;
	for (int i = 0; i <= b; i ++) {
		ans = (ans + dp[n & 1][m][i]) % mod;
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