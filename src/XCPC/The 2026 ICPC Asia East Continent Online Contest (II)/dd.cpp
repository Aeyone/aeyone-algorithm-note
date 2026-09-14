#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a((1<<n+1)-1);
	vector<vector<int>> b((1<<n+1)-1);
	for(int i=0;i<q;i++){
		int u,x;
		cin>>u>>x;
		a[u]=x;
		b[x].push_back(u);
	}
	for(int i=0;i<n;i++){
		sort(b[i].begin(),b[i].end());
		
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}