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
	string s;
	cin >> s;
	s = "#" + s;
	bool ok = (s[1] == '0');
	for (int i = 1; i <= n; i ++) {
		ok |= (s[i] == '0' && s[i - 1] == '0');
	}
	if (ok) {
		cout << -1 << '\n';
		return;
	}

	vector dp(n + 1, vector<int>(7, INF));
	dp[0][3] = 0;
	for (int i = 1; i <= n; i ++) {
		int st, ed;
		if (s[i] == '0') st = 0, ed = 0;
		else if (s[i] == '+') st = 1, ed = 3;
		else st = -3, ed = -1;

		for (int _j = -3; _j <= 3; _j ++) {
			for (int _k = st; _k <= ed; _k ++) {
				int j = _j + 3, k = _k + 3;
				if (k == j) continue;
				dp[i][k] = min(dp[i][k], max(dp[i - 1][j], abs(k - j)));
			}
		}
	}
	cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
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