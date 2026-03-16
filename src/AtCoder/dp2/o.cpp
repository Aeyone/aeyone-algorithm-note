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

void solve() {
	vector<int> a(27);
	for (int i = 1; i <= 26; i ++) {
		cin >> a[i];
	}
	vector dp(27, vector<i64>(300)); // 定义dp[i][gap]为考虑前i个字母，相邻两个字母相邻的个数为gap的方案数
	dp[0][0] = 1;
	int sum = 0;
	for (int i = 0; i < 26; i ++) {
		sum += a[i];
		if (!a[i + 1]) {
			dp[i + 1] = dp[i];
		} else {
			for (int gap = 0; gap <= sum; gap ++) { 				 	// 相邻两个字母是相同的隔板数量
				for (int p = 1; p <= min(sum + 1, a[i + 1]); p ++) { 	// 当前字母的分组数，最多分sum + 1组
					for (int in = 0; in <= min(gap, p); in ++) { 	 	// 枚举有多少个组在两个相邻的位置上，最多不能超过当前枚举的gap数量
						i64 cur = dp[i][gap];
						cur = cur * C(a[i + 1] - 1, p - 1) % MOD; 		// 给a[i + 1]分组
						cur = cur * C(gap, in) % MOD;					// 在gap上的分组数
						cur = cur * C(sum + 1 - gap, p - in) % MOD;		// 不影响gap的分组数
						dp[i + 1][gap - in + a[i + 1] - p] = (dp[i + 1][gap - in + a[i + 1] - p] + cur) % MOD; 
					}
				}
			}
		}
	}
	cout << dp[26][0] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	init(1000);
	while (_ --) {
		solve();
	}
}