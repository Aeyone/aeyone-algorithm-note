#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//跑拓扑序
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(k, vector<int>(n));
	vector<set<int>> g(n + 1);
	vector<int> in(n + 1);
	for(int i = 0; i < k; i ++){
		for(int j = 0; j < n; j ++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < k; i ++){
		for(int j = 1; j < n - 1; j ++){
			if(g[a[i][j]].find(a[i][j + 1]) == g[a[i][j]].end()){
				in[a[i][j + 1]] ++;
				g[a[i][j]].insert(a[i][j + 1]);
			}
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i ++){
		if(in[i] == 0){
			q.push(i);
		}
	}
	while(q.size()){
		auto u = q.front();
		q.pop();
		for(auto v : g[u]){
			in[v] --;
			if(!in[v]){
				q.push(v);
			}
		}
	}
	bool ok = true;
	for(int i = 1; i <= n; i ++){
		ok &= (in[i] == 0);
	}
	if(ok){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}