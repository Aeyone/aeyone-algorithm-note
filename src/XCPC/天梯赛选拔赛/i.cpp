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
	int n, k;
	cin >> n >> k;
	vector g(n, vector<int>(n));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> g[i][j];
		}
	}
	vector dp(n, vector<i64>(1 << n));
	vector<vector<int>> mask(n + 1);
	for (int i = 0; i < 1 << n; i ++) {
		mask[__builtin_popcount(i)].push_back(i);
	}

	for (int i = 0; i < n; i ++) {
		dp[i][1 << i] = 1;
	}
	for (int len = 1; len < n; len ++) {
		for (auto e : mask[len]) {
			for (int u = 0; u < n; u ++) {
				if (!(e >> u & 1)) {
					continue;
				}
				for (int v = 0; v < n; v ++) {
					if (e >> v & 1 || !g[u][v]) {
						continue;
					}
					dp[v][e | (1 << v)] += dp[u][e];
				}
			}
		}
	}
	vector<i64> cnt(1 << n);
	for (int i = 0; i < 1 << n; i ++) {
		for (int j = 0; j < n; j ++) {
			cnt[i] += dp[j][i];
		}
		cnt[i] /= 2;
	}

	i64 ans = 0;
	for (auto e : mask[k]) {
		i64 sum = 0;
		for (int sub = e; sub > 0; sub = (sub - 1) & e) {
			sum += cnt[sub] * (__builtin_popcount(sub) - 1);
		}
		ans = max(ans, sum);
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