#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	map<int, int> cnt;
	for(int i = 0; i < n * (n - 1) / 2 - 1; i ++){
		int u, v;
		cin >> u >> v;
		u -- , v --;
		g[u].push_back(v);
		cnt[u] ++, cnt[v] ++;
	}
	vector<int> l;
	for(int i = 0; i < n; i ++)
		if(cnt[i] < n - 1)
			l.push_back(i);
	
	int a = l[0] , b = l[1];

	queue<int> q;
	bool vis[60] = {};
	q.push(a);
	vis[a] = true;

	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto e : g[u]){
			if(!vis[e])
				q.push(e), vis[e] = true;
		}
	}

	if(!vis[b])
		swap(a, b);

	cout << a + 1 << " " << b + 1<< '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}