#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int pos = 0, r = n - 1;
	while(a[pos] == 0)
		pos ++;
	while(a[r] == 0)
		r --;
	if(r - pos + 1 <= x)
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