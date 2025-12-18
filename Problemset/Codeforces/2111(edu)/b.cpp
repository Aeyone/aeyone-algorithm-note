#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> f(n + 1);
	f[1] = 1;
	f[2] = 2;
	for(int i = 3; i <= n; i ++)
		f[i] = f[i - 1] + f[i - 2];
	int x = f[n] + f[n - 1];
	int y = f[n];
	// cout << x << "!!!" << y << '\n';
	string res(m, '0');
	vector<array<int, 3>> box(m);
	for(int i = 0; i < m; i ++)
		cin >> box[i][0] >> box[i][1] >> box[i][2];
	
	for(int i = 0; i < m; i ++){
		int mn = 1e9, mx = 0;
		for(int j = 0; j < 3; j ++){
			mn = min(mn, box[i][j]);
			mx = max(mx, box[i][j]);
		}
		if(mn >= y && mx >= x)
			res[i] = '1';
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}