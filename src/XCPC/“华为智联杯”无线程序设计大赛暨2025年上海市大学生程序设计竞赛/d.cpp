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
	i64 a, b, x, y;
	cin >> a >> b >> x >> y;
	bool ok = false;
	ok |= (a == x && (y & b) == b);
	ok |= (b == y && (a & x) == x);
	if (ok) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
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