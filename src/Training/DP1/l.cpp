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
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	vector<vector<int>> to(n + 2, vector<int>(26, n + 1));
	for (int i = n; i >= 1; i --) {
		to[i - 1] = to[i];
		to[i - 1][a[i] - 'a'] = i;
	}

	vector<vector<int>> dp(m + 1, vector<int>(m + 1, n + 1));

	for (int i = 0; i <= m; i ++) dp[0][i] = 0;

	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= m; j ++) {
			dp[i][j] = min(dp[i][j - 1], to[dp[i - 1][j - 1]][b[j] - 'a']);
		}
	}

	int ans = 0;
	for (int i = 0; i <= m; i ++) {
		if (*min_element(dp[i].begin(), dp[i].end()) <= n) ans = i;
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