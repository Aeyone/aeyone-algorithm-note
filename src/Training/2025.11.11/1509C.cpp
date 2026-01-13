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

#define int long long
#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<vector<int>> dp(n, vector<int>(n, INFLL));
	dp[0][n - 1] = a[n - 1] - a[0];
	for(int len = n; len >= 2; len --){
		for(int i = 0; i + len <= n; i ++){
			dp[i + 1][i + len - 1] = min(dp[i + 1][i + len - 1], dp[i][i + len - 1] + (a[i + len - 1] - a[i + 1]));
			dp[i][i + len - 2] = min(dp[i][i + len - 2], dp[i][i + len - 1] + (a[i + len - 2] - a[i]));
		}
	}
	int mn = INFLL;
	for(int i = 0; i < n; i ++){
		mn = min(mn, dp[i][i]);
	}
	cout << mn << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}