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
	vector g(n, vector<int>(m));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> g[i][j];
		}
	}
	vector<int> vis(m + 1);
	vector<array<int, 2>> tot;
	for (int j = 0; j < m; j ++) {
		int i = 0;
		while (i < n && g[i][j] == g[0][j]) {
			i ++;
		}
		tot.push_back({i, g[0][j]});
	}
	sort(tot.begin(), tot.end(), greater<array<int, 2>>{});
	int ans = n * m;
	for (auto [len, c] : tot) {
		if (vis[c]) {
			continue;
		}
		ans -= len;
		vis[c] = true;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}