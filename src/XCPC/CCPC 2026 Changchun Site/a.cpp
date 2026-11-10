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
	vector<vector<int>> a(n, vector<int>(m));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> a[i][j];
		}
	}

	vector<int> cur(m, n - 1);
	for (int i = 0; i < m; i ++) {
		while (cur[i] >= 0 && a[cur[i]][i] == 0) cur[i] --;
	}

	int ans = 0;
	while (1) {
		int min = INF;
		vector<array<int, 2>> v;
		for (int i = 0; i < m; i ++) {
			if (cur[i] == -1 && v.size() == 0) continue;
			if (v.size() == 0 || cur[i] >= v.back()[0]) {
				v.push_back({cur[i], i});
				min = std::min(min, a[cur[i]][i]);
			} else {
				break;
			}
		}

		ans += min;
		for (auto [e, idx] : v) {
			a[e][idx] -= min;
		}

		int max = -1;
		for (int i = 0; i < m; i ++) {
			while (cur[i] >= 0 && a[cur[i]][i] == 0) cur[i] --;
			max = std::max(max, cur[i]);
		}
		if (max == -1) break;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}