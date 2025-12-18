#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> f(n);
	for(int i = 0; i < n; i ++)
		cin >> f[i];
	vector<vector<int>> g(n, vector<int>(n));

	for(int i = n - 1; i >= 0; i --){
		map<int, int> vis;
		for(int j = 0; j <= i; j ++){
			int x = ((f[j] + 1) % f[i]);
			g[i][j] = x;
			vis[x] ++;
		}
		int k = 0;
		for(int j = 0; j <= i; j ++){
			while(k < (f[i] - 1) && vis[k]){
				k ++;
			}
			if(vis[g[i][j]] > 1 && k != f[j])
				vis[g[i][j]] --, vis[k] ++, g[i][j] = k;
		}
		for(int j = 0; j <= i; j ++)
			g[j][i] = g[i][j];
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++)
			cout << g[i][j] << ' ';
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}