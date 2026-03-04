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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<i64> sum(n), son(n); // sum[u]为以0为根，u作为子树时的代价和，son[u]代表子节点的总和
	auto dfs = [&](this auto &&self, int u, int fa)->void {
		son[u] = a[u];
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			son[u] += son[v];
			sum[u] += sum[v] + son[v];
		}
	};
	dfs(0, -1);

	vector<i64> res(n);
	res[0] = sum[0];
	auto dfs1 = [&](this auto &&self, int u, int fa)->void {
		for (auto v : g[u]) if (v != fa) {
			res[v] = res[u] + son[0] - son[v] * 2;
			self(v, u);
		}
	};
	dfs1(0, -1);

	cout << *max_element(res.begin(), res.end()) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}