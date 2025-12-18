#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	map<int, int> xx, yy;
	int mx = 0;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> a[i][j], mx = max(mx, a[i][j]);

	int cnt = 0;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(a[i][j] == mx)
				xx[i] ++, yy[j] ++, cnt ++;
	
	int cx = 0, cy = 0, ux = -1, uy = -1;
	for(auto [x, e] : xx){
		if(e > cx)
			ux = x, cx = e;
	}
	for(auto [y, e] : yy){
		if(e > cy)
			uy = y, cy = e;
	}

	bool ok = false;
	if(cx == 1){
		for(int i = 0; i < n; i ++){
			if(xx.find(i) != xx.end()){
				if(a[i][uy] == mx)
					ok |= (xx[i] + cy == cnt + 1);
				else
					ok |= (xx[i] + cy == cnt);
			}
		}
	}
	if(cy == 1){
		for(int i = 0; i < m; i ++){
			if(yy.find(i) != yy.end()){
				if(a[ux][i] == mx)
					ok |= (yy[i] + cx == cnt + 1);
				else
					ok |= (yy[i] + cx == cnt);
			}
		}
	}
	if(cx != 1 && cy != 1){
		if(a[ux][uy] == mx)
			cnt ++;
		ok |= (cx + cy == cnt);
	}
	if(ok)
		cout << mx - 1<< '\n';
	else
		cout << mx << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}