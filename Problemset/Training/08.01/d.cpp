#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;
vector<i64> fac, inv;

int qmi(i64 a, i64 b, int p){
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
        fac[i] = fac[i - 1] * i % mod;

    //求某个阶乘的逆元
    inv.assign(n + 1, 1);
    inv[n] = qmi(fac[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}

void solve() {
	int cnt[27] = {}, tot = 0;
	for(int i = 1; i <= 26; i ++)
		cin >> cnt[i], tot += cnt[i];

	int n = (tot + 1) / 2, _n = tot / 2;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= 26; i ++){
		if(cnt[i] == 0)
			continue;
		for(int j = n; j >= cnt[i]; j --)
			dp[j] += dp[j - cnt[i]];
	}
	i64 ans = fac[n] * fac[_n] % mod;
	for(int i = 1; i <= 26; i ++)
		ans = ans * inv[cnt[i]] % mod;

	cout << dp[n] * ans % mod << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	init(5e5);
	cin >> _;
	while (_ --)
		solve();
}