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
*	dp[i][j][k]代表从i开始的子树，类型是j，画了k条不相交边的方案数
*	每个节点都具有三种不同的形态
*	类型0：该节点i没有包含进任意一条路径
*	类型1：该节点i被包含进了一条以某个祖先为top的一条链
*	类型2：该节点i被包含进了一条由两个类型1的链，拼凑而成的一条"拐弯"的路径
*
*	转移：转移的时候要保证k[v]>0
*		v,k[v]	0				1				2
*	u,k[u]
*	 0		0,k[v]+k[u]    	0,k[u]+k[v]		0,k[u]+k[v]
*			/1,k[v]+k[u]+1	/1,k[u]+k[v]
*	
*	 1  	1,k[v]+k[u]	   	1,k[u]+k[v]		1,k[v]+k[u]
*			/2,k[u]+k[v]	/2,k[u]+k[v]-1
*	
*	 2 		2,k[v]+k[u]		2,k[v]+k[u]		2,k[v]+k[u]
*/

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector dp(n, vector(3, vector<i64>(k + 10))); 
	auto dfs = [&](this auto &&self, int u, int fa = -1)-> void {
		dp[u][0][0] = 1;
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			auto ndp = dp[u];
			for (int i = 0; i <= k + 1; i ++) {
				for (int j = 0; i + j <= k + 1; j ++) {
					for (int tu = 0; tu < 3; tu ++) {
						for (int tv = 0; tv < 3; tv ++) {
							if (j > 0) {
								ndp[tu][i + j] = (ndp[tu][i + j] + dp[u][tu][i] * dp[v][tv][j] % MOD) % MOD;
							}
						}
					}
					ndp[1][i + j + 1] = (ndp[1][i + j + 1] + dp[u][0][i] * dp[v][0][j] % MOD) % MOD;
					ndp[1][i + j] = (ndp[1][i + j] + dp[u][0][i] * dp[v][1][j] % MOD) % MOD;
					ndp[2][i + j] = (ndp[2][i + j] + dp[u][1][i] * dp[v][0][j] % MOD) % MOD;
					if (i + j - 1 >= 1) {
						ndp[2][i + j - 1] = (ndp[2][i + j - 1] + dp[u][1][i] * dp[v][1][j] % MOD) % MOD;
					}
				}
			}
			dp[u] = ndp;
		}
	};
	dfs(0);
	i64 ans = 0;
	ans = (ans + dp[0][0][k]) % MOD;
	ans = (ans + dp[0][1][k]) % MOD;
	ans = (ans + dp[0][2][k]) % MOD;
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}