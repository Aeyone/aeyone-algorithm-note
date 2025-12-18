#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s;
	cin >> s;
	vector<int> v;
	int len = 0;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == 'A')
			len ++;
		else{
			v.push_back(len);
			len = 0;
		}
	}
	v.push_back(len);
	int ans = 0, mn = 0x3f3f3f3f;
	for(auto e : v)
		ans += e, mn = min(mn, e);

	cout << ans - mn << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}