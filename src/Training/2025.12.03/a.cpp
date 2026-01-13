#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//简单的背包dp
	string s;
	cin >> s;
	int n = s.size();
	i64 ans = 1;
	for(int i = 0; i < n; i ++){
		int num = s[i] - '0';
		vector<vector<i64>> dp(4, vector<i64>(num + 1));
		dp[0][0] = 1;
		for(int j = 1; j <= 3; j ++){
			for(int cur = 0; cur <= num; cur ++){
				for(int v = cur; v <= num; v ++){
					dp[j][v] += dp[j - 1][v - cur];
				}
			}
		}
		ans = ans * dp[3][num];
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