#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int a, b;
	cin >> a >> b;
	int c = 6 - max(a, b) + 1;

	auto gcd = [&](this auto self, int a, int b)-> int{
		return (b ? self(b, a % b) : a);
	};
	
	cout << c / gcd(c, 6) << "/" << 6 / gcd(c, 6) << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}