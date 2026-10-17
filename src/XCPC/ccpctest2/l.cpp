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
	int n, b, k;
	cin >> n >> b >> k;

	vector<int> path(b), ans;

	auto dfs = [&](auto &&self, int idx, int low, int r, int cost) -> void {
		if (idx >= b) {
			if (cost == k && r == 0) {
				ans = path;
			}
			return;
		}

		for (int i = low; i <= n; i ++) {
			if (r - i < i * (b - idx - 1)) {
				break;
			}
			path[idx] = i;
			self(self, idx + 1, i, r - i, cost + (i - 1) * i / 2);
		}
	};
	dfs(dfs, 0, 1, n, 0);


	if (ans.size() == 0) {
		cout << "IMPOSSIBLE" << '\n';
	} else {
		for (auto e : ans) cout << e << ' ';
		cout << '\n';
		vector<int> a(n);
		iota(a.begin(), a.end(), 1);

		int idx = 0;
		for (auto e : ans) {
			reverse(a.begin() + idx, a.begin() + idx + e);
			idx += e;
		}
		for (auto e : a) cout << e << ' ';
		cout << '\n';
	}
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