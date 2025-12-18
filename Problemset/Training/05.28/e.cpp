#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> x(n), d(n);
	map<int, int> mp;
	for(int i = 0; i < n; i ++){
		cin >> x[i] >> d[i];
		d[i] = x[i] + d[i];
		mp[x[i]] = d[i];//位置x[i]的骆驼向位置d[i]吐了口水
	}
	bool ok = false;
	for(int i = 0; i < n; i ++){
		if(mp.find(d[i]) == mp.end())
			continue;
		ok |= (mp[d[i]] == x[i]);
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
	// cin >> _;
	while (_ --)
		solve();
}