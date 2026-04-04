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
	vector<int> a(n);
	for (auto &e : a) {
		cin >> e;
	}
	vector<vector<int>> g(n);
	for (int u = 1; u < n; u ++) {
		int v;
		cin >> v;
		v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> dp(n); // dp[u]代表为节点u所在的最大值，保证dp[u] + 1~k的所有数都被使用过了
	int k = 0;
	for (int i = 1; i < n; i ++) {
		k += (g[i].size() == 1);
	}
	auto dfs = [&](this auto &&self, int u, int fa = -1)-> void {
		if (u != 0 && g[u].size() == 1) {
			dp[u] = k;
			return;
		}
		int mx = 0, mn = INF, sum = 0;
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			mx = max(mx, dp[v]);
			mn = min(mn, dp[v]);
			sum -= (k - dp[v] + 1);
		}
		sum += (k - mn + 1);
		if (a[u]) {
			dp[u] = mx;
		} else {
			dp[u] = mn + sum;
		}
	};
	dfs(0);
	cout << dp[0] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}