#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i ++){
		cin >> g[i];
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(g[i][j] >= '1' && g[i][j] <= '9'){
				int d = g[i][j] - '1' + 1;
				g[i][j] = '.';

				for(int p = 0; p < n; p ++){
					for(int q = 0; q < m; q ++){
						if(g[p][q] >= '1' && g[p][q] <= '9'){
							continue;
						}
						if(abs(p - i) + abs(q - j) <= d){
							g[p][q] = '.';
						}
					}
				}

			}
		}
	}
	for(int i = 0; i < n; i ++){
		cout << g[i] << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}