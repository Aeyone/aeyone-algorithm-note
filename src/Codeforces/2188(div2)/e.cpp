#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> to(n);
	ranges::iota(to, 1);
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		to[u] = max(to[u], v);
	}
	for (int i = 0; i < n - 1; i ++) {
		g[i].push_back(to[i]);
		g[to[i]].push_back(i);
	}

	vector<map<int, int>> cnt(n);
	vector<int> dep(n);

	int ans = 0;
	auto dfs = [&](this auto &&self, int u, int fa = -1)-> void {
		for (auto v : g[u]) if (v != fa) {
			dep[v] = dep[u] + 1;
			self(v, u);
			if (cnt[v].size() > cnt[u].size()) {
				swap(cnt[v], cnt[u]);
			}
			int sum = cnt[u][-1], pre = 0;
			for (auto [d, c] : cnt[v]) {
				if (d != -1) {
					pre += cnt[u][d] * (d - dep[u]); // 维护前缀子树中的前缀tom的贡献和
					ans += c * pre;	// v子树当前层节点全部作为jerry的贡献
					ans += sum * c * (d - dep[u]); // v子树当前层节点全部作为tom的贡献
					sum -= cnt[u][d]; // 维护前缀子树中的后缀jerry的贡献和，其实就是大于等于当前层数的节点数量
				}
				cnt[u][d] += c;
			}
		}
		cnt[u][dep[u]] ++;
		cnt[u][-1] ++;
	};
	dfs(n - 1);
	cout << ans << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}