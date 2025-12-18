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
	vector<i64> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	i64 mn = 0;
	i64 ans = 0;
	for(i64 i = 1; i <= n; i ++){
		i64 r = i * i + i - pre[i];
		i64 l = i * i - i - pre[i - 1];
		mn = min(mn, l);
		ans = max(ans, r - mn);
	}
	cout << ans + pre[n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}