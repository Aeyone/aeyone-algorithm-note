#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int d1 = 0, d2 = 0;
	bool f1 = false, f2 = false;
	for(int i = 0; i < n; i ++){
		if(f1 && !f2)
			d1 ++;

		if(f2)
			d2 ++;

		if(s[i] == '1' && f1 && f2)
			break;
		if(s[i] == '1' && f1 && !f2)
			f2 = true;
		if(s[i] == '1' && !f1)
			f1 = true;
	}
	if(d1 == d2)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}