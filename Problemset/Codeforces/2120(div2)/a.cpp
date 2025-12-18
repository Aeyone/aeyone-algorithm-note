#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	vector<int> l(4), b(4);
	for(int i = 1; i <= 3; i ++)
		cin >> l[i] >> b[i];

	bool ok = false;
	if(l[1] == l[2] && l[2] == l[3] && (b[1] + b[2] + b[3] == l[1]))
		ok = true;

	else if(b[1] == b[2] && b[2] == b[3] && l[1] + l[2] + l[3] == b[1])
		ok = true;

	else if(l[2] + l[3] == l[1] && b[2] == b[3] && b[1] + b[2] == l[1])
		ok = true;

	else if(b[2] + b[3] == b[1] && l[2] == l[3] && l[1] + l[2] == b[1])
		ok = true;

	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}