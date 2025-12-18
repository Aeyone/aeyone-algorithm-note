#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	vector<vector<array<int, 2>>> dp(n + 1, vector<array<int, 2>>(k + 1, {-INF, -1}));
	vector<int> la(k + 1, -1);
	la[0] = 0;
	dp[0][0] = {0, 0};
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= k; j ++){
			int u = la[j];
			// cout << "cur = " << min(k - j, a[i]) << '\n';
			// cout << "u = " << u << '\n';
			// if(u == 0){
			// 	cout << "back = " << dp[u][j][1] << '\n';
			// }
			if(u == -1 || min(k - j, a[i]) <= dp[u][j][1]){
				continue;
			}
			// cout << "cur = " << min(k - j, a[i]) << " back = " << dp[u][j][1] << '\n';
			if(dp[i][j + min(k - j, a[i])][0] < dp[u][j][0] + dp[u][j][1] * (i - u)){
				dp[i][j + min(k - j, a[i])][0] = dp[u][j][0] + dp[u][j][1] * (i - u);
				dp[i][j + min(k - j, a[i])][1] = min(k - j, a[i]);
				la[j + min(k - j, a[i])] = i;
			}
		}
		for(int j = 0; j <= n; j ++){
			for(int m = 0; m <= k; m ++){
				if(dp[j][m][0] == -INF){
					cout << "X" << ' ';
				}else{
					cout << dp[j][m][0] << ' ';
				}
			}
			cout << '\n';
		}
		cout << '\n';
	}
	int ans = 0;
	for(int i = 0; i <= k; i ++){
		cout << "la = " << la[i] << ' ';
		if(la[i] != -1){
			cout << " back = " << dp[la[i]][i][1] << '\n';
			ans = max(ans, dp[la[i]][i][0] + dp[la[i]][i][1] * (n - la[i] + 1));
		}
	}
	cout << ans << '\n';
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