#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

vector<vector<int>> p(3001);

void init() {
	for (int i = 1; i <= 3000; i ++) {
		p[i].push_back(1);
		for (int j = 2; j <= i / j; j ++) {
			if (i % j == 0) {
				p[i].push_back(j);
				if (i / j != j) {
					p[i].push_back(i / j);
				}
			}
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	if (a[0] > 1) {
		cout << 0 << '\n';
		return;
	}
	a[0] = 1;
	vector dp(n, vector<i64>(m + 1)); // dp[i][j]为考虑前i个数，第i个数字取j的方案数
	dp[0][1] = 1;
	for (int i = 1; i < n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (a[i] != 0 && j != a[i]) {
				continue;
			}
			for (auto e : p[j]) {
				if (j - e >= 1) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j - e]) % MOD;
				}
			}
		}
	}
	i64 ans = 0;
	for (int i = 1; i <= m; i ++) {
		ans = (ans + dp[n - 1][i]) % MOD;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	init();
	while (_ --) {
		solve();
	}
}