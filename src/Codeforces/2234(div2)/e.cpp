#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

vector<i64> fac, inv;

i64 qmi(i64 a, i64 b, int p){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1) {
		res = a * res % p;
	}
	return res;
}

void init(int n) {
	fac.assign(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	inv.assign(n + 1, 1);
	inv[n] = qmi(fac[n], MOD - 2, MOD);
	for (int i = n - 1; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	}
}

int C(int N, int M) {
	if (M > N || M < 0) {
		return 0;
	}
	return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    auto dfs = [&](this auto &&self, int l, int r)-> i64 {
        if (l > r) return 1;
        int len = r - l + 1;
        for (int c = 0, i = l, j = r; c < len; c ++) {
            int e = ((c & 1) ? j -- : i ++);
            if (a[e] == 1ll * (e - l + 1) * (r - e + 1)) {
                return self(l, e - 1) * self(e + 1, r) % MOD * C(len - 1, e - l) % MOD;
            }
        }
        return 0;
    };
    cout << dfs(1, n) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    init(1e6);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}