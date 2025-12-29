#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

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
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    //求某个阶乘的逆元
    inv.assign(n + 1, 1);
    inv[n] = qmi(fac[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

int C(int N, int M) {//求n取m的组合数
    if (M > N || M < 0)
        return 0;
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

int A(int N, int M) {//求n取m的排列数
    if (M > N || M < 0)
        return 0;
    return fac[N] * inv[N - M] % MOD;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	i64 sum = 0;
	for (int i = 0; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	int mx = *max_element(a.begin() + 1, a.end());
	int c1 = count(a.begin() + 1, a.end(), mx);
	for (int i = 1; i <= n; i ++) {
		if (a[i] != mx) {
			a[0] -= (mx - 1 - a[i]);
		}
	}
	if (a[0] < 0) {
		cout << 0 << '\n';
		return;
	}
	int len = min(n, c1 + a[0]);
	cout << 1ll * A(len, c1) * fac[n - c1] % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	init(200);
	cin >> _;
	while (_ --) {
		solve();
	}
}