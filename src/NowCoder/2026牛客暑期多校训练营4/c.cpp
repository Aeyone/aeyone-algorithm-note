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
	vector<int> a(n);
	vector<vector<int>> d(n, vector<int>(m));
	vector<vector<i64>> cost(1 << m, vector<i64>(m));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> d[i][j];
		}
		string s;
		cin >> s;
		for (int j = 0; j < m; j ++) {
			a[i] |= ((s[j] == 'A') << j);
		}
		for (int j = 0; j < m; j ++) {
			cost[a[i]][j] += d[i][j];
		}
	}

	for (int k = 0; k < m; k ++) {
		for (int hi = 0; hi < 1 << m; hi += 1 << (k + 1)) {
			for (int lo = 0; lo < 1 << k; lo ++) {
				int mask = hi | lo;
				for (int j = 0; j < m; j ++) {
					cost[mask][j] += cost[mask | (1 << k)][j];
				}
			}
		}
	}

	vector<i64> dp(1 << m, INFLL);
	dp[0] = 0;
	for (int mask = 1; mask < 1 << m; mask ++) {
		for (int i = 0; i < m; i ++) {
			if (mask >> i & 1) {
				int la = mask ^ (1 << i);
				dp[mask] = min(dp[mask], dp[la] + cost[la][i]);
			}
		}
	}
	cout << dp[(1 << m) - 1] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}