#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	while(q --){
		map<int, int> mp;
		int l, r;
		cin >> l >> r;
		if((r - l + 1) % 2 != 0){
			cout << "No" << '\n';
			continue;
		}

		for(int i = l - 1; i < r; i ++)
			mp[a[i]] ++;

		bool ok = true;
		for(int i = 1; i <= (r - l + 1) / 2; i ++)
			ok &= (mp[i] == 2);
		if(ok)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
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