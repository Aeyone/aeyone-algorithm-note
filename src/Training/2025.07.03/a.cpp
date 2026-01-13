#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(n + 1), sufmex(n + 1), res;
	map<int, bool> mp;
	for(int i = 0; i < n; i ++)
		cin >> a[i], mp[a[i]] = true, cnt[a[i]] ++;

	mp.clear();
	int m = 0;
	sufmex[n] = 0;
	for(int i = n - 1; i >= 0; i --){
		mp[a[i]] = true;
		while(mp[m])
			m ++;
		sufmex[i] = m;
	}

	mp.clear(), m = 0;
	int idx = 0;
	for(int i = 0; i < n; i ++){
		mp[a[i]] = true;
		while(mp[m])
			m ++;

		if(sufmex[idx] == m){
			res.push_back(m);
			mp.clear();
			idx = i + 1;
			m = 0;
		}
		// cout << sufmex[idx] << ' ';
	}
	cout << res.size() << '\n';
	for(auto e : res)
		cout << e << ' ';
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