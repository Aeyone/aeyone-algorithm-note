#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	
	// vector<vector<int>> g(n, vector<int>(n));
	// for(int i = 0; i < n; i ++)
	// 	g[i][0] = k, g[i][i] = k;
	// for(int i = 2; i < n; i ++){
	// 	for(int j = 1; j < i; j ++)
	// 		g[i][j] = (g[i - 1][j - 1] ^ g[i - 1][j]);
	// }
	// for(int i = 0; i < n; i ++){
	// 	cout << "i = " << i + 1 << " # ";
	// 	for(int j = 0; j <= i; j ++)
	// 		cout << g[i][j] << ' ';
	// 	cout << '\n';
	// }
	for(int i = 0; i < n; i ++){
		if((i | (n - 1)) == (n - 1))
			cout << k << ' ';
		else
			cout << 0 << ' ';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}