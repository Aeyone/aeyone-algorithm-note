#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0; i < n; i ++)
		cin >> s[i];

	int l = 100, r = 0, d = 100, u = 0;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(s[i][j] == '*'){
				l = min(l, j);
				d = min(d, i);
				u = max(u, i);
				r = max(r, j);
			}
		}
	}
	for(int i = d; i <= u; i ++){
		for(int j = l; j <= r; j ++)
			cout << s[i][j];
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}