#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n);
	map<int, int> mp;
	for(int i = 0; i < n; i ++){
		int l;
		cin >> l;
		v[i].resize(l);
		for(int j = 0; j < l; j ++){
			cin >> v[i][j];
			mp[v[i][j]] ++;
		}
	}
	bool ok = true;
	for(int i = 1; i <= m; i ++){
		ok &= (mp[i] > 0);
	}
	if(!ok){
		cout << "NO" << '\n';
		return;
	}
	int cnt = 0;
	for(int i = 0; i < n; i ++){
		bool ok = false;
		for(int e : v[i]){
			ok |= (mp[e] == 1);
		}
		cnt += ok;
	}

	if(n - cnt >= 2){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}