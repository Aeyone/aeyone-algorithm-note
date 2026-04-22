#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

int exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, x, y);
	int X = x;
	x = y, y = X - (a / b) * y;
	return d;
}

void solve() {
	int n, d, x, y;
	cin >> n >> d >> x >> y;
	int k1 = 0, k2 = 0;
	int g = exgcd(d, n, k1, k2);
	int r = (y - x + n) % n;
	if (r % g != 0) {
		cout << "Impossible" << '\n';
	} else {
		int td = n / g, tn = d / g;
		k1 *= r / g, k2 *= r / g;

		int mx = ((k1 % td) + td) % td;
		int l = (mx - k1) / td, r = 1e9, ans = l;

		while (l <= r) {
			int mid = (l + r) / 2;
			if (k2 - mid * tn <= 0) {
				ans = mid, r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		cout << k1 + td * ans << '\n';
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