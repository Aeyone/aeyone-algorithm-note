#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> g(n);
	for(int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	} 
	for(int i = 0; i < n; i ++) {
		sort(g[i].begin(), g[i].end());
	}
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	vector<int> vis(n), dis(n, INF);
	queue<int> q;
	q.push(0);
	vis[0] = 1, dis[0] = 0;
	while(q.size()) {
		auto u = q.front();
		q.pop();
		for(auto [v, w] : g[u]) {
			if(vis[v] <= 2) {
				dis[v] = 
				vis[v] ++;
				q.push(v);
			}
		}
	}
	cout << dis[n - 1] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}