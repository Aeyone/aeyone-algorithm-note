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
*	树形DP+计数，对于每个节点，其子节点相互独立，因此把情况累乘起来就行了
*/

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
	vector<array<i64, 2>> dp(n, {1, 1}); // 0白，1黑
	auto dfs = [&](auto &&self, int u, int fa)->void{
		for (auto v : g[u]) if (v != fa) {
			self(self, v, u);
			dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]) % MOD;
			dp[u][1] = dp[u][1] * dp[v][0] % MOD;
		}
	};
	dfs(dfs, 0, -1);
	cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}