#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	vector<int> a(5), b(5);
	i64 s1 = 0, s2 = 0;
	for(int i = 0; i < 5; i ++)
		cin >> a[i], s1 += a[i];
	for(int i = 0; i < 5; i ++)
		cin >> b[i], s2 += b[i];

	i64 mx = 0;
	for(int i = 0; i < 5; i ++)
		mx = max(mx, s1 + a[i]);

	bool ok = false;
	for(int i = 0; i < 5; i ++)
		ok |= (mx > (s2 + b[i]));
	
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