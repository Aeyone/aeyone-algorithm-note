#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i ++){
		if(!(i & 1))
			cout << -1 << ' ';
		else
			cout << 3 << ' ';
	}
	if(n & 1)
		cout << -1 << '\n';
	else
		cout << 2 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}