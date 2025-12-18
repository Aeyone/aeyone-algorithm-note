#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int k, x;
	cin >> k >> x;
	cout << x * (int)pow(2, k) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}