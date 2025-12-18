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
	int n, X;
	cin >> n >> X;
	vector<int> a(n), res;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int s = 0;
	i64 ans = 0;
	for(int l = 0, r = n - 1; l <= r; s %= X){
		while(l <= r && s + a[r] < X){
			s += a[l];
			res.push_back(a[l]);
			ans += (s >= X) * a[l ++];
		}
		if(l <= r && s < X && s + a[r] >= X){
			ans += a[r];
			res.push_back(a[r]);
			s += a[r --];
		}
	}
	cout << ans << '\n';
	for(auto e : res){
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}