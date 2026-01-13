#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;
const int MAX = 3e5 + 10;
i64 fac[MAX], inv[MAX];

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

void init(){
	//求阶乘
	int n = MAX - 10;
	fac[0] = 1;
	for(i64 i = 1; i <= n; i ++)
		fac[i] = (fac[i - 1] * i) % mod;

	//求某个阶乘的逆元
	inv[n] = qmi(fac[n], mod - 2, mod);
	for(int i = n - 1; i >= 0; i --)
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
}

int C(int n, int m){//求C_n^m
	return (fac[n] * inv[m] % mod) * inv[n - m] % mod;
}

void solve() {
	int n;
	cin >> n;
	n /= 3;
	vector<array<int, 3>> w(n);
	for(int i = 0; i < n; i ++){
		cin >> w[i][0] >> w[i][1] >> w[i][2];
		sort(w[i].begin(), w[i].end());
	}

	i64 ans = C(n, n / 2);
	for(int i = 0; i < n; i ++){
		int cnt = count(w[i].begin(), w[i].end(), w[i][2]);
		if(cnt == 2)
			cnt = 1;
		else if(cnt == 1)
			cnt *= count(w[i].begin(), w[i].end(), w[i][1]);
		
		ans = (ans * cnt) % mod;
	}

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}