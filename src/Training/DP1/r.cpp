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
	vector<int> a(2 * n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	vector<i64> suf(2 * n + 2);
	for (int i = 2 * n; i >= 1; i --) {
		suf[i] = suf[i + 1] + a[i];
	}

	vector<i64> dp(2 * n + 1, -INFLL); // dp[i]为在前i个中取不超过长度为n的一段最大子段和

	set<pair<i64, int>> st;
	i64 ans = -INFLL;
	for (int i = 1; i <= 2 * n; i ++) {
		st.insert({suf[i], i});
		if (i - n >= 1) {
			st.erase({suf[i - n], i - n});
		}
		auto mx = *(--st.end());
		dp[i] = max(dp[i - 1], mx.first - suf[i + 1]);
		ans = max(ans, mx.first - suf[i + 1] + dp[mx.second - 1]);
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