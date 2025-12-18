#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	n = s.size();
	vector<array<int, 3>> dp(n);//0为L, 1为R, 2为s[i] == '1'时, 对于值：0代表没走过,1代表必须走，2代表无所谓
	if(s[0] == '0')
		dp[0][0] = 2;

	for(int i = 0; i < n - 1; i ++){
		if(s[i] == '1'){
			dp[i + 1][0] = dp[i][2];
		}else{
			if(dp[i][0] == 2){
				dp[i][1] = dp[i + 1][0] = dp[i + 1][2] = 2;
			}else if(dp[i][0] == 0){
				dp[i][1] = dp[i + 1][2] = 1;
			}
			dp[i + 1][0] = 2;
		}
	}
	bool ok = true;
	for(int i = 0; i < n; i ++){
		ok &= !(s[i] == '1' && dp[i][0] == 1);
	}
	if(s[n - 1] == '1')
		ok &= (!(dp[n - 1][2] & 1));

	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}