#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1, vector<int> (m + 1));
	for(int i = 0; i < (m + 2) / 2; i ++){
		g[0][i] --;
		for(int j = i; j >= 0; j --)
			g[0][i] += max(0, min(n - j + 1, m - i + 1));
	}
	for(int i = m; i >= (m + 2) / 2; i --)
		g[0][i] = g[0][m - i];

	for(int i = 1; i < (n + 2) / 2; i ++){
		g[i][0] = -1;
		for(int j = i; j >= 0; j --)
			g[i][0] += max(0, min(m - j + 1, n - i + 1));
	}
	for(int i = n; i >= (n + 2) / 2; i --)
		g[i][0] = g[n - i][0];

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
	
	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= m; j ++)
			cout << g[i][j] << ' ';
		cout << '\n';
	}
}


signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while(_ --)
		solve();
}