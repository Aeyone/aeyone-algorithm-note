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
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<array<int, 2>>> g(n);
	map<array<int, 2>, int> idx;
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		idx[{u, v}] = i;
		idx[{v, u}] = i;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	using T = array<i64, 3>;
	priority_queue<T, vector<T>, greater<T>> q;

	vector<int> vis(n);
	vector<i64> dis(n, INFLL);
	vector<vector<int>> gg(n);
	set<int> ans;

	q.push({0, 0, -1});
	dis[0] = 0;

	while (q.size()) {
		auto [e, u, fa] = q.top();
		q.pop();

		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		if (fa != -1) {
			gg[fa].push_back(u);
			gg[u].push_back(fa);
			ans.insert(idx[{fa, u}]);
		}

		for (auto [v, w] : g[u]) {
			if (dis[v] > e + w) {
				dis[v] = e + w;
				q.push({dis[v], v, u});
			}
		}
	}
	int cur = n - 1;

	auto dfs = [&](auto &&self, int u, int fa)->void {
		for (auto v : gg[u]) if(v != fa) {
			self(self, v, u);
			if (cur > k) {
				cur --;
				ans.erase(ans.find(idx[{u, v}]));
			}
		}
	};
	dfs(dfs, 0, -1);
	cout << ans.size() << '\n';
	for (auto e : ans) {
		cout << e + 1 << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}