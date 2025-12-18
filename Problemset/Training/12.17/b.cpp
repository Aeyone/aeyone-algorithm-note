#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//计数题，转换为维护方案数的dp
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());//从小到大贪心
	vector<vector<i64>> dp(2, vector<i64>(5001));
	dp[1][0] = 1;
	i64 ans = 0;
	for(int i = 0; i < n; i ++) {
		dp[i & 1] = dp[i & 1 ^ 1];
		for(int s = a[i]; s <= 5000; s ++) {
			if(s - a[i] <= a[i]) {
				ans = (ans + 1ll * a[i] * dp[i & 1 ^ 1][s - a[i]] % MOD) % MOD;
			}else{
				ans = (ans + 1ll * (s + 1) / 2 * dp[i & 1 ^ 1][s - a[i]] % MOD) % MOD;
			}
			dp[i & 1][s] = (dp[i & 1][s] + dp[i & 1 ^ 1][s - a[i]]) % MOD;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}