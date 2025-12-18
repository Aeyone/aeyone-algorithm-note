#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int s;
	cin >> s;
	printf("%.6lf\n", 150 * log(s));
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}