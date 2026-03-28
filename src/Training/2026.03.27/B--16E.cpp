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
	vector p(n, vector<double>(n));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> p[i][j];
		}
	}
	vector<vector<int>> mask(n + 1);
	for (int i = 0; i < 1 << n; i ++) {
		mask[__builtin_popcount(i)].push_back(i);
	}

	vector<double> dp(1 << n);
	dp[(1 << n) - 1] = 1;
	for (int cur = n; cur >= 2; cur --) {
		for (auto e : mask[cur]) {
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < n; j ++) {
					if ((e >> i & 1 ^ 1) || (e >> j & 1 ^ 1) || i == j) {
						continue;
					}
					dp[e ^ (1 << j)] += p[i][j] / (double(cur) * (cur - 1) / 2) * dp[e];
				}
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		cout << dp[1 << i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}