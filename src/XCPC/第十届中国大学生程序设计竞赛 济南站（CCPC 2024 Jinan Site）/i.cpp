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
	vector<vector<array<int, 2>>> g(n);
	vector<int> eu(n), ev(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		eu[i] = u, ev[i] = v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	vector<array<int, 2>> dp(n), match(n, {-1, -1}), ans;
	auto dfs1 = [&](this auto &&self, int u, int fa)-> void {
		bool ok = false;
		int cnt = 0;
		for (auto [v, _] : g[u]) if (v != fa) {
			self(v, u);
			cnt ++;
			ok |= dp[v][1];
		}
		if (ok) dp[u][0] = dp[u][1] = 1;
		else if (cnt & 1) dp[u][1] = 1; // u作为端点
		else dp[u][0] = 1; // u不作为端点
	};
	dfs1(0, -1);
	if (!dp[0][0]) {
		cout << -1 << '\n';
		return;
	}

	vector<int> st(n);
	for (int i = 0; i < n; i ++) {
		st[i] = dp[i][1];
	}
	st[0] = 0;

	auto side = [&](int id, int u)-> int {
		return eu[id] == u ? 0 : 1;
	};

	auto link = [&](int u, int e1, int e2)-> void { // 将e1 e2与u节点相连
		match[e1][side(e1, u)] = e2;
		match[e2][side(e2, u)] = e1;
	};

	auto dfs2 = [&](this auto &&self, int u, int fa, int efa)-> void {
		vector<int> tot;
		int p = -1;
		if (st[u]) tot.push_back(efa);
		for (auto [v, id] : g[u]) if (v != fa) {
			if (!dp[v][1] && dp[v][0]) tot.push_back(id);
			else p = id;
		}
		if ((tot.size() & 1) && p != -1) {
			tot.push_back(p);
		}
		for (int i = 0; i + 1 < tot.size(); i += 2) {
			link(u, tot[i], tot[i + 1]);
		}
		for (auto [v, id] : g[u]) if (v != fa) {
			self(v, u, id);
		}
	};
	dfs2(0, -1, -1);

	vector<int> vis(n);
	for (int e = 1; e < n; e ++) {
		if (vis[e]) continue;
		int st = -1;
		if (match[e][0] == -1) st = eu[e];
		if (match[e][1] == -1) st = ev[e];
		if (st == -1) continue;
		int ed = st, cur = e;
		while (cur != -1) {
			vis[cur] = true;
			int to = eu[cur] ^ ev[cur] ^ ed;
			cur = match[cur][side(cur, to)];
			ed = to;
		}
		ans.push_back({st, ed});
	}		

	cout << ans.size() << '\n';
	for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';

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