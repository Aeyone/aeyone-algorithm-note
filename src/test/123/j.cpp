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
	int n, m, s;
	cin >> n >> m >> s;
	s --;
	vector<int> vis(n), fire(n);
	queue<array<int, 3>> q;
	vis[s] = true;
	q.push({s, 0, 0});
	for (int i = 0; i < m; i ++) {
		int x;
		cin >> x;
		fire[x - 1] = true;
		q.push({x - 1, 1, -1});
	}
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while (q.size()) {
		auto [u, sign, d] = q.front();
		q.pop();
		// cerr << "u, sign, d" << u + 1 << ' ' << sign << ' ' << d << '\n';
		if (!sign) {
			if (fire[u]) {
				continue;
			}
			if (g[u].size() == 1) {
				cout << d << '\n';
				return;
			}
			for (auto v : g[u]) {
				if (vis[v] || fire[v]) {
					continue;
				}
				vis[v] = true;
				q.push({v, 0, d + 1});
			}
		} else {
			for (auto v : g[u]) {
				if (fire[v]) {
					continue;
				}
				fire[v] = true;
				q.push({v, 1, -1});
			}
		}
	}
	cout << -1 << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}