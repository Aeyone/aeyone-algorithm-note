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
	vector<int> a(n), pre(n), suf(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	pre[0] = a[0];
	int g = a[0];
	for(int i = 1; i < n; i ++){
		g = __gcd(g, a[i]);
		pre[i] = min(pre[i - 1], g);
	}
	suf[n - 1] = a[n - 1];
	g = a[n - 1];
	for(int i = n - 2; i >= 0; i --){
		g = __gcd(g, a[i]);
		suf[i] = min(suf[i + 1], g);
	}
	i64 ans = 0;
	for(int i = 1; i < n - 1; i ++){
		ans += min(pre[i], suf[i]);
	}
	cout << ans + g << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}