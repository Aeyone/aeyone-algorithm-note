#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

i64 qmi(i64 a, i64 b, int p = MOD){
	i64 res = 1;
	for( ;b ; b >>= 1, a = a * a % p) if(b & 1){
		res = a * res % p;
	}
	return res;
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

	i64 ans = 0;
	auto run = [&](int root)-> void {
		vector<int> dep(n);
		vector st(n, vector<int>(21));

		auto dfs = [&](this auto &&self, int u, int fa = -1)-> void {
			if (fa != -1) {
				st[u][0] = fa;
			}
			for (int p = 1; p < 21; p ++) {
				int la = st[u][p - 1];
				st[u][p] = st[la][p - 1];
			}
			for (auto v : g[u]) if (v != fa) {
				dep[v] = dep[u] + 1;
				self(v, u);
			}
		};
		st[root][0] = root;
		dfs(root);

		auto lca = [&](int x, int y)-> int {
			if (dep[x] < dep[y]) {
				swap(x, y);
			}
			for (int p = 20; p >= 0; p --) {
				if (dep[st[x][p]] >= dep[y]) {
					x = st[x][p];
				}
			}
			if (x == y) {
				return x;
			}
			for (int p = 20; p >= 0; p --) {
				if (st[x][p] != st[y][p]) {
					x = st[x][p];
					y = st[y][p];
				}
			}
			return st[x][0];
		};

		vector dp(n, vector<i64>(n)); // dp[i][j]为深度为i和j的两个点，深度为i的点先到达深度为0的概率;
		for (int i = 0; i < n; i ++) {
			dp[0][i] = 1;
		}
		for (int i = 1; i < n; i ++) {
			for (int j = 1; j < n; j ++) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD * qmi(2, MOD - 2) % MOD;
			}
		}

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < i; j ++) {
				int x = dep[i], y = dep[j], l = dep[lca(i, j)];
				ans = (ans + dp[x - l][y - l]) % MOD;
			}
		}
	};
	for (int i = 0; i < n; i ++) {
		run(i);
	}
	cout << ans * qmi(n, MOD - 2) % MOD << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}