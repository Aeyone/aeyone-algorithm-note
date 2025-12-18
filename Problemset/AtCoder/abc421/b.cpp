#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 a[10] = {};
	cin >> a[0] >> a[1];
	for(int i = 2; i < 10; i ++){
		string s = to_string(a[i - 1] + a[i - 2]);
		reverse(s.begin(), s.end());
		a[i] = stoll(s);
	}
	cout << a[9] << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}