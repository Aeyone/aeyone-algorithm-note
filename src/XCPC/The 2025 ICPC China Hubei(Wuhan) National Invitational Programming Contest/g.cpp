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
	int n, m;
	cin >> n >> m;
	vector a(n + 1, vector<int>(m + 1));

	using T = array<i64, 2>;
	map<int, vector<T>> mp;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
			mp[a[i][j]].push_back({i, j});
		}
	}
	i64 ans = 0;
	for (auto [e, v] : mp) {
		if (v.size() <= 8000) {
			ans = (ans + C(n + m - 2, n - 1)) % MOD;
			if (v.back() == T{n, m}) {
				continue;
			}
			int siz = v.size();
			v.push_back({n, m});
			vector<i64> dp(siz + 1);
			for (int i = 0; i <= siz; i ++) {
				auto [x, y] = v[i];
				dp[i] = C(x + y - 2, x - 1);
				for (int j = 0; j < i; j ++) {
					int dx = x - v[j][0], dy = y - v[j][1];
					if (dy >= 0){
						dp[i] = (dp[i] + MOD - dp[j] * C(dx + dy, dx) % MOD) % MOD;
					}
				}
			}
			ans = (ans + MOD - dp[siz]) % MOD;
		} else {
			vector dp(n + 1, vector<T>(m + 1));
			dp[1][1][a[1][1] == e] = 1;
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m; j ++) {
					if (i == 1 && j == 1) {
						continue;
					}
					dp[i][j][0] = (dp[i - 1][j][0] + dp[i][j - 1][0]) % MOD;
					dp[i][j][1] = (dp[i - 1][j][1] + dp[i][j - 1][1]) % MOD;
					if (a[i][j] == e) {
						dp[i][j][1] = (dp[i][j][1] + dp[i][j][0]) % MOD;
						dp[i][j][0] = 0;
					}
				}
			}
			ans = (ans + dp[n][m][1]) % MOD;
		}
	}
	cout << ans << '\n';
	
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	init(1e5 + 10);
	cin >> _;
	while (_ --) {
		solve();
	}
}