#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

vector<i64> fac, inv;

i64 qmi(i64 a, i64 b, int p) {
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

int C(int N, int M) {//求n取m的组合数
    if (M > N || M < 0)
        return 0;
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    i64 ans = 0, top = 0;
    if(__builtin_popcountll(n) >= k) {
        while(__builtin_popcountll(n) > k) {
            n -= n & -n;
        }
        ans = n % MOD;
    }
    for(int i = 60; i >= k; i --) {
        if(n >> i & 1) {
            ans = (ans + (((1ll << i) - 1) % MOD) * C(i - 1, k - 1) % MOD) % MOD;
            ans = (ans + (top % MOD) * C(i, k) % MOD) % MOD;
            k --;
            top += (1ll << i);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int _ = 1;
    init(100);
    cin >> _;
    while (_ --){
        solve();
    }
}