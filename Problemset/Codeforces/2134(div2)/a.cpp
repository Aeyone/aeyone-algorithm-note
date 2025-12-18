#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	bool ok = (1 ^ n  ^ b) & 1;
	if(a > b)
		ok &= (1 ^ n ^ a) & 1;
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