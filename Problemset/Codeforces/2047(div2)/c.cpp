#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(2, vector<int>(n));
	for(int i = 0; i <= 1; i ++)
		for(int j = 0; j < n; j ++)
			cin >> a[i][j];

	vector<int> res(n);
	int mx = -1e9;
	i64 sum = 0;
	for(int i = 0; i < n; i ++){
		res[i] = (a[1][i] > a[0][i]);
		mx = max(mx, a[!res[i]][i]);
		sum += a[res[i]][i];
	}
	cout << sum + mx << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}