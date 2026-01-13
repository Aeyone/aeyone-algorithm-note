#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> w(n);
	for(int i = 0; i < n; i ++){
		cin >> w[i];
	}
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<vector<i64>> dp(n, vector<i64>(m + 1, INFLL));//节点u距离终点距离为i时的最小花费
	for(int i = 0; i <= m; i ++){
		dp[0][i] = 1ll * w[0] * i;
	}
	for(int i = m; i >= 1; i --){
		for(int u = 0; u < n; u ++){
			for(auto v : g[u]){
				dp[v][i - 1] = min(dp[v][i - 1], dp[u][i] + 1ll * w[v] * (i - 1));
			}
		}
	}
	for(int i = 0; i < n; i ++){
		cout << dp[i][0] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}