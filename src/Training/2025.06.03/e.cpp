#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n, s;
	cin >> n >> s;

	auto check = [&](i64 x)-> bool{
		int sum = 0;
		while(x)
			sum += x % 10, x /= 10;
		return sum <= s;
	};

	i64 tmp = n, d = 10;
	while(!check(tmp)){
		tmp += d - (tmp % d);
		d *= 10;
	}
	cout << tmp - n << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}