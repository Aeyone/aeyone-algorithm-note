#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	map<int, int> mp1, mp2;
	for(int i = 0; i < n; i ++)
		cin >> a[i], mp1[a[i]] ++;
	for(int i = 0; i < n; i ++)
		cin >> b[i], mp2[b[i]] ++;

	if(mp1.size() * mp2.size() >= 3)
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