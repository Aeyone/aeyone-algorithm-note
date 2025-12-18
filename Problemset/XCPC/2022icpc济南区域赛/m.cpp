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

i64 qmi(i64 a, i64 b){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a){
		if(b & 1)
			res = a * res;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	i64 s = 0, ans = 0;
	for(int i = 0; i < n; i ++){
		i64 t = 0;
		for(int j = 0; max(s, a[i]) / qmi(10ll, j) > 0; j ++){
			i64 p = qmi(10ll, j);
			i64 x = (s / p), y = (a[i] / p);
			t = ((x % 10) + (y % 10) + t) / 10;
			if(t == 1){
				ans ++;
			}
		}
		s += a[i];
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