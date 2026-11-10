#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, m, x, y, z;
	cin >> n >> m >> x >> y >> z;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i ++) {
		cin >> b[i];
	}
	vector dp(2, vector<int>(n));
	for (int i = 0; i < n; i ++) {
		dp[0][i] = x + y * abs(b[0] - a[i]) + z * i;
	}

	for (int i = 1; i < m; i ++) {
		multiset<int> pre = {INFLL}, suf = {INFLL};
		for (int j = 0; j < n; j ++) {
			suf.insert(dp[i - 1 & 1][j] - z * j);
		}
		for (int j = 0; j < n; j ++) {
			int l = *pre.begin() + z * (j - 1) + y * abs(b[i] - a[j]);
			int r = *suf.begin() + z * (j + n - 1) + y * abs(b[i] - a[j]) + x;
			dp[i & 1][j] = min(l, r);
			int val = dp[i - 1 & 1][j] - z * j;
			suf.erase(suf.find(val));
			pre.insert(val);
		}
	}
	int ans = INFLL;
	for (int i = 0; i < n; i ++) {
		ans = min(ans, dp[m - 1 & 1][i] + z * (n - i - 1));
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}