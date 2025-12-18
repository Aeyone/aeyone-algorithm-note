#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	i64 s = 0;
	for(int i = 1; i <= n; i ++)
		s += i * (2 * i - 1);

	cout << s << ' ' << 2 * n << '\n';
	for(int i = 2 * n; i >= 1; i --){
		cout << 1 + (i & 1) << ' ';
		cout << (i + 1) / 2 << ' ';
		for(int i = 1; i <= n; i ++)
			cout << i << ' ';
		cout << '\n';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}