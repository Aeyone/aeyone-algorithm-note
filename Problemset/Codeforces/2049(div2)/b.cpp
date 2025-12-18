#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool flag = false, ok = true;
	for(int i = 0; i < n; i ++) if(s[i] != '.'){
		flag |= (s[i] == 'p');
		ok &= (!flag ||(flag && s[i] != 's'));
	}
	int cs = count(s.begin(), s.end(), 's'), cp = count(s.begin(), s.end(), 'p');
	ok &= ((s.front() == 's' && cs == 1) || (s.back() == 'p' && cp == 1));
	ok |= (cs == 0 || cp == 0);
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}