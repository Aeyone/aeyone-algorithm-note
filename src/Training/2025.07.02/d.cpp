#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> a[i][j];

	vector<int> row(n * m + 1), col(n * m + 1);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++){
			cin >> b[i][j];
			row[b[i][j]] = i;
			col[b[i][j]] = j;
		}

	bool ok = true;
	for(int i = 0; i < n; i ++){
		map<int, bool> mp;
		for(int k = 0; k < m; k ++)
			mp[a[i][k]] = true;

		int j = row[a[i][0]];
		for(int k = 0; k < m; k ++)
			ok &= (mp[b[j][k]]);
	}
	for(int i = 0; i < m; i ++){
		map<int, bool> mp;
		for(int k = 0; k < n; k ++)
			mp[a[k][i]] = true;

		int j = col[a[0][i]];
		for(int k = 0; k < n; k ++)
			ok &= (mp[b[k][j]]);
	}
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}