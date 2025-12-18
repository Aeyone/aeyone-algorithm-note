#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	priority_queue<int> q;
	for(int i = 0; i < n; i ++)
		cin >> a[i], mp[a[i]] ++;

	int mn = 2e9;
	for(auto [_, e] : mp)
		q.push(e), mn = min(mn, e);

	while(q.size() > 2){
		int x, y;
		x = q.top(), q.pop();
		y = q.top(), q.pop();
		int z = x - y;
		if(z < mn){
			if((x + y - mn) & 1)
				z = mn - 1, mn = z;
			else
				z = mn;
		}
		if(z != 0)
			q.push(z);
	}
	int x, y = 0;
	x = q.top(), q.pop();

	if(q.size())
		y = q.top(), q.pop();

	cout << x - y << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}