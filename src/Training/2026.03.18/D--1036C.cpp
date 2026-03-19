#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

vector dp(20, vector(10, vector<i64>(4)));


void init() { // 数位DP
	dp[0][0][0] = 1;
	for (int i = 1; i < 10; i ++) {
		dp[0][i][1] = 1;
	}
	for (int i = 1; i < 20; i ++) {
		for (int cur = 0; cur < 10; cur ++) {
			for (int j = 0; j < 10; j ++) {
				for (int k = (cur != 0); k < 4; k ++) {
					dp[i][cur][k] += dp[i - 1][j][k - (cur != 0)];
				}
			}
		}
	}
}

i64 sum(i64 x) {
	string s = to_string(x);
	ranges::reverse(s);
	int n = s.size();
	i64 ans = (n - ranges::count(s, '0') <= 3);
	int cnt = 0; // 要保证，确定的前缀数字 + 后面加入的数字大于0的数量不能超过3个
	for (int i = n - 1; i >= 0; i --) {
		for (int j = 0; j < s[i] - '0'; j ++) {
			for (int k = 0; k <= 3 - cnt; k ++) {
				ans += dp[i][j][k];
			}
		}
		cnt += (s[i] - '0' != 0);
	}
	return ans - 1;
}

void solve() {
	i64 l, r;
	cin >> l >> r;
	cout << sum(r) - sum(l - 1) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init();
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}