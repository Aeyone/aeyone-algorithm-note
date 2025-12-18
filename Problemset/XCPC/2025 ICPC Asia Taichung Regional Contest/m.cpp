/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		a[i] --;
	}
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v;
		u --, v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int> q;
	vector<int> vis(n, -1), type(k + 1);
	vis[0] = 0;
	type[a[0]] = max(type[a[0]], vis[0]);
	q.push(0);
	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto v : g[u]) if(vis[v] == -1){
			vis[v] = vis[u] + 1;
			type[a[v]] = max(type[a[v]], vis[v]);
			q.push(v);
		}
	}
	for(int i = 0; i < k; i ++){
		cout << type[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}