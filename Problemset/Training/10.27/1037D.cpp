#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//bfs序?
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> a(n), fa(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		a[i] --;
	}
	if(a[0] != 0){
		cout << "No" << '\n';
		return;
	}
	queue<int> q;
	q.push(0);
	int idx = 1;
	while(q.size()){
		int u = q.front();
		q.pop();
		set<int> st1, st2;
		for(auto v : g[u]) if(v != fa[u]){
			fa[v] = u;
			st1.insert(v);
		}
		for(int i = idx; i < idx + st1.size(); i ++){
			q.push(a[i]);
			st2.insert(a[i]);
		}
		idx += st1.size();
		if(st1 != st2){
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}