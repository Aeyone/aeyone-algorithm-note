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
	int r, s, p;
	cin >> r >> s >> p;
	int sum = r + s + p;
	vector<vector<array<int, 3>>> buk(sum + 1);
	for (int i = 0; i <= r; i ++) {
		for (int j = 0; j <= s; j ++) {
			for (int k = 0; k <= p; k ++) {
				buk[i + j + k].push_back({i, j, k});
			}
		}
	}
	double wr = 0, ws = 0, wp = 0;
	vector dp(r + 1, vector(s + 1, vector<double>(p + 1)));
	dp[r][s][p] = 1;
	for (int cnt = sum; cnt >= 1; cnt --) {
		for (auto [i, j, k] : buk[cnt]) {
			int tot = i * j + i * k + k * j;
			if (i > 0 && k > 0) {
				dp[i - 1][j][k] += dp[i][j][k] * i * k / tot;
			}
			if (i > 0 && j > 0) {
				dp[i][j - 1][k] += dp[i][j][k] * i * j / tot;
			}
			if (j > 0 && k > 0) {
				dp[i][j][k - 1] += dp[i][j][k] * j * k / tot;
			}
			if (i > 0 && !j && !k) {
				wr += dp[i][j][k];
			}
			if (j > 0 && !i && !k) {
				ws += dp[i][j][k];
			}
			if (k > 0 && !i && !j) {
				wp += dp[i][j][k];
			}
		}
	}
	cout << wr << ' ' << ws << ' ' << wp << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}