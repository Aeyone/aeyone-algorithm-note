#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 1000000007
#define INF 0x7f7f7f7f	
#define INFLL 0x7f7f7f7f7f7f7f7fLL

vector<i64> fac, inv;

i64 qmi(i64 a, i64 b, int p){
    i64 res = 1;
    for( ;b ; b >>= 1, a = a * a % p){
        if(b & 1)
            res = a * res % p;
    }
    return res;
}

void init(int n) {
    //求阶乘
    fac.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;

    //求某个阶乘的逆元
    inv.assign(n + 1, 1);
    inv[n] = qmi(fac[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

i64 C(i64 N, i64 M) {//求n取m的组合数
    if (M > N || M < 0)
        return 0;
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

void solve() {
	i64 n, k;
	cin >> n >> k;
	i64 c0 = (n & 1), c1 = 0;
	for(int i = 0; i < n; i += 2){//使得某位(&)==(^)的数量
		c0 = (c0 + C(n, i)) % MOD;
	}
	for(int i = 1; i < n; i += 2){//使得某位(&)<(^)的数量
		c1 = (c1 + C(n, i)) % MOD;
	}
	i64 ans = 0;//求出反面，即Moamen输的数量
	for(int i = 0; i < k; i ++){//要保证前面所有位都相等，然后当前位满足(&)<(^)，后面的所有位任意放
		ans = (ans + qmi(c0, i, MOD) * c1 % MOD * qmi(2, n * (k - 1 - i), MOD) % MOD) % MOD;
	}
	cout << (MOD + qmi(2, n * k, MOD) - ans) % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	init(200000);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}