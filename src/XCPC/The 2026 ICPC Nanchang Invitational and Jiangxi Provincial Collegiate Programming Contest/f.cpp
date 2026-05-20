#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

const int M = 2e6 + 10;
int path[M], ans[M], idx = 0, idx_ans = 0;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<array<int, 2>>> g(n);
	vector<int> id(2 * m);
	int cur = 0;
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		id[cur] = i;
		g[u].push_back({v, cur ++});
		id[cur] = i;
		g[v].push_back({u, cur ++});
	}
	vector<int> to(n), odd;
	iota(to.begin(), to.end(), 0);
	bool ok = true;
	for (int i = 0; i < k; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		to[u] = v;
		to[v] = u;

		if (g[u].size() < g[v].size()) swap(u, v);
		int dif = g[u].size() - g[v].size();

		if (dif == 0) continue;
		else if (dif == 1) odd.push_back(u);
		else if (dif == 2) odd.push_back(u), odd.push_back(v);
		else ok = false;
	}

	for (int i = 0; i < n; i ++) {
		if (to[i] == i && (g[i].size() & 1)) odd.push_back(i);
	}

	ok &= (odd.size() == 2 || odd.size() == 0);

	if (!odd.size()) {
		for (int i = 0; i < n; i ++) if (g[i].size()) {
				odd.push_back(i);
				break;
			}
	}

	if (!ok) {
		cout << -1 << '\n';
		return;
	}

	for (auto st : odd) {
		idx = 0, idx_ans = 0;
		vector<int> vis(m);
		int cnt = 0;
		vector<int> cur(n);

		auto euler = [&](this auto &&self, int u)-> void {
			while (cur[u] < (int)g[u].size()) {
				auto [v, e] = g[u][cur[u]++];
				if (vis[id[e]]) continue;

				vis[id[e]] = true;
				cnt++;

				self(to[v]);
				path[idx++] = v;
			}
		};

		euler(st);

		if (cnt != m) {
			continue;
		}

		ans[idx_ans ++] = odd[0];
		for (int i = idx - 1; i >= 0; i --) {
			auto u = path[i];
			ans[idx_ans ++] = u;
			if (u != to[u] && i) ans[idx_ans ++] = to[u];
		}

		cout << idx_ans << '\n';
		for (int i = 0; i < idx_ans; i ++) cout << ans[i] + 1 << ' ';
		cout << '\n';
		return;
	}
	
	cout << -1 << '\n';
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