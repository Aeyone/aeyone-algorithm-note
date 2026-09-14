#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve () {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> in(n + 1);
	while (m --) {
		int l, r;
		cin >> l >> r;
		int siz = r - l + 1;
		vector<int> a(siz);
		cin >> a[0];
		for (int i = 1; i < siz; i ++) {
			cin >> a[i];
			g[a[i - 1]].push_back(a[i]);
			in[a[i]] ++;
		}
	}
	priority_queue<int, vector<int>, greater<int>> q;
	vector<int> vis(n + 1), ans(n + 1);
	for (int i = 1; i <= n; i ++) {
		if (!in[i]) {
			vis[i] = true;
			q.push(i);
		}
	}

	int cur = 1;
	while (q.size()) {
		int u = q.top();
		q.pop();

		ans[u] = cur ++;
		for (auto v : g[u]) {
			in[v] --;
			if (in[v] == 0) {
				q.push(v);
				vis[v] = 1;
			}
		}
	}

	bool ok = false;
	for (int i = 1; i <= n; i ++) {
		ok |= (vis[i] == 0);
	}
	if (ok) {
		cout << -1 << '\n';
		return;
	}
	for (int i = 1; i <= n; i ++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

}

signed main () {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}