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

#define MOD 1000000007
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

i64 qmi(i64 a, i64 b, i64 p){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p){
		if(b & 1)
			res = a * res % p;
	}
	return res;
}

void solve() {
	i64 n, m, k;
	cin >> n >> m >> k;
	vector<i64> a(n), b(m), c(k);
	i64 sum = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		sum = (sum + a[i]) % MOD;
	}
	i64 sum2 = 0;
	for(int i = 0; i < m; i ++){
		cin >> b[i];
		sum2 = (sum2 + b[i] * sum % MOD) % MOD;
	}
	i64 sum3 = 0;
	for(int i = 0; i < k; i ++){
		cin >> c[i];
		sum3 = (sum3 + c[i] * sum2 % MOD) % MOD;
	}
	cout << sum3 * qmi((n * m % MOD * k) % MOD, MOD - 2, MOD) % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}