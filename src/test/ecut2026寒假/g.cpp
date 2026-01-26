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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>> (2, {-1, -1}));
	dp[0][0] = {0, -1};
	dp[0][1] = {-1, a[0]};
	for (int i = 1; i < n; i ++) {
		int mx0 = max(dp[i - 1][0][0], dp[i - 1][1][0]);
		int mx1 = max(dp[i - 1][0][1], dp[i - 1][1][1]);
		dp[i][0] = {mx0, mx1};
		dp[i][1] = {(mx1 == -1 ? -1 : mx1 + 2 * a[i]), (mx0 == -1 ? -1 : mx0 + a[i])};
	}
	cout << max({dp[n - 1][0][0], dp[n - 1][0][1], dp[n - 1][1][0], dp[n - 1][1][1]}) << '\n';
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