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
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> vis(n), col(n);
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		if (vis[i]) {
			continue;
		}
		bool ok = true;
		vis[i] = true;
		queue<int> q;
		q.push(i);
		int cnt[2] = {1, 0};
		while (q.size()) {
			auto u = q.front();
			q.pop();
			for (auto v : g[u]) {
				if (!vis[v]) {
					col[v] = !col[u];
					cnt[col[v]] ++;
					vis[v] = true;
					q.push(v);
				} else {
					ok &= (col[v] == !col[u]);
				}
			}
		}
		if (ok) {
			ans += max(cnt[0], cnt[1]);
		}
	}
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