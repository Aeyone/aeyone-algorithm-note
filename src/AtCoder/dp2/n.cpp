#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

/*
* 	dp[u]代表以u为子树根节点时，整个子树的方案数，cnt[u]为节点个数
*	考虑u的两个儿子节点v1，v2，对于v1的一种方案，v2的一种方案，需要保持子树加边的顺序不动
*	那么就有C(cnt[v1]+cnt[v2], cnt[v1])种组合方式，其中dp[v1] dp[v2]分别为两个子树的方案数
*	所以转移方程为 dp[u] = ∏dp[v] * C(∑cnt[v], cnt[v1]) * C(∑cnt[v] - cnt[v1], cnt[v2]) * ... * C(cnt[vn], cnt[vn])
*/

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
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<i64> cnt(n), dp(n); 
	auto dfs = [&](this auto &&self, int u, int fa = -1)->void {
		cnt[u] = 1;
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			cnt[u] += cnt[v];
		}
		dp[u] = 1;
		int sum = cnt[u] - 1;
		for (auto v : g[u]) if (v != fa) {
			dp[u] = dp[u] * C(sum, cnt[v]) % MOD * dp[v] % MOD;
			sum -= cnt[v];
		}
	};

	i64 ans = 0;
	for (int i = 0; i < n; i ++) {
		dfs(i);
		ans = (ans + dp[i]) % MOD;
	}
	cout << ans * inv[2] % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init(1e5);
	int _ = 1;
	while (_ --) {
		solve();
	}
}