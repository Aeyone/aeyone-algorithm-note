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
	int n = 4, q;
	int c[n + 1] {};
	cin >> c[1] >> c[2] >> c[3] >> c[4] >> q;

	while (q --) {
		vector<map<i64, int>> w(n + 1);
		for (int i = 1; i <= 4; i ++) {
			int d;
			cin >> d;
			for (int j = 0; d >= (1 << j); j ++) {
				w[i][1ll * c[i] * (1 << j)] ++;
				d -= (1 << j);
			}
			for (int j = 0; d >> j > 0; j ++) if (d >> j & 1) {
				w[i][1ll * c[i] * (1 << j)] ++;
			}
		}
		int s;
		cin >> s;

		vector<vector<i64>> dp(n + 1, vector<i64>(s + 1));
		dp[0][0] = 1;

		for (int i = 1; i <= 4; i ++) {
			dp[i] = dp[i - 1];

			for (auto [e, cnt] : w[i]) {
				cerr << "{"<< e << "," << cnt << "} ";
				for (int k = 1; k <= cnt; k ++) {
					for (int j = s; j >= k * e; j --) {
						dp[i][j] += dp[i][j - k * e];
					}
				}
			}
			cerr << '\n';
		}

		cout << dp[n][s] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}