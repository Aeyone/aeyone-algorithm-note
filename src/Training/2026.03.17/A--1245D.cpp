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
	vector<int> x(n), y(n), c(n), k(n);
	for (int i = 0; i < n; i ++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> k[i];
	}

	using T = array<int, 3>;
	priority_queue<T, vector<T>, greater<T>> pq;
	vector<int> vis(n), to(n);
	vector<i64> dis(n, INFLL);
	i64 ans = 0;

	for (int i = 0; i < n; i ++) {
		dis[i] = c[i];
		pq.push({c[i], i, 1});
	}

	while (pq.size()) {
		auto [e, u, type] = pq.top();
		pq.pop();

		if (vis[u] != 0) {
			continue;
		}
		vis[u] = type;
		ans += e;

		if (type == 1) {
			for (int i = 0; i < n; i ++) {
				if (i == u) {
					continue;
				}
				if (dis[i] > 1ll * (abs(x[i] - x[u]) + abs(y[i] - y[u])) * (k[i] + k[u])) {
					dis[i] = 1ll * (abs(x[i] - x[u]) + abs(y[i] - y[u])) * (k[i] + k[u]);
					to[i] = u;
					pq.push({dis[i], i, 2});
				}
			}
		}
	}
	cout << ans << '\n';
	cout << ranges::count(vis, 1) << '\n';
	for (int i = 0; i < n; i ++) {
		if (vis[i] == 1) {
			cout << i + 1 << ' ';
		}
	}
	cout << '\n';
	cout << ranges::count(vis, 2) << '\n';
	for (int i = 0; i < n; i ++) {
		if (vis[i] == 2) {
			cout << i + 1 << ' ' << to[i] + 1 << '\n';
		}
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