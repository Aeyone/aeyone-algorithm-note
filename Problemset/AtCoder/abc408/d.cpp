#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<array<int, 2>> f(n, {1e9, 1e9});
	vector<array<bool, 2>> vis(n, {true, true});

	if(s[0] == '1')
		f[0] = {0, 1};
	else
		f[0] = {1, 0};

	for(int i = 1; i < n; i ++){
		for(int j = 0; j < 2; j ++){
			if(j == 0 && f[i - 1][j] > f[i - 1][!j]){
				if(vis[i][j])
					vis[i][j] = false;
				else
					f[i][j] = f[i - 1][!j];
			}else
				f[i][j] = min(f[i - 1][j], f[i - 1][!j]);

			if(s[i] - '0' != j)
				f[i][j] ++;
		}
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}