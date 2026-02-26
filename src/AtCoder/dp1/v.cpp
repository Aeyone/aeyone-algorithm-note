#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, M;
	cin >> n >> M;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	// dp[u]代表以0为根时 节点u为黑色的时的情况数
	// 由于模数不固定 不能考虑逆元 只能对于每个子节点维护除了自己之外的积 即为前缀积和后缀积
	vector<i64> dp(n, 1), exc(n, 1); 

	auto dfs = [&](this auto &&self, int u, int fa = -1)->void {
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			exc[v] = dp[u]; // 处理前缀积
			dp[u] = dp[u] * (1 + dp[v]) % M; // 1为全白的情况 
		}
	};
	dfs(0);

	auto dfs1 = [&](this auto &&self, int u, int fa = -1)->void {
		i64 cur = 1;
		for (int i = g[u].size() - 1; i >= 0; i --) {
			int v = g[u][i];
			if (v == fa) {
				continue;
			}
			self(v, u);
			exc[v] = (exc[v] * cur) % M; //处理后缀积
			cur = cur * (dp[v] + 1) % M;
		}
	};
	dfs1(0);

	// 处理换根 当根为u->v变化时 对于v的所有子节点v' 对v的贡献不变 u对v的贡献需要在dp[u]中把v去掉 
	// up为当前u的父亲节点的累乘中不包括以节点u为子树的所有情况的数量
	vector<i64> res(n, 1);
	auto dfs2 = [&](this auto &&self, int u, int fa = -1, i64 up = 1)->void {
		res[u] = up * dp[u] % M;
		for (auto v : g[u]) if (v != fa) {
			self(v, u, (up * exc[v] + 1) % M);
		}
	};
	dfs2(0);
	for (int i = 0; i < n; i ++) {
		cout << res[i] << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}