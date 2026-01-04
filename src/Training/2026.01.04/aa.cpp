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
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,i64>>> g(n+1);
	for(int i=0;i<m;i++){
		int u,v;
		i64 w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vector<int> vis(n+1);
	vector<vector<i64>> d(n+1);
	queue<int> q;
	q.push(1),d[1].push_back(0);
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto [v,w]:g[u]){
			for(auto e:d[u]){
				d[v].push_back(e^w);
			}
			q.push(v);
		}
	}
	sort(d[n].begin(),d[n].end());
	for (auto e : d[n]) {
		cout << e << ' ';
	}
	cout << '\n';
	cout<<d[n][0]<<endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}