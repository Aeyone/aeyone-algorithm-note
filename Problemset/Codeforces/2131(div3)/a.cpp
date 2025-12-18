#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto &e : a)
		cin >> e;
	for(auto &e : b)
		cin >> e;
	i64 s = 0;
	for(int i = 0; i < n; i ++){
		if(a[i] > b[i])
			s += a[i] - b[i];
	}
	cout << s + 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}