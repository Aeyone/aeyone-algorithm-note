#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<string> a(n);
	map<string, bool> mp2, mp;
	bool ok = false;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		int m = a[i].size();
		string x = a[i];

		reverse(x.begin(), x.end());
		ok |= (m == 1 || x == a[i]);
		ok |= (mp.find(x) != mp.end() || mp2.find(x) != mp2.end());
		if(m == 3)
			ok |= (mp.find(x.substr(0, 2)) != mp.end());

		mp[a[i]] = true;
		if(m == 3)
			mp2[a[i].substr(0, 2)] = true;
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