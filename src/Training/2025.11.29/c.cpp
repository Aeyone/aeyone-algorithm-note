#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//dp细节题
	int n, k, z;
	cin >> n >> k >> z;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	vector<vector<int>> dp(n, vector<int>(z + 1));
	dp[0][0] = a[0];
	for(int i = 1; i <= k; i ++){
		dp[i][0] = dp[i - 1][0] + a[i];
		for(int j = 1; j <= min(z, (k - i) / 2); j ++){
			dp[i][j] = max(dp[i - 1][j] + a[i], dp[i][j - 1] + (a[i] + a[i - 1]));
		}
	}
	int ans = 0;
	for(int i = 0; i <= k; i ++){
		for(int j = 0; j <= z; j ++){
			ans = max(ans, dp[i][j]);
			if(i > 0 && i + 2 * j + 1 == k && j + 1 <= z){//考虑最后一次往回走
				ans = max(ans, dp[i][j] + a[i - 1]);
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}