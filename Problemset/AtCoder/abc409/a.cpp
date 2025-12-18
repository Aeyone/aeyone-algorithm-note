#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string t, a;
	cin >> t;
	cin >> a;
	bool ok = false;
	for(int i = 0; i < n; i ++)
		ok |= (a[i] == 'o' && t[i] == 'o');
	if(ok)
		cout << "Yes\n";
	else
		cout << "No\n";
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}