#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector a(n, vector<int>(n));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> a[i][j];
		}
	}
	vector<int> cost(1 << n);
	for (int mask = 1; mask < 1 << n; mask ++) {
		for (int i = 0; i < n; i ++) {
			if (mask >> i & 1) {
				for (int j = i; j < n; j ++) {
					if (mask >> j & 1) {
						cost[mask] += a[i][j];
					}
				}
			}
		}
	}
	vector<int> dp(1 << n);
	for (int mask = 1; mask < 1 << n; mask ++) {
		dp[mask] = cost[mask];
		for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
			dp[mask] = max(dp[mask], dp[sub] + cost[mask ^ sub]);
		}
	}
	cout << dp.back() << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}