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
	vector<i64> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	vector<i64> dp(n);
	for(int i = 1; i < n - 1; i ++){
		dp[i] = max(dp[i], a[i]);
		for(int j = 3; j <= 5 && i + j < n - 1; j ++){
			dp[i + j] = max(dp[i + j], dp[i] + a[i + j]);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}