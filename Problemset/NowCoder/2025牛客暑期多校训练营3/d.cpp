#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, a;
	cin >> n >> a;
	string s;
	cin >> s;
	vector<pair<char, int>> v;
	int len = 0;
	char sign = s[0];
	for(int i = 0; i < n; i ++){
		if(s[i] == sign)
			len ++;
		else
			v.push_back({sign, len}), sign = s[i], len = 1;
	}
	v.push_back({sign, len});
	bool ok1 = false, ok0 = false;
	for(auto &[c, d] : v){
		ok0 |= (c == '0' && d >= a + 1);
		ok1 |= (c == '1' && d >= a);
	}
	if(ok1 || ok0)
		cout << n << '\n';
	else
		cout << count(s.begin(), s.end(), '1') << '\n';

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}