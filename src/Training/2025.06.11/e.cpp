#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;
const int MAX = 1010;
i64 fac[MAX], inv[MAX];

i64 qmi(i64 a, i64 b){
	i64 res = 1;
	while(b){
		if(b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

void init(int n){
	//求阶乘
	fac[0] = 1;
	for(i64 i = 1; i <= 1000; i ++)
		fac[i] = (fac[i - 1] * i) % mod;

	//求某个阶乘的逆元
	inv[n] = qmi(fac[n], mod - 2);
	for(int i = n - 1; i >= 0; i --)
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
}

int C(int n, int m){//求C_n^m
	return (fac[n] * inv[m] % mod) * inv[n - m] % mod;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), cnt(n + 1);
	for(int i = 0; i < n; i ++)
		cin >> a[i], cnt[a[i]] ++;

	sort(a.begin(), a.end());
	int u = n - k, siz = 0;
	for(int i = u; i < n; i ++)
		if(a[i] == a[u])
			siz ++;
	cout << C(cnt[a[u]], siz) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	init(1000);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}