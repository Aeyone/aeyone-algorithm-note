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
	int h, w, n;
	cin >> h >> w >> n;
	vector<array<int, 2>> a(n);
	for (auto &[x, y] : a) {
		cin >> x >> y;
	}
	a.push_back({h, w});
	sort(a.begin(), a.end());

	vector<i64> dp(n + 1);
	for (int i = 0; i <= n; i ++) {
		auto [x, y] = a[i];
		dp[i] = C(x + y - 2, x - 1);
		for (int j = 0; j < i; j ++) {
			auto [xx, yy] = a[j];
			if (y >= yy) {
				int dx = x - xx, dy = y - yy;
				dp[i] = (dp[i] + MOD - dp[j] * C(dx + dy, dx) % MOD) % MOD;
			}
		}
	}
	cout << dp[n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	init(2e5);
	while (_ --) {
		solve();
	}
}