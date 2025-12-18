#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<string> s(n), t(n);
	for(int i = 0; i < n; i ++)
		cin >> s[i];
	for(int i = 0; i < n; i ++)
		cin >> t[i];
	int ans = 1e9;
	for(int k = 0; k < 4; k ++){
		int res = k;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				int x, y;
				if(k == 0)
					x = i, y = j;
				if(k == 1)
					x = n - j - 1, y = i;
				if(k == 2)
					x = n - i - 1, y = n - j - 1;
				if(k == 3)
					x = j, y = n - i - 1;
				if(s[x][y] != t[i][j])
					res ++;
			}
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}