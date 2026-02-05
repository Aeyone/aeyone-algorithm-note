#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> g[i];
		g[i] = " " + g[i];
	}
	vector dp(n + 1, vector<int>(m + 1));
	dp[1][1] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (g[i][j] != '#') {
				dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}
		}
	}
	cout << dp[n][m] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}