#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, j, k;
	cin >> n >> j >> k;
	vector<int> a(n);
	int mx = 0;
	for(int i = 0; i < n; i ++)
		cin >> a[i], mx = max(mx, a[i]);
	j --;
	int x = a[j];
	if(mx == a[j] || k >= 2)
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