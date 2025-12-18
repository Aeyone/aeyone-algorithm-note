#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, bool> mp;
	for(auto e : s)
		mp[e] = true;

	bool ok = true;
	for(auto e : s){
		if(e > 'Z')
			continue;
		ok &= mp[e + ('a' - 'A')];
	}
	for(auto e : s){
		if(e < 'a')
			continue;
		ok &= mp[e - ('a' - 'A')];
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