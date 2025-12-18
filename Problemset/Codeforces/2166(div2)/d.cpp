/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(n + 1);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	//dp[i][j]为所有由1~i的数字组成，cnt之和为j的集合的乘积之和
	vector<vector<i64>> dp(n + 1, vector<i64>(n + 1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++){
		// cout << "cnt[i] = " << cnt[i] << '\n';
		dp[i] = dp[i - 1];
		if(cnt[i] == 0){
			continue;
		}
		for(int j = cnt[i]; j <= n; j ++){
			dp[i][j] = (dp[i - 1][j] + (i64)cnt[i] * dp[i - 1][j - cnt[i]]) % MOD;
		}
	}
	int mn = *max_element(cnt.begin(), cnt.end());//cnt之和最起码要是最大的那个数
	i64 ans = 0;
	for(int i = mn; i <= n; i ++){
		ans = (ans + dp[n][i]) % MOD;
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