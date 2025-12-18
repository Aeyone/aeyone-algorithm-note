#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int h = a[k - 1];
	sort(a.begin(), a.end());

	int u = 0, dh = 0;
	while(a[u] < h)
		u ++;
	bool ok = true;
	for(int i = u; i < n - 1; i ++){
		ok &= (a[i + 1] - a[i] <= a[i] - dh);
		dh += a[i + 1] - a[i];
	}
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