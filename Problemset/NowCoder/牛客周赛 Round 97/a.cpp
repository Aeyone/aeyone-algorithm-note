#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	char a, b, c;
	map<char, int> mp;
	cin >> a >> b >> c;
	mp[a] ++, mp[b] ++, mp[c] ++;
	if(mp.size() < 3)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}