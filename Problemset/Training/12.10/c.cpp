#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	x --, y --;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, greater<pair<vector<int>, int>>> heap;
	vector<vector<int>> dis(n, vector<int>{INF});
	vector<int> vis(n);
	dis[x] = {x};
	heap.push({{x}, x});
	while(heap.size()){
		auto [arr, u] = heap.top();
		heap.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = true;
		for(auto v : g[u]) {
			vector<int> tmp = arr;
			tmp.push_back(v);
			if(dis[v] > tmp){
				dis[v] = tmp;
				heap.push({tmp, v});
			}
		}
	}
	for(auto e : dis[y]){
		cout << e + 1 << ' ';
	}
	cout << '\n';
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