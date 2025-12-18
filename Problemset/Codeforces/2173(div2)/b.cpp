#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> b[i];
	}
	vector<array<i64, 2>> dp(n + 1, {-INFLL, INFLL});
	dp[0] = {0, 0};
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < 2; j ++){
			dp[i][0] = max({dp[i][0], dp[i - 1][j] - a[i], b[i] - dp[i - 1][j]});
			dp[i][1] = min({dp[i][1], dp[i - 1][j] - a[i], b[i] - dp[i - 1][j]});
		}
	}

	cout << dp[n][0] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}