#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	vector<int> len(4);
	int dx = 0, dy = 0;
	map<pair<int, int>, bool> mp;
	map<pair<pair<int, int>, pair<int, int>>, bool> vis;

	bool flag = false;
	for(int i = 0; i < 4; i ++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		flag |= (vis[{{a, b},{c, d}}] || vis[{{c, d},{a, b}}]);
		flag |= !((abs(a - c) > 0) ^ (abs(b - d) > 0));

		vis[{{a, b},{c, d}}] = true;
		vis[{{c, d},{a, b}}] = true;
		mp[{a, b}] = true;
		mp[{c, d}] = true;

		dx = max(dx, abs(a - c));
		dy = max(dy, abs(b - d));
	}
	flag |= (dx == 0 || dy == 0);
	
	if(mp.size() != 4 || flag){
		cout << "NO\n";
		return;
	}

	int x = 2e9, y = 2e9;
	for(auto [e, _] : mp)
		if(x >= e.first && y >= e.second)
			x = e.first, y = e.second;
		// cout << e.first << " " << e.second << '\n';

	bool ok = true;
	ok &= mp[{x + dx, y}];
	ok &= mp[{x, y + dy}];
	ok &= mp[{x + dx, y + dy}];
	if(ok)
		cout << "YES\n";
	else
		cout << "NO\n";
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}