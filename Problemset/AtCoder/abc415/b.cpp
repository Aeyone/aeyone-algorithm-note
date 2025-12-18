#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	vector<pair<int, int>> v;
	int a = 0, b = 0;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == '#'){
			if(!a)
				a = i + 1;
			else if(!b)
				b = i + 1;
		}
		if(a && b)
			v.push_back({a, b}), a = 0, b = 0;
	}
	for(auto [a, b] : v)
		cout << a << ',' << b << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}