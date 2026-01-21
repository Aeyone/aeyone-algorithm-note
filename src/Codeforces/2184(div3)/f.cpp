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
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<array<int, 3>> ok(n);
	auto dfs = [&](auto &&self, int u, int fa)->void{
		ok[u][1] = true;
		if (g[u].size() == 0 || (u != 0 && g[u].size() == 1)) {
			return;
		}
		int cur = (g[u].size() - (u != 0)) % 3;
		ok[u][cur] = true;
		int cnt0 = 0, cnt2 = 0;
		for (auto v : g[u]) if (v != fa){
			self(self, v, u);
			cnt0 += ok[v][0];
			cnt2 += ok[v][2];
		}
		if (cnt2 + cnt0 + 1 >= 3) {
			ok[u] = {1, 1, 1};
		} else {
			ok[u][(cur + 1) % 3] |= (cnt2 > 0);
			ok[u][(cur + 2) % 3] |= (cnt0 > 0);
		}
	};
	dfs(dfs, 0, -1);
	if (ok[0][0]) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
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