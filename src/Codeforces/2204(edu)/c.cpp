#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	i64 a, b, c, m;
	cin >> a >> b >> c >> m;

	i64 ac = m / lcm(a, c), ab = m / lcm(a, b), bc = m / lcm(b, c), abc = m / lcm(lcm(a, b), c);
	a = m / a, b = m / b, c = m / c;
	cout << (a - ab - ac + abc) * 6 + (ab + ac - 2 * abc) * 3 + abc * 2 << ' ';
	cout << (b - ab - bc + abc) * 6 + (ab + bc - 2 * abc) * 3 + abc * 2 << ' ';
	cout << (c - bc - ac + abc) * 6 + (bc + ac - 2 * abc) * 3 + abc * 2 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}