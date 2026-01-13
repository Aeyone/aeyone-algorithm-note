#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++)
		cin >> g[i];

	int res = 0;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			int mn = m;
			for(int x = i; x < n; x ++){
				if(g[x][j] == '1')
					break;
				for(int y = j; y < mn; y ++){
					if(g[x][y] == '1'){
						mn = y;
						break;
					}
					res = max(res, (x - i + 1) * 2 + (y - j + 1) * 2);
					// cout << x << " - " << i << " || " << y << " - " << j << '\n';
					// cout << res << '\n';
				}
			}
		}
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}