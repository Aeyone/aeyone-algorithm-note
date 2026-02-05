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


void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end(), greater<int>{});

	i64 ans = 1;
	int mn = *min_element(b.begin(), b.end());
	int idx = 0;
	while (idx < n && a[idx] > mn) {
		idx ++;
	}
	cout << fac[idx] * fac[n - idx] % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init(1e6);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}