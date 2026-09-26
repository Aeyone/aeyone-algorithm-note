#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

int qmi(int a, int b) {
	int ans = 1;
	a = a % MOD;
	for (; b > 0; b >>= 1, a = a * a % MOD) if (b & 1) {
		ans = ans * a % MOD;
	}
	return ans;
}

int inv(int x) {
	return qmi(x, MOD - 2) % MOD;
}

void solve() {
	int n, m, t;
	cin >> n >> m >> t;
	t --;
	string s;
	cin >> s;
	vector<vector<array<int, 2>>> g1(n), g2(n);
	vector<int> in(n);
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --,  v --;
		g1[u].push_back({v, w});
		g2[v].push_back({u, w});
		in[u] ++;
	}
	using T = array<int, 2>;
	priority_queue<T, vector<T>, greater<T>> q;
	vector<int> dis(n, INF), vis(n);

	dis[t] = 0;
	q.push({0, t});

	while (q.size()) {
		auto [d, u] = q.top();
		q.pop();

		if (vis[u]) continue;
		vis[u] = 1;

		for (auto [v, w] : g2[u]) {
			if (dis[v] > d + w) {
				dis[v] = d + w;
				q.push({d + w, v});
			}
		}
	}
	vector<vector<array<int, 2>>> low(n);
	vector<int> ans(n), cnt(n);
	queue<int> que;

	que.push(t);
	cnt[t] = 1;

	while (que.size()) {
		auto u = que.front();
		que.pop();

		for (auto [v, w] : g1[u]) {
			if (dis[u] == dis[v] + w) {
				cnt[u] = (cnt[u] + cnt[v]) % MOD;
				if (s[u] == '1') low[u].push_back({v, w});
			}
		}

		if (s[u] == '1') {
			for (auto [v, w] : low[u]) {
				int cur = (ans[v] + w) % MOD * cnt[v] % MOD;
				ans[u] = (ans[u] + cur) % MOD;
			}
			ans[u] = ans[u] * inv(cnt[u]) % MOD;
		} else {
			for (auto [v, w] : g1[u]) {
				ans[u] = (ans[u] + (ans[v] + w) % MOD) % MOD;
			}
			ans[u] = ans[u] * inv(g1[u].size()) % MOD;
		}

		for (auto [v, w] : g2[u]) {
			in[v] --;
			if (!in[v]) {
				que.push(v);
			}
		}
	}

	for (auto e : ans) cout << e << ' ';
	cout << '\n';

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}