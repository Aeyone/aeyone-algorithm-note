#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<i64> siz(n), s2(n), s3(n);
	auto dfs = [&](this auto &&self, int u, int fa)-> void {
		siz[u] = 1;
		int s1 = 0;
		for (auto v : g[u]) if (v != fa) {
			self(v, u);
			siz[u] += siz[v];
			s3[u] += siz[v] * s2[u];
			s2[u] += siz[v] * s1;
			s1 += siz[v];
		}
	};
	dfs(0, -1);
	i64 ans = 0;
	for (int i = 0; i < n; i ++) {
		int x = sqrt(a[i]);
		if (x * x == a[i]) {
			ans += s3[i] + s2[i] * (n - siz[i] + 1) + (siz[i] - 1) * (n - siz[i]);
		}
	}
	cout << ans << '\n';
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