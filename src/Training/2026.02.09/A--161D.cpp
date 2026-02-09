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
	vector cnt(n, vector<int>(k + 1));
	i64 ans = 0;
	auto dfs = [&](auto &&self, int u, int fa)->void{
		cnt[u][0] = 1;
		for (auto v : g[u]) if (v != fa) {
			self(self, v, u);
			for (int i = 0; i < k; i ++) {
				ans += 1ll * cnt[v][i] * cnt[u][k - i - 1];
			}
			for (int i = 0; i < k; i ++) {
				cnt[u][i + 1] += cnt[v][i];
			}
		}
	};
	dfs(dfs, 0, -1);
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