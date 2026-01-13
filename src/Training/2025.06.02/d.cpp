#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;

void solve() {
	i64 n;
	cin >> n;
	vector<i64> lcm(43, 0);
	lcm[1] = 1;
	i64 tmp = 1;
	for(int i = 2; i <= 42; i ++)
		lcm[i] = i / __gcd((i64)i , lcm[i - 1]) * lcm[i - 1];
	i64 ans = 0;
	for(int i = 2; i <= 42; i ++){
		ans = (ans + i * (n / lcm[i - 1] - n / lcm[i]) % mod)% mod;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}