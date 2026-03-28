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
	int x, y;
	cin >> x >> y;
	int d = abs(x - y);
	int ans = 1;
	for (int i = 2; i <= x + y; i ++) {
		ans += (d != 0 && d % i == 0);
	}
	cout << ans << '\n';
	for (int i = 0; i < x; i ++) {
		cout << 1 << ' ';
	}
	for (int i = 0; i < y; i ++) {
		cout << -1 << ' ';
	}
	cout << '\n';
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