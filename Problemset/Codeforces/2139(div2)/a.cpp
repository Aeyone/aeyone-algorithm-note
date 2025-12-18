#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a, b;
	cin >> a >> b;
	if(a > b)
		swap(a, b);
	if(a == b)
		cout << 0 << '\n';
	else if(b % a == 0)
		cout << 1 << '\n';
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