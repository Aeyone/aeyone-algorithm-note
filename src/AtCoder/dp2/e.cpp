#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

void solve() {
	int d;
	cin >> d;
	string s;
	cin >> s;
	int n = s.size();

	reverse(s.begin(), s.end());
	s = " " + s;

	vector dp(n + 1, vector<i64>(d));// dp[i][j]为前i个数字任意组成的和的模d为j的方案数
	dp[0][0] = 1;

	for (int i = 1; i < n; i ++) {
		for (int j = 0; j < d; j ++) {
			for (int num = 0; num < 10; num ++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][(d + j - (num % d)) % d]) % MOD;
			}
		}
	}

	i64 ans = MOD - 1; //去除全0

	int cur = 0;
	for (int i = n; i >= 1; i --) {
		int u = s[i] - '0';
		for (int num = 0; num < u; num ++) {
			ans = (ans + dp[i - 1][(2 * d - cur - (num % d)) % d]) % MOD;
		}
		cur = (cur + u) % d;
	}

	cout << ans + (cur == 0) << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}