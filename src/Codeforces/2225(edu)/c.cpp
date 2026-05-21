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
	vector<string> g(2);
	cin >> g[0] >> g[1];
	g[0] = " " + g[0];
	g[1] = " " + g[1];

	vector<int> dp(n + 1, INF);
	dp[0] = 0;

	vector<string> tot = {"RRRR", "BBBB", "RRBB", "BBRR"};

	for (int i = 1; i <= n; i ++) {
		dp[i] = min(dp[i], dp[i - 1] + (g[0][i] != g[1][i]));
		if (i - 2 >= 0) {
			int cost = INF;
			string str = {g[0][i - 1], g[0][i], g[1][i - 1], g[1][i]};
			for (auto e : tot) {
				int cnt = 0;
				for (int j = 0; j < 4; j ++) cnt += (e[j] != str[j]);
				cost = min(cost, cnt);
			}
			dp[i] = min(dp[i], dp[i - 2] + cost);
		}
	}

	cout << dp[n] << '\n';
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