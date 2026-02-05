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
	vector<vector<int>> g(n);
	vector<int> in(n);
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		in[v] ++;
	}
	vector<int> dp(n);
	queue<int> q;
	for (int i = 0; i < n; i ++) {
		if (!in[i]) {
			q.push(i);
		}
	}
	while (q.size()) {
		auto u = q.front();
		q.pop();
		for (auto v : g[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
			in[v] --;
			if (!in[v]) {
				q.push(v);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}