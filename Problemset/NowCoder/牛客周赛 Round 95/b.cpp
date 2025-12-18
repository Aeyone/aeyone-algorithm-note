#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	int q;
	cin >> q;
	while(q --){
		int l, r;
		cin >> l >> r;
		l --, r --;
		vector<i64> res(r - l + 1);
		res[0] = a[l];
		for(int i = l + 1; i <= r; i ++)
			res[i - l] = a[i]  - a[i - 1];
		for(auto e : res)
			cout << e << " ";
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}