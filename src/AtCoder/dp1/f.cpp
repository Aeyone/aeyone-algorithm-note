#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<typename T> bool cmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = " " + s;
	t = " " + t;
	vector dp(n + 1, vector(m + 1, vector<int>{0, -1, -1}));

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (s[i] == t[j]) {
				cmax(dp[i][j], {dp[i - 1][j - 1][0] + 1, i - 1, j - 1});
			}
			cmax(dp[i][j], dp[i - 1][j]);
			cmax(dp[i][j], dp[i][j - 1]);
		}
	}
	string res;
	int i = dp[n][m][1], j = dp[n][m][2];
	while (i != -1 && j != -1) {
		res += s[i + 1];
		int _i = dp[i][j][1];
		int _j = dp[i][j][2];
		i = _i, j = _j;
	}
	reverse(res.begin(), res.end());
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}