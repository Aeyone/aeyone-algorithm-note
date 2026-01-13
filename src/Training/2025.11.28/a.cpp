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

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> w(n + 1), h(n + 1), b(n + 1);
	int M = 0;
	for(int i = 1; i <= n; i ++){
		cin >> w[i] >> h[i] >> b[i];
		M += w[i];
	}
	vector<i64> dp(M + 1, -INFLL), back(M + 1, -INFLL);
	back[0] = 0;
	int tot = 0;
	for(int i = 0; i < n; i ++){
		for(int v = 0; v <= M; v ++){
			if(v + w[i + 1] <= M){
				dp[v + w[i + 1]] = max(dp[v + w[i + 1]], back[v] + h[i + 1]);
			}
			dp[v] = max(dp[v], back[v] + b[i + 1]);
		}
		tot += w[i + 1];
		back = dp;
		fill(dp.begin(), dp.end(), -INFLL);
	}
	i64 ans = 0;
	for(int i = 0; i <= M / 2; i ++){
		ans = max(ans, back[i]);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}