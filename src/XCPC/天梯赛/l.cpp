#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> g(n);
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		g[u].push_back({v, w});
	}
	for (int u = 0; u < n; u ++) {
		sort(g[u].begin(), g[u].end());
	}

	int k;
	cin >> k;
	while (k --) {
		int x;
		cin >> x;
		x --;

		vector<int> ne(n), vis(n), ans = {x};

		auto dfs = [&](auto &&self, int u, int fa = -1) -> void {
			// cerr << "u, fa = " << u << ' ' << fa << '\n';
			int mx = 0;		
			for (auto [v, w] : g[u]) if (v != fa && !vis[v]) {
				mx = max(mx, w);
			}
			for (auto [v, w] : g[u]) if (v != fa && !vis[v]){
				if (w == mx) {
					ans.push_back(v);
					vis[v] = true;
					self(self, v, u);
					break;
				}
			}
		};
		vis[x] = true;
		dfs(dfs, x);

		for (int i = 0; i < ans.size() - 1; i ++) {
			cout << ans[i] + 1 << "->";
		}
		cout << ans.back() + 1 << '\n';
		
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}