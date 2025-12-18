#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	vector<int> suf(n), pre(n);
	int x = a[0];
	for(int i = 0; i < n; i ++){
		x = min(x, a[i]);
		if(a[i] == x)
			pre[i] = 1;
	}
	x = a[n - 1];
	for(int i = n - 1; i >= 0; i --){
		x = max(x, a[i]);
		if(a[i] == x)
			suf[i] = 1;
	}
	for(int i = 0; i < n; i ++)
		cout << (pre[i] || suf[i]);
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}