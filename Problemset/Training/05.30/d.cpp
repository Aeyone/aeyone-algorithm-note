#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int sum = 0;
	map<int, bool> mp;
	for(int i = 1; sum <= 500; i ++)
		sum += i, mp[sum] = true;
	int x;
	cin >> x;
	if(mp[x])
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}