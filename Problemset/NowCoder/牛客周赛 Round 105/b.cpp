#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n - 1);
	for(auto &e : a)
		cin >> e;
	for(int i = 0; i < n - 1; i ++){
		b[i] = a[i] ^ a[i + 1];
	}
	int ans = b.front();
	for(auto e : b)
		ans = __gcd(ans, e);
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}