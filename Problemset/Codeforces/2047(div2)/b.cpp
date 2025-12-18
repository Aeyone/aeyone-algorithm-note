#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> mp;
	for(auto e : s)
		mp[e] ++;
	set<pair<int, char>> st;
	for(auto [c, e] : mp){
		st.insert({e, c});
	}
	char mn = st.begin()->second, mx = (--st.end())->second;
	bool ok = false;
	for(auto &e : s){
		if(!ok && e == mn)
			e = mx, ok = true;
		cout << e;
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}