#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> a[i][j];

	int dx[3] = {0, -1, 0}, dy[3] = {-1, 0, 1};
	for(int i = 1; i < n; i ++){
		for(int j = 0; j < m; j ++){
			for(int k = 0; k < m; k ++){
				int X = i, Y = k;
				for(int p = 0; p < 3; p ++){
					int x = i + dx[p], y = k + dy[p];
					if(x < 0 || y < 0 || x >= n || y >= m)
						continue;

					if(a[x][y] >= a[i][k]){
						if((X == i && Y == k) || a[x][y] < a[X][Y])
							X = x, Y = y;
					}
				}
				a[i][k] = a[X][Y];
			}
		}
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++)
				cout << a[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
	


	while(q --){
		int num;
		cin >> num;
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