#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 a, b, x, y;
	cin >> a >> b >> x >> y;

	auto gcd = [&](this auto self, int a, int b)-> i64{
		return (b ? self(b, a % b) : a);
	};

	int g = gcd(x, y);
	x = x / g, y = y / g;

	i64 l = 0, r = a + b, ans = 0;
	while(l <= r){
		i64 mid = (l + r) >> 1;
		if(x * mid <= a && y * mid <= b)
			l = mid + 1, ans = mid;
		else
			r = mid - 1;
	}
	cout << x * ans << " " << y * ans << '\n';	
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}