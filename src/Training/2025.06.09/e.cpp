#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 infll = 1e16;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i][0] >> a[i][1];

	vector<vector<int>> g(n);
	vector<int> cnt(n);
	for(int i = 0; i < n - 1; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
		cnt[u] ++, cnt[v] ++;
	}
	queue<int> q;
	vector<bool> vis(n);
	for(int i = 0; i < n; i ++)
		if(cnt[i] == 1){
			q.push(i);
			vis[i] = true;
		}
	vector<array<i64, 2>> dp(n);
	i64 ans = 0;
	vector<bool> fa(n);
	int root = q.front();
	q.pop();
	while(q.size()){
		int e = q.front();
		root = e;
		q.pop();
		for(auto u : g[e]){
			dp[u][0] += max(dp[e][0] + abs(a[u][0] - a[e][0]), dp[e][1] + abs(a[u][0] - a[e][1]));
			dp[u][1] += max(dp[e][0] + abs(a[u][1] - a[e][0]), dp[e][1] + abs(a[u][1] - a[e][1]));
			if(!vis[u]){
				q.push(u);
				vis[u] = true;
			}
		}
	}
	cout << max(dp[root][0], dp[root][1]) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}