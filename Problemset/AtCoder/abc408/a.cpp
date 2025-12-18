#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	double d = s + 0.5;
	bool ok = true;
	ok &= (a[0] < d);
	for(int i = 1; i < n; i ++){
		ok &= (a[i] - a[i - 1] < d);
	}
	if(ok)
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