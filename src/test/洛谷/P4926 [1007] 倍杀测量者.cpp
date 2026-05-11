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
	int n, s, t;
	cin >> n >> s >> t;

	vector<vector<array<int, 3>>> g(n + 2);
	while (s --) {
		int o, a, b, k;
		cin >> o >> a >> b >> k;
		g[a].push_back({b, k, o});
	}

	while (t --) {
		int c, x;
		cin >> c >> x;
		g[n + 1].push_back({c, x, 3});
		g[c].push_back({n + 1, x, 4});
	}

	for (int i = 1; i <= n; i ++) {
		g[0].push_back({i, 1, 3});
	}

	auto check = [&](double t)-> bool {
		vector<int> cnt(n + 2), vis(n + 2);
		vector<double> dis(n + 2, 1e18);

		queue<int> q;
		dis[0] = 0;
		vis[0] = true;
		q.push(0);

		while (q.size()) {
			auto u = q.front();
			q.pop();

			vis[u] = false;
				// cerr << "u = " << u << '\n';


			for (auto [v, k, o] : g[u]) {
				double w;
				if (o == 1) w = (k - t > 0 ? -log(k - t) : 1e18);
				else if (o == 2) w = log(k + t);
				else if (o == 3) w = log(k);
				else w = -log(k);

				// cerr << "u = " << u << ' ';
				// cerr << "w = " << w << ' ';
				// cerr << '\n';

				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					if (!vis[v]) {
						if (++ cnt[v] > n + 1) { // 判断负环
							return true;
						}
						q.push(v);
						vis[v] = true;
					}
				}
			}
		}
		return false;
	};

	double l = 0, r = 1e10, ans = -1;
	while (r - l >= 1e-8) {
		double mid = (l + r) / 2;
		if (check(mid)) { // check检查是否存在负环
			ans = mid, l = mid;
		} else {
			r = mid;
		}
	}
	// cout << check(3.9) << '\n';
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(8);
	int _ = 1;
	while (_ --) {
		solve();
	}
}