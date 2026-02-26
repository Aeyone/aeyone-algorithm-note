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
	vector g(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> g[i][j];
		}
	}
	vector row(n + 1, vector<int>(m + 2)), col(m + 1, vector<int>(n + 2));
	for (int i = 1; i <= n; i ++) {
		for (int j = m; j >= 0; j --) {
			row[i][j] = row[i][j + 1] + g[i][j];
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = n; j >= 0; j --) {
			col[i][j] = col[i][j + 1] + g[j][i];
		}
	}

	using T = array<int, 3>;
	vector dp(n + 2, vector<T>(m + 2, {INF, -INF, -1}));
	dp[1][1] = {0, 0};
	for (int i = 1; i <= n + 1; i ++) {
		for (int j = 1; j <= m + 1; j ++) {
			auto [cur1, cur2, _t] = dp[i][j];
			if (j + 1 <= m + 1) {
				auto [a1, a2, _] = dp[i][j + 1];
				if (abs(a1 - a2) > abs(cur1 - (cur2 + col[j][i]))){
					dp[i][j + 1] = {cur1, cur2 + col[j][i], 2};
				}
			}
			if (i + 1 <= n + 1) {
				auto [b1, b2, _] = dp[i + 1][j];
				if (abs(b1 - b2) > abs((cur1 + row[i][j]) - cur2)) {
					dp[i + 1][j] = {cur1 + row[i][j], cur2, 1};
				}
			}
		}
	}
	cout << 1ll * dp[n + 1][m + 1][0] * dp[n + 1][m + 1][1] << '\n';
	string ans;
	int x = n + 1, y = m + 1;
	while (x != 1 || y != 1) {
		if (dp[x][y][2] == 1) {
			x --;
			ans.push_back('D');
		} else {
			y --;
			ans.push_back('R');
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}