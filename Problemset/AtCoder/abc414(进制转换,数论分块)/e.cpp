#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

int qmi(int a, int b, int p){
	int res = 1;
	while(b){
		if(b & 1)
			res = (i64)a * res % p;
		b >>= 1;
		a = (i64)a * a % p;
	}
	return res;
}

void solve() {
	i64 n;
	cin >> n;
	i64 s1 = (((n - 1) % mod) * (n % mod) % mod + n - 1) % mod;
	i64 s2 = ((n - 1) % mod) * ((n + 2) % mod) % mod * qmi(2, mod - 2, mod) % mod;
	i64 s3 = 0;
	for(i64 i = 2; i <= n; i ++){
		i64 k = n / i, r = n / k, d = r - i + 1;
		s3 = (s3 + (k % mod * d % mod) % mod) % mod;
		i = r;
	}
	cout << (s1 - s2 - s3 + 2 * mod) % mod << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}