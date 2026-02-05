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
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	for (auto &[x, y, z] : a) {
		cin >> x >> y >> z;
	}
	vector<array<int, 3>> dp(n);
	dp[0] = a[0];
	for (int i = 1; i < n; i ++) {
		for (int j = 0; j < 3; j ++) {
			dp[i][j] = max({dp[i][j], dp[i - 1][(j + 1) % 3] + a[i][j], dp[i - 1][(j + 2) % 3] + a[i][j]});
		}
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}