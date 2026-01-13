#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<bool>> f(n, vector<bool>(n));//f[i][j]代表第i位置上，能够从j位置上的数转移而来
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			if(s[i] == s[j] || s[i] == '?' || s[j] == '?'){
				f[j][i] = true;
			}
		}
	}
	// for(int i = 0; i < n; i ++){
	// 	for(int j = 0; j < n; j ++){
	// 		cout << f[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	int ans = 0;
	for(int i = 1; i < n; i ++){
		for(int x = i, y = 0, d = 1; y < n && x < n; x += d, y += d, d = 1){
			if(!f[x][y]){
				continue;
			}
			while(x + d < n && y + d < x && f[x + d][y + d] == f[x][y]){
				d ++;
			}
			if(y + d == x){
				ans = max(ans, d);
			}
		}
	}
	cout << ans * 2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}