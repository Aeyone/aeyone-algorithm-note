#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), need(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	
	i64 add = 0;
	for(int i = 0; i < n; i ++){
		cin >> b[i];
		need[i] = max(0, b[i] - a[i]);
		add += need[i];
	}
	bool ok = true;
	for(int i = 0; i < n; i ++){
		ok &= (a[i] >= b[i] + (add - need[i]) - need[i]);
	}
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