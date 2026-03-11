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
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> g(n);
	for (int i = 0; i < m; i ++) {
		int u, v, c;
		cin >> u >> v >> c;
		u --, v --;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}

	vector dis(n, vector<i64>(n, INFLL)); // dis[i][j]为1号到节点i长度为j的路径的最小消耗时间
	dis[0][0] = 0;

	for (int len = 1; len < n; len ++) {
		for (int u = 0; u < n; u ++) {
			for (auto [v, c] : g[u]) {
				dis[v][len] = min(dis[v][len], dis[u][len - 1] + c);
			}
		}
	}

	int q;
	cin >> q;
	while (q --) {
		int t;
		cin >> t;
		t --;

		i64 ans = INFLL, pre = 0;
		for (int i = 1; i < n; i ++) {
			int w;
			cin >> w;
			pre += w;
			ans = min(ans, dis[t][i] + pre);
		}
		cout << ans << '\n';
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