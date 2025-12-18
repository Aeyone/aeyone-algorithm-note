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

	bool ok = (a[n - 1] == b[n - 1]);
	for(int i = n - 2; i >= 0; i --){
		int x1 = (a[i] ^ b[i + 1]);
		int x2 = (a[i] ^ a[i + 1]);
		ok &= (a[i] == b[i] || x1 == b[i] || x2 == b[i]);
	}
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}