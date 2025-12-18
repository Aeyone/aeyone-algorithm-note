#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(min(a, c) >= min(b, d))
		cout << "Gellyfish" << '\n';
	else
		cout << "Flower" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}