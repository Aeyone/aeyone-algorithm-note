#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mp[a[i]] ++;
	}
	int sum = mp.size() - 1;
	cout << 2 * sum + 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}