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
	vector<vector<int>> g(n + 1);
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		x --;
		g[x].push_back(i);
	}
	for(auto e : g){
		if(e.size()){
			sort(e.begin(), e.end());
		}
	}
	vector<int> dp(n + 1, INF);
	dp[0] = 0;
	for(int x = 0; x < n; x ++){
		// if(x + 2 <= n){
		// 	dp[x + 2] = min(dp[x + 2], dp[x]);
		// }
		if(!g[x].size() || !g[x + 1].size()){
			dp[x + 1] = min(dp[x + 1], dp[x]);
		}else{
			int a = lower_bound(g[x].begin(), g[x].end(), g[x + 1].back()) - g[x].begin();
			int b = g[x + 1].size() - (lower_bound(g[x + 1].begin(), g[x + 1].end(), g[x].front()) - g[x + 1].begin());
			dp[x + 1] = min(dp[x + 1], dp[x] + a);
			if(x + 2 <= n){
				dp[x + 2] = min({dp[x + 2], dp[x] + a, dp[x] + b});
			}
		}
	}
	// for(int i = 0; i < n; i ++){
	// 	cout << dp[i] << ' ';
	// }
	// cout << '\n';
	cout << min(dp[n - 1], dp[n]) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}