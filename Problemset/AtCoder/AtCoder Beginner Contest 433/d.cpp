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
i64 qmi(i64 a, i64 b, int p){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p){
		if(b & 1)
			res = a * res % p;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), mi(11);
	vector<unordered_map<int, int>> mp(11);
	for(int i = 1; i <= 10; i ++){
		mi[i] = qmi(10, i, m);
	}
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		for(int j = 1; j <= 10; j ++){
			mp[j][1ll * a[i] * mi[j] % m] ++;
		}
	}
	i64 ans = 0;
	for(int i = 0; i < n; i ++){
		int len = to_string(a[i]).size();
		ans += mp[len][(m - (a[i] % m)) % m];
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