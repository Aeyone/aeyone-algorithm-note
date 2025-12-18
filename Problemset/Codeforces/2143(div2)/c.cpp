#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<int> in(n);
	for(int i = 1; i < n; i ++){
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		u --, v --;
		int a = min(u, v), b = max(u, v);
		if(x >= y)
			g[a].push_back(b), in[b] ++;
		else
			g[b].push_back(a), in[a] ++;
	}
	queue<int> q;
	vector<int> res(n);
	for(int i = 0; i < n; i ++){
		if(in[i] == 0)
			q.push(i);
	}
	int idx = n;
	while(q.size()){
		int u = q.front();
		q.pop();
		res[u] = idx --;
		for(auto v : g[u]){
			in[v] --;
			if(in[v] == 0)
				q.push(v);
		}
	}
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}