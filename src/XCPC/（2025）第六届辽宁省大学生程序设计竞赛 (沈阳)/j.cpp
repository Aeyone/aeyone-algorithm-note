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
	vector<vector<int>> g(n + 1);
	while (m --) {
		int c;
		cin >> c;
		if (c == 1) {
			int idx, x;
			cin >> idx >> x;
			g[idx].push_back(x);
		}
		if (c == 2) {
			int idx1, j1, idx2, j2;
			cin >> idx1 >> j1 >> idx2 >> j2;
			swap(g[idx1][j1 - 1], g[idx2][j2 - 1]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		cout << g[i].size() << ' ';
		for (auto e : g[i]) {
			cout << e << ' ';
		}
		cout << '\n';
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