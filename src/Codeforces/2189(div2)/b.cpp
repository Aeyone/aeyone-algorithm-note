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
	i64 n, x;
	cin >> n >> x;
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	i64 mx = 0, mx2 = 0;
	for (int i = 0; i < n; i ++) {
		mx = max(mx, 1ll * a[i] * b[i] - c[i]);
		mx2 += 1ll * a[i] * (b[i] - 1);
	}
	x -= mx2;
	if (x <= 0) {
		cout << 0 << '\n';
		return;
	}
	if (mx == 0) {
		cout << -1 << '\n';
	} else {
		cout << max(0ll, (x + mx - 1) / mx) << '\n';
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