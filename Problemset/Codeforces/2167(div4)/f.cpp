#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> vis(n), deep(n);
	queue<int> q;
	for(int i = 0; i < n; i ++){
		if(g[i].size() == 1){
			vis[i] = true;
			q.push(i);
		}
	}
	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto v : g[u]){
			if(vis[v]){
				continue;
			}
			deep[v] = deep[u] + 1;
			vis[v] = true;
			q.push(v);
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i ++){
		cnt += (deep[i] <= k - 1);
	}
	cout << n * (n - cnt) + cnt << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}