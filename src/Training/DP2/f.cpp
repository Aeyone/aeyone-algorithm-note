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
	int n, s;
	cin >> n >> s;
	vector<int> t(n + 1), c(n + 1), st(n + 1), sc(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> t[i] >> c[i];
		st[i] = st[i - 1] + t[i];
		sc[i] = sc[i - 1] + c[i];
	}
	vector<i64> dp(n + 1, INFLL); // dp[i]表示将前i个任务中分成任意组的最小花费
	dp[0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < i; j ++) {
			dp[i] = min(dp[i], dp[j] + 1ll * st[i] * (sc[i] - sc[j]) + 1ll * s * (sc[n] - sc[j]));
		}
	}
	for (int i = 1; i <= n; i ++) {
		cerr << dp[i] << ' ';
	}
	cerr << '\n';
	cout << dp[n] << '\n';
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