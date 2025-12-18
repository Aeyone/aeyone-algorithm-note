#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	map<int, int> mp1, mp2;
	for(int i = 1; i <= n; i ++)
		cin >> a[i], mp1[a[i]] ++;

	mp2 = mp1;
	i64 pre = 1e16, suf = 1e16;
	for(int i = 1; i <= n; i ++){
		bool ok = true;
		mp1[a[i]] --;
		for(int j = i + 1; j <= n; j ++)
			ok &= (mp1[a[j]] == 1);
		if(ok)
			pre = min(pre, (i64)a[i] * i);
	}

	vector<int> b(n + 1);
	b = a;
	reverse(b.begin() + 1, b.end());
	for(int i = 1; i <= n; i ++){
		bool ok = true;
		mp2[b[i]] --;
		for(int j = i + 1; j <= n; j ++)
			ok &= (mp2[b[j]] == 1);
		if(ok)
			suf = min(suf, (i64)b[i] * i);
	}
	cout << min(suf, pre) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}